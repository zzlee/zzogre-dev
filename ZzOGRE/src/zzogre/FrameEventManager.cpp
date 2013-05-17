/*
 * FrameEventManager.cpp
 *
 *  Created on: 2013/3/5
 *      Author: SUCHEN
 */

#include "FrameEventManager.h"

using namespace boost;
using namespace std;

namespace zzogre {

Ogre::FrameEvent _FrameEvent = { 0, 0 };
FrameEventManager _FrameEventManager;

FrameEventManager::FrameEventManager() {
}

FrameEventManager::~FrameEventManager() {
}

bool FrameEventManager::frameStarted(const Ogre::FrameEvent& evt) {
	_FrameEvent = evt;
	mProcessors[FET_Started].fireEvent();

	return true;
}

bool FrameEventManager::frameRenderingQueued(const Ogre::FrameEvent& evt) {
	_FrameEvent = evt;
	mProcessors[FET_Queued].fireEvent();

	return true;
}

bool FrameEventManager::frameEnded(const Ogre::FrameEvent& evt) {
	_FrameEvent = evt;
	mProcessors[FET_Ended].fireEvent();

	return true;
}

FrameEventManager::EventProcessor::EventProcessor() :
		mIdSeed(0), mInEventProcessing(false), mHandlerRemoved(false) {
}

FrameEventManager::EventProcessor::~EventProcessor() {
	for (unordered_map<uint32_t, FrameEventHandler*>::iterator i =
			mHandlers.begin(); i != mHandlers.end(); ++i) {
		delete (*i).second;
	}

	for (unordered_map<uint32_t, FrameEventHandler*>::iterator i =
			mNewHandlers.begin(); i != mNewHandlers.end(); ++i) {
		delete (*i).second;
	}
}

uint32_t FrameEventManager::EventProcessor::addHandler(
		FrameEventHandler handler) {
	uint32_t id = mIdSeed++;
	if (id == 0)
		id = mIdSeed++;

	if (mInEventProcessing)
		mNewHandlers[id] = new FrameEventHandler(handler);
	else
		mHandlers[id] = new FrameEventHandler(handler);

	return id;
}

void FrameEventManager::EventProcessor::removeHandler(uint32_t id) {
	if (mInEventProcessing) {
		unordered_map<uint32_t, FrameEventHandler*>::iterator i =
				mHandlers.find(id);
		if (i == mHandlers.end()) {
			i = mNewHandlers.find(id);
			if (i == mNewHandlers.end())
				return;

			delete (*i).second;
			mNewHandlers.erase(i);
			return;
		}

		(*i).second = NULL;
		mHandlerRemoved = true;
	} else {
		unordered_map<uint32_t, FrameEventHandler*>::iterator i =
				mHandlers.find(id);
		if (i == mHandlers.end())
			return;

		delete (*i).second;
		mHandlers.erase(i);
	}
}

void FrameEventManager::EventProcessor::fireEvent() {
	mInEventProcessing = true;
	for (unordered_map<uint32_t, FrameEventHandler*>::const_iterator i =
			mHandlers.begin(); i != mHandlers.end(); ++i) {
		if ((*i).second)
			(*(*i).second)();
	}
	mInEventProcessing = false;

	for (unordered_map<uint32_t, FrameEventHandler*>::const_iterator i =
			mNewHandlers.begin(); i != mNewHandlers.end(); ++i) {
		mHandlers.insert(*i);
	}
	mNewHandlers.clear();

	if (mHandlerRemoved) {
		for (unordered_map<uint32_t, FrameEventHandler*>::iterator i =
				mHandlers.begin(); i != mHandlers.end();) {
			if ((*i).second)
				++i;
			else
				i = mHandlers.erase(i);
		}
		mHandlerRemoved = false;
	}
}

}

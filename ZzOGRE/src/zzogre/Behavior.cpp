/*
 * Behavior.cpp
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

#include "Behavior.h"

using namespace std;

#include <boost/bind.hpp>
using namespace boost;

#include "OISRenderWindow.h"

namespace zzogre {

Behavior::Behavior() :
		mStarted(false), mEnableMouseEvent(false), mEnableKeyEvent(
				false) {
	handleEnable = boost::bind(&Behavior::_Enable, this);
	handleDisable = boost::bind(&Behavior::_Disable, this);

	mEnableFrameEvent[FET_Started] = mEnableFrameEvent[FET_Queued] =
			mEnableFrameEvent[FET_Ended] = false;
	memset(mFrameEventIds, 0, sizeof(mFrameEventIds));
}

Behavior::~Behavior() {
}

void Behavior::onEnable() {
}

void Behavior::onDisable() {
}

void Behavior::onStart() {
}

void Behavior::onFrameStarted() {
}

void Behavior::onFrameQueued() {
}

void Behavior::onFrameEnded() {
}

void Behavior::onMouseMoved(const OIS::MouseEvent &arg) {
}

void Behavior::onMousePressed(const OIS::MouseEvent &arg,
		OIS::MouseButtonID id) {
}

void Behavior::onMouseReleased(const OIS::MouseEvent &arg,
		OIS::MouseButtonID id) {
}

void Behavior::onKeyPressed(const OIS::KeyEvent &arg) {
}

void Behavior::onKeyReleased(const OIS::KeyEvent &arg) {
}

void Behavior::onUnconnectedPong(RakNet::Packet* packet) {
}

void Behavior::onConnected(RakNet::Packet* packet) {
}

void Behavior::onDisonnected(RakNet::Packet* packet) {
}

void Behavior::onConnectedToServer(RakNet::Packet* packet) {
}

void Behavior::onDisonnectedFromServer(RakNet::Packet* packet) {
}

void Behavior::onFailedToConnect(RakNet::Packet* packet) {
}

void Behavior::onDataPacket(RakNet::Packet* packet) {
}

void Behavior::onSave(XmlNode* node) {
}

void Behavior::onLoad(XmlNode* node) {
}

void Behavior::_Enable() {
	onEnable();

	if (mStarted) {
		if (mEnableFrameEvent[FET_Started]) {
			mFrameEventIds[FET_Started] = _FrameEventManager.addHandler(
					boost::bind(&Behavior::onFrameStarted,
								this), FET_Started);
		}
	}
	else {
		mFrameEventIds[FET_Started] = _FrameEventManager.addHandler(
				boost::bind(&Behavior::_Start, this), FET_Started);
		mStarted = true;
	}

	if (mEnableFrameEvent[FET_Ended]) {
		mFrameEventIds[FET_Ended] = _FrameEventManager.addHandler(
				boost::bind(&Behavior::onFrameEnded,
							this), FET_Ended);
	}

	if (mEnableFrameEvent[FET_Queued]) {
		mFrameEventIds[FET_Queued] = _FrameEventManager.addHandler(
				boost::bind(&Behavior::onFrameQueued,
							this), FET_Queued);
	}

	if (mEnableMouseEvent)
		mInputSource->addMouseEventHandler(this);

	if (mEnableKeyEvent)
		mInputSource->addKeyEventHandler(this);
}

void Behavior::_Disable() {
	for (size_t i = 0; i < (size_t) FET_Types; ++i) {
		FrameEventType type = (FrameEventType) i;
		if (mFrameEventIds[type]) {
			_FrameEventManager.removeHandler(mFrameEventIds[type], type);
			mFrameEventIds[type] = 0;
		}
	}

	if (mEnableMouseEvent)
		mInputSource->removeMouseEventHandler(this);

	if (mEnableKeyEvent)
		mInputSource->removeKeyEventHandler(this);

	onDisable();
}

void Behavior::_Start() {
	onStart();

	_FrameEventManager.removeHandler(mFrameEventIds[FET_Started], FET_Started);
	mFrameEventIds[FET_Started] = 0;

	if(mEnableFrameEvent[FET_Started]) {
		onFrameStarted();

		mFrameEventIds[FET_Started] = _FrameEventManager.addHandler(
				boost::bind(&Behavior::onFrameStarted,
							this), FET_Started);
	}
}

} /* namespace zzogre */

/*
 * FrameEventManager.h
 *
 *  Created on: 2013/3/5
 *      Author: SUCHEN
 */

#ifndef FRAMEEVENTMANAGER_H_
#define FRAMEEVENTMANAGER_H_

#include <OgreFrameListener.h>

#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <boost/function.hpp>

namespace zzogre {

enum FrameEventType {
	FET_Started = 0, FET_Queued = 1, FET_Ended = 2, FET_Types,
};

typedef boost::function<void()> FrameEventHandler;

class FrameEventManager: public Ogre::FrameListener {
public:
	FrameEventManager();
	virtual ~FrameEventManager();

	virtual bool frameStarted(const Ogre::FrameEvent& evt);
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
	virtual bool frameEnded(const Ogre::FrameEvent& evt);

	uint32_t addHandler(FrameEventHandler handler, FrameEventType type) {
		return mProcessors[type].addHandler(handler);
	}

	void removeHandler(uint32_t id, FrameEventType type) {
		return mProcessors[type].removeHandler(id);
	}

protected:
	struct EventProcessor {
		uint32_t mIdSeed;
		bool mInEventProcessing;
		bool mHandlerRemoved;
		boost::unordered_map<uint32_t, FrameEventHandler*> mHandlers;
		boost::unordered_map<uint32_t, FrameEventHandler*> mNewHandlers;

		EventProcessor();
		~EventProcessor();

		uint32_t addHandler(FrameEventHandler handler);
		void removeHandler(uint32_t id);
		void fireEvent();
	};

	EventProcessor mProcessors[FET_Types];
};

extern Ogre::FrameEvent _FrameEvent;
extern FrameEventManager _FrameEventManager;

}

#endif /* FRAMEEVENTMANAGER_H_ */

/*
 * Behavior.h
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

#ifndef BEHAVIOR_H_
#define BEHAVIOR_H_

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <OISMouse.h>
#include <OISKeyboard.h>
#include <OISInputManager.h>

#include <RakNet/NetworkIDObject.h>
#include <RakNet/RakNetTypes.h>

#include "zzlab/ZzLab.h"
#include "Component.h"
#include "FrameEventManager.h"

namespace zzogre {

class OISRenderWindow;

class Behavior: public Component,
		public boost::enable_shared_from_this<Behavior> {
	friend class OISRenderWindow;
	friend class RakNetManager;

protected:
	explicit Behavior();

public:
	virtual ~Behavior();

protected:
	// state events
	virtual void onEnable();
	virtual void onDisable();
	virtual void onStart();

	// frame events
	virtual void onFrameStarted();
	virtual void onFrameQueued();
	virtual void onFrameEnded();

	void enableFrameEvent(FrameEventType type, bool enable = true) {
		mEnableFrameEvent[type] = enable;
	}

	// input events
	virtual void onMouseMoved(const OIS::MouseEvent &arg);
	virtual void onMousePressed(const OIS::MouseEvent &arg,
			OIS::MouseButtonID id);
	virtual void onMouseReleased(const OIS::MouseEvent &arg,
			OIS::MouseButtonID id);
	virtual void onKeyPressed(const OIS::KeyEvent &arg);
	virtual void onKeyReleased(const OIS::KeyEvent &arg);

	void disableInputEvent() {
		mInputSource.reset();
		mEnableMouseEvent = mEnableKeyEvent = false;
	}

	void enableInputEvent(boost::shared_ptr<OISRenderWindow> source, bool mouseEvent,
			bool keyEvent) {
		mInputSource = source;
		mEnableMouseEvent = mouseEvent;
		mEnableKeyEvent = keyEvent;
	}

	// network events
	virtual void onUnconnectedPong(RakNet::Packet* packet);
	virtual void onConnected(RakNet::Packet* packet);
	virtual void onDisonnected(RakNet::Packet* packet);
	virtual void onConnectedToServer(RakNet::Packet* packet);
	virtual void onDisonnectedFromServer(RakNet::Packet* packet);
	virtual void onFailedToConnect(RakNet::Packet* packet);
	virtual void onDataPacket(RakNet::Packet* packet);

	// serialize events
	virtual void onSave(XmlNode* node);
	virtual void onLoad(XmlNode* node);

private:
	void _Enable();
	void _Disable();
	void _Start();

	bool mEnableFrameEvent[FET_Types];
	uint32_t mFrameEventIds[FET_Types];
	bool mStarted;

	boost::shared_ptr<OISRenderWindow> mInputSource;
	bool mEnableMouseEvent;
	bool mEnableKeyEvent;
};
ZZLAB_TYPEDEF_SHARED_PTR(Behavior);

} /* namespace zzogre */
#endif /* BEHAVIOR_H_ */

/*
 * OISRenderWindow.h
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

#ifndef OISRENDERWINDOW_H_
#define OISRENDERWINDOW_H_

#include <string>

#include <OgreWindowEventUtilities.h>
#include <OISMouse.h>
#include <OISKeyboard.h>

#include <boost/unordered_map.hpp>

#include "zzlab/ZzLab.h"
#include "Behavior.h"

namespace zzogre {

class OISRenderWindow: public Ogre::WindowEventListener,
		public OIS::MouseListener,
		public OIS::KeyListener {
public:
	std::string name;
	int width, height;
	bool useFullScreen;

	std::string title;
	int left, top;
	int monitorIndex;
	int colourDepth;
	bool depthBuffer;
	HWND externalWindowHandle;
	HWND parentWindowHandle;
	int FSAA;
	std::string FSAAHint;
	int displayFrequency;
	bool vsync;
	int vsyncInterval;
	std::string border;
	bool outerDimensions;
	bool gamma;
	bool enableDoubleClick;
	bool deactivateOnFocusChange;

	bool mouseForeground;
	bool mouseExclusive;
	bool keyboardForeground;
	bool keyboardExclusive;

	bool autoCapture;
	bool quitOnDestroy;

	OISRenderWindow();
	virtual ~OISRenderWindow();

public:
	void initialise();

	Ogre::RenderWindow* getRenderWindow() const {
		return mRenderWindow;
	}

	OIS::InputManager* getInputManager() const {
		return mInputManager;
	}

	OIS::Mouse* getMouse() const {
		return mMouse;
	}

	OIS::Keyboard* getKeyboard() const {
		return mKeyboard;
	}

	void addMouseEventHandler(Behavior* behavior);
	void removeMouseEventHandler(Behavior* behavior);
	void addKeyEventHandler(Behavior* behavior);
	void removeKeyEventHandler(Behavior* behavior);

	void setRenderWindowActive();

	// window events
	virtual void windowMoved(Ogre::RenderWindow *rw);
	virtual void windowResized(Ogre::RenderWindow *rw);
	virtual bool windowClosing(Ogre::RenderWindow *rw);
	virtual void windowClosed(Ogre::RenderWindow *rw);
	virtual void windowFocusChange(Ogre::RenderWindow *rw);

	// mouse events
	virtual bool mouseMoved(const OIS::MouseEvent &arg);
	virtual bool mousePressed(const OIS::MouseEvent &arg,
			OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent &arg,
			OIS::MouseButtonID id);

	// key events
	virtual bool keyPressed(const OIS::KeyEvent &arg);
	virtual bool keyReleased(const OIS::KeyEvent &arg);

protected:
	Ogre::RenderWindow* mRenderWindow;
	OIS::InputManager* mInputManager;
	OIS::Mouse* mMouse;
	OIS::Keyboard* mKeyboard;

	bool mInMouseEventProcessing;
	bool mMouseHandlerRemoved;
	boost::unordered_map<Behavior*, Behavior*> mMouseEventHandlers;
	boost::unordered_map<Behavior*, Behavior*> mNewMouseEventHandlers;

	bool mInKeyEventProcessing;
	bool mKeyHandlerRemoved;
	boost::unordered_map<Behavior*, Behavior*> mKeyEventHandlers;
	boost::unordered_map<Behavior*, Behavior*> mNewKeyEventHandlers;

	uint32_t mCaptureInputId;
	void onCaptureInput();

	void handlePostMouseEvent();
	void handlePostKeyEvent();
};
ZZLAB_TYPEDEF_SHARED_PTR(OISRenderWindow);

} /* namespace zzogre */
#endif /* OISRENDERWINDOW_H_ */

/*
 * OISRenderWindow.cpp
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

#include "OISRenderWindow.h"

using namespace std;

using namespace boost;

#include <OISInputManager.h>
using namespace OIS;

using namespace Ogre;

#include "ZzOGRE.h"
#include "FrameEventManager.h"

namespace zzogre {

OISRenderWindow::OISRenderWindow() :
		name("RenderWindow-0"), width(1024), height(768), useFullScreen(false), title(
				"Scene"), left(-65536), top(-65536), monitorIndex(-1), colourDepth(
				32), depthBuffer(true), externalWindowHandle(NULL), parentWindowHandle(
				NULL), FSAA(0), FSAAHint(""), displayFrequency(60), vsync(
				false), vsyncInterval(1), border("resize"), outerDimensions(
				false), gamma(false), enableDoubleClick(false), deactivateOnFocusChange(true),

		mouseForeground(true), mouseExclusive(false), keyboardForeground(
				true), keyboardExclusive(false),

		autoCapture(true), quitOnDestroy(true), mRenderWindow(NULL), mInputManager(
				NULL), mMouse(NULL), mKeyboard(NULL), mInMouseEventProcessing(false), mMouseHandlerRemoved(false),
				mInKeyEventProcessing(false), mKeyHandlerRemoved(false), mCaptureInputId(0) {
}

OISRenderWindow::~OISRenderWindow() {
	if (mCaptureInputId)
		_FrameEventManager.removeHandler(mCaptureInputId, FET_Started);

	if (mInputManager) {
		mInputManager->destroyInputObject(mMouse);
		mInputManager->destroyInputObject(mKeyboard);
		InputManager::destroyInputSystem(mInputManager);
	}

	if (mRenderWindow)
		_Root->destroyRenderTarget(mRenderWindow);
}

void OISRenderWindow::initialise() {
	Ogre::NameValuePairList renderWindowParams;
	renderWindowParams["title"] = title;
	if (left > -65536)
		renderWindowParams["left"] = StringConverter::toString(left);
	if (top > -65536)
		renderWindowParams["top"] = StringConverter::toString(top);
	renderWindowParams["colourDepth"] = StringConverter::toString(colourDepth);
	renderWindowParams["depthBuffer"] = StringConverter::toString(depthBuffer);
	if (externalWindowHandle)
		renderWindowParams["externalWindowHandle"] = StringConverter::toString(
				(int) externalWindowHandle);
	if (parentWindowHandle)
		renderWindowParams["parentWindowHandle"] = StringConverter::toString(
				(int) parentWindowHandle);
	renderWindowParams["FSAA"] = StringConverter::toString(FSAA);
	renderWindowParams["FSAAHint"] = FSAAHint;
	renderWindowParams["displayFrequency"] = StringConverter::toString(
			displayFrequency);
	renderWindowParams["vsync"] = StringConverter::toString(vsync);
	renderWindowParams["vsyncInterval"] = StringConverter::toString(
			vsyncInterval);
	renderWindowParams["border"] = border;
	renderWindowParams["outerDimensions"] = StringConverter::toString(
			outerDimensions);
	renderWindowParams["gamma"] = StringConverter::toString(gamma);
	if(monitorIndex >= 0)
		renderWindowParams["monitorIndex"] = StringConverter::toString(monitorIndex);
	renderWindowParams["enableDoubleClick"] = StringConverter::toString(
			enableDoubleClick);

	// Create render window
	mRenderWindow = _Root->createRenderWindow(name, width, height,
			useFullScreen, &renderWindowParams);
	mRenderWindow->setDeactivateOnFocusChange(deactivateOnFocusChange);
	WindowEventUtilities::addWindowEventListener(mRenderWindow, this);

	// Create OIS objects
	ParamList inputParams;
	size_t windowHandle = 0;
	mRenderWindow->getCustomAttribute("WINDOW", &windowHandle);
	inputParams.insert(
			make_pair<string, string>("WINDOW",
					StringConverter::toString(windowHandle)));
	inputParams.insert(
			make_pair<string, string>("w32_mouse",
					mouseForeground ? "DISCL_FOREGROUND" : "DISCL_BACKGROUND"));
	inputParams.insert(
			make_pair<string, string>("w32_mouse",
					mouseExclusive ? "DISCL_EXCLUSIVE" : "DISCL_NONEXCLUSIVE"));
	inputParams.insert(
			make_pair<string, string>("w32_keyboard",
					keyboardForeground ?
							"DISCL_FOREGROUND" : "DISCL_BACKGROUND"));
	inputParams.insert(
			make_pair<string, string>("w32_keyboard",
					keyboardExclusive ?
							"DISCL_EXCLUSIVE" : "DISCL_NONEXCLUSIVE"));
	mInputManager = InputManager::createInputSystem(inputParams);
	mMouse = static_cast<Mouse*>(mInputManager->createInputObject(OISMouse,
			true));
	mMouse->setEventCallback(this);
	mKeyboard = static_cast<Keyboard*>(mInputManager->createInputObject(
			OISKeyboard, true));
	mKeyboard->setEventCallback(this);

	const MouseState &ms = mMouse->getMouseState();
	ms.width = width;
	ms.height = height;

	if (autoCapture) {
		mCaptureInputId = _FrameEventManager.addHandler(
				boost::bind(&OISRenderWindow::onCaptureInput, this),
				FET_Started);
	}
}

void OISRenderWindow::addMouseEventHandler(Behavior* behavior) {
	if(mInMouseEventProcessing)
		mNewMouseEventHandlers[behavior] = behavior;
	else
		mMouseEventHandlers[behavior] = behavior;
}

void OISRenderWindow::removeMouseEventHandler(Behavior* behavior) {
	if(mInMouseEventProcessing) {
		unordered_map<Behavior*, Behavior*>::iterator i = mMouseEventHandlers.find(behavior);
		if (i == mMouseEventHandlers.end()) {
			i = mNewMouseEventHandlers.find(behavior);
			if (i == mMouseEventHandlers.end())
				return;

			mMouseEventHandlers.erase(i);

			return;
		}

		(*i).second = NULL;
		mMouseHandlerRemoved = true;
	} else {
		unordered_map<Behavior*, Behavior*>::iterator i = mMouseEventHandlers.find(behavior);
		if (i == mMouseEventHandlers.end())
			return;

		mMouseEventHandlers.erase(i);
	}
}

void OISRenderWindow::addKeyEventHandler(Behavior* behavior) {
	if(mInKeyEventProcessing)
		mNewKeyEventHandlers[behavior] = behavior;
	else
		mKeyEventHandlers[behavior] = behavior;
}

void OISRenderWindow::removeKeyEventHandler(Behavior* behavior) {
	if(mInKeyEventProcessing) {
		unordered_map<Behavior*, Behavior*>::iterator i = mKeyEventHandlers.find(behavior);
		if (i == mKeyEventHandlers.end()) {
			i = mNewKeyEventHandlers.find(behavior);
			if (i == mNewKeyEventHandlers.end())
				return;

			mNewKeyEventHandlers.erase(i);

			return;
		}

		(*i).second = NULL;
		mKeyHandlerRemoved = true;
	} else {
		unordered_map<Behavior*, Behavior*>::iterator i = mKeyEventHandlers.find(behavior);
		if (i == mKeyEventHandlers.end())
			return;

		mKeyEventHandlers.erase(i);
	}
}

void OISRenderWindow::setRenderWindowActive() {
	zzogre::setRenderWindowActive(mRenderWindow);
}

void OISRenderWindow::windowMoved(Ogre::RenderWindow *rw) {
}

void OISRenderWindow::windowResized(Ogre::RenderWindow *rw) {
	const MouseState &ms = mMouse->getMouseState();
	ms.width = rw->getWidth();
	ms.height = rw->getHeight();
}

bool OISRenderWindow::windowClosing(Ogre::RenderWindow *rw) {
	if (quitOnDestroy) {
		_Root->queueEndRendering();
		return false;
	}

	return true;
}

void OISRenderWindow::windowClosed(Ogre::RenderWindow *rw) {
}

void OISRenderWindow::windowFocusChange(Ogre::RenderWindow *rw) {
}

bool OISRenderWindow::mouseMoved(const OIS::MouseEvent &arg) {
	mInMouseEventProcessing = true;
	for (unordered_map<Behavior*, Behavior*>::const_iterator i =
			mMouseEventHandlers.begin(); i != mMouseEventHandlers.end(); ++i) {
		if((*i).second)
			(*i).second->onMouseMoved(arg);
	}

	handlePostMouseEvent();

	return true;
}

bool OISRenderWindow::mousePressed(const OIS::MouseEvent &arg,
		OIS::MouseButtonID id) {
	mInMouseEventProcessing = true;
	for (unordered_map<Behavior*, Behavior*>::const_iterator i =
			mMouseEventHandlers.begin(); i != mMouseEventHandlers.end(); ++i) {
		if((*i).second)
			(*i).second->onMousePressed(arg, id);
	}

	handlePostMouseEvent();

	return true;
}

bool OISRenderWindow::mouseReleased(const OIS::MouseEvent &arg,
		OIS::MouseButtonID id) {
	mInMouseEventProcessing = true;
	for (unordered_map<Behavior*, Behavior*>::const_iterator i =
			mMouseEventHandlers.begin(); i != mMouseEventHandlers.end(); ++i) {
		if((*i).second)
			(*i).second->onMouseReleased(arg, id);
	}

	handlePostMouseEvent();

	return true;
}

bool OISRenderWindow::keyPressed(const OIS::KeyEvent &arg) {
	mInKeyEventProcessing = true;
	for (unordered_map<Behavior*, Behavior*>::const_iterator i =
			mKeyEventHandlers.begin(); i != mKeyEventHandlers.end(); ++i) {
		if((*i).second)
			(*i).second->onKeyPressed(arg);
	}

	handlePostKeyEvent();

	return true;
}

bool OISRenderWindow::keyReleased(const OIS::KeyEvent &arg) {
	mInKeyEventProcessing = true;
	for (unordered_map<Behavior*, Behavior*>::const_iterator i =
			mKeyEventHandlers.begin(); i != mKeyEventHandlers.end(); ++i) {
		if((*i).second)
			(*i).second->onKeyReleased(arg);
	}

	handlePostKeyEvent();

	return true;
}

void OISRenderWindow::onCaptureInput() {
	mMouse->capture();
	mKeyboard->capture();
}

void OISRenderWindow::handlePostMouseEvent() {
	mInMouseEventProcessing = false;

	for (unordered_map<Behavior*, Behavior*>::const_iterator i =
			mNewMouseEventHandlers.begin(); i != mNewMouseEventHandlers.end(); ++i)
		mMouseEventHandlers.insert(*i);
	mNewMouseEventHandlers.clear();

	if(mMouseHandlerRemoved) {
		for (unordered_map<Behavior*, Behavior*>::iterator i =
				mMouseEventHandlers.begin(); i != mMouseEventHandlers.end();) {
			if ((*i).second)
				++i;
			else
				i = mMouseEventHandlers.erase(i);
		}
		mMouseHandlerRemoved = false;
	}
}

void OISRenderWindow::handlePostKeyEvent() {
	mInKeyEventProcessing = false;

	for (unordered_map<Behavior*, Behavior*>::const_iterator i =
			mNewKeyEventHandlers.begin(); i != mNewKeyEventHandlers.end(); ++i)
		mKeyEventHandlers.insert(*i);
	mNewKeyEventHandlers.clear();

	if(mKeyHandlerRemoved) {
		for (unordered_map<Behavior*, Behavior*>::iterator i =
				mKeyEventHandlers.begin(); i != mKeyEventHandlers.end();) {
			if ((*i).second)
				++i;
			else
				i = mKeyEventHandlers.erase(i);
		}
		mKeyHandlerRemoved = false;
	}
}

} /* namespace zzogre */

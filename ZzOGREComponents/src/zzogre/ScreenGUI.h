/*
 * ScreenGUI.h
 *
 *  Created on: 2013/5/8
 *      Author: SUCHEN
 */

#ifndef SCREENGUI_H_
#define SCREENGUI_H_

#include <zzogre/ZzOGRE.h>
#include <zzogre/Behavior.h>
#include <zzogre/SceneNodes.h>
#include <zzogre/OISRenderWindow.h>

#include <gui3d/Gui3DScreenPanel.h>

namespace zzogre {

class ScreenGUI : public Behavior {
	ZZOGRE_COMPONENT_TYPE(ScreenGUI);

public:
	ScreenGUI();
	virtual ~ScreenGUI();

	Ogre::String renderWindowName;
	Ogre::String atlasName;
	Ogre::Vector2 position;
	Ogre::Vector2 size;

	const ScreenPanelPtr& panel() const {
		return mPanel;
	}

protected:
	Gorilla::Screen* mScreen;
	ScreenPanelPtr mPanel;

	// state events
	virtual void onEnable();
	virtual void onDisable();

	// serialize events
	virtual void onSave(XmlNode* node);
	virtual void onLoad(XmlNode* node);

	// frame events
	virtual void onFrameStarted();

	// input events
	virtual void onMouseMoved(const OIS::MouseEvent &arg);
	virtual void onMousePressed(const OIS::MouseEvent &arg,
			OIS::MouseButtonID id);
	virtual void onMouseReleased(const OIS::MouseEvent &arg,
			OIS::MouseButtonID id);
	virtual void onKeyPressed(const OIS::KeyEvent &arg);
	virtual void onKeyReleased(const OIS::KeyEvent &arg);
};
ZZLAB_TYPEDEF_SHARED_PTR(ScreenGUI);

} /* namespace zzogre */
#endif /* SCREENGUI_H_ */

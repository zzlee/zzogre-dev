/*
 * ScreenGUI.cpp
 *
 *  Created on: 2013/5/8
 *      Author: SUCHEN
 */

#include "ScreenGUI.h"

#include <OgreStringConverter.h>
using namespace Ogre;

using namespace rapidxml;

namespace zzogre {

ZZOGRE_COMPONENT_REGISTER(ScreenGUI);

ScreenGUI::ScreenGUI() :
		atlasName("completeGUIDemo") {
}

ScreenGUI::~ScreenGUI() {
}

void ScreenGUI::onEnable() {
	OISRenderWindowPtr inputSource;
	if (!renderWindowName.empty()) {
		for (std::vector<OISRenderWindowPtr>::const_iterator i =
				_Windows.begin(); i != _Windows.end(); ++i) {
			if ((*i)->getRenderWindow()->getName() == renderWindowName) {
				inputSource = *i;
				break;
			}
		}
	} else {
		inputSource = _Window;
	}

	Ogre::Viewport* viewport = inputSource->getRenderWindow()->getViewport(
			0);

	mScreen = _Gui3D->createScreen(viewport, atlasName,
			parent.get()->getName() + "/Screen");
	mPanel.reset(
			new Gui3D::ScreenPanel(_Gui3D, mScreen, position, size,
					atlasName, parent.get()->getName() + "/ScreenPanel"));

	enableFrameEvent(FET_Started);
	enableInputEvent(inputSource, true, true);
}

void ScreenGUI::onDisable() {
	mPanel.reset();
	_Gui3D->destroyScreen(mScreen);
}

void ScreenGUI::onSave(XmlNode* node) {
	XmlDocument* doc = node->document();
	XmlNode* data = doc->allocate_node(node_element, "data");
	node->append_node(data);

	XmlAttribute* attr = doc->allocate_attribute("render-window-name",
			renderWindowName.c_str());
	data->append_attribute(attr);

	attr = doc->allocate_attribute("atlas-name", atlasName.c_str());
	data->append_attribute(attr);

	attr = doc->allocate_attribute("position",
			doc->allocate_string(
					StringConverter::toString(position).c_str()));
	data->append_attribute(attr);

	attr = doc->allocate_attribute("size",
			doc->allocate_string(StringConverter::toString(size).c_str()));
	data->append_attribute(attr);
}

void ScreenGUI::onLoad(XmlNode* node) {
	XmlNode* data = node->first_node("data");
	if (data) {
		XmlAttribute* attr = data->first_attribute("render-window-name");
		if (attr)
			renderWindowName = attr->value();

		attr = data->first_attribute("atlas-name");
		if (attr)
			atlasName = attr->value();

		attr = data->first_attribute("position");
		if (attr)
			position = StringConverter::parseVector2(attr->value());

		attr = data->first_attribute("size");
		if (attr)
			size = StringConverter::parseVector2(attr->value());
	}
}

void ScreenGUI::onFrameStarted() {
	mPanel->injectTime(_FrameEvent.timeSinceLastFrame);
}

void ScreenGUI::onMouseMoved(const OIS::MouseEvent &arg) {
	mPanel->injectMouseMoved(arg.state.X.abs, arg.state.Y.abs);
}

void ScreenGUI::onMousePressed(const OIS::MouseEvent &arg,
		OIS::MouseButtonID id) {
	mPanel->injectMousePressed(arg, id);
}

void ScreenGUI::onMouseReleased(const OIS::MouseEvent &arg,
		OIS::MouseButtonID id) {
	mPanel->injectMouseReleased(arg, id);
}

void ScreenGUI::onKeyPressed(const OIS::KeyEvent &arg) {
	mPanel->injectKeyPressed(arg);
}

void ScreenGUI::onKeyReleased(const OIS::KeyEvent &arg) {
	mPanel->injectKeyReleased(arg);
}

} /* namespace zzogre */

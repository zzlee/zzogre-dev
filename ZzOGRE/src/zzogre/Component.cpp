/*
 * Component.cpp
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

using namespace std;

#include "Component.h"
#include "ComponentManager.h"
#include "BehaviorsPlugin.h"
#include "SceneNodes.h"
#include "FrameEventManager.h"

#include <boost/format.hpp>
#include <boost/bind.hpp>
using namespace boost;

#define MAX_COMPONENT_TYPES		512

static void _() {
}

namespace zzogre {

static const char* _ComponentNames[MAX_COMPONENT_TYPES];
static ComponentCreator _ComponentCreators[MAX_COMPONENT_TYPES];
static bool _ComponentRegistered[MAX_COMPONENT_TYPES];
static size_t _ComponentTypes = 0;

Component::Component() :
		enable(false, bind(&Component::onEnableModified, this, _1, _2)), parent(
				(Ogre::SceneNode*) NULL,
				bind(&Component::onParentModified, this, _1, _2)) {
	handleEnable = boost::bind(_);
	handleDisable = boost::bind(_);
}

Component::~Component() {
}

void Component::save(XmlNode* node) {
	onSave(node);
}

void Component::load(XmlNode* node) {
	onLoad(node);
}

void Component::onSave(XmlNode* node) {
}

void Component::onLoad(XmlNode* node) {
}

void Component::onEnableModified(bool& a, const bool& b) {
	if (a == b)
		return;

	if (parent.get()) {
		if (b) {
			handleEnable();
		} else {
			handleDisable();
		}
	}

	a = b;
}

void Component::onParentModified(Ogre::SceneNode*& a,
		Ogre::SceneNode* const & b) {
//	cout << "onParentModified:" << a << ',' << b << endl;

	if (a == b)
		return;

	bool enable_ = enable.get();
	if (enable_)
		enable.set(false);

	boost::shared_ptr<Component> pThis;
	if (a || b)
		pThis = shared_from_this();

	if (a)
		SceneNodes::removeComponentImpl(a, pThis);

	a = b;

	if (b)
		SceneNodes::addComponentImpl(b, pThis);

	if (enable_)
		enable.set(true);
}

ComponentRegister::ComponentRegister(const char* name,
		ComponentCreator creator) {
	_ComponentNames[_ComponentTypes] = name;
	_ComponentCreators[_ComponentTypes] = creator;
	_ComponentRegistered[_ComponentTypes] = false;

	++_ComponentTypes;
}

void BehaviorsPlugin::initialise() {
	for (size_t i = 0; i < _ComponentTypes; ++i) {
		if (_ComponentRegistered[i])
			continue;

		ComponentManager::registerComponentType(_ComponentNames[i],
				_ComponentCreators[i]);
		_ComponentRegistered[i] = true;
	}
}

} /* namespace zzogre */

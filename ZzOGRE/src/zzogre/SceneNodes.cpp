/*
 * SceneNodes.cpp
 *
 *  Created on: 2013/1/30
 *      Author: SUCHEN
 */

#include "SceneNodes.h"
using namespace std;
using namespace boost;

#include <OgreSceneNode.h>
using namespace Ogre;

#include "ComponentManager.h"
using namespace zzogre;

namespace zzogre {

void SceneNodes::enumerateAllChildren(Ogre::SceneNode* sceneNode,
		boost::function<void(Ogre::SceneNode*)> callback) {
	callback(sceneNode);

	Node::ChildNodeIterator iter = sceneNode->getChildIterator();
	while (iter.hasMoreElements()) {
		SceneNode* node = dynamic_cast<SceneNode*>(iter.getNext());
		if (!node)
			continue;

		enumerateAllChildren(node, callback);
	}
}

static void enableSelf(Component* component, bool enable) {
	component->enable.set(enable);
}

void SceneNodes::activeAll(Ogre::SceneNode* parent, bool enable) {
	function<void(Component*)> func = boost::bind(enableSelf, _1, enable);
	apply(parent, func);
}

void SceneNodes::activeAllInHierarchy(Ogre::SceneNode* parent,
		bool enable) {
	function<void(Component*)> func = boost::bind(enableSelf, _1, enable);
	applyAll(parent, func);
}

Ogre::Any SceneNodes::getDeviceResource(Ogre::MovableObject* movableObject) {
	return movableObject->getUserObjectBindings().getUserAny(
			"zzogre/device/resource");
}

}

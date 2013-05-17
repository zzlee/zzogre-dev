/*
 * ComponentManager.cpp
 *
 *  Created on: 2013/1/19
 *      Author: SUCHEN
 */

#include "ComponentManager.h"

#include <OgreAny.h>
#include <OgreUserObjectBindings.h>
#include <OgreSceneNode.h>
using namespace Ogre;

#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/unordered_map.hpp>
#include <boost/format.hpp>
using namespace boost;

#include <string>
using namespace std;

#include "Logger.h"

namespace zzogre {

ComponentManager::ComponentManager() {
}

ComponentManager::~ComponentManager() {
	for (unordered_set<ComponentPtr>::const_iterator i = mComponents.begin();
			i != mComponents.end(); ++i) {
		const ComponentPtr& component = *i;
		component->enable.set(false);
	}
}

static unordered_map<string, ComponentCreator> _ComponentTypes;

bool ComponentManager::registerComponentType(const std::string& type,
		ComponentCreator creator) {
	if (_ComponentTypes.find(type) != _ComponentTypes.end())
		return false;

	LOGI(format("[%s] registered.") % type);
	_ComponentTypes[type] = creator;

	return true;
}

Component* ComponentManager::createNew(const std::string& type) {
	unordered_map<string, ComponentCreator>::iterator i = _ComponentTypes.find(
			type);
	if (i == _ComponentTypes.end())
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
				"not such component type:" + type, __PRETTY_FUNCTION__);

	return (*i).second();
}

} /* namespace zzogre */

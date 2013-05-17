/*
 * BehaviorsPlugin.cpp
 *
 *  Created on: 2013/4/2
 *      Author: SUCHEN
 */

#include "BehaviorsPlugin.h"

namespace zzogre {

BehaviorsPlugin::BehaviorsPlugin(const Ogre::String& name) : mName(name) {
}

BehaviorsPlugin::~BehaviorsPlugin() {
}

const Ogre::String& BehaviorsPlugin::getName() const {
	return mName;
}

void BehaviorsPlugin::install() {
}

void BehaviorsPlugin::shutdown() {
}

void BehaviorsPlugin::uninstall() {
}

} /* namespace zzogre */

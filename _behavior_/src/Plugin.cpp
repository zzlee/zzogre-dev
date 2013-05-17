/*
 * Main.cpp
 *
 *  Created on: 2013/3/29
 *      Author: SUCHEN
 */

#include <zzogre/ZzOGRE.h>
#include <zzogre/BehaviorsPlugin.h>
using namespace zzogre;

static BehaviorsPlugin plugin(STRINGIZE(BEHAVIOR_NAME));

extern "C" void dllStartPlugin() {
	_Root->installPlugin(&plugin);
}

extern "C" void dllStopPlugin() {
	_Root->uninstallPlugin(&plugin);
}

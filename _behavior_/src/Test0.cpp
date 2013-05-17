/*
 * Test0.cpp
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

#include "Test0.h"

using namespace std;
using namespace Ogre;

#include <zzogre/ZzOGRE.h>
#include <zzogre/FrameEventManager.h>
#include <zzogre/Logger.h>
using namespace zzogre;

ZZOGRE_COMPONENT_REGISTER(Test0);

Test0::Test0() {
	LOGI(__PRETTY_FUNCTION__);

	enableFrameEvent(FET_Started);
	enableInputEvent(_Window, true, true);
}

Test0::~Test0() {
	LOGI(__PRETTY_FUNCTION__);
}

void Test0::onEnable() {
	cout << __PRETTY_FUNCTION__ << endl;
}

void Test0::onDisable() {
	cout << __PRETTY_FUNCTION__ << endl;
}

void Test0::onKeyPressed(const OIS::KeyEvent &arg) {
	sendMessage("play", arg.key, arg.text);
}

void Test0::onMessage(const std::string& msg,
		const zzogre::MessageArguments& args) {
	cout << "onMessage:" << msg << endl;

	if (msg == "play") {
		cout << args.size() << endl;
		cout << any_cast<OIS::KeyCode>(args[0]) << ','
				<< any_cast<unsigned int>(args[1]) << endl;
	}
}

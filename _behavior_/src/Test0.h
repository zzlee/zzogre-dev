/*
 * Test0.h
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

#ifndef TEST0_H_
#define TEST0_H_

#include <string>

#include <zzogre/Behavior.h>

class Test0: public zzogre::Behavior {
	ZZOGRE_COMPONENT_TYPE(Test0);

protected:
	explicit Test0();

public:
	virtual ~Test0();

protected:
	virtual void onEnable();
	virtual void onDisable();

	virtual void onKeyPressed(const OIS::KeyEvent &arg);
	virtual void onMessage(const std::string& msg,
			const zzogre::MessageArguments& args);
};

#endif /* TEST0_H_ */

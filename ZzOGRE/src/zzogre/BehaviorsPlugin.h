/*
 * BehaviorsPlugin.h
 *
 *  Created on: 2013/4/2
 *      Author: SUCHEN
 */

#ifndef BEHAVIORSPLUGIN_H_
#define BEHAVIORSPLUGIN_H_

#include <OgreString.h>
#include <OgrePlugin.h>

#include <boost/function.hpp>

#include "ComponentManager.h"

namespace zzogre {

class BehaviorsPlugin : public Ogre::Plugin {
public:
	BehaviorsPlugin(const Ogre::String& name);
	virtual ~BehaviorsPlugin();

    const Ogre::String& getName() const;
    void install();
    void initialise();
    void shutdown();
    void uninstall();

protected:
    Ogre::String mName;
};

} /* namespace zzogre */
#endif /* BEHAVIORSPLUGIN_H_ */

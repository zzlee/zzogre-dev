/*
 * RakNetManager.h
 *
 *  Created on: 2013/4/27
 *      Author: SUCHEN
 */

#ifndef RAKNETMANAGER_H_
#define RAKNETMANAGER_H_

#include <zzogre/Behavior.h>
#include <zzogre/ActiveProperty.h>

namespace zzogre {

class RakNetManager: public Behavior {
	ZZOGRE_COMPONENT_TYPE(RakNetManager);

public:
	bool server;
	unsigned short maxConnections;
	unsigned short port;
	std::string host;
	std::string offlinePingResponse;
	float updateRate;

	virtual ~RakNetManager();

	RakNet::RakPeerInterface* getPeer() const {
		return mPeer;
	}

protected:
	RakNet::RakPeerInterface* mPeer;
	float mProcessDuration;
	float mTimeToProcessNetwork;

	explicit RakNetManager();

	virtual void onLoad(XmlNode* node);
	virtual void onSave(XmlNode* node);

	virtual void onEnable();
	virtual void onDisable();
	virtual void onFrameStarted();
};
ZZLAB_TYPEDEF_SHARED_PTR(RakNetManager);

} /* namespace zzogre */
#endif /* RAKNETMANAGER_H_ */

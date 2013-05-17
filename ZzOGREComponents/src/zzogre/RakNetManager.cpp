/*
 * RakNetManager.cpp
 *
 *  Created on: 2013/4/27
 *      Author: SUCHEN
 */

#include "RakNetManager.h"

#include <algorithm>
using namespace std;

#include <boost/format.hpp>
using namespace boost;

using namespace Ogre;

#include <rapidxml/rapidxml.hpp>
using namespace rapidxml;

#include "zzogre/ZzOGRE.h"
#include "zzogre/SceneNodes.h"
#include "zzogre/Logger.h"
#include "zzogre/Behavior.h"
#include "zzogre/FrameEventManager.h"

#include <RakNet/RakPeerInterface.h>
#include <RakNet/MessageIdentifiers.h>
using namespace RakNet;

namespace zzogre {

ZZOGRE_COMPONENT_REGISTER(RakNetManager);

RakNetManager::RakNetManager() :
		server(true), maxConnections(8), port(8550), host("127.0.0.1"), updateRate(
				15.0f), mPeer(NULL), mProcessDuration(1 / 15.0f), mTimeToProcessNetwork(
				0) {
	enableFrameEvent(FET_Started);
}

RakNetManager::~RakNetManager() {
}

void RakNetManager::onLoad(XmlNode* node) {
	node = node->first_node("data");
	if (node) {
		XmlAttribute* attr = node->first_attribute("type");
		if (attr)
			server = (strcmp(attr->value(), "server") == 0);

		attr = node->first_attribute("max-connections");
		if (attr)
			maxConnections = StringConverter::parseReal(attr->value());

		attr = node->first_attribute("port");
		if (attr)
			port = StringConverter::parseInt(attr->value());

		attr = node->first_attribute("host");
		if (attr)
			host = attr->value();

		attr = node->first_attribute("offline-ping-response");
		if (attr)
			offlinePingResponse = attr->value();

		attr = node->first_attribute("update-rate");
		if (attr)
			updateRate = StringConverter::parseReal(attr->value());
	}
}

void RakNetManager::onSave(XmlNode* node) {
	XmlDocument* doc = node->document();

	XmlNode* node0 = doc->allocate_node(node_element, "data");
	node->append_node(node0);

	node = node0;

	XmlAttribute* attr = doc->allocate_attribute("type",
			server ? "server" : "client");
	node->append_attribute(attr);

	attr = doc->allocate_attribute("max-connections",
			doc->allocate_string(
					StringConverter::toString(maxConnections).c_str()));
	node->append_attribute(attr);

	attr = doc->allocate_attribute("port",
			doc->allocate_string(StringConverter::toString(port).c_str()));
	node->append_attribute(attr);

	attr = doc->allocate_attribute("host", host.c_str());
	node->append_attribute(attr);

	attr = doc->allocate_attribute("offline-ping-response",
			offlinePingResponse.c_str());
	node->append_attribute(attr);

	attr = doc->allocate_attribute("update-rate",
			doc->allocate_string(
					StringConverter::toString(updateRate).c_str()));
	node->append_attribute(attr);
}

void RakNetManager::onEnable() {
	mPeer = RakPeerInterface::GetInstance();

	if (server) {
		LOGI(
				format(
						"RakNet startup as server, port=%d, maxConnections=%d, updateRate=%f")
						% port % maxConnections % updateRate);

		SocketDescriptor sd(port, NULL);
		StartupResult ret = mPeer->Startup(maxConnections, &sd, 1);
		if (ret != RakNet::RAKNET_STARTED) {
			OGRE_EXCEPT(Exception::ERR_INVALID_STATE,
					(format("startup error: %d") % ret).str(),
					__PRETTY_FUNCTION__);
		}

		mPeer->SetMaximumIncomingConnections(maxConnections);
		if (!offlinePingResponse.empty()) {
			LOGI(format("Offline Ping Response = %s") % offlinePingResponse);

			mPeer->SetOfflinePingResponse(offlinePingResponse.c_str(),
					min<unsigned int>(offlinePingResponse.length(), 400));
		}
	} else {
		LOGI(
				format(
						"RakNet startup as client, host=%s, port=%d, updateRate=%f")
						% host % port % updateRate);

		SocketDescriptor sd;
		StartupResult ret = mPeer->Startup(1, &sd, 1);
		if (ret != RakNet::RAKNET_STARTED) {
			OGRE_EXCEPT(Exception::ERR_INVALID_STATE,
					(format("startup error: %d") % ret).str(),
					__PRETTY_FUNCTION__);
		}

		ConnectionAttemptResult ret0 = mPeer->Connect(host.c_str(), port, NULL,
				0);
		if (ret0 != RakNet::CONNECTION_ATTEMPT_STARTED) {
			OGRE_EXCEPT(Exception::ERR_INVALID_STATE,
					(format("connect error: %d") % ret0).str(),
					__PRETTY_FUNCTION__);
		}
	}

	mProcessDuration = 1.0f / updateRate;
}

void RakNetManager::onDisable() {
	LOGI("RakNet shutdown");

	mPeer->Shutdown(100);
	RakPeerInterface::DestroyInstance(mPeer);
	mPeer = NULL;
}

void RakNetManager::onFrameStarted() {
	mTimeToProcessNetwork -= _FrameEvent.timeSinceLastFrame;
	if (mTimeToProcessNetwork > 0)
		return;

	for (RakNet::Packet* p = mPeer->Receive(); p;
			mPeer->DeallocatePacket(p), p = mPeer->Receive()) {
		switch (p->data[0]) {
		case ID_UNCONNECTED_PONG: {
			LOGI("Network: ID_UNCONNECTED_PONG");

			function<void(Behavior*)> func = boost::bind(
					&Behavior::onUnconnectedPong, _1, p);
			SceneNodes::applyAll(_SceneManager->getRootSceneNode(), func);
		}
			break;
		case ID_DISCONNECTION_NOTIFICATION: {
			LOGI("Network: ID_DISCONNECTION_NOTIFICATION");

			function<void(Behavior*)> func = boost::bind(
					server ?
							&Behavior::onDisonnected :
							&Behavior::onDisonnectedFromServer, _1, p);
			SceneNodes::applyAll(_SceneManager->getRootSceneNode(), func);
		}
			break;
		case ID_ALREADY_CONNECTED:
			LOGI("Network: ID_ALREADY_CONNECTED");
			break;
		case ID_CONNECTION_ATTEMPT_FAILED: {
			LOGI("Network: ID_CONNECTION_ATTEMPT_FAILED");

			function<void(Behavior*)> func = boost::bind(
					&Behavior::onFailedToConnect, _1, p);
			SceneNodes::applyAll(_SceneManager->getRootSceneNode(), func);
		}
			break;
		case ID_NO_FREE_INCOMING_CONNECTIONS:
			LOGI("Network: ID_NO_FREE_INCOMING_CONNECTIONS");
			break;
		case ID_CONNECTION_REQUEST_ACCEPTED: {
			LOGI("Network: ID_CONNECTION_REQUEST_ACCEPTED");

			function<void(Behavior*)> func = boost::bind(
					&Behavior::onConnectedToServer, _1, p);
			SceneNodes::applyAll(_SceneManager->getRootSceneNode(), func);
		}
			break;
		case ID_NEW_INCOMING_CONNECTION: {
			LOGI("Network: ID_NEW_INCOMING_CONNECTION");

			function<void(Behavior*)> func = boost::bind(&Behavior::onConnected,
					_1, p);
			SceneNodes::applyAll(_SceneManager->getRootSceneNode(), func);
		}
			break;
		case ID_CONNECTION_LOST: {
			LOGI("Network: ID_CONNECTION_LOST");
		}
			break;

		default: {
			function<void(Behavior*)> func = boost::bind(
					&Behavior::onDataPacket, _1, p);
			SceneNodes::applyAll(_SceneManager->getRootSceneNode(), func);
		}
			break;
		}
	}

	mTimeToProcessNetwork += mProcessDuration;
}

} /* namespace zzogre */

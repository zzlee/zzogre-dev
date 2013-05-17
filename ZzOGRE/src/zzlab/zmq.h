/*
 * zmq.h
 *
 *  Created on: 2013/3/29
 *      Author: SUCHEN
 */

#ifndef ZMQ_H_
#define ZMQ_H_

#include "ZzLab.h"

#include <zmq.hpp>

ZZLAB_TYPEDEF_SHARED_PTR1(zmq::context_t, ZmqContext);
ZZLAB_TYPEDEF_SHARED_PTR1(zmq::socket_t, ZmqSocket);

#endif /* ZMQ_H_ */

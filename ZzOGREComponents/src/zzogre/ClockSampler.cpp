/*
 * ClockSampler.cpp
 *
 *  Created on: 2013/5/8
 *      Author: SUCHEN
 */

#include "ClockSampler.h"

#include <zzlab/ZzLab.h>
#include <zzlab/ZzCOM.h>
using namespace zzlab;

namespace zzogre {

ZZOGRE_COMPONENT_REGISTER(ClockSampler);

ClockSampler* _ClockSampler = NULL;

ClockSampler::ClockSampler() : time(0) {
	HRESULT hr = S_OK;

	_ClockSampler = this;
	hr = _Clock->get_Now(&mStartTime), HR(hr);
}

ClockSampler::~ClockSampler() {
	_ClockSampler = NULL;
}

void ClockSampler::onEnable() {
	enableFrameEvent(FET_Started);
}

void ClockSampler::onFrameStarted() {
	HRESULT hr = S_OK;

	LONGLONG now;
	hr = _Clock->get_Now(&now), HR(hr);

	time = (now - mStartTime) / 10000000.0;
}

} /* namespace zzogre */

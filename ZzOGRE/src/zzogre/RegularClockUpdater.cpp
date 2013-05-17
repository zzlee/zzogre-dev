/*
 * RegularClockUpdater.cpp
 *
 *  Created on: 2013/4/10
 *      Author: SUCHEN
 */

#include "RegularClockUpdater.h"

#include "ZzOGRE.h"

using namespace zzlab;

#include <boost/bind.hpp>
using namespace boost;

namespace zzogre {

RegularClockUpdater::RegularClockUpdater(LONG numerator, LONG denominator) : mUpdateId(0) {
	HRESULT hr = S_OK;

	IClockPtr _clock;
	hr = _ZzCOM->CreateRegularClock(numerator, denominator, (IClock **) &_clock), HR(hr);
	_Clock = _clock;

	hr = _clock->QueryInterface(IID_IRegularClock, (void**) &mRegularClock), HR(hr);

	mUpdateId = _FrameEventManager.addHandler(
				bind(&RegularClockUpdater::update, this), FET_Started);
}

RegularClockUpdater::~RegularClockUpdater() {
	_FrameEventManager.removeHandler(mUpdateId, FET_Started);
}

void RegularClockUpdater::update() {
	HRESULT hr = S_OK;

	hr = mRegularClock->Tick(), HR(hr);
}

} /* namespace zzogre */

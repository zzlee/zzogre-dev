/*
 * ZzCOM.cpp
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

#include "../ZzCOM.h"

#include <iostream>
using namespace std;

namespace zzlab {

IRootPtr _ZzCOM;
IClockPtr _Clock;

static void init() {
	HRESULT hr = S_OK;

	hr = CoCreateInstance(CLSID_Root, NULL, CLSCTX_INPROC_SERVER, IID_IRoot,
			(void**) &_ZzCOM), HR(hr);
	hr = _ZzCOM->CreateNativeClock((IClock**) &_Clock), HR(hr);

	cout << "ZzCOM initialized" << endl;
}

static void deinit() {
	_Clock.reset();
	_ZzCOM.reset();
}

static RegisterInitializer _(init, deinit);

}


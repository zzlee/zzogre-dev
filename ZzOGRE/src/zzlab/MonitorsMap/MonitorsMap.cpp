/*
 * MonitorsMap.cpp
 *
 *  Created on: 2013/3/29
 *      Author: SUCHEN
 */

#include "../MonitorsMap.h"

#include <d3d9.h>

#include <limits>
using namespace std;

ZZLAB_TYPEDEF_COM_PTR(IDirect3D9);

namespace zzlab {

static void init() {
	_MonitorsMap.reset(new MonitorsMap());
}
static void deinit() {
	_MonitorsMap.reset();
}
static RegisterInitializer _(init, deinit);

MonitorsMapPtr _MonitorsMap;

MonitorsMap::MonitorsMap() {
	cout << "Create monitors map..." << endl;

	IDirect3D9Ptr d3d9(Direct3DCreate9(D3D_SDK_VERSION));
	for (UINT i = 0; i < d3d9->GetAdapterCount(); ++i) {
		HMONITOR monitor = d3d9->GetAdapterMonitor(i);
		MONITORINFO monitorInfo = { sizeof(MONITORINFO) };
		if (!GetMonitorInfo(monitor, &monitorInfo))
			HR(HRESULT_FROM_WIN32(GetLastError()));

		cout << "Adapter " << i << " ==> " << monitorInfo.rcMonitor.left << ','
				<< monitorInfo.rcMonitor.top << ','
				<< monitorInfo.rcMonitor.right << ','
				<< monitorInfo.rcMonitor.bottom << endl;

		mAdapterInfos.push_back((AdapterInfo ) { i, monitorInfo.rcMonitor });
	}
}

MonitorsMap::~MonitorsMap() {
}

UINT MonitorsMap::adapterByRegion(const RECT& rect) {
	for (vector<AdapterInfo>::const_iterator i = mAdapterInfos.begin();
			i != mAdapterInfos.end(); ++i) {
		if (EqualRect(&rect, &(*i).region))
			return (*i).adapter;
	}

	return (numeric_limits<UINT>::max)();
}

const RECT& MonitorsMap::regionByAdapter(UINT adapter) {
	const static RECT empty = { 0, 0, 0, 0 };

	for (vector<AdapterInfo>::const_iterator i = mAdapterInfos.begin();
			i != mAdapterInfos.end(); ++i) {
		if (adapter == (*i).adapter) {
			return (*i).region;
		}
	}

	return empty;
}

void MonitorsMap::getMonitorRegions(std::vector<RECT>& ret) {
	for (vector<AdapterInfo>::const_iterator i = mAdapterInfos.begin();
			i != mAdapterInfos.end(); ++i) {
		ret.push_back((*i).region);
	}
}

}



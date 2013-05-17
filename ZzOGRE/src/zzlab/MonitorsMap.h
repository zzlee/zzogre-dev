/*
 * MonitorsMap.h
 *
 *  Created on: 2013/3/29
 *      Author: SUCHEN
 */

#ifndef MONITORSMAP_H_
#define MONITORSMAP_H_

#include "ZzLab.h"

namespace zzlab {

class MonitorsMap {
public:
	struct AdapterInfo {
		UINT adapter;
		RECT region;
	};

	MonitorsMap();
	~MonitorsMap();

	UINT adapterByRegion(const RECT& rect);
	const RECT& regionByAdapter(UINT adapter);
	void getMonitorRegions(std::vector<RECT>& ret);

	const std::vector<AdapterInfo>& adapterInfos() const {
		return mAdapterInfos;
	}

protected:
	std::vector<AdapterInfo> mAdapterInfos;
};
typedef boost::shared_ptr<MonitorsMap> MonitorsMapPtr;

extern MonitorsMapPtr _MonitorsMap;

}

#endif /* MONITORSMAP_H_ */

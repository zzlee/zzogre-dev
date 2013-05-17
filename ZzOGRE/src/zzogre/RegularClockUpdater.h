/*
 * RegularClockUpdater.h
 *
 *  Created on: 2013/4/10
 *      Author: SUCHEN
 */

#ifndef REGULARCLOCKUPDATER_H_
#define REGULARCLOCKUPDATER_H_

#include "zzlab/ZzCOM.h"

namespace zzogre {

class RegularClockUpdater {
public:
	RegularClockUpdater(LONG numerator, LONG denominator);
	virtual ~RegularClockUpdater();

protected:
	IRegularClockPtr mRegularClock;
	uint32_t mUpdateId;

	void update();
};
ZZLAB_TYPEDEF_SHARED_PTR(RegularClockUpdater);

} /* namespace zzogre */
#endif /* REGULARCLOCKUPDATER_H_ */

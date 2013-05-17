/*
 * ClockSampler.h
 *
 *  Created on: 2013/5/8
 *      Author: SUCHEN
 */

#ifndef CLOCKSAMPLER_H_
#define CLOCKSAMPLER_H_

#include <zzogre/Behavior.h>
#include <zzogre/SceneNodes.h>

namespace zzogre {

class ClockSampler : public Behavior {
	ZZOGRE_COMPONENT_TYPE(ClockSampler);

public:
	ClockSampler();
	virtual ~ClockSampler();

	double time;

protected:
	virtual void onEnable();
	virtual void onFrameStarted();

	LONGLONG mStartTime;
};
extern ClockSampler* _ClockSampler;

} /* namespace zzogre */
#endif /* CLOCKSAMPLER_H_ */

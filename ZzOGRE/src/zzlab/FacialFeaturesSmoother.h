/*
 * FacialFeaturesSmoother.h
 *
 *  Created on: 2013/3/7
 *      Author: SUCHEN
 */

#ifndef FACIALFEATURESSMOOTHER_H_
#define FACIALFEATURESSMOOTHER_H_

#include "ZzLab.h"
#include "FaceSDK.h"
#include <vector>

namespace zzlab {

class FacialFeaturesSmoother {
public:
	size_t SmoothingLength;

	FacialFeaturesSmoother();
	~FacialFeaturesSmoother();

	void clear();
	void smooth(FSDK_Features facialFeatures);

protected:
	typedef std::vector<TPoint> Features;
	typedef boost::shared_ptr<Features> FeaturesPtr;
	std::vector<FeaturesPtr> mFacialFeaturesArray;

	static void smoothFeatures(std::vector<FeaturesPtr>& facialFeaturesArray,
			FSDK_Features facialFeatures);
};
ZZLAB_TYPEDEF_SHARED_PTR(FacialFeaturesSmoother);

} /* namespace zzlab */
#endif /* FACIALFEATURESSMOOTHER_H_ */

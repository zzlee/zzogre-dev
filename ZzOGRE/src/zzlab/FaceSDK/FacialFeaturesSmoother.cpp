/*
 * FacialFeaturesSmoother.cpp
 *
 *  Created on: 2013/3/7
 *      Author: SUCHEN
 */

#include "../FacialFeaturesSmoother.h"

namespace zzlab {

FacialFeaturesSmoother::FacialFeaturesSmoother() {
	SmoothingLength = 10;
}

FacialFeaturesSmoother::~FacialFeaturesSmoother() {
}

void FacialFeaturesSmoother::clear() {
	mFacialFeaturesArray.clear();
}

void FacialFeaturesSmoother::smooth(FSDK_Features facialFeatures) {
	if (mFacialFeaturesArray.size() == SmoothingLength) {
		FeaturesPtr back = mFacialFeaturesArray.front();
		for (size_t i = 0; i < mFacialFeaturesArray.size() - 1; i++)
			mFacialFeaturesArray[i] = mFacialFeaturesArray[i + 1];
		copy(facialFeatures, facialFeatures + FSDK_FACIAL_FEATURE_COUNT,
				back->begin());
		mFacialFeaturesArray.back() = back;

		smoothFeatures(mFacialFeaturesArray, facialFeatures);
	} else {
		FeaturesPtr features(new Features(FSDK_FACIAL_FEATURE_COUNT));
		copy(facialFeatures, facialFeatures + FSDK_FACIAL_FEATURE_COUNT,
				features->begin());
		mFacialFeaturesArray.push_back(features);
	}
}

void FacialFeaturesSmoother::smoothFeatures(
		std::vector<FeaturesPtr>& facialFeaturesArray,
		FSDK_Features facialFeatures) {
	// You may change these coefficients if you need to increase or decrease the smoothing
	float SpatialSmoothingCoeff =
			0.5f
					* sqrt(
							(float) ((facialFeatures[0].x - facialFeatures[1].x)
									* (facialFeatures[0].x - facialFeatures[1].x)
									+ (facialFeatures[0].y - facialFeatures[1].y)
											* (facialFeatures[0].y
													- facialFeatures[1].y)));
	float TemporalSmoothingCoeff = 250.0f;
	TPoint OldCenter;
	TPoint NewCenter;
	OldCenter.x = 0;
	OldCenter.y = 0;
	NewCenter.x = 0;
	NewCenter.y = 0;
	for (int i = 0; i < FSDK_FACIAL_FEATURE_COUNT; i++) {
		OldCenter.x += facialFeatures[i].x;
		OldCenter.y += facialFeatures[i].y;
		float x = 0;
		float y = 0;
		float xSumOfWeights = 0;
		float ySumOfWeights = 0;
		for (size_t j = 0; j < facialFeaturesArray.size(); ++j) {
			Features& features = *(facialFeaturesArray[j]);
			float xWeight = exp(
					-(features[i].x - facialFeatures[i].x)
							* (features[i].x - facialFeatures[i].x)
							/ SpatialSmoothingCoeff
							- (int(j) - facialFeaturesArray.size() + 1)
									* (int(j) - facialFeaturesArray.size() + 1)
									/ TemporalSmoothingCoeff);
			float yWeight = exp(
					-(features[i].y - facialFeatures[i].y)
							* (features[i].y - facialFeatures[i].y)
							/ SpatialSmoothingCoeff
							- (int(j) - facialFeaturesArray.size() + 1)
									* (int(j) - facialFeaturesArray.size() + 1)
									/ TemporalSmoothingCoeff);
			xSumOfWeights += xWeight;
			ySumOfWeights += yWeight;
			x += (xWeight * features[i].x);
			y += (yWeight * features[i].y);
		}
		facialFeatures[i].x = (int) (x / xSumOfWeights);
		facialFeatures[i].y = (int) (y / ySumOfWeights);
		NewCenter.x += facialFeatures[i].x;
		NewCenter.y += facialFeatures[i].y;
	}

	OldCenter.x /= FSDK_FACIAL_FEATURE_COUNT;
	OldCenter.y /= FSDK_FACIAL_FEATURE_COUNT;
	NewCenter.x /= FSDK_FACIAL_FEATURE_COUNT;
	NewCenter.y /= FSDK_FACIAL_FEATURE_COUNT;
	for (int i = 0; i < FSDK_FACIAL_FEATURE_COUNT; i++) {
		facialFeatures[i].x += OldCenter.x - NewCenter.x;
		facialFeatures[i].y += OldCenter.y - NewCenter.y;
	}
}

} /* namespace zzlab */

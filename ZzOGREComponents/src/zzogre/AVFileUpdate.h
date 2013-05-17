/*
 * AVFileUpdate.h
 *
 *  Created on: 2012/11/30
 *      Author: SUCHEN
 */

#ifndef AVFILEUPDATE_H_
#define AVFILEUPDATE_H_

#include <zzlab/ZzCOM.h>
#include <zzogre/Behavior.h>

#include <boost/signals.hpp>

#include <opencv2/opencv.hpp>

namespace zzogre {

class AVFileUpdate: public Behavior {
	ZZOGRE_COMPONENT_TYPE(AVFileUpdate);

public:
	// User set
	std::string name, group;

	// User get
	float fps;
	VARIANT_BOOL hasVideo;
	VARIANT_BOOL hasAudio;
	IMediaPlayerPtr player;
	IFilterGraphPtr graph;
	IMediaSeekingPtr seeking;

	// User events
	boost::signal<void (const Size_t&)> size;
	boost::signal<void (const ImageType_t&)> type;
	boost::signal<void (const cv::Mat&)> output;

public:
	explicit AVFileUpdate();
	virtual ~AVFileUpdate();

protected:
	float mTime;
	float mDuration;
	ILAVMediaPlayerPtr mMediaPlayer;

	int mType;
	Size_t mSize;

	virtual void onEnable();
	virtual void onDisable();
	virtual void onFrameStarted();
};
ZZLAB_TYPEDEF_SHARED_PTR(AVFileUpdate);

} /* namespace zzogre */

#endif /* AVFILEUPDATE_H_ */

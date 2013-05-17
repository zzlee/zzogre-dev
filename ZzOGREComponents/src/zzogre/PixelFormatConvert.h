/*
 * PixelFormatConvert.h
 *
 *  Created on: 2012/11/30
 *      Author: SUCHEN
 */

#ifndef PIXELFORMATCONVERT_H_
#define PIXELFORMATCONVERT_H_

#include <boost/function.hpp>
#include <boost/signals.hpp>

#include <zzlab/ZzCOM.h>
#include <zzogre/Behavior.h>

#include <OgrePixelFormat.h>

#include <opencv2/opencv.hpp>

namespace zzogre {

class PixelFormatConvert: public Behavior {
	ZZOGRE_COMPONENT_TYPE(PixelFormatConvert);

public:
	ActiveProperty<ImageType_t> sourceType;
	ActiveProperty<Ogre::PixelFormat> destFormat;
	ActiveProperty<Size_t> size;
	ActiveProperty<cv::Mat> input;

public:
	explicit PixelFormatConvert();
	virtual ~PixelFormatConvert();

	boost::signal<void(const cv::Mat&)> output;

protected:
	void onEnable();
	void onDisable();

	void resetConnect();
	void allocBuffer();
	void freeBuffer();

	void convert_BGRX_XRGB(const cv::Mat& src);
	void convert_BGR_XRGB(const cv::Mat& src);
	void convert_I420_XRGB(const cv::Mat& src);
	void convert_YV12_XRGB(const cv::Mat& src);
	void convert_YUY2_XRGB(const cv::Mat& src);

	boost::function<void(const cv::Mat&)> mConvert;
	ImageInfo_t mBuffer;
	cv::Mat mOutput;

	void onSourceTypeModified(ImageType_t& a, const ImageType_t& b);
	void onDestFormatModified(Ogre::PixelFormat& a, const Ogre::PixelFormat& b);
	void onSizeModified(Size_t& a, const Size_t& b);
	void onInputModified(cv::Mat& a, const cv::Mat& b);
};
ZZLAB_TYPEDEF_SHARED_PTR(PixelFormatConvert);

} /* namespace zzogre */

#endif /* PIXELFORMATCONVERT_H_ */

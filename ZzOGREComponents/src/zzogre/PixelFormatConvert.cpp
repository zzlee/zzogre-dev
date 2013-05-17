/*
 * PixelFormatConvert.cpp
 *
 *  Created on: 2012/11/30
 *      Author: SUCHEN
 */

#include "PixelFormatConvert.h"

using namespace std;
using namespace zzlab;

#include <boost/bind.hpp>
using namespace boost;

#include <opencv2/opencv.hpp>
using namespace cv;

namespace zzogre {

ZZOGRE_COMPONENT_REGISTER(PixelFormatConvert);

PixelFormatConvert::PixelFormatConvert() :
		sourceType(ImageType_BGR,
				bind(&PixelFormatConvert::onSourceTypeModified, this, _1, _2)), destFormat(
				Ogre::PF_X8R8G8B8,
				bind(&PixelFormatConvert::onDestFormatModified, this, _1, _2)), size(
				(Size_t ) { 0, 0 },
				bind(&PixelFormatConvert::onSizeModified, this, _1, _2)), input(
				bind(&PixelFormatConvert::onInputModified, this, _1, _2)), mBuffer(
				(ImageInfo_t ) { (LONG_PTR) NULL, 0 }) {
}

PixelFormatConvert::~PixelFormatConvert() {
}

void PixelFormatConvert::onEnable() {
	if (!mBuffer.Pointer) {
		allocBuffer();
	}

	resetConnect();
}

void PixelFormatConvert::onDisable() {
	freeBuffer();
}

void PixelFormatConvert::resetConnect() {
	if (destFormat.get() == Ogre::PF_X8R8G8B8) {
		if (sourceType.get() == ImageType_BGRX
				|| sourceType.get() == ImageType_BGRA) {
			mConvert = bind(&PixelFormatConvert::convert_BGRX_XRGB, this, _1);
		} else if (sourceType.get() == ImageType_BGR) {
			mConvert = bind(&PixelFormatConvert::convert_BGR_XRGB, this, _1);
		} else if (sourceType.get() == ImageType_I420) {
			mConvert = bind(&PixelFormatConvert::convert_I420_XRGB, this, _1);
		} else if (sourceType.get() == ImageType_YV12) {
			mConvert = bind(&PixelFormatConvert::convert_YV12_XRGB, this, _1);
		} else if (sourceType.get() == ImageType_YUY2) {
			mConvert = bind(&PixelFormatConvert::convert_YUY2_XRGB, this, _1);
		} else {
			HR(E_INVALIDARG);
		}
	} else {
		HR(E_INVALIDARG);
	}
}

void PixelFormatConvert::allocBuffer() {
//	cout << __PRETTY_FUNCTION__ << endl;

	HRESULT hr = S_OK;

	if (size.get().Width <= 0 || size.get().Height <= 0)
		return;

	if (destFormat.get() == Ogre::PF_X8R8G8B8) {
		hr = _ZzCOM->CreateImage_8u_C4(size.get(), &mBuffer), HR(hr);
		mOutput = Mat4b(size.get().Height, size.get().Width, (Vec4b*)mBuffer.Pointer, mBuffer.Step);
	}
}

void PixelFormatConvert::freeBuffer() {
//	cout << __PRETTY_FUNCTION__ << endl;

	if (mBuffer.Pointer) {
		_ZzCOM->FreeImage(mBuffer);
		mBuffer.Pointer = (LONG_PTR) NULL;
	}
}

void PixelFormatConvert::convert_BGRX_XRGB(const cv::Mat& src) {
	HRESULT hr = S_OK;

	hr = _ZzCOM->Copy_8u_C4R((ImageInfo_t ) { (LONG_PTR) src.data, src.step },
			mBuffer, size.get()), HR(hr);
	output(mOutput);
}

void PixelFormatConvert::convert_BGR_XRGB(const cv::Mat& src) {
	HRESULT hr = S_OK;

	hr = _ZzCOM->Copy_8u_C3AC4R(
			(ImageInfo_t ) { (LONG_PTR) src.data, src.step }, mBuffer,
			size.get()), HR(hr);
	output(mOutput);
}

void PixelFormatConvert::convert_I420_XRGB(const cv::Mat& src) {
	HRESULT hr = S_OK;

	ImageInfo_t srcY = { (LONG_PTR) src.data, src.step };
	ImageInfo_t srcU = { srcY.Pointer + srcY.Step * size.get().Height, srcY.Step
			/ 2 };
	ImageInfo_t srcV = { srcU.Pointer + srcU.Step * size.get().Height / 2,
			srcU.Step };
	hr = _ZzCOM->YCbCr420ToBGR_8u_P3C4R(srcY, srcU, srcV, mBuffer, size.get(),
			255), HR(hr);
	output(mOutput);
}

void PixelFormatConvert::convert_YV12_XRGB(const cv::Mat& src) {
	HRESULT hr = S_OK;

	ImageInfo_t srcY = { (LONG_PTR) src.data, src.step };
	ImageInfo_t srcV = { srcY.Pointer + srcY.Step * size.get().Height, srcY.Step
			/ 2 };
	ImageInfo_t srcU = { srcV.Pointer + srcV.Step * size.get().Height / 2,
			srcV.Step };
	hr = _ZzCOM->YCbCr420ToBGR_8u_P3C4R(srcY, srcU, srcV, mBuffer, size.get(),
			255), HR(hr);
	output(mOutput);
}

void PixelFormatConvert::convert_YUY2_XRGB(const cv::Mat& src) {
	HRESULT hr = S_OK;

	hr = _ZzCOM->YCbCr422ToBGR_8u_C2C4R((ImageInfo_t ) { (LONG_PTR) src.data,
					src.step }, mBuffer, size.get(), 255), HR(hr);
	output(mOutput);
}

void PixelFormatConvert::onSourceTypeModified(ImageType_t& a,
		const ImageType_t& b) {
	if (a == b)
		return;

	a = b;

	if (enable.get()) {
		resetConnect();
	}
}

void PixelFormatConvert::onDestFormatModified(Ogre::PixelFormat& a,
		const Ogre::PixelFormat& b) {
//	cout << __PRETTY_FUNCTION__ << endl;

	if (a == b)
		return;

	a = b;

	if (enable.get()) {
		resetConnect();
	}
}

void PixelFormatConvert::onSizeModified(Size_t& a, const Size_t& b) {
//	cout << __PRETTY_FUNCTION__ << endl;

	if (b.Width <= 0 || b.Height <= 0)
		HR(E_INVALIDARG);

	if (a.Width == b.Width && a.Height == b.Height)
		return;

	a = b;

	if (enable.get()) {
		freeBuffer();
		allocBuffer();
	}
}

void PixelFormatConvert::onInputModified(cv::Mat& a, const cv::Mat& b) {
//	cout << __PRETTY_FUNCTION__ << endl;

	mConvert(b);

	a = b;
}

} /* namespace zzogre */

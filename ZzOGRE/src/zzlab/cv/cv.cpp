/*
 * cv.cpp
 *
 *  Created on: 2013/3/29
 *      Author: SUCHEN
 */

#include "../cv.h"

using namespace cv;

namespace zzlab {

int toCvMatType(ImageType_t type, Size_t* size) {
	switch (type) {
	case ImageType_Gray:
		return CV_8UC1;
		break;

	case ImageType_BGR:
	case ImageType_RGB:
		return CV_8UC3;

	case ImageType_BGRA:
	case ImageType_BGRX:
	case ImageType_RGBA:
	case ImageType_RGBX:
		return CV_8UC4;

	case ImageType_U16:
		return CV_16UC1;
		break;

	case ImageType_YUY2:
		if (size)
			size->Width *= 2;
		return CV_8UC2;
		break;

	case ImageType_YV12:
	case ImageType_I420:
		if (size)
			size->Height = size->Height * 3 / 2;
		return CV_8UC1;
		break;

	default:
		return CV_8UC1;
	}
}

}

/*
 * cv.h
 *
 *  Created on: 2013/3/29
 *      Author: SUCHEN
 */

#ifndef CV_H_
#define CV_H_

#include "ZzLab.h"
#include "ZzCOM.h"

#include <opencv2/opencv.hpp>

namespace zzlab {

extern int toCvMatType(ImageType_t type, Size_t* size = NULL);

}


#endif /* CV_H_ */

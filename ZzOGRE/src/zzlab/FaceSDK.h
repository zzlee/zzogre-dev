/*
 * FaceSDK.h
 *
 *  Created on: 2013/3/29
 *      Author: SUCHEN
 */

#ifndef FACESDK_H_
#define FACESDK_H_

#include "ZzLab.h"
#include <LuxandFaceSDK.h>
#include "FacialFeaturesSmoother.h"

#ifndef FS
#define FS(e) zzlab::FS_(e, __FILE__, __LINE__)
#endif

namespace zzlab {

extern void FS_(int err, const char* file, int line);

}

#endif /* FACESDK_H_ */

/*
 * ZzCOM.h
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

#ifndef ZZCOM_H_
#define ZZCOM_H_

#include "ZzLab.h"
#include "ZzCOM_i.h"

ZZLAB_TYPEDEF_COM_PTR(IRoot);
ZZLAB_TYPEDEF_COM_PTR(IEB3FileLoader);
ZZLAB_TYPEDEF_COM_PTR(ISharedMemory);
ZZLAB_TYPEDEF_COM_PTR(ISharedVideo);
ZZLAB_TYPEDEF_COM_PTR(IEnumVideoCaptureSources);
ZZLAB_TYPEDEF_COM_PTR(IDshowVideoCaptureSource);
ZZLAB_TYPEDEF_COM_PTR(ILAVMediaPlayer);
ZZLAB_TYPEDEF_COM_PTR(IMediaPlayer);
ZZLAB_TYPEDEF_COM_PTR(IClock);
ZZLAB_TYPEDEF_COM_PTR(IStaticClock);
ZZLAB_TYPEDEF_COM_PTR(IRegularClock);
ZZLAB_TYPEDEF_COM_PTR(IDshowMediaPlayer);

namespace zzlab {

extern IRootPtr _ZzCOM;
extern IClockPtr _Clock;

}

#endif /* ZZCOM_H_ */

/*
 * al.h
 *
 *  Created on: 2013/3/29
 *      Author: SUCHEN
 */

#ifndef AL_H_
#define AL_H_

#include "ZzLab.h"
#include <AL/al.h>
#include <AL/alc.h>

#ifndef AL
#define AL(e) zzlab::AL_(e, __FILE__, __LINE__)
#endif

#ifndef AL0
#define AL0 AL(alGetError())
#endif

namespace zzlab {

extern void AL_(ALenum err, const char* file, int line);

}

#endif /* AL_H_ */

/*
 * PRNG.h
 *
 *  Created on: 2013/5/8
 *      Author: SUCHEN
 */

#ifndef PRNG_H_
#define PRNG_H_

#include <zzlab/ZzLab.h>
#include <emmintrin.h>

namespace zzlab {

class PRNG {
public:
	PRNG();
	~PRNG();

	void srand(unsigned int seed);
	unsigned int rand();

protected:
	__m128i mCurSeed;
};
ZZLAB_TYPEDEF_SHARED_PTR(PRNG);

} /* namespace zzogre */
#endif /* PRNG_H_ */

/*
 * PRNG.cpp
 *
 *  Created on: 2013/5/8
 *      Author: SUCHEN
 */

#include "PRNG.h"

namespace zzlab {

PRNG::PRNG() {
}

PRNG::~PRNG() {
}

void PRNG::srand(unsigned int seed) {
	mCurSeed = _mm_set_epi32( seed, seed+1, seed, seed+1 );
}

unsigned int PRNG::rand() {
	static const unsigned int mult[4] = { 214013, 17405, 214013, 69069 };
	static const unsigned int gadd[4] = { 2531011, 10395331, 13737667, 1 };
	static const unsigned int mask[4] = { 0xFFFFFFFF, 0, 0xFFFFFFFF, 0 };

	__m128i adder = _mm_load_si128( (__m128i*) gadd);
	__m128i multiplier = _mm_load_si128( (__m128i*) mult);
	__m128i mod_mask = _mm_load_si128( (__m128i*) mask);
	__m128i cur_seed_split = _mm_shuffle_epi32( mCurSeed, _MM_SHUFFLE( 2, 3, 0, 1 ) );
	mCurSeed = _mm_mul_epu32( mCurSeed, multiplier );
	multiplier = _mm_shuffle_epi32( multiplier, _MM_SHUFFLE( 2, 3, 0, 1 ) );
	cur_seed_split = _mm_mul_epu32( cur_seed_split, multiplier );
	mCurSeed = _mm_and_si128( mCurSeed, mod_mask);
	cur_seed_split = _mm_and_si128( cur_seed_split, mod_mask );
	cur_seed_split = _mm_shuffle_epi32( cur_seed_split, _MM_SHUFFLE( 2, 3, 0, 1 ) );
	mCurSeed = _mm_or_si128( mCurSeed, cur_seed_split );
	mCurSeed = _mm_add_epi32( mCurSeed, adder);

	unsigned int result;
	_mm_storeu_si128( (__m128i*) &result, mCurSeed);

	return result;
}


} /* namespace zzogre */

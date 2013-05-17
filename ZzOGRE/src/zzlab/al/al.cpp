/*
 * al.cpp
 *
 *  Created on: 2013/3/29
 *      Author: SUCHEN
 */

#include "../al.h"

#include <stdexcept>
using namespace std;

namespace zzlab {

void AL_(ALenum err, const char* file, int line) {
	if (err == AL_NO_ERROR)
		return;

	stringstream ss;
	ss << file << '(' << line << "): OpenAL error, err=" << err;
	throw runtime_error(ss.str());
}

}

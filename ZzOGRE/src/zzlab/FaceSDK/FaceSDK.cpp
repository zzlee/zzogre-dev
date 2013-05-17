/*
 * FaceSDK.cpp
 *
 *  Created on: 2013/3/29
 *      Author: SUCHEN
 */

#include "../FaceSDK.h"

#include <stdexcept>
using namespace std;

namespace zzlab {

static void init() {
	int fse = FSDKE_OK;
	string licenseKey =
			"OUfUlimlTlqDwLvAJM+wmSFLmQ1IEPCOpH3Mds9Yy47BxQJRJs6PAzSyqYm6WlRK7m9XE+bx3yDxOcNDbt/1ZL1uv9blwkwqZDtegZJ62R8leYBNNb5ngb9n+M1WIVMBqSfgbx5k5fG8i9qtJlKel8xpitUGBN5NbozQDZWP5Sc=";
	string dataPath = "";

	fse = FSDK_ActivateLibrary(&licenseKey[0]), FS(fse);
	fse = FSDK_Initialize(&dataPath[0]), FS(fse);

	cout << "FaceSDK initialized." << endl;
}
static void deinit() {
	// TODO: finalize crash issue
	//FSDK_Finalize();
}
static RegisterInitializer _(init, deinit);

void FS_(int err, const char* file, int line) {
	if (err == FSDKE_OK)
		return;

	stringstream ss;
	ss << file << '(' << line << "): FaceSDK error, err=" << err;
	throw runtime_error(ss.str());
}

}



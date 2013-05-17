/*
 * Euler.cpp
 *
 *  Created on: 2013/4/15
 *      Author: SUCHEN
 */

#include "Euler.h"

#include <sstream>
#include <vector>
using namespace std;

namespace zzogre {

Euler Euler::ZERO = Euler();

Euler::Euler() :
		mYaw(Ogre::Radian(0.0f)), mPitch(Ogre::Radian(0.0f)), mRoll(
				Ogre::Radian(0.0f)), mChanged(true) {
}

Euler::Euler(const Ogre::Radian& y, const Ogre::Radian& p,
		Ogre::Radian r) :
		mYaw(y), mPitch(p), mRoll(r), mChanged(true) {
}

Euler::Euler(int y, int p, int r) :
		mYaw(Ogre::Degree((Ogre::Real) y)), mPitch(
				Ogre::Degree((Ogre::Real) p)), mRoll(
				Ogre::Degree((Ogre::Real) r)), mChanged(true) {
}

Euler::Euler(Ogre::Real y, Ogre::Real p, Ogre::Real r) :
		mYaw(Ogre::Radian(y)), mPitch(Ogre::Radian(p)), mRoll(Ogre::Radian(r)), mChanged(
				true) {
}

Euler::Euler(const Ogre::Vector3& axvec) :
		mYaw(Ogre::Radian(axvec.y)), mPitch(Ogre::Radian(axvec.x)), mRoll(
				Ogre::Radian(axvec.z)), mChanged(true) {
}

Euler::Euler(const Ogre::Quaternion& quaternion) {
	fromQuaternion(quaternion);
}

void Euler::fromQuaternion(const Ogre::Quaternion& quaternion) {
	mYaw = Ogre::Math::ATan2(
			2 * quaternion.y * quaternion.w - 2 * quaternion.x * quaternion.z,
			1 - 2 * Ogre::Math::Pow(quaternion.y, 2)
					- 2 * Ogre::Math::Pow(quaternion.z, 2));
	mRoll = Ogre::Math::ASin(
			2 * quaternion.x * quaternion.y + 2 * quaternion.z * quaternion.w);
	mPitch = Ogre::Math::ATan2(
			2 * quaternion.x * quaternion.w - 2 * quaternion.y * quaternion.z,
			1 - 2 * Ogre::Math::Pow(quaternion.x, 2)
					- 2 * Ogre::Math::Pow(quaternion.z, 2));

	if (quaternion.x * quaternion.y + quaternion.z * quaternion.w == 0.5) {
		mPitch = 2.0f * Ogre::Math::ATan2(quaternion.x, quaternion.w);
		mYaw = 0.0f;
	} else if (quaternion.x * quaternion.y + quaternion.z * quaternion.w
			== -0.5) {
		mPitch = -2.0f * Ogre::Math::ATan2(quaternion.x, quaternion.w);
		mYaw = 0.0f;
	}

	mCachedQuaternion = quaternion;
	mChanged = false;
}

void Euler::normalise(bool normYaw, bool normPitch,
		bool normRoll) {
	if (normYaw) {
		Ogre::Real yaw = mYaw.valueRadians();
		if (yaw < -Ogre::Math::PI) {
			yaw = fmod(yaw, Ogre::Math::PI * 2.0f);
			if (yaw < -Ogre::Math::PI) {
				yaw += Ogre::Math::PI * 2.0f;
			}
			mYaw = yaw;
			mChanged = true;
		} else if (yaw > Ogre::Math::PI) {
			yaw = fmod(yaw, Ogre::Math::PI * 2.0f);
			if (yaw > Ogre::Math::PI) {
				yaw -= Ogre::Math::PI * 2.0f;
			}
			mYaw = yaw;
			mChanged = true;
		}
	}
	if (normPitch) {
		Ogre::Real pitch = mPitch.valueRadians();
		if (pitch < -Ogre::Math::PI) {
			pitch = fmod(pitch, Ogre::Math::PI * 2.0f);
			if (pitch < -Ogre::Math::PI) {
				pitch += Ogre::Math::PI * 2.0f;
			}
			mPitch = pitch;
			mChanged = true;
		} else if (pitch > Ogre::Math::PI) {
			pitch = fmod(pitch, Ogre::Math::PI * 2.0f);
			if (pitch > Ogre::Math::PI) {
				pitch -= Ogre::Math::PI * 2.0f;
			}
			mPitch = pitch;
			mChanged = true;
		}
	}
	if (normRoll) {
		Ogre::Real roll = mRoll.valueRadians();
		if (roll < -Ogre::Math::PI) {
			roll = fmod(roll, Ogre::Math::PI * 2.0f);
			if (roll < -Ogre::Math::PI) {
				roll += Ogre::Math::PI * 2.0f;
			}
			mRoll = roll;
			mChanged = true;
		} else if (roll > Ogre::Math::PI) {
			roll = fmod(roll, Ogre::Math::PI * 2.0f);
			if (roll > Ogre::Math::PI) {
				roll -= Ogre::Math::PI * 2.0f;
			}
			mRoll = roll;
			mChanged = true;
		}
	}
}

} /* namespace zzogre */


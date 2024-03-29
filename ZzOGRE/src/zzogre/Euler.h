/*
 * Euler.h
 *
 *  Created on: 2013/1/17
 *      Author: SUCHEN
 */

#ifndef EULER_H_
#define EULER_H_

#include <OgreMath.h>
#include <OgreQuaternion.h>
#include <OgreVector3.h>

namespace zzogre {

/**
 @class Euler
 @brief Class for %Euler rotations

 <table><tr><td>Yaw is a rotation around the Y axis.</td><td>Pitch is a rotation around the X axis.</td><td>Roll is a rotation around the Z axis.</td></tr>
 <tr><td><img src="http://www.ogre3d.org/tikiwiki/tiki-download_file.php?fileId=2112" /></td><td><img src="http://www.ogre3d.org/tikiwiki/tiki-download_file.php?fileId=2113" /></td><td><img src="http://www.ogre3d.org/tikiwiki/tiki-download_file.php?fileId=2114" /></td></tr></table>
 */
class Euler {
public:
	static Euler ZERO;

public:
	/// Default constructor.
	Euler();

	/**
	 @brief Constructor which takes yaw, pitch and roll values.
	 @param y Starting value for yaw
	 @param p Starting value for pitch
	 @param r Starting value for roll
	 */
	Euler(const Ogre::Radian& y, const Ogre::Radian& p = Ogre::Radian(0.0f),
			Ogre::Radian r = Ogre::Radian(0.0f));

	/**
	 @brief Constructor which takes yaw, pitch and roll values as ints (degrees).
	 @param y Starting value for yaw [degree]
	 @param p Starting value for pitch [degree]
	 @param r Starting value for roll [degree]
	 */
	Euler(int y, int p = 0, int r = 0);

	/**
	 @brief Constructor which takes yaw, pitch and roll values as reals (radians).
	 @param y Starting value for yaw [radian]
	 @param p Starting value for pitch [radian]
	 @param r Starting value for roll [radian]
	 */
	Euler(Ogre::Real y, Ogre::Real p = 0.0f, Ogre::Real r = 0.0f);

	/**
	 @brief Default constructor with presets.
	 @param axvec Starting values as a combined vector
	 */
	Euler(const Ogre::Vector3& axvec);

	/**
	 @brief Default constructor with presets.
	 @param quaternion Calculate starting values from this quaternion
	 */
	Euler(const Ogre::Quaternion& quaternion);

	/// Get the Yaw angle.
	const Ogre::Radian& getYaw() const {
		return mYaw;
	}

	/// Get the Pitch angle.
	const Ogre::Radian& getPitch() const {
		return mPitch;
	}

	/// Get the Roll angle.
	const Ogre::Radian& getRoll() const {
		return mRoll;
	}

	/**
	 @brief Set the yaw.
	 @param y New value for yaw
	 */
	Euler &setYaw(const Ogre::Radian& y) {
		mYaw = y;
		mChanged = true;
		return *this;
	}

	/**
	 @brief Set the pitch.
	 @param p New value for pitch
	 */
	Euler &setPitch(const Ogre::Radian& p) {
		mPitch = p;
		mChanged = true;
		return *this;
	}

	/**
	 @brief Set the roll.
	 @param r New value for roll
	 */
	Euler &setRoll(const Ogre::Radian& r) {
		mRoll = r;
		mChanged = true;
		return *this;
	}

	/**
	 @brief Set all rotations at once.
	 @param y New value for yaw
	 @param p New value for pitch
	 @param r New value for roll
	 */
	Euler &setRotation(const Ogre::Radian& y, const Ogre::Radian& p,
			const Ogre::Radian& r) {
		mYaw = y;
		mPitch = p;
		mRoll = r;
		mChanged = true;
		return *this;
	}

	/**
	 @brief Apply a relative yaw.
	 @param y Angle to add on current yaw
	 */
	Euler &yaw(const Ogre::Radian& y) {
		mYaw += y;
		mChanged = true;
		return *this;
	}

	/**
	 @brief Apply a relative pitch.
	 @param p Angle to add on current pitch
	 */
	Euler &pitch(const Ogre::Radian& p) {
		mPitch += p;
		mChanged = true;
		return *this;
	}

	/**
	 @brief Apply a relative roll.
	 @param r Angle to add on current roll
	 */
	Euler &roll(const Ogre::Radian& r) {
		mRoll += r;
		mChanged = true;
		return *this;
	}

	/**
	 @brief Apply all relative rotations at once.
	 @param y Angle to add on current yaw
	 @param p Angle to add on current pitch
	 @param r Angle to add on current roll
	 */
	Euler &rotate(const Ogre::Radian& y, const Ogre::Radian& p,
			const Ogre::Radian& r) {
		mYaw += y;
		mPitch += p;
		mRoll += r;
		mChanged = true;
		return *this;
	}

	/// Get a vector pointing forwards.
	Ogre::Vector3 getForward() {
		return toQuaternion() * Ogre::Vector3::NEGATIVE_UNIT_Z;
	}

	/// Get a vector pointing to the right.
	Ogre::Vector3 getRight() {
		return toQuaternion() * Ogre::Vector3::UNIT_X;
	}

	/// Get a vector pointing up.
	Ogre::Vector3 getUp() {
		return toQuaternion() * Ogre::Vector3::UNIT_Y;
	}

	/**
	 @brief Calculate the quaternion of the euler object.
	 @details The result is cached, it is only recalculated when the component euler angles are changed.
	 */
	Ogre::Quaternion toQuaternion() {
		if (mChanged) {
			mCachedQuaternion = Ogre::Quaternion(mYaw, Ogre::Vector3::UNIT_Y)
					* Ogre::Quaternion(mPitch, Ogre::Vector3::UNIT_X)
					* Ogre::Quaternion(mRoll, Ogre::Vector3::UNIT_Z);
			mChanged = false;
		}
		return mCachedQuaternion;
	}

	/// Casting operator. This allows any ogre function that wants a Quaternion to accept a Euler instead.
	operator Ogre::Quaternion() {
		return toQuaternion();
	}

	/**
	 @brief Calculate the current eulers of a given quaternion object.
	 @param quaternion Quaternion which is used to calculate current euler angles
	 */
	void fromQuaternion(const Ogre::Quaternion& quaternion);

	/**
	 @brief Set the yaw and pitch to face in the given direction.
	 @details The direction doesn't need to be normalised. Roll is always unaffected.
	 @param setYaw If false, the yaw isn't changed.
	 @param setPitch If false, the pitch isn't changed.
	 */
	inline Euler &setDirection(const Ogre::Vector3 &v, bool setYaw = true,
			bool setPitch = true) {
		Ogre::Vector3 d(v.normalisedCopy());
		if (setPitch)
			mPitch = Ogre::Math::ASin(d.y);
		if (setYaw)
			mYaw = Ogre::Math::ATan2(-d.x, -d.z); //+Ogre::Math::PI/2.0;
		mChanged = setYaw || setPitch;

		return *this;
	}

	/**
	 @brief Normalise the selected rotations to be within the +/-180 degree range.
	 @details The normalise uses a wrap around, so for example a yaw of 360 degrees becomes 0 degrees, and -190 degrees becomes 170.
	 @param normYaw If false, the yaw isn't normalized.
	 @param normPitch If false, the pitch isn't normalized.
	 @param normRoll If false, the roll isn't normalized.
	 */
	void normalise(bool normYaw = true, bool normPitch = true,
			bool normRoll = true);

	/**
	 @brief Return the relative euler angles required to rotate from the current forward direction to the specified dir vector.
	 @details The result euler can then be added to the current euler to immediately face dir.
	 The rotation won't flip upside down then roll instead of a 180 degree yaw.
	 @param setYaw If false, the angle is set to 0. If true, the angle is calculated.
	 @param setPitch If false, the angle is set to 0. If true, the angle is calculated.
	 @param shortest If false, the full value of each angle is used. If true, the angles are normalised and the shortest
	 rotation is found to face the correct direction. For example, when false a yaw of 1000 degrees and a dir of
	 (0,0,-1) will return a -1000 degree yaw. When true, the same yaw and dir would give 80 degrees (1080 degrees faces
	 the same way as (0,0,-1).
	 */
	inline Euler getRotationTo(const Ogre::Vector3 &dir, bool setYaw = true,
			bool setPitch = true, bool shortest = true) {
		Euler t1;
		Euler t2;
		t1.setDirection(dir, setYaw, setPitch);
		t2 = t1 - *this;
		if (shortest && setYaw) {
			t2.normalise();
		}
		return t2;
	}

	/// Clamp the yaw angle to a range of +/-limit.
	inline Euler &limitYaw(const Ogre::Radian &limit) {
		if (mYaw > limit) {
			mYaw = limit;
			mChanged = true;
		} else if (mYaw < -limit) {
			mYaw = -limit;
			mChanged = true;
		}
		return *this;
	}

	/// Clamp the pitch angle to a range of +/-limit.
	inline Euler &limitPitch(const Ogre::Radian &limit) {
		if (mPitch > limit) {
			mPitch = limit;
			mChanged = true;
		} else if (mPitch < -limit) {
			mPitch = -limit;
			mChanged = true;
		}
		return *this;
	}

	/// Clamp the roll angle to a range of +/-limit.
	inline Euler &limitRoll(const Ogre::Radian &limit) {
		if (mRoll > limit) {
			mRoll = limit;
			mChanged = true;
		} else if (mRoll < -limit) {
			mRoll = -limit;
			mChanged = true;
		}
		return *this;
	}

	/// Stream operator, for printing the euler component angles to a stream
	inline friend std::ostream &operator<<(std::ostream &o, const Euler &e) {
		o << "<Y:" << e.mYaw << ", P:" << e.mPitch << ", R:" << e.mRoll << ">";
		return o;
	}

	/// Add two euler objects.
	inline Euler operator+(const Euler &rhs) const {
		return Euler(mYaw + rhs.mYaw, mPitch + rhs.mPitch, mRoll + rhs.mRoll);
	}

	/// Add a vector with radiant euler angles.
	inline Euler operator+(const Ogre::Vector3 &angles) const {
		return Euler(mYaw + Ogre::Radian(angles.y),
				mPitch + Ogre::Radian(angles.x), mRoll + Ogre::Radian(angles.z));
	}

	/**
	 @brief Subtract two euler objects.
	 @details This finds the difference as relative angles.
	 */
	inline Euler operator-(const Euler &rhs) const {
		return Euler(mYaw - rhs.mYaw, mPitch - rhs.mPitch, mRoll - rhs.mRoll);
	}

	/// Subtract a vector with radiant euler angles.
	inline Euler operator-(const Ogre::Vector3 &angles) const {
		return Euler(mYaw - Ogre::Radian(angles.y),
				mPitch - Ogre::Radian(angles.x), mRoll - Ogre::Radian(angles.z));
	}

	/// Interpolate the euler angles by rhs.
	inline Euler operator*(Ogre::Real rhs) const {
		return Euler(mYaw * rhs, mPitch * rhs, mRoll * rhs);
	}

	/// Interpolate the euler angle by lhs.
	inline friend Euler operator*(Ogre::Real lhs, const Euler &rhs) {
		return Euler(lhs * rhs.mYaw, lhs * rhs.mPitch, lhs * rhs.mRoll);
	}

	/**
	 @brief Multiply two eulers.
	 @details This has the same effect as multiplying quaternions.
	 @returns The result is a quaternion.
	 */
	inline Ogre::Quaternion operator*(const Euler &rhs) const {
		Euler e1(*this), e2(rhs);
		return e1.toQuaternion() * e2.toQuaternion();
	}

	/// Apply the euler rotation to the vector rhs.
	inline Ogre::Vector3 operator*(const Ogre::Vector3 &rhs) {
		return toQuaternion() * rhs;
	}

	/// Copy assignment operator (Euler)
	inline Euler& operator=(const Euler& src) {
		setRotation(src.getYaw(), src.getPitch(), src.getRoll());
		return *this;
	}

	/// Copy assignment operator (Quaternion)
	inline Euler& operator=(const Ogre::Quaternion& quaternion) {
		fromQuaternion(quaternion);
		return *this;
	}

	/// Copy assignment operator (Vector3)
	inline Euler& operator=(const Ogre::Vector3& pyr) {
		setRotation(Ogre::Radian(pyr.y), Ogre::Radian(pyr.x),
				Ogre::Radian(pyr.z));
		return *this;
	}

protected:
	Ogre::Radian mYaw;					//!< Rotation around the Y axis.
	Ogre::Radian mPitch;				//!< Rotation around the X axis.
	Ogre::Radian mRoll;					//!< Rotation around the Z axis.
	Ogre::Quaternion mCachedQuaternion;	//!< Cached quaternion equivalent of this euler object.
	bool mChanged;					//!< Is the cached quaternion out of date?
};

} /* namespace zzogre */
#endif /* EULER_H_ */

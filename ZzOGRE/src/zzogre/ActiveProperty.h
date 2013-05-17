/*
 * ActiveProperty.h
 *
 *  Created on: 2013/1/18
 *      Author: SUCHEN
 */

#ifndef ACTIVEPROPERTY_H_
#define ACTIVEPROPERTY_H_

#include <boost/function.hpp>
#include <boost/bind.hpp>

namespace zzogre {

template<class T>
class ActiveProperty {
public:
	typedef T value_t;
	typedef const T const_value_t;

	typedef boost::function<void(T&, const T&)> modify_t;

	explicit ActiveProperty() :
			mValue(T()), mModify(
					boost::bind(&ActiveProperty<T>::modify, this, _1, _2)), mConnected(
					NULL) {
	}

	explicit ActiveProperty(modify_t mod) :
			mValue(T()), mModify(mod), mConnected(NULL) {
	}

	explicit ActiveProperty(const T& v) :
			mValue(v), mModify(
					boost::bind(&ActiveProperty<T>::modify, this, _1, _2)), mConnected(
					NULL) {
	}

	explicit ActiveProperty(const T& v, modify_t mod) :
			mValue(v), mModify(mod), mConnected(NULL) {
	}

	~ActiveProperty() {
	}

	const T& get() const {
		return mValue;
	}

	void set(const T& t) {
		mModify(mValue, t);
	}

	void link(ActiveProperty& connected) {
		unlink();

		mModifyCache = mModify;
		mConnected = &connected;
		mModify = boost::bind(&ActiveProperty<T>::modifyConnected, this, _1,
				_2);
	}

	void unlink() {
		if (!mConnected)
			return;

		mConnected = NULL;
		mModify = mModifyCache;
		mModifyCache = modify_t();
	}

protected:
	T mValue;

	modify_t mModify;
	void modify(T& a, const T& b) {
		a = b;
	}

	modify_t mModifyCache;
	ActiveProperty* mConnected;
	void modifyConnected(T& a, const T& b) {
		mModifyCache(a, b);
		mConnected->set(b);
	}
};

} /* namespace zzogre */
#endif /* ACTIVEPROPERTY_H_ */

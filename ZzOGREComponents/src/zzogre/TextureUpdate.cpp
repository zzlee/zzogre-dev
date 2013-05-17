/*
 * TextureUpdate.cpp
 *
 *  Created on: 2012/11/30
 *      Author: SUCHEN
 */

#include "TextureUpdate.h"
using namespace std;

#include <boost/bind.hpp>
#include <boost/format.hpp>
using namespace boost;

#include <OgreHardwareBuffer.h>
using namespace Ogre;

using namespace cv;

namespace zzogre {

ZZOGRE_COMPONENT_REGISTER(TextureUpdate);

TextureUpdate::TextureUpdate() :
		texture(bind(&TextureUpdate::onTextureModified, this, _1, _2)), roi(
				bind(&TextureUpdate::onROIModified, this, _1, _2)), input(
				bind(&TextureUpdate::onInputModified, this, _1, _2)) {
}

TextureUpdate::~TextureUpdate() {
}

void TextureUpdate::onEnable() {
	mPixelBuffer = texture.get()->getBuffer();
	mPixelBox.format = texture.get()->getFormat();
}

void TextureUpdate::onDisable() {
	mPixelBuffer.setNull();
}

void TextureUpdate::onTextureModified(Ogre::TexturePtr& a,
		const Ogre::TexturePtr& b) {
	if (a == b)
		return;

	if (enable.get()) {
		mPixelBuffer = b->getBuffer();
		mPixelBox.format = b->getFormat();
	}

	a = b;
}

void TextureUpdate::onROIModified(Ogre::Rect& a, const Ogre::Rect& b) {
	mPixelBox.left = b.left;
	mPixelBox.top = b.top;
	mPixelBox.right = b.right;
	mPixelBox.bottom = b.bottom;

	a = b;
}

void TextureUpdate::onInputModified(cv::Mat& a, const cv::Mat& b) {
	mPixelBox.data = b.data;
	mPixelBox.rowPitch = b.step / b.elemSize();
	mPixelBox.slicePitch = mPixelBox.rowPitch * mPixelBox.getHeight();
	mPixelBuffer->blitFromMemory(mPixelBox);

	a = b;
}

} /* namespace zzogre */

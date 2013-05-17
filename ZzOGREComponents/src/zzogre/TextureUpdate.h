/*
 * TextureUpdate.h
 *
 *  Created on: 2012/11/30
 *      Author: SUCHEN
 */

#ifndef TEXTUREUPDATE_H_
#define TEXTUREUPDATE_H_

#include <OgreTexture.h>
#include <OgreHardwarePixelBuffer.h>
#include <OgrePixelFormat.h>

#include <zzogre/Behavior.h>

#include <opencv2/opencv.hpp>

namespace zzogre {

class TextureUpdate: public Behavior {
	ZZOGRE_COMPONENT_TYPE(TextureUpdate);

public:
	ActiveProperty<Ogre::TexturePtr> texture;
	ActiveProperty<Ogre::Rect> roi;
	ActiveProperty<cv::Mat> input;

public:
	explicit TextureUpdate();
	virtual ~TextureUpdate();

protected:
	Ogre::HardwarePixelBufferSharedPtr mPixelBuffer;
	Ogre::PixelBox mPixelBox;

	void onEnable();
	void onDisable();
	void onTextureModified(Ogre::TexturePtr& a, const Ogre::TexturePtr& b);
	void onROIModified(Ogre::Rect& a, const Ogre::Rect& b);
	void onInputModified(cv::Mat& a, const cv::Mat& b);
};
ZZLAB_TYPEDEF_SHARED_PTR(TextureUpdate);

} /* namespace zzogre */

#endif /* TEXTUREUPDATE_H_ */

/*
 * YV12TextureUpdate.h
 *
 *  Created on: 2013/4/29
 *      Author: SUCHEN
 */

#ifndef YV12TEXTUREUPDATE_H_
#define YV12TEXTUREUPDATE_H_

#include <zzlab/ZzCOM.h>
#include <zzogre/ZzOGRE.h>
#include <zzogre/Behavior.h>
#include <zzogre/ActiveProperty.h>

#include <OgreTexture.h>
#include <OgreHardwarePixelBuffer.h>

#include <opencv2/opencv.hpp>

namespace zzogre {

class YV12TextureUpdate : public Behavior {
	ZZOGRE_COMPONENT_TYPE(YV12TextureUpdate);

public:
	// User set
	std::string sourceSceneNodeName;
	Ogre::Rect roi;

public:
	virtual ~YV12TextureUpdate();

protected:
	explicit YV12TextureUpdate();

protected:
	Ogre::HardwarePixelBufferSharedPtr mPixelBuffer[3];
	Ogre::PixelBox mPixelBox[3];

	void onEnable();
	void onDisable();
	void onStart();

	void onLoad(XmlNode* node);
	void onSave(XmlNode* node);

	void onSourceSizeModified(const Size_t& a);
	void onSourceTypeModified(const ImageType_t& a);
	void onSourceOutputModified(const cv::Mat& a);
};
ZZLAB_TYPEDEF_SHARED_PTR(YV12TextureUpdate);

} /* namespace zzogre */
#endif /* YV12TEXTUREUPDATE_H_ */

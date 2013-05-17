/*
 * YV12TextureUpdate.cpp
 *
 *  Created on: 2013/4/29
 *      Author: SUCHEN
 */

#include "YV12TextureUpdate.h"
#include "AVFileUpdate.h"

#include <OgreManualObject.h>
#include <OgreTexture.h>
using namespace Ogre;

#include <zzogre/SceneNodes.h>
#include <zzogre/Logger.h>

#include <boost/bind.hpp>
#include <boost/format.hpp>
using namespace boost;

using namespace rapidxml;
using namespace std;

namespace zzogre {

ZZOGRE_COMPONENT_REGISTER(YV12TextureUpdate);

YV12TextureUpdate::YV12TextureUpdate() :
		roi(0, 0, -1, -1) {
}

YV12TextureUpdate::~YV12TextureUpdate() {
}

void YV12TextureUpdate::onEnable() {
	ManualObject* manualObject = getAttachedObject<ManualObject>();
	RenderWindowResourcesClosure closure(manualObject);

	ManualObject::ManualObjectSection* section = manualObject->getSection(0);
	MaterialPtr material = _MaterialManager->getByName(
			section->getMaterialName());

	int width = roi.right - roi.left;
	int height = roi.bottom - roi.top;

	TexturePtr mainTexY = _TextureManager->createManual(
			(format("%s/Y") % manualObject->getName()).str(),
			section->getMaterialGroup(), Ogre::TEX_TYPE_2D, width, height, 0,
			Ogre::PF_L8, Ogre::TU_DYNAMIC_WRITE_ONLY_DISCARDABLE);
	material->getTechnique(0)->getPass(0)->getTextureUnitState("MainTex/Y")->setTexture(
			mainTexY);
	mPixelBuffer[0] = mainTexY->getBuffer();
	mPixelBox[0].format = mainTexY->getFormat();
	mPixelBox[0].left = 0;
	mPixelBox[0].top = 0;
	mPixelBox[0].right = width;
	mPixelBox[0].bottom = height;

	TexturePtr mainTexU = _TextureManager->createManual(
			(format("%s/U") % manualObject->getName()).str(),
			section->getMaterialGroup(), Ogre::TEX_TYPE_2D, width / 2,
			height / 2, 0, Ogre::PF_L8,
			Ogre::TU_DYNAMIC_WRITE_ONLY_DISCARDABLE);
	material->getTechnique(0)->getPass(0)->getTextureUnitState("MainTex/U")->setTexture(
			mainTexU);
	mPixelBuffer[2] = mainTexU->getBuffer();
	mPixelBox[2].format = mainTexU->getFormat();
	mPixelBox[2].left = 0;
	mPixelBox[2].top = 0;
	mPixelBox[2].right = width / 2;
	mPixelBox[2].bottom = height / 2;

	TexturePtr mainTexV = _TextureManager->createManual(
			(format("%s/V") % manualObject->getName()).str(),
			section->getMaterialGroup(), Ogre::TEX_TYPE_2D, width / 2,
			height / 2, 0, Ogre::PF_L8,
			Ogre::TU_DYNAMIC_WRITE_ONLY_DISCARDABLE);
	material->getTechnique(0)->getPass(0)->getTextureUnitState("MainTex/V")->setTexture(
			mainTexV);
	mPixelBuffer[1] = mainTexV->getBuffer();
	mPixelBox[1].format = mainTexV->getFormat();
	mPixelBox[1].left = 0;
	mPixelBox[1].top = 0;
	mPixelBox[1].right = width / 2;
	mPixelBox[1].bottom = height / 2;

	// clear textures
	cv::Mat1b zero(height, width);
	zero.setTo(0);
	mPixelBox[0].rowPitch = zero.step;
	mPixelBox[0].data = (uint8_t*) zero.data;
	mPixelBox[0].slicePitch = mPixelBox[0].rowPitch * mPixelBox[0].getHeight();
	mPixelBuffer[0]->blitFromMemory(mPixelBox[0]);

	zero.setTo(128);
	mPixelBox[1].rowPitch = mPixelBox[0].rowPitch / 2;
	mPixelBox[1].data = (uint8_t*) zero.data;
	mPixelBox[1].slicePitch = mPixelBox[1].rowPitch * mPixelBox[1].getHeight();
	mPixelBuffer[1]->blitFromMemory(mPixelBox[1]);

	zero.setTo(128);
	mPixelBox[2].rowPitch = mPixelBox[1].rowPitch;
	mPixelBox[2].data = (uint8_t*) zero.data;
	mPixelBox[2].slicePitch = mPixelBox[2].rowPitch * mPixelBox[2].getHeight();
	mPixelBuffer[2]->blitFromMemory(mPixelBox[2]);
}

void YV12TextureUpdate::onDisable() {
	mPixelBuffer[0].setNull();
	mPixelBuffer[1].setNull();
	mPixelBuffer[2].setNull();
}

void YV12TextureUpdate::onStart() {
	LOGI(__PRETTY_FUNCTION__);

	SceneNode* sourceNode = _SceneManager->getSceneNode(sourceSceneNodeName);
	AVFileUpdatePtr avFileUpdate = SceneNodes::getComponent<AVFileUpdate>(
			sourceNode);

	avFileUpdate->size.connect(
			boost::bind(&YV12TextureUpdate::onSourceSizeModified, this, _1));
	avFileUpdate->type.connect(
			boost::bind(&YV12TextureUpdate::onSourceTypeModified, this, _1));
	avFileUpdate->output.connect(
			boost::bind(&YV12TextureUpdate::onSourceOutputModified, this, _1));
}

void YV12TextureUpdate::onLoad(XmlNode* node) {
	node = node->first_node("data");
	if (node) {
		XmlAttribute* attr = node->first_attribute("source-scene-node");
		if (attr)
			sourceSceneNodeName = attr->value();

		attr = node->first_attribute("roi");
		if (attr)
			roi = zzogre::parseRect(attr->value());
	}
}

void YV12TextureUpdate::onSave(XmlNode* node) {
	XmlDocument* doc = node->document();

	XmlNode *node0 = doc->allocate_node(node_element, "data");
	node->append_node(node0);
	node = node0;

	XmlAttribute* attr = doc->allocate_attribute("source-scene-node",
			sourceSceneNodeName.c_str());
	node->append_attribute(attr);

	attr = doc->allocate_attribute("roi",
			doc->allocate_string(zzogre::toString(roi).c_str()));
	node->append_attribute(attr);
}

void YV12TextureUpdate::onSourceSizeModified(const Size_t& a) {
	ZzOgreAssert(
			roi.left >= 0 && roi.right <= a.Width && roi.top >= 0
					&& roi.bottom <= a.Height, "Image out of bound");
}

void YV12TextureUpdate::onSourceTypeModified(const ImageType_t& a) {
	ZzOgreAssert(a == ImageType_YV12, "Image type unsupported");
}

void YV12TextureUpdate::onSourceOutputModified(const cv::Mat& a) {
	mPixelBox[0].rowPitch = a.step;
	mPixelBox[0].data = (uint8_t*) a.data + roi.top * mPixelBox[0].rowPitch
			+ roi.left;
	mPixelBox[0].slicePitch = mPixelBox[0].rowPitch * mPixelBox[0].getHeight();
	mPixelBuffer[0]->blitFromMemory(mPixelBox[0]);

	mPixelBox[1].rowPitch = mPixelBox[0].rowPitch / 2;
	mPixelBox[1].data = ((uint8_t*) a.data + mPixelBox[0].slicePitch)
			+ roi.top * mPixelBox[1].rowPitch + roi.left / 2;
	mPixelBox[1].slicePitch = mPixelBox[1].rowPitch * mPixelBox[1].getHeight();
	mPixelBuffer[1]->blitFromMemory(mPixelBox[1]);

	mPixelBox[2].rowPitch = mPixelBox[1].rowPitch;
	mPixelBox[2].data = ((uint8_t*) a.data + mPixelBox[0].slicePitch
			+ mPixelBox[1].slicePitch) + roi.top * mPixelBox[2].rowPitch
			+ roi.left / 2;
	mPixelBox[2].slicePitch = mPixelBox[2].rowPitch * mPixelBox[2].getHeight();
	mPixelBuffer[2]->blitFromMemory(mPixelBox[2]);
}

} /* namespace zzogre */

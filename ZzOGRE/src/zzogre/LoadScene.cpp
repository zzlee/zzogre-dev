/*
 * LoadScene.cpp
 *
 *  Created on: 2013/4/10
 *      Author: SUCHEN
 */

#include "ZzOGRE.h"

using namespace std;

#include <rapidxml/rapidxml.hpp>
using namespace rapidxml;

#include <boost/format.hpp>
using namespace boost;

#include <OgreSceneManager.h>
#include <OgreViewport.h>
#include <OgreCamera.h>
#include <OgreManualObject.h>
#include <OgreRenderable.h>
using namespace Ogre;

#include "Logger.h"
#include "SceneNodes.h"
#include "Component.h"

namespace zzogre {

static void loadMovableObjectAttributes(XmlNode* node, MovableObject* object);
static void loadRenderableAttributes(XmlNode* node, Renderable* object);
static void load(XmlNode* node, Camera* object);
static void load(XmlNode* node, ManualObject* object);
static void load(XmlNode* node, Entity* object);
static void load(XmlNode* node, SceneNode* sceneNode);

static void loadMovableObjectAttributes(XmlNode* node, MovableObject* object) {
	XmlAttribute* attr = node->first_attribute("visible");
	if (attr)
		object->setVisible(StringConverter::parseBool(attr->value()));

	attr = node->first_attribute("rendering-distance");
	if (attr)
		object->setRenderingDistance(StringConverter::parseReal(attr->value()));

	attr = node->first_attribute("rendering-min-pixel-size");
	if (attr)
		object->setRenderingMinPixelSize(
				StringConverter::parseReal(attr->value()));

	attr = node->first_attribute("render-queue-group");
	if (attr)
		object->setRenderQueueGroup(
				StringConverter::parseUnsignedInt(attr->value()));

	attr = node->first_attribute("query-flags");
	if (attr)
		object->setQueryFlags(zzogre::parseFlags(attr->value()));

	attr = node->first_attribute("visibility-flags");
	if (attr)
		object->setVisibilityFlags(zzogre::parseFlags(attr->value()));

	attr = node->first_attribute("light-mask");
	if (attr)
		object->setLightMask(zzogre::parseFlags(attr->value()));

	attr = node->first_attribute("cast-shadows");
	if (attr)
		object->setCastShadows(StringConverter::parseBool(attr->value()));

	attr = node->first_attribute("zzogre/device/resource");
	if (attr)
		object->getUserObjectBindings().setUserAny("zzogre/device/resource",
				Any(attr->value()));
}

static void loadRenderableAttributes(XmlNode* node, Renderable* object) {
	XmlAttribute* attr = node->first_attribute("use-identity-projection");
	if (attr)
		object->setUseIdentityProjection(
				StringConverter::parseBool(attr->value()));

	attr = node->first_attribute("use-identity-view");
	if (attr)
		object->setUseIdentityView(StringConverter::parseBool(attr->value()));
}

static void load(XmlNode* node, Camera* object) {
	loadMovableObjectAttributes(node, object);
	loadRenderableAttributes(node, object);

	XmlAttribute* attr = node->first_attribute("fov-y");
	if (attr)
		object->setFOVy(StringConverter::parseAngle(attr->value()));

	attr = node->first_attribute("near-clip-distance");
	if (attr)
		object->setNearClipDistance(StringConverter::parseReal(attr->value()));

	attr = node->first_attribute("far-clip-distance");
	if (attr)
		object->setFarClipDistance(StringConverter::parseReal(attr->value()));

	attr = node->first_attribute("aspect-ratio");
	if (attr)
		object->setAspectRatio(StringConverter::parseReal(attr->value()));

	attr = node->first_attribute("auto-aspect-ratio");
	if (attr)
		object->setAutoAspectRatio(StringConverter::parseBool(attr->value()));

	attr = node->first_attribute("frustum-offset");
	if (attr)
		object->setFrustumOffset(StringConverter::parseReal(attr->value()));

	attr = node->first_attribute("focal-length");
	if (attr)
		object->setFocalLength(StringConverter::parseReal(attr->value()));

	attr = node->first_attribute("projection-type");
	if (attr) {
		if (strcmp(attr->value(), "orthographic") == 0)
			object->setProjectionType(PT_ORTHOGRAPHIC);
		else if (strcmp(attr->value(), "perspective") == 0)
			object->setProjectionType(PT_PERSPECTIVE);
		else
		ZzOgreAssert(false, "unknown projection type: " + string(attr->value()));
	}

	attr = node->first_attribute("ortho-window");
	if (attr) {
		Vector2 val = StringConverter::parseVector2(attr->value());
		object->setOrthoWindow(val.x, val.y);
	}

	attr = node->first_attribute("polygon-mode");
	if (attr) {
		if (strcmp(attr->value(), "points") == 0)
			object->setPolygonMode(PM_POINTS);
		else if (strcmp(attr->value(), "wireframe") == 0)
			object->setPolygonMode(PM_WIREFRAME);
		else if (strcmp(attr->value(), "solid") == 0)
			object->setPolygonMode(PM_SOLID);
		else
		ZzOgreAssert(false, string("unknown polygon-mode: ") + attr->value());
	}

	attr = node->first_attribute("render-target-name");
	if (attr) {
		RenderTarget* renderTarget = zzogre::getRenderTarget(attr->value());

		int ZOrder;
		Vector4 dimensions;

		attr = node->first_attribute("z-order");
		if (attr)
			ZOrder = StringConverter::parseInt(attr->value());
		else
			ZOrder = 0;

		attr = node->first_attribute("dimensions");
		if (attr)
			dimensions = StringConverter::parseVector4(attr->value());
		else {
			dimensions.x = dimensions.y = 0.0f;
			dimensions.z = dimensions.w = 1.0f;
		}

		Viewport* viewport = renderTarget->addViewport(object, ZOrder,
				dimensions.x, dimensions.y, dimensions.z, dimensions.w);

		attr = node->first_attribute("background-colour");
		if (attr)
			viewport->setBackgroundColour(
					StringConverter::parseColourValue(attr->value()));

		attr = node->first_attribute("depth-clear");
		if (attr)
			viewport->setDepthClear(StringConverter::parseReal(attr->value()));

		attr = node->first_attribute("clear-every-frame");
		if (attr) {
			bool clearEveryFrame = StringConverter::parseBool(attr->value());

			attr = node->first_attribute("clear-buffers");
			if (attr)
				viewport->setClearEveryFrame(clearEveryFrame,
						zzogre::parseFlags(attr->value()));
			else
				viewport->setClearEveryFrame(clearEveryFrame);
		}

		attr = node->first_attribute("material-scheme");
		if (attr)
			viewport->setMaterialScheme(attr->value());

		attr = node->first_attribute("overlays-enabled");
		if (attr)
			viewport->setOverlaysEnabled(
					StringConverter::parseBool(attr->value()));

		attr = node->first_attribute("skies-enabled");
		if (attr)
			viewport->setSkiesEnabled(
					StringConverter::parseBool(attr->value()));

		attr = node->first_attribute("shadows-enabled");
		if (attr)
			viewport->setShadowsEnabled(
					StringConverter::parseBool(attr->value()));

		attr = node->first_attribute("visibility-mask");
		if (attr)
			viewport->setVisibilityMask(zzogre::parseFlags(attr->value()));

		attr = node->first_attribute("render-queue-invocation-sequence-name");
		if (attr)
			viewport->setRenderQueueInvocationSequenceName(attr->value());
	}
}

static void load(XmlNode* node, ManualObject* object) {
	loadMovableObjectAttributes(node, object);

	XmlAttribute* attr = node->first_attribute("dynamic");
	if (attr)
		object->setDynamic(StringConverter::parseBool(attr->value()));

	for (XmlNode* node0 = node->first_node("section"); node0;
			node0 = node0->next_sibling("section")) {
		XmlAttribute* materialName = node0->first_attribute("material-name");
		if (!materialName)
			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
					"material name for manual object section is missing",
					__FUNCTION__);

		XmlAttribute* materialGroup = node0->first_attribute("material-group");
		if (!materialGroup)
			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
					"material group for manual object section is missing",
					__FUNCTION__);

		XmlAttribute* type = node0->first_attribute("type");
		if (!type)
			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
					"type for manual object section is missing", __FUNCTION__);

		RenderOperation::OperationType opType;
		if (strcmp(type->value(), "point-list") == 0)
			opType = RenderOperation::OT_POINT_LIST;
		else if (strcmp(type->value(), "line-list") == 0)
			opType = RenderOperation::OT_LINE_LIST;
		else if (strcmp(type->value(), "line-strip") == 0)
			opType = RenderOperation::OT_LINE_STRIP;
		else if (strcmp(type->value(), "triangle-list") == 0)
			opType = RenderOperation::OT_TRIANGLE_LIST;
		else if (strcmp(type->value(), "triangle-strip") == 0)
			opType = RenderOperation::OT_TRIANGLE_STRIP;
		else
			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
					"unknown type (" + string(type->value())
							+ ") for manual object section", __FUNCTION__);

		object->begin(materialName->value(), opType, materialGroup->value());
		for (XmlNode* node1 = node0->first_node("vertex-data"); node1; node1 =
				node1->next_sibling("vertex-data")) {
			XmlNode* position = node1->first_node("position");
			if (position)
				object->position(
						StringConverter::parseVector3(position->value()));

			XmlNode* normal = node1->first_node("normal");
			if (normal)
				object->normal(StringConverter::parseVector3(normal->value()));

			XmlNode* tangent = node1->first_node("tangent");
			if (tangent)
				object->tangent(
						StringConverter::parseVector3(tangent->value()));

			XmlNode* colour = node1->first_node("colour");
			if (colour)
				object->colour(
						StringConverter::parseColourValue(colour->value()));

			XmlNode* texcoord = node1->first_node("texture-coord");
			if (texcoord) {
				// Split on space
				Ogre::vector<Ogre::String>::type vec = Ogre::StringUtil::split(
						texcoord->value());

				switch (vec.size()) {
				case 1:
					object->textureCoord(StringConverter::parseReal(vec[0]));
					break;

				case 2:
					object->textureCoord(StringConverter::parseReal(vec[0]),
							StringConverter::parseReal(vec[1]));
					break;

				case 3:
					object->textureCoord(StringConverter::parseReal(vec[0]),
							StringConverter::parseReal(vec[1]),
							StringConverter::parseReal(vec[2]));
					break;

				case 4:
					object->textureCoord(StringConverter::parseReal(vec[0]),
							StringConverter::parseReal(vec[1]),
							StringConverter::parseReal(vec[2]),
							StringConverter::parseReal(vec[3]));
					break;
				}
			}
		}

		XmlNode* indexData = node0->first_node("index-data");
		if (indexData) {
			// Split on space
			Ogre::vector<Ogre::String>::type vec = Ogre::StringUtil::split(
					indexData->value());

			for (Ogre::vector<Ogre::String>::type::const_iterator i =
					vec.begin(); i != vec.end(); ++i) {
				object->index(StringConverter::parseUnsignedInt(*i));
			}
		}

		{
			ManualObject::ManualObjectSection* _section = object->end();
			if (_section)
				loadRenderableAttributes(node0, _section);
		}
	}

	attr = node->first_attribute("keep-declaration-order");
	if (attr)
		object->setKeepDeclarationOrder(
				StringConverter::parseBool(attr->value()));

	attr = node->first_attribute("use-identity-projection");
	if (attr)
		object->setUseIdentityProjection(
				StringConverter::parseBool(attr->value()));

	attr = node->first_attribute("use-identity-view");
	if (attr)
		object->setUseIdentityView(StringConverter::parseBool(attr->value()));

	attr = node->first_attribute("bounding-box");
	if (attr)
		object->setBoundingBox(zzogre::parseAxisAlignedBox(attr->value()));
}

static void load(XmlNode* node, Entity* object) {
	loadMovableObjectAttributes(node, object);

	XmlAttribute* attr = node->first_attribute("material-name");
	if (attr) {
		XmlAttribute* group = node->first_attribute("material-group");
		object->setMaterialName(attr->value(),
				group ? group->value() : ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME);
	}

	attr = node->first_attribute("display-skeleton");
	if (attr)
		object->setDisplaySkeleton(StringConverter::parseBool(attr->value()));

	attr = node->first_attribute("skip-animation-state-update");
	if (attr)
		object->setSkipAnimationStateUpdate(
				StringConverter::parseBool(attr->value()));

	attr = node->first_attribute("always-update-main-skeleton");
	if (attr)
		object->setAlwaysUpdateMainSkeleton(
				StringConverter::parseBool(attr->value()));
}

static void load(XmlNode* node, SceneNode* sceneNode) {
	{
		XmlAttribute* initialPosition = node->first_attribute(
				"initial-position");
		XmlAttribute* initialOrientation = node->first_attribute(
				"initial-orientation");
		XmlAttribute* initialScale = node->first_attribute("initial-scale");

		if (initialPosition || initialOrientation || initialScale) {
			if (initialPosition)
				sceneNode->setPosition(
						StringConverter::parseVector3(
								initialPosition->value()));

			if (initialOrientation) {
				Euler euler = zzogre::parseEuler(initialOrientation->value());
				sceneNode->setOrientation(euler);
			}

			if (initialScale)
				sceneNode->setScale(
						StringConverter::parseVector3(initialScale->value()));

			sceneNode->setInitialState();
		}
	}

	XmlAttribute* attr = node->first_attribute("position");
	if (attr)
		sceneNode->setPosition(StringConverter::parseVector3(attr->value()));

	attr = node->first_attribute("orientation");
	if (attr) {
		Euler euler = zzogre::parseEuler(attr->value());
		sceneNode->setOrientation(euler);
	}

	attr = node->first_attribute("scale");
	if (attr)
		sceneNode->setScale(StringConverter::parseVector3(attr->value()));

	for (XmlNode* node0 = node->first_node("attached-object"); node0; node0 =
			node0->next_sibling("attached-object")) {
		XmlAttribute* name = node0->first_attribute("name");
		if (!name)
			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
					"attached object name is missing", __FUNCTION__);

		XmlAttribute* type = node0->first_attribute("type");
		if (!type)
			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
					"attached object type is missing", __FUNCTION__);

		sceneNode->attachObject(
				sceneNode->getCreator()->getMovableObject(name->value(),
						type->value()));
	}

	for (XmlNode* node0 = node->first_node("scene-node"); node0;
			node0 = node0->next_sibling("scene-node")) {
		XmlAttribute* name = node0->first_attribute("name");
		if (!name)
			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
					"scene node name is missing", __FUNCTION__);

		load(node0, sceneNode->createChildSceneNode(name->value()));
	}

	for (XmlNode* node0 = node->first_node("component"); node0;
			node0 = node0->next_sibling("component")) {
		XmlAttribute* type = node0->first_attribute("type");
		if (!type)
			OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
					"component type is missing", __FUNCTION__);

		ComponentPtr component = SceneNodes::addComponent(sceneNode,
				type->value(), false);
		component->load(node0);

		XmlAttribute* enable = node0->first_attribute("enable");
		if (enable)
			component->enable.set(StringConverter::parseBool(enable->value()));
	}
}

void loadScene(const std::string& name, const std::string& group,
		Ogre::SceneManager*& ret) {
	XmlDocument doc;
	DataStreamPtr stream = _ResourceGroupManager->openResource(name, group);
	string data(stream->size() + 1, '\0');
	stream->read(&data[0], data.size() - 1);

	doc.parse<parse_default>(&data[0]);

	XmlNode* scene = doc.first_node("scene");
	XmlAttribute* attr = scene->first_attribute("zzogre-version");
	if (!attr)
		OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
				"zzogre-version is missing", __FUNCTION__);

	if (strcmp(attr->value(), ZZOGRE_VERSION) != 0)
		OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED,
				"zzogre-version != " + string(ZZOGRE_VERSION), __FUNCTION__);

	XmlAttribute* _name = scene->first_attribute("name");
	if (!_name)
		OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED, "scene name is missing",
				__FUNCTION__);

	XmlAttribute* type = scene->first_attribute("type");
	if (!type)
		OGRE_EXCEPT(Exception::ERR_RT_ASSERTION_FAILED, "scene type is missing",
				__FUNCTION__);

	ret = _Root->createSceneManager(type->value(), _name->value());

	attr = scene->first_attribute("ambient-light");
	if (attr) {
		ColourValue color;
		color.setAsRGBA(StringConverter::parseInt(attr->value()));
		ret->setAmbientLight(color);
	}

	{
		FogMode fogMode;
		attr = scene->first_attribute("fog-mode");
		if (attr) {
			if (strcmp(attr->value(), "none") == 0)
				fogMode = FOG_NONE;
			else if (strcmp(attr->value(), "exp") == 0)
				fogMode = FOG_EXP;
			else if (strcmp(attr->value(), "exp2") == 0)
				fogMode = FOG_EXP2;
			else if (strcmp(attr->value(), "linear") == 0)
				fogMode = FOG_LINEAR;
			else
				fogMode = FOG_NONE;
		} else
			fogMode = FOG_NONE;

		ColourValue color;
		attr = scene->first_attribute("fog-colour");
		if (attr)
			color = StringConverter::parseColourValue(attr->value());
		else
			color = ColourValue::White;

		float fogStart;
		attr = scene->first_attribute("fog-start");
		if (attr)
			fogStart = StringConverter::parseReal(attr->value());
		else
			fogStart = 0;

		float fogEnd;
		attr = scene->first_attribute("fog-end");
		if (attr)
			fogEnd = StringConverter::parseReal(attr->value());
		else
			fogEnd = 1;

		float fogDensity;
		attr = scene->first_attribute("fog-density");
		if (attr)
			fogDensity = StringConverter::parseReal(attr->value());
		else
			fogDensity = 0.001;

		ret->setFog(fogMode, color, fogDensity, fogStart, fogEnd);
	}

	for (XmlNode* node = scene->first_node("movable-object"); node;
			node = node->next_sibling("movable-object")) {

		XmlAttribute* name = node->first_attribute("name");
		ZzOgreAssert(name, "movable object name is missing");

		XmlAttribute* type = node->first_attribute("type");
		ZzOgreAssert(type, "movable object type is missing");

		if (strcmp(type->value(), "Camera") == 0)
			load(node, ret->createCamera(name->value()));
		else if (strcmp(type->value(), "ManualObject") == 0) {
			RenderWindowResourcesClosurePtr closure;

			ManualObject* object;
			XmlAttribute* attr = node->first_attribute(
					"zzogre-device-resource");
			if (attr) {
				closure.reset(new RenderWindowResourcesClosure(attr->value()));

				object = ret->createManualObject(name->value());
				object->getUserObjectBindings().setUserAny(
						"zzogre/device/resource",
						Any(Ogre::String(attr->value())));
			} else
				object = ret->createManualObject(name->value());

			load(node, object);
		} else if (strcmp(type->value(), "Entity") == 0) {
			Entity* object;

			XmlAttribute* meshName = node->first_attribute("mesh-name");
			if (meshName) {
				XmlAttribute* group = node->first_attribute("group");
				object =
						ret->createEntity(name->value(), meshName->value(),
								group ? group->value() : ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME);
			} else {
				XmlAttribute* prefabType = node->first_attribute("prefab-type");
				ZzOgreAssert(prefabType, "no mesh name or prefab-type");

				SceneManager::PrefabType _type;
				if (strcmp(prefabType->value(), "plane") == 0)
					_type = SceneManager::PT_PLANE;
				else if (strcmp(prefabType->value(), "cube") == 0)
					_type = SceneManager::PT_CUBE;
				else if (strcmp(prefabType->value(), "sphere") == 0)
					_type = SceneManager::PT_SPHERE;
				else
				ZzOgreAssert(false,
						"unexpected prefab-type, "
								+ string(prefabType->value()));

				object = ret->createEntity(name->value(), _type);
			}

			load(node, object);
		} else
			OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
					"unknown movable object type: " + string(type->value()),
					__FUNCTION__);

		// TODO: other movable objects
	}

	load(scene->first_node("scene-node"), ret->getRootSceneNode());
}

}

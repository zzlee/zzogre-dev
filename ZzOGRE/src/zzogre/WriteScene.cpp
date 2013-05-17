/*
 * WriteScene.cpp
 *
 *  Created on: 2013/4/10
 *      Author: SUCHEN
 */

#include "ZzOGRE.h"

#include <fstream>
using namespace std;

#include <OgreSceneManager.h>
#include <OgreCamera.h>
#include <OgreManualObject.h>
#include <OgreViewport.h>
#include <OgreRenderTarget.h>
#include <OgreRenderable.h>
#include <OgreHardwareIndexBuffer.h>
#include <OgreStringConverter.h>
using namespace Ogre;

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>
using namespace rapidxml;

#include <boost/format.hpp>
#include <boost/bind.hpp>
using namespace boost;

#include "Euler.h"
#include "SceneNodes.h"
#include "Component.h"

namespace zzogre {

static void write(XmlDocument* doc, SceneManager* scene);
static void write(XmlNode* node, SceneNode* sceneNode);
static void writeMovableObjectAttributes(XmlNode* node, MovableObject* object);
static void writeRenderableAttributes(XmlNode* node, Renderable* object);
static void write(XmlNode* node, ManualObject* object);
static void write(XmlNode* node, ManualObject::ManualObjectSection* object);
static void write(XmlNode* node, Camera* object);
static void write(XmlNode* node, Entity* object);

static void write(XmlDocument* doc, SceneManager* scene) {
	XmlNode *node = doc->allocate_node(node_element, "scene");
	doc->append_node(node);

	XmlAttribute* attr = doc->allocate_attribute("name",
			scene->getName().c_str());
	node->append_attribute(attr);

	attr = doc->allocate_attribute("type", scene->getTypeName().c_str());
	node->append_attribute(attr);

	attr = doc->allocate_attribute("zzogre-version", ZZOGRE_VERSION);
	node->append_attribute(attr);

	attr =
			doc->allocate_attribute("ambient-light",
					doc->allocate_string(
							StringConverter::toString(scene->getAmbientLight()).c_str()));
	node->append_attribute(attr);

	{
		const char* value = NULL;
		switch (scene->getFogMode()) {
		case FOG_NONE:
			value = "none";
			break;

		case FOG_EXP:
			value = "exp";
			break;

		case FOG_EXP2:
			value = "exp2";
			break;

		case FOG_LINEAR:
			value = "linear";
			break;
		}

		attr = doc->allocate_attribute("fog-mode", value);
		node->append_attribute(attr);
	}

	attr = doc->allocate_attribute("fog-colour",
			doc->allocate_string(
					StringConverter::toString(scene->getFogColour()).c_str()));
	node->append_attribute(attr);

	attr = doc->allocate_attribute("fog-start",
			doc->allocate_string(
					StringConverter::toString(scene->getFogStart()).c_str()));
	node->append_attribute(attr);

	attr = doc->allocate_attribute("fog-end",
			doc->allocate_string(
					StringConverter::toString(scene->getFogEnd()).c_str()));
	node->append_attribute(attr);

	attr = doc->allocate_attribute("fog-density",
			doc->allocate_string(
					StringConverter::toString(scene->getFogDensity()).c_str()));
	node->append_attribute(attr);

	// Camera
	for (SceneManager::CameraIterator iter = scene->getCameraIterator();
			iter.hasMoreElements(); iter.moveNext()) {
		write(node, iter.peekNextValue());
	}

	// ManualObject
	for (SceneManager::MovableObjectIterator iter =
			scene->getMovableObjectIterator("ManualObject");
			iter.hasMoreElements(); iter.moveNext()) {
		write(node, dynamic_cast<ManualObject*>(iter.peekNextValue()));
	}

	// Entity
	for (SceneManager::MovableObjectIterator iter =
			scene->getMovableObjectIterator("Entity"); iter.hasMoreElements();
			iter.moveNext()) {
		write(node, dynamic_cast<Entity*>(iter.peekNextValue()));
	}

	// TODO: other movable objects

	write(node, scene->getRootSceneNode());
}

static void write(XmlNode* node, SceneNode* sceneNode) {
	XmlDocument* doc = node->document();
	XmlNode* node0 = doc->allocate_node(node_element, "scene-node");
	node->append_node(node0);

	XmlAttribute* attr = doc->allocate_attribute("name",
			doc->allocate_string(sceneNode->getName().c_str()));
	node0->append_attribute(attr);

	attr =
			doc->allocate_attribute("position",
					doc->allocate_string(
							StringConverter::toString(sceneNode->getPosition()).c_str()));
	node0->append_attribute(attr);

	attr =
			doc->allocate_attribute("orientation",
					doc->allocate_string(
							zzogre::toString(Euler(sceneNode->getOrientation())).c_str()));
	node0->append_attribute(attr);

	attr = doc->allocate_attribute("scale",
			doc->allocate_string(
					StringConverter::toString(sceneNode->getScale()).c_str()));
	node0->append_attribute(attr);

	attr =
			doc->allocate_attribute("initial-position",
					doc->allocate_string(
							StringConverter::toString(
									sceneNode->getInitialPosition()).c_str()));
	node0->append_attribute(attr);

	attr =
			doc->allocate_attribute("initial-orientation",
					doc->allocate_string(
							zzogre::toString(
									Euler(sceneNode->getInitialOrientation())).c_str()));
	node0->append_attribute(attr);

	attr =
			doc->allocate_attribute("initial-scale",
					doc->allocate_string(
							StringConverter::toString(
									sceneNode->getInitialScale()).c_str()));
	node0->append_attribute(attr);

	unsigned short objects = sceneNode->numAttachedObjects();
	for (unsigned short i = 0; i < objects; ++i) {
		MovableObject* movableObject = sceneNode->getAttachedObject(i);

		XmlNode* node1 = doc->allocate_node(node_element, "attached-object");
		node0->append_node(node1);

		XmlAttribute* attr = doc->allocate_attribute("name",
				doc->allocate_string(movableObject->getName().c_str()));
		node1->append_attribute(attr);

		attr = doc->allocate_attribute("type",
				doc->allocate_string(movableObject->getMovableType().c_str()));
		node1->append_attribute(attr);
	}

	ComponentsPtr components = SceneNodes::getAllComponents(sceneNode);
	for (Components::const_iterator i = components->begin();
			i != components->end(); ++i) {
		const ComponentPtr& component = *i;

		XmlNode* node1 = doc->allocate_node(node_element, "component");
		node0->append_node(node1);

		XmlAttribute* attr = doc->allocate_attribute("type",
				doc->allocate_string(component->getTypeName().c_str()));
		node1->append_attribute(attr);

		attr =
				doc->allocate_attribute("enable",
						doc->allocate_string(
								StringConverter::toString(
										component->enable.get()).c_str()));
		node1->append_attribute(attr);

		component->save(node1);
	}

	for (Ogre::Node::ChildNodeIterator iter = sceneNode->getChildIterator();
			iter.hasMoreElements(); iter.moveNext()) {
		SceneNode* child = dynamic_cast<SceneNode*>(iter.peekNextValue());
		if (child)
			write(node0, child);
	}
}

static void writeMovableObjectAttributes(XmlNode* node, MovableObject* object) {
	XmlDocument* doc = node->document();

	XmlAttribute* attr = doc->allocate_attribute("name",
			doc->allocate_string(object->getName().c_str()));
	node->append_attribute(attr);

	attr = doc->allocate_attribute("type",
			doc->allocate_string(object->getMovableType().c_str()));
	node->append_attribute(attr);

	attr = doc->allocate_attribute("visible",
			doc->allocate_string(
					StringConverter::toString(object->getVisible()).c_str()));
	node->append_attribute(attr);

	attr =
			doc->allocate_attribute("rendering-distance",
					doc->allocate_string(
							StringConverter::toString(
									object->getRenderingDistance()).c_str()));
	node->append_attribute(attr);

	attr = doc->allocate_attribute("rendering-min-pixel-size",
			doc->allocate_string(
					StringConverter::toString(
							object->getRenderingMinPixelSize()).c_str()));
	node->append_attribute(attr);

	attr =
			doc->allocate_attribute("render-queue-group",
					doc->allocate_string(
							StringConverter::toString(
									object->getRenderQueueGroup()).c_str()));
	node->append_attribute(attr);

	attr = doc->allocate_attribute("query-flags",
			doc->allocate_string(
					zzogre::flagsToString(object->getQueryFlags()).c_str()));
	node->append_attribute(attr);

	attr =
			doc->allocate_attribute("visibility-flags",
					doc->allocate_string(
							zzogre::flagsToString(object->getVisibilityFlags()).c_str()));
	node->append_attribute(attr);

	attr = doc->allocate_attribute("light-mask",
			doc->allocate_string(
					zzogre::flagsToString(object->getLightMask()).c_str()));
	node->append_attribute(attr);

	attr =
			doc->allocate_attribute("cast-shadows",
					doc->allocate_string(
							StringConverter::toString(object->getCastShadows()).c_str()));
	node->append_attribute(attr);

	Any deviceResource = object->getUserObjectBindings().getUserAny(
			"zzogre/device/resource");
	if (!deviceResource.isEmpty()) {
		attr = doc->allocate_attribute("zzogre-device-resource",
				doc->allocate_string(
						any_cast<Ogre::String>(deviceResource).c_str()));
		node->append_attribute(attr);
	}
}

static void writeRenderableAttributes(XmlNode* node, Renderable* object) {
	XmlDocument* doc = node->document();

	XmlAttribute* attr = doc->allocate_attribute("use-identity-projection",
			doc->allocate_string(
					StringConverter::toString(
							object->getUseIdentityProjection()).c_str()));
	node->append_attribute(attr);

	attr =
			doc->allocate_attribute("use-identity-view",
					doc->allocate_string(
							StringConverter::toString(
									object->getUseIdentityView()).c_str()));
	node->append_attribute(attr);
}

static void write(XmlNode* node, ManualObject* object) {
	XmlDocument* doc = node->document();
	XmlNode* node0 = doc->allocate_node(node_element, "movable-object");
	node->append_node(node0);

	writeMovableObjectAttributes(node0, object);

	XmlAttribute* attr = doc->allocate_attribute("dynamic",
			doc->allocate_string(
					StringConverter::toString(object->getDynamic()).c_str()));
	node0->append_attribute(attr);

	for (unsigned int i = 0; i < object->getNumSections(); ++i) {
		ManualObject::ManualObjectSection* section = object->getSection(0);

		XmlNode* node1 = doc->allocate_node(node_element, "section");
		node0->append_node(node1);

		write(node1, section);
	}

	attr =
			doc->allocate_attribute("keep-declaration-order",
					doc->allocate_string(
							StringConverter::toString(
									object->getKeepDeclarationOrder()).c_str()));
	node0->append_attribute(attr);

	attr = doc->allocate_attribute("use-identity-projection",
			doc->allocate_string(
					StringConverter::toString(
							object->getUseIdentityProjection()).c_str()));
	node0->append_attribute(attr);

	attr =
			doc->allocate_attribute("use-identity-view",
					doc->allocate_string(
							StringConverter::toString(
									object->getUseIdentityView()).c_str()));
	node0->append_attribute(attr);

	attr = doc->allocate_attribute("bounding-box",
			doc->allocate_string(
					zzogre::toString(object->getBoundingBox()).c_str()));
	node0->append_attribute(attr);
}

static void addFloat1Node(uint8_t* p, size_t offset, XmlNode* node,
		const char* name) {
	float* v = (float*) (p + offset);

	XmlDocument* doc = node->document();
	XmlNode* node1 = doc->allocate_node(node_element, name,
			doc->allocate_string(StringConverter::toString(v[0]).c_str()));
	node->append_node(node1);
}

static void addFloat2Node(uint8_t* p, size_t offset, XmlNode* node,
		const char* name) {
	float* v = (float*) (p + offset);

	XmlDocument* doc = node->document();
	XmlNode* node1 = doc->allocate_node(node_element, name,
			doc->allocate_string(
					StringConverter::toString(Vector2(v[0], v[1])).c_str()));
	node->append_node(node1);
}

static void addFloat3Node(uint8_t* p, size_t offset, XmlNode* node,
		const char* name) {
	float* v = (float*) (p + offset);

	XmlDocument* doc = node->document();
	XmlNode* node1 =
			doc->allocate_node(node_element, name,
					doc->allocate_string(
							StringConverter::toString(Vector3(v[0], v[1], v[2])).c_str()));
	node->append_node(node1);
}

static void addFloat4Node(uint8_t* p, size_t offset, XmlNode* node,
		const char* name) {
	float* v = (float*) (p + offset);

	XmlDocument* doc = node->document();
	XmlNode* node1 =
			doc->allocate_node(node_element, name,
					doc->allocate_string(
							StringConverter::toString(
									Vector4(v[0], v[1], v[2], v[3])).c_str()));
	node->append_node(node1);
}

static void addColourARGBNode(uint8_t* p, size_t offset, XmlNode* node,
		const char* name) {
	uint32_t* v = (uint32_t*) (p + offset);

	XmlDocument* doc = node->document();
	ColourValue color;
	color.setAsARGB(*v);
	XmlNode* node1 = doc->allocate_node(node_element, name,
			doc->allocate_string(StringConverter::toString(color).c_str()));
	node->append_node(node1);
}

static void write(XmlNode* node, ManualObject::ManualObjectSection* object) {
	XmlDocument* doc = node->document();

	writeRenderableAttributes(node, object);

	XmlAttribute* attr = doc->allocate_attribute("material-name",
			object->getMaterialName().c_str());
	node->append_attribute(attr);

	attr = doc->allocate_attribute("material-group",
			object->getMaterialGroup().c_str());
	node->append_attribute(attr);

	RenderOperation* op = object->getRenderOperation();
	if (op) {
		{
			const char* value = NULL;
			switch (op->operationType) {
			case RenderOperation::OT_POINT_LIST:
				value = "point-list";
				break;

			case RenderOperation::OT_LINE_LIST:
				value = "line-list";
				break;

			case RenderOperation::OT_LINE_STRIP:
				value = "line-strip";
				break;

			case RenderOperation::OT_TRIANGLE_LIST:
				value = "triangle-list";
				break;

			case RenderOperation::OT_TRIANGLE_STRIP:
				value = "triangle-strip";
				break;

			case RenderOperation::OT_TRIANGLE_FAN:
				value = "triangle-fan";
				break;
			}
			attr = doc->allocate_attribute("type", value);
			node->append_attribute(attr);
		}

		if (op->vertexData) {
			size_t vertexSize =
					op->vertexData->vertexDeclaration->getVertexSize(0);
			std::vector<uint8_t> buffer(
					op->vertexData->vertexCount * vertexSize);
			op->vertexData->vertexBufferBinding->getBuffer(0)->readData(
					op->vertexData->vertexStart * vertexSize, buffer.size(),
					&buffer[0]);

			std::vector<function<void(uint8_t*, XmlNode*)> > nodeAdders;

			const VertexElement* elem =
					op->vertexData->vertexDeclaration->findElementBySemantic(
							VES_POSITION);
			if (elem && elem->getType() == VET_FLOAT3) {
				function<void(uint8_t*, XmlNode*)> func = bind(&addFloat3Node,
						_1, elem->getOffset(), _2, "position");
				nodeAdders.push_back(func);
			}

			elem = op->vertexData->vertexDeclaration->findElementBySemantic(
					VES_NORMAL);
			if (elem && elem->getType() == VET_FLOAT3) {
				function<void(uint8_t*, XmlNode*)> func = bind(&addFloat3Node,
						_1, elem->getOffset(), _2, "normal");
				nodeAdders.push_back(func);
			}

			elem = op->vertexData->vertexDeclaration->findElementBySemantic(
					VES_TANGENT);
			if (elem && elem->getType() == VET_FLOAT3) {
				function<void(uint8_t*, XmlNode*)> func = bind(&addFloat3Node,
						_1, elem->getOffset(), _2, "tangent");
				nodeAdders.push_back(func);
			}

			elem = op->vertexData->vertexDeclaration->findElementBySemantic(
					VES_DIFFUSE);
			if (elem && elem->getType() == VET_COLOUR_ARGB) {
				function<void(uint8_t*, XmlNode*)> func = bind(
						&addColourARGBNode, _1, elem->getOffset(), _2,
						"colour");
				nodeAdders.push_back(func);
			}

			elem = op->vertexData->vertexDeclaration->findElementBySemantic(
					VES_TEXTURE_COORDINATES);
			if (elem) {
				switch (elem->getType()) {
				case VET_FLOAT1: {
					function<void(uint8_t*, XmlNode*)> func = bind(
							&addFloat1Node, _1, elem->getOffset(), _2,
							"texture-coord");
					nodeAdders.push_back(func);
				}
					break;
				case VET_FLOAT2: {
					function<void(uint8_t*, XmlNode*)> func = bind(
							&addFloat2Node, _1, elem->getOffset(), _2,
							"texture-coord");
					nodeAdders.push_back(func);
				}
					break;
				case VET_FLOAT3: {
					function<void(uint8_t*, XmlNode*)> func = bind(
							&addFloat3Node, _1, elem->getOffset(), _2,
							"texture-coord");
					nodeAdders.push_back(func);
				}
					break;
				case VET_FLOAT4: {
					function<void(uint8_t*, XmlNode*)> func = bind(
							&addFloat4Node, _1, elem->getOffset(), _2,
							"texture-coord");
					nodeAdders.push_back(func);
				}
					break;

				default:
					break;
				}
			}

			for (size_t i = 0; i < op->vertexData->vertexCount; ++i) {
				uint8_t* p = (uint8_t*) &buffer[i * vertexSize];

				XmlNode* node1 = doc->allocate_node(node_element,
						"vertex-data");
				node->append_node(node1);

				for (std::vector<function<void(uint8_t*, XmlNode*)> >::const_iterator j =
						nodeAdders.begin(); j != nodeAdders.end(); ++j) {
					(*j)(p, node1);
				}
			}
		}

		if (op->useIndexes && op->indexData && op->indexData->indexCount > 0) {
			string indexList;
			IndexData* data = op->indexData;
			switch (data->indexBuffer->getType()) {
			case HardwareIndexBuffer::IT_32BIT: {
				std::vector<uint32_t> buffer(data->indexCount);
				data->indexBuffer->readData(data->indexStart * 4,
						data->indexCount * 4, &buffer[0]);

				indexList += StringConverter::toString(*buffer.begin());
				for (std::vector<uint32_t>::const_iterator i = buffer.begin()
						+ 1; i != buffer.end(); ++i)
					indexList += " " + StringConverter::toString(*i);
			}
				break;

			default: {
				std::vector<uint16_t> buffer(data->indexCount);
				data->indexBuffer->readData(data->indexStart * 2,
						data->indexCount * 2, &buffer[0]);

				indexList += StringConverter::toString(*buffer.begin());
				for (std::vector<uint16_t>::const_iterator i = buffer.begin()
						+ 1; i != buffer.end(); ++i)
					indexList += " " + StringConverter::toString(*i);
			}
				break;
			}

			XmlNode* node1 = doc->allocate_node(node_element, "index-data",
					doc->allocate_string(indexList.c_str()));
			node->append_node(node1);
		}

	}
}

static void write(XmlNode* node, Camera* object) {
	XmlDocument* doc = node->document();
	XmlNode* node0 = doc->allocate_node(node_element, "movable-object");
	node->append_node(node0);

	writeMovableObjectAttributes(node0, object);
	writeRenderableAttributes(node0, object);

	XmlAttribute* attr = doc->allocate_attribute("fov-y",
			doc->allocate_string(
					StringConverter::toString(object->getFOVy()).c_str()));
	node0->append_attribute(attr);

	attr =
			doc->allocate_attribute("near-clip-distance",
					doc->allocate_string(
							StringConverter::toString(
									object->getNearClipDistance()).c_str()));
	node0->append_attribute(attr);

	attr =
			doc->allocate_attribute("far-clip-distance",
					doc->allocate_string(
							StringConverter::toString(
									object->getFarClipDistance()).c_str()));
	node0->append_attribute(attr);

	attr =
			doc->allocate_attribute("aspect-ratio",
					doc->allocate_string(
							StringConverter::toString(object->getAspectRatio()).c_str()));
	node0->append_attribute(attr);

	attr =
			doc->allocate_attribute("auto-aspect-ratio",
					doc->allocate_string(
							StringConverter::toString(
									object->getAutoAspectRatio()).c_str()));
	node0->append_attribute(attr);

	attr =
			doc->allocate_attribute("frustum-offset",
					doc->allocate_string(
							StringConverter::toString(
									object->getFrustumOffset()).c_str()));
	node0->append_attribute(attr);

	attr =
			doc->allocate_attribute("focal-length",
					doc->allocate_string(
							StringConverter::toString(object->getFocalLength()).c_str()));
	node0->append_attribute(attr);

	{
		const char* value = NULL;
		switch (object->getProjectionType()) {
		case PT_ORTHOGRAPHIC:
			value = "orthographic";
			break;

		case PT_PERSPECTIVE:
			value = "perspective";
			break;
		}

		attr = doc->allocate_attribute("projection-type", value);
		node0->append_attribute(attr);
	}

	attr = doc->allocate_attribute("ortho-window",
			doc->allocate_string(
					StringConverter::toString(
							Vector2(object->getOrthoWindowWidth(),
									object->getOrthoWindowHeight())).c_str()));
	node0->append_attribute(attr);

	{
		const char* value = NULL;
		switch (object->getPolygonMode()) {
		case PM_POINTS:
			value = "points";
			break;

		case PM_WIREFRAME:
			value = "wireframe";
			break;

		case PM_SOLID:
			value = "solid";
			break;
		}

		attr = doc->allocate_attribute("polygon-mode", value);
		node0->append_attribute(attr);
	}

	Viewport* viewport = object->getViewport();
	if (viewport) {
		RenderTarget* renderTarget = viewport->getTarget();
		attr = doc->allocate_attribute("render-target-name",
				renderTarget->getName().c_str());
		node0->append_attribute(attr);

		attr =
				doc->allocate_attribute("z-order",
						doc->allocate_string(
								StringConverter::toString(viewport->getZOrder()).c_str()));
		node0->append_attribute(attr);

		attr = doc->allocate_attribute("dimensions",
				doc->allocate_string(
						StringConverter::toString(
								Vector4(viewport->getLeft(), viewport->getTop(),
										viewport->getWidth(),
										viewport->getHeight())).c_str()));
		node0->append_attribute(attr);

		attr = doc->allocate_attribute("background-colour",
				doc->allocate_string(
						StringConverter::toString(
								viewport->getBackgroundColour()).c_str()));
		node0->append_attribute(attr);

		attr =
				doc->allocate_attribute("depth-clear",
						doc->allocate_string(
								StringConverter::toString(
										viewport->getDepthClear()).c_str()));
		node0->append_attribute(attr);

		attr = doc->allocate_attribute("clear-every-frame",
				doc->allocate_string(
						StringConverter::toString(
								viewport->getClearEveryFrame()).c_str()));
		node0->append_attribute(attr);

		attr =
				doc->allocate_attribute("clear-buffers",
						doc->allocate_string(
								zzogre::flagsToString(
										viewport->getClearBuffers()).c_str()));
		node0->append_attribute(attr);

		attr = doc->allocate_attribute("material-scheme",
				viewport->getMaterialScheme().c_str());
		node0->append_attribute(attr);

		attr = doc->allocate_attribute("overlays-enabled",
				doc->allocate_string(
						StringConverter::toString(
								viewport->getOverlaysEnabled()).c_str()));
		node0->append_attribute(attr);

		attr =
				doc->allocate_attribute("skies-enabled",
						doc->allocate_string(
								StringConverter::toString(
										viewport->getSkiesEnabled()).c_str()));
		node0->append_attribute(attr);

		attr =
				doc->allocate_attribute("shadows-enabled",
						doc->allocate_string(
								StringConverter::toString(
										viewport->getShadowsEnabled()).c_str()));
		node0->append_attribute(attr);

		attr =
				doc->allocate_attribute("visibility-mask",
						doc->allocate_string(
								zzogre::flagsToString(
										viewport->getVisibilityMask()).c_str()));
		node0->append_attribute(attr);

		attr = doc->allocate_attribute("render-queue-invocation-sequence-name",
				viewport->getRenderQueueInvocationSequenceName().c_str());
		node0->append_attribute(attr);
	}
}

static void write(XmlNode* node, Entity* object) {
	XmlDocument* doc = node->document();
	XmlNode* node0 = doc->allocate_node(node_element, "movable-object");
	node->append_node(node0);

	writeMovableObjectAttributes(node0, object);

	XmlAttribute* attr =
			doc->allocate_attribute("display-skeleton",
					doc->allocate_string(
							StringConverter::toString(
									object->getDisplaySkeleton()).c_str()));
	node0->append_attribute(attr);

	attr = doc->allocate_attribute("skip-animation-state-update",
			doc->allocate_string(
					StringConverter::toString(
							object->getSkipAnimationStateUpdate()).c_str()));
	node0->append_attribute(attr);

	attr = doc->allocate_attribute("always-update-main-skeleton",
			doc->allocate_string(
					StringConverter::toString(
							object->getAlwaysUpdateMainSkeleton()).c_str()));
	node0->append_attribute(attr);
}

void writeScene(SceneManager* scene, const std::string& filename) {
	XmlDocument doc;
	write(&doc, scene);

	ofstream file(filename.c_str());
	file << doc;
}

}

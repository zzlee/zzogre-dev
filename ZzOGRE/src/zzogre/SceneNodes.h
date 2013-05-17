/*
 * SceneNodes.h
 *
 *  Created on: 2013/1/19
 *      Author: SUCHEN
 */

#ifndef SCENENODES_H_
#define SCENENODES_H_

#include <OgreSceneNode.h>
#include <OgreMovableObject.h>
#include <OgreAny.h>

#include <boost/function.hpp>

#include "ComponentManager.h"
namespace zzogre {

class SceneNodes {
	friend class Component;

public:	template<class T>
	static T* getAttachedObjectByName(Ogre::SceneNode* sceneNode,
			const std::string& name) {
		return dynamic_cast<T*>(sceneNode->getAttachedObject(name));
	}

	template<class T>
	static T* getAttachedObject(Ogre::SceneNode* sceneNode) {
		Ogre::SceneNode::ObjectIterator iter = sceneNode->getAttachedObjectIterator();
		while (iter.hasMoreElements()) {
			T* ret = dynamic_cast<T*>(iter.getNext());
			if (ret)
				return ret;
		}

		return NULL;
	}

	static void enumerateAllChildren(Ogre::SceneNode* sceneNode,
			boost::function<void(Ogre::SceneNode*)> callback);

	static Ogre::Any getComponentManagerAny(const Ogre::SceneNode* parent) {
		return parent->getUserObjectBindings().getUserAny("__cm__");
	}

	static bool hasComponentManager(const Ogre::SceneNode* parent) {
		return !getComponentManagerAny(parent).isEmpty();
	}

	static boost::shared_ptr<ComponentManager> getComponentManager(
			Ogre::SceneNode* parent) {
		Ogre::Any any = getComponentManagerAny(parent);
		if (any.isEmpty()) {
			ComponentManagerPtr ptr(new ComponentManager());
			parent->getUserObjectBindings().setUserAny("__cm__", Ogre::Any(ptr));

			return ptr;
		} else {
			return boost::dynamic_pointer_cast<ComponentManager>(
					Ogre::any_cast<ComponentManagerPtr>(any));
		}
	}

	static boost::shared_ptr<ComponentManager> getComponentManagerIfExist(
			const Ogre::SceneNode* parent) {
		Ogre::Any any = getComponentManagerAny(parent);
		if (any.isEmpty()) {
			return ComponentManagerPtr();
		} else {
			return boost::dynamic_pointer_cast<ComponentManager>(
					Ogre::any_cast<ComponentManagerPtr>(any));
		}
	}

	template<class T>
	static boost::shared_ptr<T> addComponent(Ogre::SceneNode* parent, bool enable = true) {
		boost::shared_ptr<Component> component((Component*) new T);
		component->parent.set(parent);
		component->enable.set(enable);

		return boost::dynamic_pointer_cast<T>(component);
	}

	static ComponentPtr addComponent(Ogre::SceneNode* parent,
			const std::string& type, bool enable = true) {
		ComponentPtr component(ComponentManager::createNew(type));
		component->parent.set(parent);
		component->enable.set(enable);

		return component;
	}

	template<class T>
	static boost::shared_ptr<T> addComponent(Ogre::SceneNode* parent,
			const std::string& type, bool enable = true) {
		return boost::dynamic_pointer_cast<T>(addComponent(parent, type, enable));
	}

	template<class T>
	static boost::shared_ptr<T> getComponent(Ogre::SceneNode* parent) {
		return getComponentManager(parent)->getComponent<T>();
	}

	static boost::shared_ptr<Component> getComponent(Ogre::SceneNode* parent, const std::string& type) {
		return getComponentManager(parent)->getComponent(type);
	}

	template<class T>
	static boost::shared_ptr<T> getComponent(Ogre::SceneNode* parent, const std::string& type) {
		return getComponentManager(parent)->getComponent<T>(type);
	}

	static boost::shared_ptr<std::vector<boost::shared_ptr<Component> > > getAllComponents(Ogre::SceneNode* parent) {
		return getComponentManager(parent)->getAllComponents();
	}

	template<class T>
	static boost::shared_ptr<std::vector<boost::shared_ptr<T> > > getComponents(Ogre::SceneNode* parent) {
		return getComponentManager(parent)->getComponents<T>();
	}

	static boost::shared_ptr<std::vector<boost::shared_ptr<Component> > > getComponents(Ogre::SceneNode* parent, const std::string& type) {
		return getComponentManager(parent)->getComponents(type);
	}

	template<class T>
	static boost::shared_ptr<std::vector<boost::shared_ptr<T> > > getComponents(Ogre::SceneNode* parent, const std::string& type) {
		return getComponentManager(parent)->getComponents<T>(type);
	}

	template<class T>
	static void removeComponent(Ogre::SceneNode* parent) {
		return getComponentManager(parent)->removeComponent<T>();
	}

	static void removeComponent(Ogre::SceneNode* parent, const std::string& type) {
		getComponentManager(parent)->removeComponent(type);
	}

	static void removeAllComponents(Ogre::SceneNode* parent) {
		getComponentManager(parent)->removeAllComponents();
	}

	template<class T>
	static void removeComponents(Ogre::SceneNode* parent) {
		return getComponentManager(parent)->removeComponents<T>();
	}

	static void removeComponents(Ogre::SceneNode* parent, const std::string& type) {
		getComponentManager(parent)->removeComponents(type);
	}

	static size_t getComponentCount(Ogre::SceneNode* parent) {
		return getComponentManager(parent)->getComponentCount();
	}

	template<class T>
	static void apply(Ogre::SceneNode* parent,
			boost::function<void(boost::shared_ptr<T>)> callback) {
		getComponentManager(parent)->apply(callback);
	}

	template<class T>
	static void apply(Ogre::SceneNode* parent,
			boost::function<void(T*)> callback) {
		getComponentManager(parent)->apply(callback);
	}

	template<class T>
	static void applyAll(Ogre::SceneNode* parent,
			boost::function<void(boost::shared_ptr<T>)> callback);

	template<class T>
	static void applyAll(Ogre::SceneNode* parent,
			boost::function<void(T*)> callback);

	static void activeAll(Ogre::SceneNode* parent, bool enable = true);
	static void activeAllInHierarchy(Ogre::SceneNode* parent,
			bool enable = true);

	static Ogre::Any getDeviceResource(Ogre::MovableObject* movableObject);

protected:
	static void addComponentImpl(Ogre::SceneNode* parent,
			ComponentPtr component) {
		getComponentManager(parent)->addComponentImpl(component);
	}

	static void removeComponentImpl(Ogre::SceneNode* parent,
			ComponentPtr component) {
		getComponentManager(parent)->removeComponentImpl(component);
	}
};

template<class T>
void SceneNodes::applyAll(Ogre::SceneNode* parent,
		boost::function<void(boost::shared_ptr<T>)> callback) {
	Ogre::Any any = getComponentManagerAny(parent);
	if (!any.isEmpty()) {
		boost::shared_ptr<ComponentManager> cm = boost::dynamic_pointer_cast<
				ComponentManager>(Ogre::any_cast<ComponentManagerPtr>(any));

		cm->apply(callback);
	}

	Ogre::Node::ChildNodeIterator iter = parent->getChildIterator();
	while (iter.hasMoreElements()) {
		Ogre::SceneNode* node = dynamic_cast<Ogre::SceneNode*>(iter.getNext());
		if (!node)
			continue;

		applyAll(node, callback);
	}
}

template<class T>
void SceneNodes::applyAll(Ogre::SceneNode* parent,
		boost::function<void(T*)> callback) {
	Ogre::Any any = getComponentManagerAny(parent);
	if (!any.isEmpty()) {
		boost::shared_ptr<ComponentManager> cm = boost::dynamic_pointer_cast<
				ComponentManager>(Ogre::any_cast<ComponentManagerPtr>(any));

		cm->apply(callback);
	}

	Ogre::Node::ChildNodeIterator iter = parent->getChildIterator();
	while (iter.hasMoreElements()) {
		Ogre::SceneNode* node = dynamic_cast<Ogre::SceneNode*>(iter.getNext());
		if (!node)
			continue;

		applyAll(node, callback);
	}
}

template<class T>
T* Component::getAttachedObjectByName(const std::string& name) const {
	return SceneNodes::getAttachedObjectByName<T>(parent.get(), name);
}

template<class T>
T* Component::getAttachedObject() const {
	return SceneNodes::getAttachedObject<T>(parent.get());
}

template<class T>
boost::shared_ptr<T> Component::getComponent() const {
	return SceneNodes::getComponent<T>(parent.get());
}

inline boost::shared_ptr<Component> Component::getComponent(const std::string& type) const {
	return SceneNodes::getComponent(parent.get(), type);
}

template<class T>
boost::shared_ptr<T> Component::getComponent(const std::string& type) const {
	return SceneNodes::getComponent<T>(parent.get(), type);
}

inline boost::shared_ptr<std::vector<boost::shared_ptr<Component> > > Component::getAllComponents() {
	return SceneNodes::getAllComponents(parent.get());
}

template<class T>
boost::shared_ptr<std::vector<boost::shared_ptr<T> > > Component::getComponents() {
	return SceneNodes::getComponents<T>(parent.get());
}

inline boost::shared_ptr<std::vector<boost::shared_ptr<Component> > > Component::getComponents(const std::string& type) {
	return SceneNodes::getComponents(parent.get(), type);
}

template<class T>
boost::shared_ptr<std::vector<boost::shared_ptr<T> > > Component::getComponents(const std::string& type) {
	return SceneNodes::getComponents<T>(parent.get(), type);
}

template<class T>
inline void Component::removeComponent() {
	return SceneNodes::removeComponent<T>(parent.get());
}

inline void Component::removeComponent(const std::string& type) {
	SceneNodes::removeComponent(parent.get(), type);
}

inline void Component::removeAllComponents() {
	SceneNodes::removeAllComponents(parent.get());
}

template<class T>
void Component::removeComponents() {
	return SceneNodes::removeComponents<T>(parent.get());
}

inline void Component::removeComponents(const std::string& type) {
	SceneNodes::removeComponents(parent.get(), type);
}

inline size_t Component::getComponentCount() const {
	return SceneNodes::getComponentCount(parent.get());
}

template<class T>
void Component::apply(boost::function<void(boost::shared_ptr<T>)> callback) {
	SceneNodes::apply(parent.get(), callback);
}

template<class T>
void Component::apply(boost::function<void(T*)> callback) {
	SceneNodes::apply(parent.get(), callback);
}

template<class T>
void Component::applyAll(boost::function<void(boost::shared_ptr<T>)> callback) {
	SceneNodes::applyAll(parent.get(), callback);
}

template<class T>
void Component::applyAll(boost::function<void(T*)> callback) {
	SceneNodes::applyAll(parent.get(), callback);
}

inline void Component::activeAll(bool enable) {
	SceneNodes::activeAll(parent.get(), enable);
}

inline void Component::activeAllInHierarchy(bool enable) {
	SceneNodes::activeAllInHierarchy(parent.get(), enable);
}

} /* namespace zzogre */

#endif /* SCENENODES_H_ */

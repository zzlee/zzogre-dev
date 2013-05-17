/*
 * ComponentManager.h
 *
 *  Created on: 2013/1/19
 *      Author: SUCHEN
 */

#ifndef COMPONENTMANAGER_H_
#define COMPONENTMANAGER_H_

#include "zzlab/ZzLab.h"

#include <boost/function.hpp>
#include <boost/unordered_set.hpp>

#include <vector>

#include <OgreSceneNode.h>
#include <OgreException.h>

#include "Component.h"

namespace zzogre {

class ComponentManager {
	friend class Component;
	friend class SceneNodes;

protected:
	ComponentManager();

public:
	virtual ~ComponentManager();

	static bool registerComponentType(const std::string& type,
			ComponentCreator creator);
	static Component* createNew(const std::string& type);

	template<class T>
	boost::shared_ptr<T> getComponent() const {
		for(boost::unordered_set<ComponentPtr>::const_iterator i = mComponents.begin();i != mComponents.end();++i) {
			const ComponentPtr& component = *i;
			boost::shared_ptr<T> ret = boost::dynamic_pointer_cast<T>(component);
			if(ret)
				return ret;
		}

		return boost::shared_ptr<T>();
	}

	boost::shared_ptr<Component> getComponent(const std::string& type) const {
		for(boost::unordered_set<ComponentPtr>::const_iterator i = mComponents.begin();i != mComponents.end();++i) {
			const ComponentPtr& component = *i;
			if(component->getTypeName() == type)
				return component;
		}

		return boost::shared_ptr<Component>();
	}

	template<class T>
	boost::shared_ptr<T> getComponent(const std::string& type) const {
		for(boost::unordered_set<ComponentPtr>::const_iterator i = mComponents.begin();i != mComponents.end();++i) {
			const ComponentPtr& component = *i;
			if(component->getTypeName() == type)
				return boost::dynamic_pointer_cast<T>(component);
		}

		return boost::shared_ptr<T>();
	}

	boost::shared_ptr<std::vector<boost::shared_ptr<Component> > > getAllComponents() {
		boost::shared_ptr<std::vector<boost::shared_ptr<Component> > > ret(new std::vector<boost::shared_ptr<Component> >());
		for(boost::unordered_set<ComponentPtr>::const_iterator i = mComponents.begin();i != mComponents.end();++i) {
			ret->push_back(*i);
		}

		return ret;
	}

	template<class T>
	boost::shared_ptr<std::vector<boost::shared_ptr<T> > > getComponents() {
		boost::shared_ptr<std::vector<boost::shared_ptr<T> > > ret(new std::vector<boost::shared_ptr<T> >());
		for(boost::unordered_set<ComponentPtr>::const_iterator i = mComponents.begin();i != mComponents.end();++i) {
			const ComponentPtr& component = *i;
			boost::shared_ptr<T> typedComponent = boost::dynamic_pointer_cast<T>(component);
			if(typedComponent)
				ret->push_back(typedComponent);
		}

		return ret;
	}

	boost::shared_ptr<std::vector<boost::shared_ptr<Component> > > getComponents(const std::string& type) {
		boost::shared_ptr<std::vector<boost::shared_ptr<Component> > > ret(new std::vector<boost::shared_ptr<Component> >());
		for(boost::unordered_set<ComponentPtr>::const_iterator i = mComponents.begin();i != mComponents.end();++i) {
			const ComponentPtr& component = *i;
			if(component->getTypeName() == type)
				ret->push_back(component);
		}

		return ret;
	}

	template<class T>
	boost::shared_ptr<std::vector<boost::shared_ptr<T> > > getComponents(const std::string& type) {
		boost::shared_ptr<std::vector<boost::shared_ptr<Component> > > ret(new std::vector<boost::shared_ptr<Component> >());
		for(boost::unordered_set<ComponentPtr>::const_iterator i = mComponents.begin();i != mComponents.end();++i) {
			const ComponentPtr& component = *i;
			if(component->getTypeName() == type) {
				boost::shared_ptr<T> typedComponent = boost::dynamic_pointer_cast<T>(component);
				if(typedComponent)
					ret->push_back(typedComponent);
			}
		}

		return ret;
	}

	template<typename T>
	void removeComponent() {
		for(boost::unordered_set<ComponentPtr>::const_iterator i = mComponents.begin();i != mComponents.end();++i) {
			const ComponentPtr& component = *i;
			boost::shared_ptr<T> typedComponent = boost::dynamic_pointer_cast<T>(component);
			if(typedComponent) {
				typedComponent->parent.set(NULL);
				break;
			}
		}
	}

	void removeComponent(const std::string& type) {
		for(boost::unordered_set<ComponentPtr>::const_iterator i = mComponents.begin();i != mComponents.end();++i) {
			const ComponentPtr& component = *i;
			if(component->getTypeName() == type) {
				component->parent.set(NULL);
				break;
			}
		}
	}

	void removeAllComponents() {
		std::vector<ComponentPtr> temp;
		for(boost::unordered_set<ComponentPtr>::const_iterator i = mComponents.begin();i != mComponents.end();++i) {
			const ComponentPtr& component = *i;
			temp.push_back(component);
		}

		for(std::vector<ComponentPtr>::const_iterator i = temp.begin();i != temp.end();++i) {
			const ComponentPtr& component = *i;
			component->parent.set(NULL);
		}
	}

	template<typename T>
	void removeComponents() {
		std::vector<boost::shared_ptr<T> > temp;
		for(boost::unordered_set<ComponentPtr>::const_iterator i = mComponents.begin();i != mComponents.end();++i) {
			const ComponentPtr& component = *i;
			boost::shared_ptr<T> typedComponent = boost::dynamic_pointer_cast<T>(component);
			if(typedComponent)
				temp.push_back(typedComponent);
		}

		for(typename std::vector<boost::shared_ptr<T> >::const_iterator i = temp.begin();i != temp.end();++i) {
			const boost::shared_ptr<T>& component = *i;
			component->parent.set(NULL);
		}
	}

	void removeComponents(const std::string& type) {
		std::vector<ComponentPtr> temp;
		for(boost::unordered_set<ComponentPtr>::const_iterator i = mComponents.begin();i != mComponents.end();++i) {
			const ComponentPtr& component = *i;
			if(component->getTypeName() == type)
				temp.push_back(component);
		}

		for(std::vector<ComponentPtr>::const_iterator i = temp.begin();i != temp.end();++i) {
			const ComponentPtr& component = *i;
			component->parent.set(NULL);
		}
	}

	size_t getComponentCount() const {
		return mComponents.size();
	}

	template<class T>
	void apply(boost::function<void(boost::shared_ptr<T>)> callback) {
		for (boost::unordered_set<ComponentPtr>::iterator i = mComponents.begin();
				i != mComponents.end(); ++i) {
			boost::shared_ptr<T> ptr = boost::dynamic_pointer_cast<T>(*i);
			if(ptr)
				callback(ptr);
		}
	}

	template<class T>
	void apply(boost::function<void(T*)> callback) {
		for (boost::unordered_set<ComponentPtr>::iterator i = mComponents.begin();
				i != mComponents.end(); ++i) {
			T* ptr = dynamic_cast<T*>((*i).get());
			if(ptr)
				callback(ptr);
		}
	}

protected:
	boost::unordered_set<ComponentPtr> mComponents;

	void addComponentImpl(ComponentPtr component) {
		mComponents.insert(component);
	}

	void removeComponentImpl(ComponentPtr component) {
		boost::unordered_set<ComponentPtr>::iterator i = mComponents.find(component);
		if (i != mComponents.end())
			mComponents.erase(i);
	}

	void onRemoteMessage(RakNet::RakString msg, RakNet::BitStream& bits);
};
ZZLAB_TYPEDEF_SHARED_PTR(ComponentManager);

inline boost::shared_ptr<Component> Component::addComponent(
		const std::string& type, bool enable) const {
	ComponentPtr component(ComponentManager::createNew(type));
	component->parent.set(parent.get());
	component->enable.set(enable);

	return component;
}

} /* namespace zzogre */
#endif /* COMPONENTMANAGER_H_ */

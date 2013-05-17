/*
 * Component.h
 *
 *  Created on: 2013/4/1
 *      Author: SUCHEN
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>
#include <boost/unordered_map.hpp>

#include "zzlab/ZzLab.h"
#include "ActiveProperty.h"

#include <OgreSceneNode.h>

#include <RakNet/BitStream.h>

#include <rapidxml/rapidxml.hpp>

#define ZZOGRE_COMPONENT_TYPE(type) \
	public: \
	static const std::string& __typeName() { \
		static std::string ret = # type; \
		return ret; \
	} \
	static zzogre::Component* __createNew() { \
		return new type(); \
	} \
	virtual const std::string& getTypeName() { \
		return __typeName(); \
	}

#define ZZOGRE_COMPONENT_TYPE_NAME(type, name) \
	public: \
	static const std::string& __typeName() { \
		static std::string ret = name; \
		return ret; \
	} \
	static zzogre::Component* __createNew() { \
		return new type(); \
	} \
	virtual const std::string& getTypeName() { \
		return __typeName(); \
	}

#define ZZOGRE_COMPONENT_REGISTER(type) \
	static zzogre::ComponentRegister __register(type::__typeName().c_str(), type::__createNew)

namespace zzogre {

typedef char XmlChar;
typedef rapidxml::xml_document<XmlChar> XmlDocument;
typedef rapidxml::xml_node<XmlChar> XmlNode;
typedef rapidxml::xml_attribute<XmlChar> XmlAttribute;

typedef std::vector<Ogre::Any> MessageArguments;
ZZLAB_TYPEDEF_SHARED_PTR(MessageArguments);

class Component: public boost::enable_shared_from_this<Component> {
	friend class ComponentManager;

protected:
	explicit Component();

public:
	ActiveProperty<bool> enable;
	ActiveProperty<Ogre::SceneNode*> parent;

	virtual ~Component();

	virtual const std::string& getTypeName() = 0;

	template<class T>
	boost::shared_ptr<T> addComponent(bool enable = true) const {
		boost::shared_ptr<Component> component((Component*) new T);
		component->parent.set(parent.get());
		component->enable.set(enable);

		return boost::dynamic_pointer_cast<T>(component);
	}

	boost::shared_ptr<Component> addComponent(const std::string& type,
			bool enable = true) const;

	template<class T>
	boost::shared_ptr<T> addComponent(const std::string& type, bool enable =
			true) const {
		return boost::dynamic_pointer_cast<T>(addComponent(type, enable));
	}

	template<class T>
	boost::shared_ptr<T> getComponent() const;
	boost::shared_ptr<Component> getComponent(const std::string& type) const;
	template<class T>
	boost::shared_ptr<T> getComponent(const std::string& type) const;

	boost::shared_ptr<std::vector<boost::shared_ptr<Component> > > getAllComponents();
	template<class T>
	boost::shared_ptr<std::vector<boost::shared_ptr<T> > > getComponents();
	boost::shared_ptr<std::vector<boost::shared_ptr<Component> > > getComponents(const std::string& type);
	template<class T>
	boost::shared_ptr<std::vector<boost::shared_ptr<T> > > getComponents(const std::string& type);

	template<class T>
	void removeComponent();
	void removeComponent(const std::string& type);

	void removeAllComponents();
	template<class T>
	void removeComponents();
	void removeComponents(const std::string& type);

	size_t getComponentCount() const;

	template<class T>
	T* getAttachedObjectByName(const std::string& name) const;
	template<class T>
	T* getAttachedObject() const;

	template<class T>
	void apply(boost::function<void(boost::shared_ptr<T>)> callback);

	template<class T>
	void apply(boost::function<void(T*)> callback);

	template<class T>
	void applyAll(boost::function<void(boost::shared_ptr<T>)> callback);

	template<class T>
	void applyAll(boost::function<void(T*)> callback);

	void activeAll(bool enable = true);
	void activeAllInHierarchy(bool enable = true);

	template<class T0>
	void sendMessage(const std::string& msg, T0 t0) {
		MessageArgumentsPtr args(new MessageArguments());
		args->push_back(Ogre::Any(t0));

		onMessage(msg, *args);
	}

	template<class T0, class T1>
	void sendMessage(const std::string& msg, T0 t0, T1 t1) {
		MessageArgumentsPtr args(new MessageArguments());
		args->push_back(Ogre::Any(t0));
		args->push_back(Ogre::Any(t1));

		onMessage(msg, *args);
	}

	template<class T0, class T1, class T2>
	void sendMessage(const std::string& msg, T0 t0, T1 t1, T2 t2) {
		MessageArgumentsPtr args(new MessageArguments());
		args->push_back(Ogre::Any(t0));
		args->push_back(Ogre::Any(t1));
		args->push_back(Ogre::Any(t2));

		onMessage(msg, *args);
	}

	template<class T0, class T1, class T2, class T3>
	void sendMessage(const std::string& msg, T0 t0, T1 t1, T2 t2, T3 t3) {
		MessageArgumentsPtr args(new MessageArguments());
		args->push_back(Ogre::Any(t0));
		args->push_back(Ogre::Any(t1));
		args->push_back(Ogre::Any(t2));
		args->push_back(Ogre::Any(t3));

		onMessage(msg, *args);
	}

	template<class T0, class T1, class T2, class T3, class T4>
	void sendMessage(const std::string& msg, T0 t0, T1 t1, T2 t2, T3 t3,
			T4 t4) {
		MessageArgumentsPtr args(new MessageArguments());
		args->push_back(Ogre::Any(t0));
		args->push_back(Ogre::Any(t1));
		args->push_back(Ogre::Any(t2));
		args->push_back(Ogre::Any(t3));
		args->push_back(Ogre::Any(t4));

		onMessage(msg, *args);
	}

	template<class T0, class T1, class T2, class T3, class T4, class T5>
	void sendMessage(const std::string& msg, T0 t0, T1 t1, T2 t2, T3 t3, T4 t4,
			T5 t5) {
		MessageArgumentsPtr args(new MessageArguments());
		args->push_back(Ogre::Any(t0));
		args->push_back(Ogre::Any(t1));
		args->push_back(Ogre::Any(t2));
		args->push_back(Ogre::Any(t3));
		args->push_back(Ogre::Any(t4));
		args->push_back(Ogre::Any(t5));

		onMessage(msg, *args);
	}

	template<class T0, class T1, class T2, class T3, class T4, class T5,
			class T6>
	void sendMessage(const std::string& msg, T0 t0, T1 t1, T2 t2, T3 t3, T4 t4,
			T5 t5, T6 t6) {
		MessageArgumentsPtr args(new MessageArguments());
		args->push_back(Ogre::Any(t0));
		args->push_back(Ogre::Any(t1));
		args->push_back(Ogre::Any(t2));
		args->push_back(Ogre::Any(t3));
		args->push_back(Ogre::Any(t4));
		args->push_back(Ogre::Any(t5));
		args->push_back(Ogre::Any(t6));

		onMessage(msg, *args);
	}

	void save(XmlNode* node);
	void load(XmlNode* node);

protected:
	// state events
	boost::function<void()> handleEnable;
	boost::function<void()> handleDisable;

	// serialize events
	virtual void onSave(XmlNode* node);
	virtual void onLoad(XmlNode* node);

	void enableMessage(const std::string& msg,
			boost::function<void(const MessageArguments&)> func) {
		mMassageMap[msg] = func;
	}

private:
	boost::unordered_map<std::string,
			boost::function<void(const MessageArguments&)> > mMassageMap;
	void onMessage(const std::string& msg, const MessageArguments& args) {
		if (!enable.get())
			return;

		boost::unordered_map<std::string,
				boost::function<void(const MessageArguments&)> >::iterator i =
				mMassageMap.find(msg);
		if (i == mMassageMap.end())
			return;

		(*i).second(args);
	}

	void onEnableModified(bool& a, const bool& b);
	void onParentModified(Ogre::SceneNode*& a, Ogre::SceneNode* const & b);
	void onPostRemove();

	bool mAwake;
};
ZZLAB_TYPEDEF_SHARED_PTR(Component);
typedef std::vector<boost::shared_ptr<Component> > Components;
ZZLAB_TYPEDEF_SHARED_PTR(Components);

typedef Component* (*ComponentCreator)();

class ComponentRegister {
public:
	ComponentRegister(const char* name, ComponentCreator creator);
};

} /* namespace zzogre */
#endif /* COMPONENT_H_ */

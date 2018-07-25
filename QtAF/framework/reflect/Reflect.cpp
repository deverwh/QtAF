#include "Reflect.h"

ObjectFactory::ObjectFactory()
{

}

ObjectFactory::~ObjectFactory()
{

}

Reflector::~Reflector()
{
	for(auto it = m_objectFactories.begin(); it != m_objectFactories.end(); ++it){
		delete it->second;
	}
	m_objectFactories.clear();
}

Reflector & Reflector::instance()
{
	static Reflector reflector;
	return reflector;
}

void Reflector::registerFactory(const std::string &className, ObjectFactory *objectFactory)
{
	auto it = m_objectFactories.find(className);
	if (it == m_objectFactories.end()){
		m_objectFactories[className] = objectFactory;
	}else{
		// ÒÑ´æÔÚ
	}
}

void * Reflector::reflect(const std::string &className)
{
	auto it = m_objectFactories.find(className);
	if (it != m_objectFactories.end()){
		return it->second->instance();
	}
	return nullptr;
}

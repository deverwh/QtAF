#pragma once

#include <string>
#include <map>

// 对象工厂抽象类，用来生成对象实例
class ObjectFactory{
public:
	ObjectFactory();
	virtual ~ObjectFactory();
	virtual void *instance() = 0;
};

// 反射器，用来管理（对象名，对象工厂）的映射关系
class Reflector{
public:
	~Reflector();

	static Reflector &instance();
	void registerFactory(const std::string &className, ObjectFactory *objectFactory);
	void *reflect(const std::string &className);

protected:
	Reflector(){}
	Reflector(const Reflector &);
	Reflector operator=(const Reflector &);

private:
	std::map<std::string, ObjectFactory *> m_objectFactories;
};

// 需要进行反射的类，需要在cpp文件中进行反射声明
#define REFLECT(name) \
class ObjectFactory_##name : public ObjectFactory {\
public:\
	ObjectFactory_##name(){}\
	virtual ~ObjectFactory_##name(){}\
	void *instance(){\
		return new name();\
	}\
};\
class Register_##name{\
public:\
	Register_##name(){\
		Reflector::instance().registerFactory(#name, new ObjectFactory_##name());\
	}\
};\
Register_##name register_##name; 
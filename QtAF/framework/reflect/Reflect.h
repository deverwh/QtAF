#pragma once

#include <string>
#include <map>

// ���󹤳������࣬�������ɶ���ʵ��
class ObjectFactory{
public:
	ObjectFactory();
	virtual ~ObjectFactory();
	virtual void *instance() = 0;
};

// ���������������������������󹤳�����ӳ���ϵ
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

// ��Ҫ���з�����࣬��Ҫ��cpp�ļ��н��з�������
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
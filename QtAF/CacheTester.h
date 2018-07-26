#pragma once

#include "framework/cache/Cache.h"
#include <QObject>
#include <QDebug>

class ClassA : public QObject{
public:
	ClassA(QObject *parent = nullptr) : QObject(parent){ qDebug() << __FUNCTION__; }

	void doWork(){
		qDebug() << __FUNCTION__;
	}
};

class CacheTester{
public:
	void runTest(){
		ClassA *obj = reinterpret_cast<ClassA *>(Cache::retrieve("ClassA"));
		if (obj == nullptr){
			obj = new ClassA();
			Cache::insert("ClassA", obj);
		}
		obj->doWork();
	}
};
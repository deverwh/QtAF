#pragma once

#include <QObject>

__interface IProductFactory{
public:
	virtual void *getProduct() = 0;
};
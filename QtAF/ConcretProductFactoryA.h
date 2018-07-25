#pragma once

#include "IProductFactory.h"

class ConcretProductFactoryA : public IProductFactory
{
public:
	virtual ~ConcretProductFactoryA(void);

	virtual void * getProduct();
};


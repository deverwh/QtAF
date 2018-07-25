#include "ConcretProductFactoryA.h"
#include "framework/reflect/Reflect.h"

ConcretProductFactoryA::~ConcretProductFactoryA(void)
{
}

void * ConcretProductFactoryA::getProduct()
{
	static int p = 123;
	return &p;
}

REFLECT(ConcretProductFactoryA)
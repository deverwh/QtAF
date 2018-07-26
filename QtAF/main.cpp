#include <QtGui/QApplication>

#include "framework/classfactory/ClassFactory.h"
#include "IProductFactory.h"

#include "CacheTester.h"

#include <QDebug>

int main(int argc, char *argv[])
{

	auto factory = reinterpret_cast<IProductFactory *>(QtAF::ClassFactory::getFactory("ProductFactory"));
	auto p = factory->getProduct();

	qDebug() << *(int *)(p);

	// CacheTest
// 	CacheTester cacheTester;
// 	cacheTester.runTest();
// 	cacheTester.runTest();
}

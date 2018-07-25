#include <QtGui/QApplication>

#include "framework/classfactory/ClassFactory.h"
#include "IProductFactory.h"

#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	auto factory = reinterpret_cast<IProductFactory *>(QtAF::ClassFactory::getFactory("ProductFactory"));
	auto p = factory->getProduct();

	qDebug() << *(int *)(p);

	return a.exec();
}

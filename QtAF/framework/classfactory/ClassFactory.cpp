#include "ClassFactory.h"
#include "framework/reflect/Reflect.h"
#include <QtXml>

void * QtAF::ClassFactory::getFactory(const QString &factoryName)
{
	void *factory = nullptr;

	// ∂¡»°≈‰÷√Œƒº˛
	QDomDocument doc;
	QFile file("config.xml");
	if (!file.open(QIODevice::ReadOnly)) return nullptr;
	if (!doc.setContent(&file)){
		file.close();
		return nullptr;
	}

	file.close();
	auto xmlExplainNode = doc.firstChild();
	auto rootElement = doc.documentElement();
	auto frameworkElement = rootElement.firstChildElement("Framework");
	if (!frameworkElement.isNull()){
		auto classFactoryElement = frameworkElement.firstChildElement("ClassFactory");
		if (!classFactoryElement.isNull()){
			auto classElement = classFactoryElement.firstChildElement("Factory");
			while (!classElement.isNull()){
				auto nameAttr = classElement.attribute("name", "");
				if (0 == nameAttr.compare(factoryName, Qt::CaseInsensitive)){
					auto typeAttr = classElement.attribute("type", "");
					if (!typeAttr.isEmpty()){
						 return Reflector::instance().reflect(typeAttr.toStdString());
					}	
				}
				classElement = classElement.nextSiblingElement("Class");
			}
		}
	}
	return factory;
}

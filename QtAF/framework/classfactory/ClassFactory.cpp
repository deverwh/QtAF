#include "ClassFactory.h"
#include "framework/reflect/Reflect.h"
#include <QtXml>
#include <tinyxpath/tinyxml.h>
#include <tinyxpath/xpath_static.h>

void * QtAF::ClassFactory::getFactory(const QString &factoryName)
{
	void *factory = nullptr;

	// Ê¹ÓÃtinyxml
	TiXmlDocument doc("config.xml");
	bool isOk = doc.LoadFile(TIXML_ENCODING_UTF8);
	auto rootElement = doc.RootElement();
	auto n = rootElement->Value();
	// XPath£º/Configuration/Framework/ClassFactory/Factory[@name='factoryName']
	auto xpath = QString("/Configuration/Framework/ClassFactory/Factory[@name='%1']").arg(factoryName);
	auto factoryNode = TinyXPath::XNp_xpath_node(rootElement, xpath.toStdString().c_str());
	if (factoryNode != nullptr){
		auto className = factoryNode->FirstChild()->Value();
		return Reflector::instance().reflect(className);
	}

	return factory;
}

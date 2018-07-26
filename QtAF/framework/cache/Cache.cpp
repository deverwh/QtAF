#include "Cache.h"
#include <QHash>
#include <tinyxpath/tinyxml.h>
#include <QUuid>

static QHash<QString, QObject *> objectTable;
static TiXmlElement *objectXmlMap = new TiXmlElement("Cache");

TiXmlNode *createNode(const QString &xpath);

void Cache::insert(const QString &xpath, QObject *obj)
{
	auto newXpath = xpath;
	int separator = newXpath.lastIndexOf("/");
	// 获取组名
	auto group = newXpath.left(separator);
	// 获取原始名
	auto element = newXpath.right(separator + 1);

 	auto groupNode = objectXmlMap->FirstChild(group.toStdString().c_str());
	if (groupNode == nullptr){
		// 需要做线程同步
		groupNode = createNode(group);
	}
	// 获取GUID
	auto objectId = QUuid::createUuid().toString();
	auto objectElement = new TiXmlElement(element.toStdString().c_str());
	objectElement->SetAttribute("objectId", objectId.toStdString().c_str());
	groupNode->LinkEndChild(objectElement);
	objectTable.insert(objectId, obj);
}

QObject * Cache::retrieve(const QString &key)
{
	return objectTable.value(key, nullptr);
}

TiXmlNode *createNode(const QString &xpath)
{
	return nullptr;
}
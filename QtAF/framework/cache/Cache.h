#pragma once

#include <QObject>

class Cache
{
public:
	static void insert(const QString &xpath, QObject *obj);
	static QObject *retrieve(const QString &xpath);	
};
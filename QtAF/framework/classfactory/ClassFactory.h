#pragma once

// 类工厂服务类
#include <QMap>

namespace QtAF{

	class ClassFactory
	{
	public:
		static void *getFactory(const QString &factoryName);
	};
}
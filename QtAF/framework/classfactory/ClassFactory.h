#pragma once

// �๤��������
#include <QMap>

namespace QtAF{

	class ClassFactory
	{
	public:
		static void *getFactory(const QString &factoryName);
	};
}
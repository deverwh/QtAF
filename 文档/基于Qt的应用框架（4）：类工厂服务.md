# 目标 #

----------
- 减少“指定具体类”的要求

通常我们按以下方式创建对象，并调用其服务：
	
	BusinessObject bo = new BusinessObject();
	bo.doWork();

由于BusinessObject是一个具体类，以后想用其他类来代替它，将不得不在整个应用中替换该类名和变量类型。如果要访问的方法是属于具体类时，完全消除具体类的名字是不可能的，但是，应尽量减少对具体类的直接引用。

- 为开发者隐藏对象创建的复杂性

有些类的创建需要额外的信息，如数据库连接对象的创建，需要用户名和密码等，我们希望应用开发者专注于业务逻辑，而不是那些基础设施级的信息。借助类工厂和配置文件，能用一行代码创建该对象

	IBusinessObject bo = ClassFactoryService.getBusinessObject().getComplexBusinessObject();

- 无论是否是远程对象，使对象的创建不受位置、版本和区域性的限制
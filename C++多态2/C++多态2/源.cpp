
//  编译器不得不给出构造函数的4个场景
// 1. 在A类中有缺省的构造函数    在B类中没有构造函数但是含有A类对象
//
// 2. 继承：
//    在A类中有缺省的构造函数    之后B类继承于A类，没有显示定义构造函数，
//    当创建B类对象时，要使得B类对象创建完整就必须调用A类的构造函数来初始化A类的那一部分。
//    初始化A类对象构造函数在B类的初始化列表处调用
//
//3.  虚拟继承：
//    A类没有显示定义，但是B类虚拟继承于A，之后在构造B类的对象时，会创建两个参数一个是前四个字节是对象空间首地址，一个是1表示是虚拟继承
//    通过前四个字节所找到映射的虚基表，通过偏移量来找到基类对象的位置。
//    对象模型：基类对象在下，子类对象在上。
//
//4.  带有虚函数的类，
//     创建好对象，前四个字节存地址
//     每多一个虚函数,	前四个字节的地址所映射的表中就增加一个地址占四个字节--->虚表指针
//     基类：基类的虚函数按照其在类中的声明次序存放在虚表中。


//带有虚函数的类，不继承

#if 0
#include<iostream>
using namespace std;

class Base
{
public:
	virtual void Test()
	{
		cout << "Base::Test()" << endl;
	}

	virtual void Test1()
	{
		cout << "Base::Test1()" << endl;
	}
public:
	int _b;
};

typedef void(*FuncPtr)();

void Print(Base& b)
{
	cout << sizeof(b) << endl;
	FuncPtr* ptr = (FuncPtr*)(*(int*)&b);
	while (*ptr)
	{
		(*ptr++)();
	}
}

int main()
{
	Base b;
	Print(b);

	system("pause");
	return 0;
}
#endif

//******************************************************************************
//派生类/子类：
//******************************************************************************

//子类是将基类的虚函数拷一份。
//因为：在对象的前四个字节即指向虚表的地址和基类对象的前四个字节内容不一样

// 如果子类对基类虚函数进行重写，
//先拷一份基类的，--->
//子类对那个基类虚函数重写，就用自己重写的虚函数替换虚表中相同偏移位置的位置。--->否则就继续用拷贝的基类的虚函数的地址。

//对于派生类自己新增加的虚函数跟在派生类虚表的最后（跟在继承的基类的虚表的后面）

#if 0

#include<iostream>
using namespace std;

class Base
{
public:
	virtual void Test()
	{
		cout << "Base::Test()" << endl;
	}

	virtual void Test1()
	{
		cout << "Base::Test1()" << endl;
	}
public:
	int _b;
};


typedef void(*FuncPtr)();


class children : public Base
{
	virtual void Test4()
	{
		cout << "children::Test4()" << endl;
	}

	virtual void Test1()
	{
		cout << "children::Test1()" << endl;
	}

	virtual void Test5()
	{
		cout << "children::Test5()" << endl;
	}
private:
	int _b = 10;
};

void PrintVirtualFunc(Base& b)
{
	FuncPtr* ptr = (FuncPtr*)(*(int*)&b);
	while (*ptr)
	{
		cout << "ptr = " << ptr << endl;
		(*ptr++)();
	}
}

int main()
{
	cout << sizeof(children) << endl;

	Base b;
	b._b = 3;
	//FuncPtr* ptr = (FuncPtr*)(*(int*)&b);
	////第一个虚函数的地址
	//(*ptr)();
	//ptr++;
	////第二个虚函数的地址
	//(*ptr)();
	cout << "Base:" << endl;
	PrintVirtualFunc(b);

	children c;
	cout << "children:" << endl;
	PrintVirtualFunc(c);
	system("pause");
	return 0;
}

#endif

//多继承的问题
#if 1

#include<iostream>
using namespace std;

class Base1
{
public:
	virtual void TestFunc1()
	{
		cout << "Base1::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base1::TestFunc2()" << endl;
	}
public:
	int b1;
};

class Base2
{
public:
	virtual void TestFunc3()
	{
		cout << "Base2::TestFunc3()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "Base2::TestFunc4()" << endl;
	}
public:
	int b2;
};

class children : public Base1, public Base2
{
	virtual void TestFunc2()
	{
		cout << "children::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "children::TestFunc3()" << endl;
	}

	virtual void TestFunc5()
	{
		cout << "children::TestFunc5()" << endl;
	}
public:
	int c;
};

typedef void(*FuncPtr)();

void PrintBase1(Base1& c)
{
	FuncPtr* FuncptrS = (FuncPtr*)(*(int*)&c);
	while (*FuncptrS)
	{
		cout << "FuncptrS = " << FuncptrS << " ";
		(*FuncptrS++)();

	}
}

void PrintBase2(Base2& c)
{
	FuncPtr* FuncptrS = (FuncPtr*)(*(int*)&c);
	while (*FuncptrS)
	{
		cout << "FuncptrS = " << FuncptrS << " ";
		(*FuncptrS++)();

	}
}

void Printchildren(children& c)
{
	FuncPtr* FuncptrS = (FuncPtr*)(*(int*)&c);
	while (*FuncptrS)
	{
		cout << "FuncptrS = " << FuncptrS << " ";
		(*FuncptrS++)();

	}
}
int main()
{
	cout << sizeof(children) << endl;//20
	children c;
	children c1;
	c.b1 = 1;
	c.b2 = 2;
	c.c = 3;

	cout << "c" << ":" << endl;
	cout << "PrintBase1(c) : " << endl;
	PrintBase1(c);
	cout << "PrintBase2(c) : " << endl;
	PrintBase2(c);
	//多继承时c中的虚拟函数放在第一张虚表的后面
	cout << "Printchildren(c1) : " << endl;
	Printchildren(c);
	cout << endl;

	cout << "c1" << ":" << endl;
	cout << "PrintBase1(c1) : " << endl;
	PrintBase1(c1);
	cout << "PrintBase2(c1) : " << endl;
	PrintBase2(c1);
	//多继承时c中的虚拟函数放在第一张虚表的后面
	cout << "Printchildren(c1) : " << endl;
	Printchildren(c1);

	system("pause");
	return 0;
}
#endif

//抽象类
#if 0
#include<iostream>
using namespace std;

class Abstract
{
public:
	virtual void AbstrS() = 0;

	void Print()
	{
		cout << "Abstract::AbstrS()" << endl;
	}
};

class children : public Abstract
{
public:
	virtual void AbstrS()
	{
		cout << "children::AbstrS()" << endl;
	}
};

int main()
{
	//抽象类不能被实例化
	//Abstract a;

	children c;
	c.AbstrS();
	c.Print();
	system("pause");
	return 0;
}
#endif
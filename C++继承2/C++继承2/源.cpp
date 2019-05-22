#if 0
#include<iostream>
using namespace std;

//编译器生成的构造函数---默认的
//无参的和缺省的 ---缺省

//******************************************************************************//
//除了全缺省和默认构造，其它的构造函数必须在子类构造函数初始化列表进行初始化****//
//******************************************************************************//
class Base
{
public:
	Base(int data = 10)
		:_data(data)
	{}
	Base(const Base& b)
		:_data(b._data)
	{
		cout << "Base::Base(const Base& b)" << endl;
	}
	Base& operator=(Base& s)
	{
		cout << "Base operator=(Base& s)" << endl;
		return *this;
	}
	~Base()
	{
		cout << "Base::~Base()" << endl;
	}
public:
	int _data;
};
class children : public Base
{
public:
	children()
		:Base(10)
		,_ChData(66)
	{}
	children(const children& C)
		:Base(C)
	{
		cout << "children(const children& C)" << endl;
	}
	children& operator=(children& s)
	{
		Base::operator=(s);
		cout << "children operator=(children& s)" << endl;
		return *this;
	}
	~children()
	{
		cout << "children::~children()" << endl;
	}
private:
	int _ChData;
};
int main()
{
	children c1;
	//children c2(c1);

	//c2 = c1;
	//在验证子类销毁时是否会调用父类析构函数，要将pause去掉
	system("pause");
	return 0;
}

#endif


#if 0
#include<iostream>
using namespace std;

//设计一个类使得它不能被继承
//两种方法：
//         1.将父类的构造函数给成私有化
//         2.在父类类名后加final表明禁止继承（C++11）
class BASE //final
{
public:
	static BASE GetBASE()
	{
		return BASE();
	}
	void SetInfo(int data)
	{
		_data = data;
	}
	void PrintBASE()
	{
		cout << "BASE::_data = " << _data << endl;
	}
private:
//public:
	BASE()
	{}
private:
	int _data;
};

class CHILD : public BASE
{};

int main()
{
	//CHILD c;
	BASE b = BASE::GetBASE();
	b.SetInfo(6);
	b.PrintBASE();
	//CHILD c;
	system("pause");
	return 0;
}

#endif


#if 0
//友元关系不能被继承

#include<iostream>
using namespace std;

class Base
{
public:
	friend  void TestFunc();

	void Print()
	{
		cout << "Base::_ChData = " << _data << endl;
	}
private:
	int _data;
};

class CHILD : public Base
{
public:
	void PrintCH()
	{
		cout << "CHILD::_ChData = " << _ChData << endl;
	}
protected:
//public:
	int _ChData;
};

void TestFunc()
{
	Base B;
	B._data = 10;
	B.Print();

	//不可以访问S的成员变量
	CHILD S;
	S._ChData = 10;
	S.PrintCH();
}
int main()
{
	TestFunc();
	system("pause");
	return 0;
}
#endif


#if 0
//类中静态成员可以被继承
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		_count++;
	}
	Base(Base& b)
	{
		_count++;
	}
protected:
	static int _count;
};

int Base::_count = 0;

class CHILD : public Base
{
public:
	void PrintBase()
	{
		cout << "_count = " << _count << endl;
	}
};

void TestFunc()
{
	CHILD C;
	C.PrintBase();
}

int main()
{
	TestFunc();
	return 0;
}

#endif

//多继承
//在内存中继承的成员变量顺序与继承的父类的顺序一样
//不同继承体系下---对象的模型（对象中成员变量在内存中的布局情况）

//菱形继承

#if 0
#include<iostream>
using namespace std;

class A
{
protected:
	int _a;
};

class B1 : public A
{
	void SetAInfo(int a)
	{
		_a = a;
	}
protected:
	int _b1;
};

class B2 : public A
{
public:
	void SetAInfo(int a)
	{
		_a = a;
	}
protected:
	int _b2;
};

class C : public B2, public B1
{
public:
	void SetAInfo(int a1, int a2)
	{
		B1::_a = a1;
		B2::_a = a2;
	}
	void SetAB1Info(int a1)
	{
		B1::_a = a1;
	}
	void SetAB2Info(int a2)
	{
		B2::_a = a2;
	}

	void PrintSizeof()
	{
		cout << "sizeof(C) = " << sizeof(C) << endl;
	}

	void PrintAB1B2a()
	{
		cout << "A::_a = " << A::_a << endl;
		cout << "B1::_a = " << B1::_a << endl;
		cout << "B2::_a = " << B2::_a << endl;
	}
protected:
	int _c;
};

//不能再c中直接去设置a的成员的值，存在二义性，务必要区分是设置B1B2中的哪一个
//方法一：（加类名作用域限定符区分），明确是哪一份（根本上没有解决）只存一份就可以了
//方法二：菱形虚拟继承  --- > 可以解决菱形继承中存在的二义性问题
int main()
{

	C c;
	c.PrintSizeof();
	c.SetAInfo(2, 6);
	//c.SetAB2Info(8);
	//c.SetAB1Info(1);
	//在顶级父类中的成员变量的值取决于第一个继承的类中设置该成员的值
	c.PrintAB1B2a();
	system("pause");
	return 0;
}

#endif


//虚拟继承  class B : virtual public A
//在继承方式前加关键字virtual
//虚拟继承与普通继承的区别：
//1.对象模型倒立（成员变量在内存中基类成员在最下面。
//2.对象中多了四个字节--最上面是编译器自己维护，最上面是编译器自己维护（当成员都是int）4个字节）
//3.编译器为派生类生成默认的构造函数--2个参数  空间首地址 1代表虚拟继承的标志

#if 0
#include<iostream>
using namespace std;

class A
{
public:
	int _a;
};

class B : virtual public A
{
public:
	int _b;
};

int main()
{
	
	B s;
	s._a = 1;//1.取对象前四个字节的内容为地址
	         //--->2.在这个地址上+4取到里面的内容data
	         //--->3.从对象起始地址向后偏移data和字节将1赋值给基类成员_a
	//虚基表  第一个字节存偏移当前类的字节0，第二个字节存基类偏移量
	s._b = 2;
	

	return 0;
}

#endif

//虚拟继承解决菱形继承二义性问题

#if 1
#include<iostream>
using namespace std;

class A
{
public:
	void PrintA()
	{
		cout << "&A = " << this << endl;
		cout << "&A::_a = " << &(*this)._a << endl;
	}
public:
	int _a;
};

class B1 :  virtual public A
{
public:
	void PrintB1()
	{
		cout << "&B1 = " << this << endl;
		cout << "&B1::_a = " << &(*this)._a << endl;
	}
public:
	int _b1;
};

class B2 : virtual public A
{
public:
	void PrintB2()
	{
		cout << "&B2 = " << this << endl;
		cout << "&B2::_a = " << &(*this)._a << endl;
	}
public:
	int _b2;
};

class C : public B2, public B1
{
	
public:
	int _c;
};


int main()
{
	C c;
	cout << "sizeof(C) = " << sizeof(C) << endl;  //24
	c._a = 5;
	c._b1 = 6;
	c._b2 = 7;
	c._c = 10;
	c.PrintA();
	c.PrintB1();
	c.PrintB2();

	system("pause");
	return 0;
}

#endif

//#include<iostream>
//using namespace std;


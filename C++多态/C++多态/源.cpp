
//多态条件
//1.在基类中该函数必须为虚函数（即在该函数前加上virtual关键字）
//2.在子类中必须对这个函数进行重写，即与这个函数原型一样
//（返回值类型，参数列表，函数名字必须一致(virtual可加可不加（但确保不再被继承）)）只不过是实现另一个功能
// 重写例外：
//          1.返回值类型有例外：
//                    协变：基类虚函数返回基类对象的指针或者引用
//                          派生类虚函数返回派生类对象的指针或者引用
//          2.析构函数例外


#if 0
#include<iostream>
using namespace std;

class Base
{
public:
	virtual void Test1()
	{
		cout << "Base::Test1()" << endl;
	}
};

class children : public Base
{
public:
	virtual void Test1()
	{
		cout << "children::Test1()" << endl;
	}
};

void TestFunc(Base& b)
{
	b.Test1();
}
int main()
{
	Base b;
	children c;

	TestFunc(b);
	TestFunc(c);

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

class Base
{
public:
	//0.多态
	virtual void Test()
	{
		cout << "Base::Test()" << endl;
	}

	//1.当基类丢失虚拟关键字时验证是不是多态
	void Test1()
	{
		cout << "Base::Test1()" << endl;
	}

	//没有构成重写
	//2.当函数参数列表不同时验证
	virtual void Test2()
	{
		cout << "Base::Test2()" << endl;
	}
	//没有构成重写
	//3.当函数名不同时验证
	virtual void Test3()
	{
		cout << "Base::Test3()" << endl;
	}

	//4.返回值类型不同验证 --->此时在对应的派生类中该函数将报错
	virtual  int Test4()
	{
		cout << "Base::Test3()" << endl;
		return 0;
	}
};

class children : public Base
{
public:
	virtual void Test()
	{
		cout << "children::Test()" << endl;
	}

	virtual void Test1()
	{
		cout << "children::Test1()" << endl;
	}

	virtual void Test2(char)
	{
		cout << "children::Test2()" << endl;
	}
	virtual void Test3S()
	{
		cout << "children::Test3()" << endl;
	}

	//报错  说与基类中对应函数既不相同也不协变
	//virtual  void Test4()
	//{
	//	cout << "Base::Test3()" << endl;
	//}
};

void TestFunc(Base& b)
{
	b.Test();
	b.Test1();
	b.Test2();
	b.Test3();
}
int main()
{
	Base b;
	children c;

	TestFunc(b);
	TestFunc(c);

	system("pause");
	return 0;
}
#endif


//协变

#if 0

#include<iostream>
using namespace std;

class Base
{
public:
	//返回该类型的指针
	virtual Base* Test1()
	{
		cout << "Base::Test1()" << endl;
		return nullptr;
	}

	//返回该类型的引用
	virtual Base& Test2()
	{
		cout << "Base::Test1()" << endl;
		return *this;
	}
};

class children : public Base
{
public:
	//协变---返回值的类型不同
	virtual children* Test1()
	{
		cout << "children::Test1()" << endl;
		return nullptr;
	}

	virtual children& Test2()
	{
		cout << "children::Test1()" << endl;
		return *this;
	}
};

void TestFunc(Base& b)
{
	b.Test1();
	b.Test2();
}
int main()
{
	Base b;
	children c;

	TestFunc(b);
	TestFunc(c);

	system("pause");
	return 0;
}
#endif

//验证析构函数是否构成多态

#if 0

#include<iostream>
using namespace std;

class Base
{
public:
	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}
};

class children : public Base
{
public:
	~children()
	{
		cout << "children::~children()" << endl;
	}
};

void TestFunc(Base& b)
{
	b.~Base();
}

int main()
{
	Base* Bptr = new children;
	delete Bptr;

	system("pause");
	return 0;
}
#endif

//当将重写的函数给成私有，可不可以？
//可以， 虽然子类中将重写的函数给成了私有的，但是在编译期间发现时基类的调用，而基类的被重写函数是公有的。
//在程序运行时，进行子类的调用时，发现被重写就会调用自己的函数
//多态中，成员访问权限可以不一样，基类必须公有，子类随便
#if 0
#include<iostream>
using namespace std;

class Base
{
public:
	virtual void Test1()
	{
		cout << "Base::Test1()" << endl;
	}
};

class children : public Base
{
private:
	virtual void Test1()
	{
		cout << "children::Test1()" << endl;
	}
};

void TestFunc(Base& b)
{
	b.Test1();
}

int main()
{
	Base b;
	children c;
	TestFunc(b);
	TestFunc(c);

	system("pause");
	return 0;
}
#endif



//最好将基类的析构函数给成虚函数
//否则如果在派生类中在堆上申请了一块资源就可能造成内存泄漏

//当将基类析构函数不设置为虚函数时，不调用派生类的析构函数来释放资源
#if 1
#include<iostream>
using namespace std;

class Base
{
public:
	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}
};

class children : public Base
{
public:
	children()
	{
	     ptr = new int;
	}
	~children()
	{
		if (ptr)
		{
			delete ptr;
		}
		cout << "children::~children()" << endl;
	}
private:
	int* ptr;
};

void TestFunc(Base& b)
{
	b.~Base();
}


int main()
{
	//变量有两种类型：
	//     静态类型：--->变量声明的类型如Bptr的Base*，在编译期间就可以确定
	//     动态类型：--->实际指向的类型 如Bptr指向children类型，代码运行起来确定
	//如果多态条件没有满足，使用对象的静态类型来调用虚函数 ----基类的虚函数
	//如果多态条件满足，就使用对象的动态类型来调用虚函数， ----先去调用当前对象所指向的类型的函数。
	Base* Bptr = new children;
	delete Bptr;

	system("pause");
	return 0;
}

#endif

//override关键字（C++11）用来说明对该函数进行重写，防止重写时函数名写错等情况
//只能放在派生类的虚函数后面

//final : 1.修饰类，说明该类不能被继承
//        2.修饰虚函数---说明在此类后面的子类中不能将这个函数再被重写

#if 0
#include<iostream>
using namespace std;

class Base
{
public:
	virtual void Test1()
	{
		cout << "Base::Test1()" << endl;
	}
};

class children : public Base
{
public:
	virtual void Test1()override
	{
		cout << "children::Test1()" << endl;
	}
};

void TestFunc(Base& b)
{
	b.Test1();
}
int main()
{
	Base b;
	children c;

	TestFunc(b);
	TestFunc(c);

	system("pause");
	return 0;
}

#endif

#include<iostream>
using namespace std;
#include<crtdbg.h>

#if 0
int main()
{
	//new后跟所申请空间的类型
	//申请单个元素空间可以初始化
	//申请一段连续空间不能初始化
	int* ptr = new int;
	int* ptr1 = new int(0);
	int* ptr2 = new int[100];

	delete ptr;
	delete ptr1;
	delete[] ptr2;
	system("pause");
	return 0;
}

#endif

//什么是内存泄漏？如何检测？

#if 0

class Creat
{
public:
	Creat()
	{
		cout << "构造函数" << this << endl;
		_t = 0;
		_ptr = (int*)malloc(sizeof(int));
	}
	~Creat()
	{
		cout << "析构函数" << this << endl;
		free(_ptr);
		_ptr = nullptr;
	}
private:
	int* _ptr;
	int _t;
};

//自定义类型：
//malloc：只是将空间动态开辟成功，不调用构造函数初始化空间
//free：只负责将空间释放掉
//new：将空间开辟成功，还需要调用构造函数完成空间的初始化
//delete：先调用析构函数释放对象中的资源，再释放对象所占的资源
int main()
{
	//此处不能用delete去释放，因为自定义类型malloc创建对象空间时，对象里面的_ptr指针并未申请空间。
	//（并未调用构造函数，此时不是个对象，只是和对象空间一样大）
	//而调用delete去释放它会清理对象的资源，当释放_ptr时会崩溃。

	//malloc只是创建一个和对象一样大的空间
	Creat* ptr = (Creat*)malloc(sizeof(Creat));
	free(ptr);
	//delete(ptr);

	//new创建的是对象
	//Creat* ptr2 = new Creat;
	//free(ptr2);
	//_CrtDumpMemoryLeaks();
	Creat* ptr1 = new Creat[10];
	//free(ptr1);
	//delete ptr1;//只清理了第一个对象的资源后崩溃。
    delete[] ptr1;//从最后一个开始清理资源往前清理。
	system("pause");
	return 0;
}
#endif

#if 0
class Creat
{
public:
	Creat()
	{
		cout << "构造函数" << this << endl;
		_t = 0;
		_ptr = (int*)malloc(sizeof(int));
	}
	~Creat()
	{
		cout << "析构函数" << this << endl;
		free(_ptr);
		_ptr = nullptr;
	}
private:
	int* _ptr;
	int _t;
};

//重写创造对象空间
void* operator new(size_t size, const char* FileName, const char* FuncName,int LineNo)
{
	cout << FileName << ":" << FuncName << ":" << LineNo << ":" << size << endl;
	return malloc(size);
}

#define new new(__FILE__, __FUNCTION__, __LINE__)
int main()
{
	Creat* pt = new Creat;
	system("pause");
	delete pt;
	return 0;
}
#endif

#if 0
class Creat
{
public:
	Creat()
	{
		cout << "构造函数" << this << endl;
	    _t = 0;
	   _ptr = (int*)malloc(sizeof(int));
	}
	~Creat()
	{
		cout << "析构函数" << this << endl;
		free(_ptr);
		_ptr = nullptr;
	}
private:
	int* _ptr;
	int _t;
};
//在内存池提供表内存
void* Allocate(size_t size)
{
	return malloc(size);
}

//返回（释放）内存
void DeAllocate(void* p)
{
	free(p);
}

//定位new
int main()
{
	Creat* pt = new Creat;
	delete pt;

	pt = (Creat*)Allocate(sizeof(Creat));
	new(pt) Creat;  //new(地址) 类型构造函数
	//定位new函数什么也没做为什么要给出来？
	//一、统一new，否则将成为构造
	//二、编译器执行成本比较大
	//定位new表达式不负责创建空间，只负责构造函数
	//void* operator new(size_t size, void* where)
	//{
	//	return where;
	//}
	pt->~Creat();
	DeAllocate(pt);
	system("pause");
	delete pt;
	return 0;
}
#endif


//只能在堆上创建对象
#if 0
class HeapCreat
{
public:
	static HeapCreat* CreatObject(int data)
	{
		HeapCreat* ptr = new HeapCreat(data);
		return ptr;
	}
	//2.C++11
	HeapCreat(const HeapCreat&) = delete;
private:
	HeapCreat(int)
	{}
	//1.C++98中禁止外部用户调用拷贝构造函数
	//HeapCreat(const HeapCreat&);
};

int main()
{
	HeapCreat* ptrS = HeapCreat::CreatObject(10);
	//HeapCreat p(*ptrS);
	system("pause");
	return 0;
}
#endif

//可以在全局变量区域创建对象
//只能在栈上创建对象
//class onlystack
//{
//public:
//	onlystack()
//	{}
//private:
//	void* operator new(size_t size)
//	{}
//	void operator delete(void*)
//	{}
//};

#if 0
//多创建一个对象
class onlystack
{
public:
	static onlystack CreatStack(int num)
	{
		return onlystack(num);
	}
private:
	onlystack(int)
	{}
};
int main()
{
	//给成静态的原因：当不给成静态时，在调用方法时必须依赖对象调用。然而对象还没有创建出来，不能调用
	//静态方法：不依赖对象可以通过类直接调用
	//onlystack str.CreatStack(10);

	onlystack str(onlystack::CreatStack(10));
	return 0;
}
#endif

//设计一个类：防止被拷贝
//禁止拷贝构造
//禁止对象赋值

class Test
{
public:
	Test()
	{}
	Test(const Test& data) = delete;
	Test& operator=(const Test& data) = delete;

//private:
//	Test(const Test& data)
//	{}
//	Test& operator=(const Test& data)
//	{}
};

int main()
{
	Test t1;
	//Test t2(t1);
	//Test t3 = t1;
	return 0;
}


//禁止在析构函数中调delete
//否则造成无限递归
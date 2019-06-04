#if 0
#include<iostream>
using namespace std;

struct NewType
{
	int a;
	int b;
	int c;
};

template<class DataType>
class SmartPtr
{
public:
	SmartPtr(DataType* ptr = nullptr)
		:_ptr(ptr)
	{
		cout << "SmartPtr(DataType* ptr)" << endl;
	}

	DataType& operator*()
	{
		return *_ptr;
	}

	DataType* operator->()
	{
		return _ptr;
	}

	~SmartPtr()
	{
		if (_ptr != nullptr)
		{
			delete _ptr;
			_ptr = nullptr;
			cout << "delete _ptr" << endl;
		}
		cout << "~SmartPtr()" << endl;
	}
protected:
	DataType* _ptr;
};

int main()
{
	SmartPtr<int> ptrS(new int);
	SmartPtr<NewType> ptr(new NewType);
	(*ptr).b = 6;
	ptr->b = 10;
	return 0;
}
#endif


//auto_ptr
//针对赋值或者拷贝时的多个对象共用一个资源的情况：如何让析构函数清理资源时，不会对无效指针进行清理。
//分为两种：1.是直接在拷贝对象或者进行对象赋值时，SmartPtr<NewType> ptr(Ptr1);
//             直接将Ptr1的资源移交给ptr，
// 缺陷：Ptr1不能再被使用。
//
//          2.SmartPtr<NewType> ptr(Ptr1);二者共享一块资源，不过Ptr1将被设置为可以访问资源，但不能拥有对资源的销毁权。
//             资源销毁权转交到ptr上。
// 缺陷：当ptr的作用域小于Ptr1时，在ptr作用域外使用Ptr1会崩溃，因为此时Ptr1的资源已经被释放了。
//
//unique_ptr :针对auto_ptr缺陷
//           unique_ptr 将拷贝构造和赋值运算符重载进行私有化，或者（C++11）= delete;
//           解决这种资源共享的问题。
// 缺陷：不能共享。

#if 0
#include<iostream>
using namespace std;

template<class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~UniquePtr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return -ptr;
	}
	T* Get()
	{
		return _ptr;
	}
//C++98
//private:
//	UniquePtr(const UniquePtr<T>&){}
//	UniquePtr<T>& operator=(const UniquePtr<T>&){}

//C++11
	UniquePtr(const UniquePtr<T>&) = delete;
	UniquePtr<T>& operator=(const UniquePtr<T>&) = delete;

protected:
	T * _ptr;
};

void TestFunc()
{
	UniquePtr<int> data1(new int);
	*data1 = 10;
	//UniquePtr<int> data2(data1);
	UniquePtr<int> data2(new int);
	//data2 = data1;
}
int main()
{
	TestFunc();
	system("pause");
	return 0;
}
#endif

//shared_ptr
//RAII + operator*()/operator->() + 引用计数--->资源释放方式
// 通过仿函数方式定制删除器
// 缺陷： 循环引用   ---双向链表例子。
// 解决办法：weak_ptr: 不能单独管理资源，必须与shared_ptr配合使用
//           RAII + operator*()/operator->() + 引用计数

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
class DefDF
{
public:
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
};

template<class T>
class FreePtr
{
public:
	void operator()(T*& ptr)
	{
		if (ptr)
		{
			free(ptr);
			ptr = nullptr;
		}
	}
};

class FClosePtr
{
public:
	void operator()(FILE*& ptr)
	{
		if (ptr)
		{
			fclose(ptr);
			ptr = nullptr;
		}
	}
};
template<class T, class DF = DefDF<T>>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		:_ptr(ptr)
		,_count(nullptr)
	{
		if (_ptr)
		{
			_count = new int(1);
		}
	}

	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _count(sp._count)
	{
		if (_count)
		{
			++(*_count);
		}
	}

	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (this != &sp)
		{
			//当前对象没有被共享时，必须将其资源释放，否则没有机会释放了资源泄露。
			if (_ptr && --(*_count) == 0)
			{
				//delete _ptr;
				DF()(_ptr);
				delete _count;
			}
			_ptr = sp._ptr;
			_count = sp._count;
			if (sp._ptr)
			{
				++(*_count);
			}
		}

		return *this;
	}

	int UseCount()
	{
		return *_count;
	}

	T* operator->()
	{
		return _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	~SharedPtr()
	{
		if (--(*_count) == 0 && _ptr)
		{
			//delete _ptr;
			DF()(_ptr);

			delete _count;
			_ptr = nullptr;
			_count = nullptr;
		}
	}

protected:
	T * _ptr;
	int* _count;
};

void TestSharedPtr()
{
	SharedPtr<int> sp1(new int);
	cout << sp1.UseCount() << endl;

	SharedPtr<int> sp2(sp1);
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
}


void TestSharedPtrS()
{
	SharedPtr<int> sp1(new int);
	cout << sp1.UseCount() << endl;
	SharedPtr<int> sp2(sp1);
	cout << sp2.UseCount() << endl;

	SharedPtr<int> sp3(new int);
	cout << sp3.UseCount() << endl;

	//sp1 = sp3;
	sp3 = sp1;
	cout << sp1.UseCount() << endl;
	cout << sp3.UseCount() << endl;
}

void TestSharedPtrSS()
{
	SharedPtr<int> sp1(new int);
	SharedPtr<int, FreePtr<int>> sp2((int*)malloc(4 * sizeof(int)));
	SharedPtr<FILE, FClosePtr> sp3(fopen("1.txt", "w"));
}
int main()
{
	TestSharedPtrSS();
	return 0;
}

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
//��Ը�ֵ���߿���ʱ�Ķ��������һ����Դ��������������������������Դʱ���������Чָ���������
//��Ϊ���֣�1.��ֱ���ڿ���������߽��ж���ֵʱ��SmartPtr<NewType> ptr(Ptr1);
//             ֱ�ӽ�Ptr1����Դ�ƽ���ptr��
// ȱ�ݣ�Ptr1�����ٱ�ʹ�á�
//
//          2.SmartPtr<NewType> ptr(Ptr1);���߹���һ����Դ������Ptr1��������Ϊ���Է�����Դ��������ӵ�ж���Դ������Ȩ��
//             ��Դ����Ȩת����ptr�ϡ�
// ȱ�ݣ���ptr��������С��Ptr1ʱ����ptr��������ʹ��Ptr1���������Ϊ��ʱPtr1����Դ�Ѿ����ͷ��ˡ�
//
//unique_ptr :���auto_ptrȱ��
//           unique_ptr ����������͸�ֵ��������ؽ���˽�л������ߣ�C++11��= delete;
//           ���������Դ��������⡣
// ȱ�ݣ����ܹ���

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
//RAII + operator*()/operator->() + ���ü���--->��Դ�ͷŷ�ʽ
// ͨ���º�����ʽ����ɾ����
// ȱ�ݣ� ѭ������   ---˫���������ӡ�
// ����취��weak_ptr: ���ܵ���������Դ��������shared_ptr���ʹ��
//           RAII + operator*()/operator->() + ���ü���

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
			//��ǰ����û�б�����ʱ�����뽫����Դ�ͷţ�����û�л����ͷ�����Դй¶��
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

#include<iostream>
using namespace std;
#include<crtdbg.h>

#if 0
int main()
{
	//new���������ռ������
	//���뵥��Ԫ�ؿռ���Գ�ʼ��
	//����һ�������ռ䲻�ܳ�ʼ��
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

//ʲô���ڴ�й©����μ�⣿

#if 0

class Creat
{
public:
	Creat()
	{
		cout << "���캯��" << this << endl;
		_t = 0;
		_ptr = (int*)malloc(sizeof(int));
	}
	~Creat()
	{
		cout << "��������" << this << endl;
		free(_ptr);
		_ptr = nullptr;
	}
private:
	int* _ptr;
	int _t;
};

//�Զ������ͣ�
//malloc��ֻ�ǽ��ռ䶯̬���ٳɹ��������ù��캯����ʼ���ռ�
//free��ֻ���𽫿ռ��ͷŵ�
//new�����ռ俪�ٳɹ�������Ҫ���ù��캯����ɿռ�ĳ�ʼ��
//delete���ȵ������������ͷŶ����е���Դ�����ͷŶ�����ռ����Դ
int main()
{
	//�˴�������deleteȥ�ͷţ���Ϊ�Զ�������malloc��������ռ�ʱ�����������_ptrָ�벢δ����ռ䡣
	//����δ���ù��캯������ʱ���Ǹ�����ֻ�ǺͶ���ռ�һ����
	//������deleteȥ�ͷ���������������Դ�����ͷ�_ptrʱ�������

	//mallocֻ�Ǵ���һ���Ͷ���һ����Ŀռ�
	Creat* ptr = (Creat*)malloc(sizeof(Creat));
	free(ptr);
	//delete(ptr);

	//new�������Ƕ���
	//Creat* ptr2 = new Creat;
	//free(ptr2);
	//_CrtDumpMemoryLeaks();
	Creat* ptr1 = new Creat[10];
	//free(ptr1);
	//delete ptr1;//ֻ�����˵�һ���������Դ�������
    delete[] ptr1;//�����һ����ʼ������Դ��ǰ����
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
		cout << "���캯��" << this << endl;
		_t = 0;
		_ptr = (int*)malloc(sizeof(int));
	}
	~Creat()
	{
		cout << "��������" << this << endl;
		free(_ptr);
		_ptr = nullptr;
	}
private:
	int* _ptr;
	int _t;
};

//��д�������ռ�
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
		cout << "���캯��" << this << endl;
	    _t = 0;
	   _ptr = (int*)malloc(sizeof(int));
	}
	~Creat()
	{
		cout << "��������" << this << endl;
		free(_ptr);
		_ptr = nullptr;
	}
private:
	int* _ptr;
	int _t;
};
//���ڴ���ṩ���ڴ�
void* Allocate(size_t size)
{
	return malloc(size);
}

//���أ��ͷţ��ڴ�
void DeAllocate(void* p)
{
	free(p);
}

//��λnew
int main()
{
	Creat* pt = new Creat;
	delete pt;

	pt = (Creat*)Allocate(sizeof(Creat));
	new(pt) Creat;  //new(��ַ) ���͹��캯��
	//��λnew����ʲôҲû��ΪʲôҪ��������
	//һ��ͳһnew�����򽫳�Ϊ����
	//����������ִ�гɱ��Ƚϴ�
	//��λnew���ʽ�����𴴽��ռ䣬ֻ�����캯��
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


//ֻ���ڶ��ϴ�������
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
	//1.C++98�н�ֹ�ⲿ�û����ÿ������캯��
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

//������ȫ�ֱ������򴴽�����
//ֻ����ջ�ϴ�������
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
//�ഴ��һ������
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
	//���ɾ�̬��ԭ�򣺵������ɾ�̬ʱ���ڵ��÷���ʱ��������������á�Ȼ������û�д������������ܵ���
	//��̬�������������������ͨ����ֱ�ӵ���
	//onlystack str.CreatStack(10);

	onlystack str(onlystack::CreatStack(10));
	return 0;
}
#endif

//���һ���ࣺ��ֹ������
//��ֹ��������
//��ֹ����ֵ

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


//��ֹ�����������е�delete
//����������޵ݹ�
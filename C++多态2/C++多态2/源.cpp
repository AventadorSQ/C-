
//  ���������ò��������캯����4������
// 1. ��A������ȱʡ�Ĺ��캯��    ��B����û�й��캯�����Ǻ���A�����
//
// 2. �̳У�
//    ��A������ȱʡ�Ĺ��캯��    ֮��B��̳���A�࣬û����ʾ���幹�캯����
//    ������B�����ʱ��Ҫʹ��B����󴴽������ͱ������A��Ĺ��캯������ʼ��A�����һ���֡�
//    ��ʼ��A������캯����B��ĳ�ʼ���б�����
//
//3.  ����̳У�
//    A��û����ʾ���壬����B������̳���A��֮���ڹ���B��Ķ���ʱ���ᴴ����������һ����ǰ�ĸ��ֽ��Ƕ���ռ��׵�ַ��һ����1��ʾ������̳�
//    ͨ��ǰ�ĸ��ֽ����ҵ�ӳ��������ͨ��ƫ�������ҵ���������λ�á�
//    ����ģ�ͣ�����������£�����������ϡ�
//
//4.  �����麯�����࣬
//     �����ö���ǰ�ĸ��ֽڴ��ַ
//     ÿ��һ���麯��,	ǰ�ĸ��ֽڵĵ�ַ��ӳ��ı��о�����һ����ַռ�ĸ��ֽ�--->���ָ��
//     ���ࣺ������麯�������������е�����������������С�


//�����麯�����࣬���̳�

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
//������/���ࣺ
//******************************************************************************

//�����ǽ�������麯����һ�ݡ�
//��Ϊ���ڶ����ǰ�ĸ��ֽڼ�ָ�����ĵ�ַ�ͻ�������ǰ�ĸ��ֽ����ݲ�һ��

// �������Ի����麯��������д��
//�ȿ�һ�ݻ���ģ�--->
//������Ǹ������麯����д�������Լ���д���麯���滻�������ͬƫ��λ�õ�λ�á�--->����ͼ����ÿ����Ļ�����麯���ĵ�ַ��

//�����������Լ������ӵ��麯������������������󣨸��ڼ̳еĻ�������ĺ��棩

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
	////��һ���麯���ĵ�ַ
	//(*ptr)();
	//ptr++;
	////�ڶ����麯���ĵ�ַ
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

//��̳е�����
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
	//��̳�ʱc�е����⺯�����ڵ�һ�����ĺ���
	cout << "Printchildren(c1) : " << endl;
	Printchildren(c);
	cout << endl;

	cout << "c1" << ":" << endl;
	cout << "PrintBase1(c1) : " << endl;
	PrintBase1(c1);
	cout << "PrintBase2(c1) : " << endl;
	PrintBase2(c1);
	//��̳�ʱc�е����⺯�����ڵ�һ�����ĺ���
	cout << "Printchildren(c1) : " << endl;
	Printchildren(c1);

	system("pause");
	return 0;
}
#endif

//������
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
	//�����಻�ܱ�ʵ����
	//Abstract a;

	children c;
	c.AbstrS();
	c.Print();
	system("pause");
	return 0;
}
#endif
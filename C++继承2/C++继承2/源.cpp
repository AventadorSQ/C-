#if 0
#include<iostream>
using namespace std;

//���������ɵĹ��캯��---Ĭ�ϵ�
//�޲εĺ�ȱʡ�� ---ȱʡ

//******************************************************************************//
//����ȫȱʡ��Ĭ�Ϲ��죬�����Ĺ��캯�����������๹�캯����ʼ���б���г�ʼ��****//
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
	//����֤��������ʱ�Ƿ����ø�������������Ҫ��pauseȥ��
	system("pause");
	return 0;
}

#endif


#if 0
#include<iostream>
using namespace std;

//���һ����ʹ�������ܱ��̳�
//���ַ�����
//         1.������Ĺ��캯������˽�л�
//         2.�ڸ����������final������ֹ�̳У�C++11��
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
//��Ԫ��ϵ���ܱ��̳�

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

	//�����Է���S�ĳ�Ա����
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
//���о�̬��Ա���Ա��̳�
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

//��̳�
//���ڴ��м̳еĳ�Ա����˳����̳еĸ����˳��һ��
//��ͬ�̳���ϵ��---�����ģ�ͣ������г�Ա�������ڴ��еĲ��������

//���μ̳�

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

//������c��ֱ��ȥ����a�ĳ�Ա��ֵ�����ڶ����ԣ����Ҫ����������B1B2�е���һ��
//����һ�����������������޶������֣�����ȷ����һ�ݣ�������û�н����ֻ��һ�ݾͿ�����
//����������������̳�  --- > ���Խ�����μ̳��д��ڵĶ���������
int main()
{

	C c;
	c.PrintSizeof();
	c.SetAInfo(2, 6);
	//c.SetAB2Info(8);
	//c.SetAB1Info(1);
	//�ڶ��������еĳ�Ա������ֵȡ���ڵ�һ���̳е��������øó�Ա��ֵ
	c.PrintAB1B2a();
	system("pause");
	return 0;
}

#endif


//����̳�  class B : virtual public A
//�ڼ̳з�ʽǰ�ӹؼ���virtual
//����̳�����ͨ�̳е�����
//1.����ģ�͵�������Ա�������ڴ��л����Ա�������档
//2.�����ж����ĸ��ֽ�--�������Ǳ������Լ�ά�����������Ǳ������Լ�ά��������Ա����int��4���ֽڣ�
//3.������Ϊ����������Ĭ�ϵĹ��캯��--2������  �ռ��׵�ַ 1��������̳еı�־

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
	s._a = 1;//1.ȡ����ǰ�ĸ��ֽڵ�����Ϊ��ַ
	         //--->2.�������ַ��+4ȡ�����������data
	         //--->3.�Ӷ�����ʼ��ַ���ƫ��data���ֽڽ�1��ֵ�������Ա_a
	//�����  ��һ���ֽڴ�ƫ�Ƶ�ǰ����ֽ�0���ڶ����ֽڴ����ƫ����
	s._b = 2;
	

	return 0;
}

#endif

//����̳н�����μ̳ж���������

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


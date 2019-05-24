
//��̬����
//1.�ڻ����иú�������Ϊ�麯�������ڸú���ǰ����virtual�ؼ��֣�
//2.�������б�����������������д�������������ԭ��һ��
//������ֵ���ͣ������б��������ֱ���һ��(virtual�ɼӿɲ��ӣ���ȷ�����ٱ��̳У�)��ֻ������ʵ����һ������
// ��д���⣺
//          1.����ֵ���������⣺
//                    Э�䣺�����麯�����ػ�������ָ���������
//                          �������麯����������������ָ���������
//          2.������������


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
	//0.��̬
	virtual void Test()
	{
		cout << "Base::Test()" << endl;
	}

	//1.�����ඪʧ����ؼ���ʱ��֤�ǲ��Ƕ�̬
	void Test1()
	{
		cout << "Base::Test1()" << endl;
	}

	//û�й�����д
	//2.�����������б�ͬʱ��֤
	virtual void Test2()
	{
		cout << "Base::Test2()" << endl;
	}
	//û�й�����д
	//3.����������ͬʱ��֤
	virtual void Test3()
	{
		cout << "Base::Test3()" << endl;
	}

	//4.����ֵ���Ͳ�ͬ��֤ --->��ʱ�ڶ�Ӧ���������иú���������
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

	//����  ˵������ж�Ӧ�����Ȳ���ͬҲ��Э��
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


//Э��

#if 0

#include<iostream>
using namespace std;

class Base
{
public:
	//���ظ����͵�ָ��
	virtual Base* Test1()
	{
		cout << "Base::Test1()" << endl;
		return nullptr;
	}

	//���ظ����͵�����
	virtual Base& Test2()
	{
		cout << "Base::Test1()" << endl;
		return *this;
	}
};

class children : public Base
{
public:
	//Э��---����ֵ�����Ͳ�ͬ
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

//��֤���������Ƿ񹹳ɶ�̬

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

//������д�ĺ�������˽�У��ɲ����ԣ�
//���ԣ� ��Ȼ�����н���д�ĺ���������˽�еģ������ڱ����ڼ䷢��ʱ����ĵ��ã�������ı���д�����ǹ��еġ�
//�ڳ�������ʱ����������ĵ���ʱ�����ֱ���д�ͻ�����Լ��ĺ���
//��̬�У���Ա����Ȩ�޿��Բ�һ����������빫�У��������
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



//��ý�������������������麯��
//������������������ڶ���������һ����Դ�Ϳ�������ڴ�й©

//����������������������Ϊ�麯��ʱ��������������������������ͷ���Դ
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
	//�������������ͣ�
	//     ��̬���ͣ�--->����������������Bptr��Base*���ڱ����ڼ�Ϳ���ȷ��
	//     ��̬���ͣ�--->ʵ��ָ������� ��Bptrָ��children���ͣ�������������ȷ��
	//�����̬����û�����㣬ʹ�ö���ľ�̬�����������麯�� ----������麯��
	//�����̬�������㣬��ʹ�ö���Ķ�̬�����������麯���� ----��ȥ���õ�ǰ������ָ������͵ĺ�����
	Base* Bptr = new children;
	delete Bptr;

	system("pause");
	return 0;
}

#endif

//override�ؼ��֣�C++11������˵���Ըú���������д����ֹ��дʱ������д������
//ֻ�ܷ�����������麯������

//final : 1.�����࣬˵�����಻�ܱ��̳�
//        2.�����麯��---˵���ڴ������������в��ܽ���������ٱ���д

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

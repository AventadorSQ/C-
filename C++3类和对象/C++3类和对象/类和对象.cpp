#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0
struct student
{
	//如果把函数声明和定义全部放到类中，编译器有可能会把它当做内联函数来处理
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStu()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}
	//成员变量
	char _name[20];
	char _gender[10];
	int  _age;
};

int main()
{
	student s1,s2;
	s1.SetStudentInfo("Jarry", "女",20);
	s2.SetStudentInfo("Tom", "男", 27);
	
	s1.PrintStu();
	s2.PrintStu();
	
	system("pause");
	return 0;
}

#endif

#if 0
class student
{
	//如果把函数声明和定义全部放到类中，编译器有可能会把它当做内联函数来处理
public:
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStu()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}

	int add(int a, int b)
	{
		return (a^b) ^ (a&b) << 1;
	}
private:
	//成员变量
	char _name[20];
	char _gender[10];
	int  _age;
};

int main()
{
	student s1, s2;
	int a, b;
	cin >> a >> b;
	cout << s1.add(a, b) << endl;
	//s1.SetStudentInfo("Jarry", "女", 20);
	//s2.SetStudentInfo("Tom", "男", 27);
	//s1.PrintStu();
	//s2.PrintStu();

	system("pause");
	return 0;
}
//class和struct区别：
//在类和对象上：
//class默认私有
//struct默认公有访问权限,就是为了兼容C语言
//public：该成员可以在类外使用
//private/protected：则不能在类外访问

#endif

//类的作用域
#if 0
namespace N
{
	int a = 10;
}

int a = 20;

class Test
{
public:
	void Set(int a)
	{
		cout << &a << endl;
		a = a;//参数给参数赋值
	}

	void Print()
	{
		cout << a << endl;
	}

private:
	int a;  //成员变量在类中具有全局属性
};
//在类中全局变量可以在函数下面   why？？？
//*************************************************************************************

int main()
{
	int a = 40;
	Test s;
	s.Set(30);
	cout << N::a << endl;
	cout << ::a << endl;
	s.Print();
	cout << a << endl;
	system("pause");
	return 0;
}

#endif

//类的实例化
//类类型创建对象

#if 0
//类大小的计算方式：与结构体的计算方式一样
class A
{
public:
	void SetA()
	{}
protected:
	int a;
};

class B
{
public:
	void SetA()
	{}
};

class C
{};

int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	system("pause");
	return 0;
}

#endif
//offsetof

//编译器如何识别类：
//1.识别类名
//2.识别类中的成员变量
//3.识别类中的成员函数&并且对类中的成员函数进行修改
//（在函数参数部分加 类类型* this）（后面每一个成员变量都用this指针找到）

//调用约定
 //_thiscall    ecx寄存器
//_cdecl       参数压栈的方式

#if 0
struct Student
{
	char _name[20];
	char _gender[20];
	int age;
};

void SetStudentInfo(Student* ptr, const char* name, const char* gender, int age)
{
	strcpy(ptr->_name, name);
	strcpy(ptr->_gender, gender);
	ptr->age = age;
}

void PrintStudentInfo(Student* ptr)
{
	printf("%s  %s  %d\n", ptr->_name, ptr->_gender, ptr->age);
}

int main()
{
	Student ps;
	SetStudentInfo(&ps, "Tom", "男", 18);
	PrintStudentInfo(&ps);
	system("pause");
	return 0;
}

#endif

class Student
{
public:
	void SetStudentInfo( const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout << this << endl;
		cout << _name << " " << _gender << " " << _age << endl;
	}

	//不定参数是通过参数压栈（_cdecl约定）
	void TestFunc(...)
	{}

private:
	char _name[20];
	char _gender[20];
	int _age;
};

int main()
{
	Student s;
	s.SetStudentInfo("Tom", "男", 18);
	cout << &s << endl;
	s.PrintStudentInfo();

	//不定参数压栈时通过eax寄存器来传递
	Student s1;
	s1.TestFunc(66);

	//this可以为空吗?
	Student s2;
	s2.SetStudentInfo("Tom2", "男", 22);
	Student* ps = &s2;
	ps->PrintStudentInfo();
	ps = nullptr;
	//指针虽然为空，但是它是一个对象，就会把指针里面内容（虽然为空）传进去
	ps->PrintStudentInfo();

	system("pause");
	return 0;
}

//this   const char*   char&
//为什么会传this指针而不用引用？
//因为类比引用出现的早。C++1.0才有引用
//
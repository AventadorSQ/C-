#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#include<string.h>

#if 0
class Student
{
public:
	void SetStudentInfo(const char* name, const char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudentInfo()
	{
		cout << this << endl;
		//cout << _name << " " << _gender << " " << _age << endl;
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

#endif

#if 0
class A {
public: A()
      {
	     ++_scount;
      }
		A(const A& t) { ++_scount; }
		static int GetACount() { return _scount; }
private:
	static int _scount;
};
int A::_scount = 0;
void TestA()
{
	cout << A::GetACount() << endl;
	A a1, a2;
	A a3(a1);
	cout << A::GetACount() << endl;
}

int main()
{
	TestA();
	system("system");
	return 0;
}

#endif

//#pragme pack(8)
class A
{
private:
	int a;
	char str;
	class B
	{
	private:
		int s;
		int s1;
	};
};

int main()
{
	A temp;
	cout << sizeof(temp) << endl;
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0
struct student
{
	//����Ѻ��������Ͷ���ȫ���ŵ����У��������п��ܻ����������������������
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
	//��Ա����
	char _name[20];
	char _gender[10];
	int  _age;
};

int main()
{
	student s1,s2;
	s1.SetStudentInfo("Jarry", "Ů",20);
	s2.SetStudentInfo("Tom", "��", 27);
	
	s1.PrintStu();
	s2.PrintStu();
	
	system("pause");
	return 0;
}

#endif

#if 0
class student
{
	//����Ѻ��������Ͷ���ȫ���ŵ����У��������п��ܻ����������������������
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
	//��Ա����
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
	//s1.SetStudentInfo("Jarry", "Ů", 20);
	//s2.SetStudentInfo("Tom", "��", 27);
	//s1.PrintStu();
	//s2.PrintStu();

	system("pause");
	return 0;
}
//class��struct����
//����Ͷ����ϣ�
//classĬ��˽��
//structĬ�Ϲ��з���Ȩ��,����Ϊ�˼���C����
//public���ó�Ա����������ʹ��
//private/protected���������������

#endif

//���������
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
		a = a;//������������ֵ
	}

	void Print()
	{
		cout << a << endl;
	}

private:
	int a;  //��Ա���������о���ȫ������
};
//������ȫ�ֱ��������ں�������   why������
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

//���ʵ����
//�����ʹ�������

#if 0
//���С�ļ��㷽ʽ����ṹ��ļ��㷽ʽһ��
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

//���������ʶ���ࣺ
//1.ʶ������
//2.ʶ�����еĳ�Ա����
//3.ʶ�����еĳ�Ա����&���Ҷ����еĳ�Ա���������޸�
//���ں����������ּ� ������* this��������ÿһ����Ա��������thisָ���ҵ���

//����Լ��
 //_thiscall    ecx�Ĵ���
//_cdecl       ����ѹջ�ķ�ʽ

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
	SetStudentInfo(&ps, "Tom", "��", 18);
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

	//����������ͨ������ѹջ��_cdeclԼ����
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
	s.SetStudentInfo("Tom", "��", 18);
	cout << &s << endl;
	s.PrintStudentInfo();

	//��������ѹջʱͨ��eax�Ĵ���������
	Student s1;
	s1.TestFunc(66);

	//this����Ϊ����?
	Student s2;
	s2.SetStudentInfo("Tom2", "��", 22);
	Student* ps = &s2;
	ps->PrintStudentInfo();
	ps = nullptr;
	//ָ����ȻΪ�գ���������һ�����󣬾ͻ��ָ���������ݣ���ȻΪ�գ�����ȥ
	ps->PrintStudentInfo();

	system("pause");
	return 0;
}

//this   const char*   char&
//Ϊʲô�ᴫthisָ����������ã�
//��Ϊ������ó��ֵ��硣C++1.0��������
//
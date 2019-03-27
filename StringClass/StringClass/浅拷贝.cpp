#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//写时拷贝技术
//注意多线程:原子操作

class String
{
public:
	String(const char* _str = "")
		:count(new int(1))
	{
		if (_str == nullptr)
		{
			_str = "";
		}
		Sptr = new char[strlen(_str) + 1];
		strcpy(Sptr, _str);
	}
	String(const String& s)
		:Sptr(s.Sptr)
		,count(s.count)
	{
		++(*count);
	}
	~String()
	{
		cout << *count << endl;
		Release();
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			Release();
			Sptr = s.Sptr;
			count = s.count;
		}
	}
private:
	void Release()
	{
		if (--*count == 0 && Sptr)
		{
			delete[] Sptr;
			Sptr = nullptr;

			delete count;
			count = nullptr;
		}
	}
private:
	char* Sptr;
	//static int count;
	int* count;
};

void Test()
{
	String s1("SUST");
	String s2(s1);

	String s3("hello");
	String s4 = s3;
}
int main()
{
	Test();
	system("pause");
	return 0;
}
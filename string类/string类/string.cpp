
//���֮��ͳ����
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cassert>
#include<string>

using namespace std;

class String
{
private:
	friend ostream& operator<<(ostream& _cout, const String s);
public:
	String(const char* _str="")
	{
		if (_str == nullptr)
		{
			assert(false);
			return;
		}
		str = new char[strlen(_str) + 1];
		strcpy(str, _str);
	}

	~String()
	{
		delete str;
		str = nullptr;
	}

	String(const String& s)
		:str (new char[strlen(s.str) + 1])
	{
		if (this == &s)
		{
			return;
		}
		strcpy(str, s.str);
	}
	String& operator=(const String& s)
	{
		if (this == &s)
		{
			return *this;
		}
		char* NewStr = new char[strlen(s.str) + 1];
		strcpy(NewStr, s.str);
		delete str;
		str = NewStr;

		return *this;
	}
private:
	char* str;
};

ostream& operator<<(ostream& _cout, const String s)
{
	_cout << s.str << " ";
	return _cout;
}
int main()
{
	String Sptr("NDC������");
	cout << "Sptr" << " " << Sptr << " " << &Sptr << endl;
	String sptr(Sptr);
	cout << "sptr" << " " << sptr << " " << &sptr << endl;
	String SSptr = sptr;
	cout << "SSptr" << " " << SSptr << " " << &SSptr << endl;
	system("pause");
	return 0;
}
#endif

//���֮�ִ�����
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cassert>
#include<string>

using namespace std;

class String
{
private:
	friend ostream& operator<<(ostream& _cout, const String s);
public:
	String(const char* _str = "")
	{
		if (_str == nullptr)
		{
			_str = "";
		}
		str = new char[strlen(_str) + 1];
		strcpy(str, _str);
	}

	~String()
	{
		delete str;
		str = nullptr;
	}

	String(const String& s)
		:str(nullptr)
	{
		//�ı���ǿ������캯�����ٴ����ռ䣬���ù��캯��ȥ���ٿռ䡣
		//ʵ���ϵ��ù��캯������Ϊ���ٿ�������Ŀռ�
		String NewStr(s.str);
		swap(str, NewStr.str);
	}
	String& operator=(String& s)
	{
		swap(str, s.str);
		return *this;
	}
private:
	char* str;
};

ostream& operator<<(ostream& _cout, const String s)
{
	_cout << s.str << " ";
	return _cout;
}
int main()
{
	String Sptr("NDC������");
	cout << "Sptr" << " " << Sptr << " " << &Sptr << endl;
	String sptr(Sptr);
	cout << "sptr" << " " << sptr << " " << &sptr << endl;
	String SSptr = Sptr;
	cout << "SSptr" << " " << SSptr << " " << &SSptr << endl;
	cout << "Sptr" << " " << Sptr << " " << &Sptr << endl;
	system("pause");
	return 0;
}
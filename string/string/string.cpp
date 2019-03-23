#include<iostream>
using namespace std;

#include<string>

#if 0
int main()
{
	string s1;
	cout << s1 << endl;
	string s2("hello C++");
	cout << s2 << endl;
	string s3(6, '&');
	cout << s3 << endl;
	string s4(s3);
	cout << s4 << endl;
	string s5(s2, 3);
	cout << s5 << endl;
	system("pause");
	return 0;
}
#endif

//resize(size_t n, char ch):将字符串中有效字符的个数改变到n个，多出的元素空间用ch填充
//注意：1.resize中可能会增容
//      2.n如果小于源字符串中原来有效字符串的个数--缩短--底层空间不变

#if 0
int main()
{
	string s("hello world");
	cout << (int)s.c_str() << endl;
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	if (s.empty())
	{
		cout << "s是空字符串" << endl;
	}
	else
	{
		cout << "s不是空字符串" << endl;
	}

	s.resize(20, '6');
	cout << (int)s.c_str() << endl;
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	s.resize(50, 'b');
	cout << (int)s.c_str() << endl;
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	//当小时也不会开辟空间
	s.resize(12, 'b');
	cout << (int)s.c_str() << endl;
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	system("pause");
	return 0;
}

#endif

#if 0
//reserve： 只负责预留空间，不会改变有效元素的个数
//注意：如果利用reserve缩小底层空间，string类忽略该操作
int main()
{
	string s("hello world");
	cout << (int)s.c_str() << endl;
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	//s.resize(10);

	s.reserve(30);
	cout << (int)s.c_str() << endl;
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	//小时不会重新开辟空间
	s.reserve(20);
	cout << (int)s.c_str() << endl;
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	s.clear();
	cout << (int)s.c_str() << endl;
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	system("pause");
	return 0;
}
#endif

int main()
{
	string s;
	//s.reserve(30);
	s.resize(30);

	s[5] = '6';
	cout << s << endl;
	system("pause");
	return 0;
}
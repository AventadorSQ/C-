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

//resize(size_t n, char ch):���ַ�������Ч�ַ��ĸ����ı䵽n���������Ԫ�ؿռ���ch���
//ע�⣺1.resize�п��ܻ�����
//      2.n���С��Դ�ַ�����ԭ����Ч�ַ����ĸ���--����--�ײ�ռ䲻��

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
		cout << "s�ǿ��ַ���" << endl;
	}
	else
	{
		cout << "s���ǿ��ַ���" << endl;
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
	//��СʱҲ���Ὺ�ٿռ�
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
//reserve�� ֻ����Ԥ���ռ䣬����ı���ЧԪ�صĸ���
//ע�⣺�������reserve��С�ײ�ռ䣬string����Ըò���
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

	//Сʱ�������¿��ٿռ�
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
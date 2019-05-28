#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//int main()
//{
//	FILE* fp = fopen("abc.txt", "rb");
//	if (NULL == fp)
//	{
//		cout << errno << endl;
//	}
//
//http://www.baidu.com;
//	fclose(fp);
//	system("pause");
//	return 0;
//}

//void Div(int left, int right)
//{
//	if (0 == right)
//	{
//		throw 1;
//	}
//
//	cout << left / right << endl;
//}
//void Div(double left, int right)
//{
//	if (0 == right)
//	{
//		throw 1.0;
//	}
//
//	cout << left / right << endl;
//}
//
//int main()
//{
//	try
//	{
//		Div(10.0, 0);
//		Div(5, 3);
//	}
//	catch (int ERROR)//异常的捕获按照类型捕获
//	{
//		cout << ERROR << endl;
//	}
//	catch (double ERROR)//异常的捕获按照类型捕获
//	{
//		cout << ERROR << endl;
//	}
//
//	system("pause");
//	return 0;
//}



//处理异常是找最近的捕获方法
#if 0
void Div(int left, int right)
{
	if (0 == right)
	{
		throw 1;
	}

	cout << left / right << endl;
}
void Div(double left, int right)
{
	try
	{
		if (0 == right)
		{
			throw 1;
		}
		cout << left / right << endl;
	}
	catch (int a)
	{
		cout << a << endl;
	}
}

int main()
{
	try
	{
		Div(10.0, 0);
		Div(15.0, 3);
		Div(5, 3);
	}
	catch (int ERROR)//异常的捕获按照类型捕获
	{
		cout << ERROR << endl;
	}
	catch (double ERROR)//异常的捕获按照类型捕获
	{
		cout << ERROR << endl;
	}

	system("pause");
	return 0;
}
#endif

//万能捕获

void TestFunc(int left, int right)
{
	int a;
		if (right == 0)
		{
			throw 1;
		}
		a = left / right;
		cout << a << endl;

}
int main()
{
	try
	{
		TestFunc(5, 0);
	}
	catch (...)
	{
		cout << "未知错误" << endl;
		//throw;
	}
	system("pause");
	return 0;
}
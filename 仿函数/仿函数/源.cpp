#include<iostream>
using namespace std;

class IsOdd
{
public:
	bool operator()(int data)
	{
		if (data % 2 == 0)
		{
			return true;
		}

		return false;
	}
};

void Test1()
{
	IsOdd m;
	int data;
	cout << "请输入一个整数:" << endl;
	cin >> data;
	if (m(data))
	{
		cout << "偶数" << endl;
	}
	else
	{
		cout << "奇数" << endl;
	}
}

int main()
{
	Test1();
	system("pause");
	return 0;
}
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
	cout << "������һ������:" << endl;
	cin >> data;
	if (m(data))
	{
		cout << "ż��" << endl;
	}
	else
	{
		cout << "����" << endl;
	}
}

int main()
{
	Test1();
	system("pause");
	return 0;
}
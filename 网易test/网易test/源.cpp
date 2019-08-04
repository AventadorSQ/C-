#include<iostream>
using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;
	long long temp = 1;
	if (a<b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	while (temp != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	cout << a << endl;
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;

void Dispose(int Num)
{
	if (Num <= 1)
	{
		cout << 1;
		return;
	}

	for (int i = 1; i <= Num; i++)
	{
		for (int j = i; j <= Num - j + 2; j++)
		{
			for (int x = 0; x < Num - j + 1; x++)
			{
				if (x != Num - j)
				{
					cout << i << "+";
				}
				else
				{
					cout << j << endl;
				}
			}
		}
	}
}

int main()
{
	int Num;
	cin >> Num;
	Dispose(Num);
	system("pause");
	return 0;
}
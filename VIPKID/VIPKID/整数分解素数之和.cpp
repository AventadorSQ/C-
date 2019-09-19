#include<iostream>
using namespace std;

bool IsSuShu(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

void Dispose(int Num)
{
	for (int i = 6; i <= Num; i = i + 2)
	{
		for (int j = 2; j <= i / 2; j++)
		{
			if (IsSuShu(j) && IsSuShu(i - j))
			{
				cout << i << "=" << j << "+" << i - j << endl;
			}
		}
	}
}

int main()
{
	int Num;
	cin >> Num;
	Dispose(Num);
	//system("pause");
	return 0;
}
#include<iostream>
using namespace std;
#include<cmath>

void Dispose(int num)
{
	int Max, Result;
	int Index1, Index2;
	if (num < 4)
	{
		if (num > 2)
		{
			cout << 2;
			return;
		}
		Result = 2;
		if (num == 2)
		{
			cout << 3;
			return;
		}
		else
		{
			cout << 2;
			return;
		}
	}

	if (num % 2)
	{
		Index1 = ((num - 3) % 6) / 2;
		Index2 = (num - 3) / 6 * 2 + 1;
		Max = pow(3, Index2) * pow(2, Index1);
	}
	else
	{
		Index1 = num % 6 / 2;
		Index2 = num / 6 * 2;
		Max = pow(3, Index2) * pow(2, Index1);
	}
	cout << Index1 + Index2 + Max;
}

int main()
{
	int num;
	cin >> num;
	Dispose(num);
	return 0;
}
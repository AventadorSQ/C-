#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;

class Solution {
public:
	bool isHappy(int n)
	{
		if (n > 0)
		{
			int x = n;
			int count = 0;
			int SumS = 0;
			int i = 0;
			cout << n << ":";
			while ((x != 1) && (x != 0) && (i < 20))
			{
				i++;
				count = IsNCount(x);
				SumS = Sum(x, count);
				cout << SumS << " ";
				x = SumS;
				//if (x == 4)
				//{
				//	return false;
				//}
			}
			cout << endl;

			if (x == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}
	//求这个数有多少位
	int IsNCount(int x)
	{
		int count = 0;
		while (x != 0)
		{
			x = x / 10;
			count++;
		}
		return count;
	}

	//把每个数的每一位进行处理
	int Sum(int x, int count)
	{
		int sum = 0;
		int i = count - 1;
		//cout << x << ":";
		while (i >= 0)
		{

			sum = (x / (int)pow(10, i)) * (x / (int)pow(10, i)) + sum;
			//cout << sum;
			x = x % (int)pow(10, i);
			i--;
		}
		//cout << endl;
		return sum;
	}
};

int main()
{
	int num;
	int i = 0;
	srand((unsigned int)time(NULL));
	while (i < 100)
	{
		num = rand() % 10000;
		Solution S;
		cout << endl;
		cout << "IsHappyNum:";
		cout << S.isHappy(num) << endl;
		i++;
	}
	system("pause");
	return 0;
}


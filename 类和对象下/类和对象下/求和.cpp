#include<iostream>
using namespace std;

class sum
{
public:
	sum()
	{
		_count++;
		_sum += _count;
	}
	static int Get_Sum()
	{
		//data = 10;
		return _sum;
	}
private:
	int data = 1;
	static int _count;
	static int _sum;
};

int sum::_count = 0;
int sum::_sum = 0;

int main()
{
	sum d[100];
	cout << "_sum = " << sum::Get_Sum() << endl;
	system("pause");
	return 0;
}
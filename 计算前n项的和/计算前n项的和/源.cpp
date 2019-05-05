#include<iostream>
using namespace std;
class SumS
{
public:
	SumS()
	{
		Number++;
		Sum += Number;
	}
	int GetSum()
	{
		return Sum;
	}
	static void Reset()
	{
		Number = 0;
		Sum = 0;
	}
private:
	static int Number;
	static int Sum;
};
int SumS::Number = 0;
int SumS::Sum = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		SumS::Reset();
		SumS* ptr = new SumS[n];
		int Sums = ptr->GetSum();

		delete[]ptr;
		return Sums;
	}
};

int main()
{
	Solution S;
	cout << S.Sum_Solution(5) << endl;
	system("pause");
	return 0;
}
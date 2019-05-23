#include<iostream>
using namespace std;
#include<vector>

void Dispose(vector<int>& vs)
{
	int MaxSum = vs[0];
	int Sum = 0;
	for (int i = 0; i < vs.size(); i++)
	{
		Sum = Sum + vs[i];
		if (Sum > MaxSum)
		{
			MaxSum = Sum;
		}
		if (Sum < 0)
		{
			Sum = 0;
		}
	}
	cout << MaxSum << endl;
}

int main()
{
	int N;
	vector<int> v;
	while (cin >> N)
	{
		int data = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> data;
			v.push_back(data);
		}

		Dispose(v);
	}
	return 0;
}
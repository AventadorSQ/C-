#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		int num = 0;
		cin >> num;
		v[i] = num;
	}
	for (int j = 0; j < n - 1; j++)
	{
		if (v[j] > v[j + 1])
		{
			v[j + 1] = v[j];
		}
	}
	for (int k = 0; k < n; k++)
	{
		cout << v[k] << " ";
	}
	system("pause");
	return 0;
}
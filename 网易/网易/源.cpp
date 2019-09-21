#include<iostream>
using namespace std;
#include<map>
#include<vector>
int main()
{
	int RenCount, WenCount;
	cin >> RenCount >> WenCount;
	map<int, int> m;
	vector<int> v;
	v.resize(RenCount);
	for (int i = 0; i < RenCount; i++)
	{
		cin >> v[i];
		m[v[i]]++;
	}
	int temp;
	for (int j = 0; j < WenCount; j++)
	{
		cin >> temp;
		cout << m[temp] << endl;
	}
	return 0;
}
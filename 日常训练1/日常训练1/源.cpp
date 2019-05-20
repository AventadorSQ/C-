#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>


int MaxFunc(vector<int>& v1)
{
	sort(v1.begin(), v1.end());

	int MaxData = 0;
	int size = v1.size();
	//for (int i = 0; i < size; i++)
	//{
	//	cout << v1[i] << " ";
	//}
	//cout << endl;
	//cout << size << endl;
	for (int i = (size / 3); i < 2 * (size / 3); i++)
	{
		MaxData += v1[i];
	}
	return MaxData;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int data;
		vector<int> v;
		for (int i = 0; i < 3 * n; i++)
		{
			cin >> data;
			v.push_back(data);
		}
		int MaxData = MaxFunc(v);
		cout << MaxData << endl;
	}
	return 0;
}
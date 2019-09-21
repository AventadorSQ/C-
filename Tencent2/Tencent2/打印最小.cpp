#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void Dispose(vector<int>& v, int CiShu)
{
	vector<int>::iterator it;
	sort(v.begin(), v.end());
	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		if (i < CiShu)
		{
			int temp = v[0];
			cout << temp << endl;
			for (int j = 0; j < v.size() - 1; j++)
			{
				v[j] = v[j + 1] - temp;
			}
			v.resize(v.size() - 1);
		}
	}
}

int main()
{
	vector<int> v;
	int DataCount;
	int CiShu;
	cin >> DataCount >> CiShu;
	v.resize(DataCount);
	for (int i = 0; i < DataCount; i++)
	{
		cin >> v[i];
	}

	Dispose(v, CiShu);
	return 0;
}
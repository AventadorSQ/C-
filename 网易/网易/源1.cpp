#include<iostream>
using namespace std;
#include<vector>

int main()
{
	vector<vector<int>> v;
	int count;
	while(cin >> count)
	{
		v.resize(count);

		int ShuSize = 0;
		for (int i = 0; i < count; i++)
		{
			cin >> ShuSize;
			v[i].resize(ShuSize);
			for (int j = 0; j < ShuSize; j++)
			{
				cin >> v[i][j];
			}
		}
		int MaxCount = 0;
		int Count = 0;
		int sum = 0;
		for (int i = 0; i < count; i++)
		{
			Count = 0;
			MaxCount = 0;
			sum = 0;
			for (int j = 0; j < v[i].size(); j++)
			{
				if (sum <= v[i][j])
				{
					Count++;
					sum += v[i][j];
					if (j == v[i].size() - 1)
					{
						if (MaxCount < Count)
						{
							MaxCount = Count;
						}
					}
				}
				else if (sum > v[i][j])
				{
					if (MaxCount < Count)
					{
						j--;
						MaxCount = Count;
						Count = 0;
						sum = 0;
					}
				}
			}
			cout << MaxCount << endl;
		}
	}
	return 0;
}
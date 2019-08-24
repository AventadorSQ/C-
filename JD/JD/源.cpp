#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

bool IsTrue(vector<int>& temp, vector<int>& V, int pos)
{
	for (size_t i = 0; i <= pos; i++)
	{
		for (size_t j = 0; j <= pos; j++)
		{
			if (temp[i] == V[j])
			{
				break;
			}
			if (j == pos)
			{
				return false;
			}
		}
	}
	return true;
}
void Dispose(vector<int>& V)
{
	int MaxCount = 0;
	vector<int> temp;
	for (size_t i = 0; i < V.size(); i++)
	{
		temp.push_back(V[i]);
	}
	sort(temp.begin(), temp.end());

	int pos = 0;
	for (size_t x = 0; x < V.size(); x++)
	{
		for (size_t y = pos; y < V.size(); y++)
		{
			if (V[x] == temp[y])
			{
				pos = y;
				if (IsTrue(temp, V, pos) == true)
				{
					MaxCount++;
					x = pos;
					y = pos;
					break;
				}
				else
				{
					break;
				}
			}
		}
	}
	cout << MaxCount;
}

int main()
{
	long long count = 0;
	vector<int> v;
	while (cin >> count)
	{
		int temp = 0;
		v.resize(count);
		for (long long i = 0; i < count; i++)
		{
			cin >> temp;
			v[i] = temp;
		}
		Dispose(v);
	}
	return 0;
}
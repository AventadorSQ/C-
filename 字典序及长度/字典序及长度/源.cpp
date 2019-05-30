#include<iostream>
using namespace std;
#include<vector>
#include<string>

void Dispose(vector<string>& v)
{
	int size = v.size();
	if (v.size() == 1)
	{
		cout << "both" << endl;
		return;
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (v[i] > v[i + 1])
		{
			cout << "none" << endl;
			return;
		}

		int SizeStr = v[i].size();
		for (int j = 0; j < SizeStr; j++)
		{
			if (v[i][j] > v[i + 1][j])
			{
				cout << "none" << endl;
				return;
			}
		}
	}
	cout << "both" << endl;
}

int main()
{
	vector<string> v;
	int count = 0;
	while (cin >> count)
	{
		for (int i = 0; i < count; i++)
		{
			getline(cin, v[i]);
		}
		Dispose(v);
	}
	system("pause");
	return 0;
}
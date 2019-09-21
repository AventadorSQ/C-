#include<iostream>
using namespace std;
#include<vector>
#include<string>

void Dispose(vector<string>& v)
{
	int size = v.size();
	for (int i = 0; i < size; i++)
	{
		if (v[i].size() < 11)
		{
			cout << "NO" << endl;
			continue;
		}
		for (size_t j = 0; j < v[i].size() - 10; j++)
		{
			if (v[i][j] == '8')
			{
				cout << "YES" << endl;
				break;
			}
			else if (j == v[i].size() - 11)
			{
				cout << "NO" << endl;
				break;
			}
		}
	}
}

int main()
{
	vector<string> v;
	int count = 0;
	cin >> count;
	int WeiShu;
	string str;
	for (int i = 0; i < count; i++)
	{
		cin >> WeiShu;
		str.resize(WeiShu);
		for (int j = 0; j < WeiShu; j++)
		{
			cin >> str[j];
		}
		v.push_back(str);
	}

	Dispose(v);
	//system("pause");
	return 0;
}
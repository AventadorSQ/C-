#include<iostream>
using namespace std;
#include<vector>
#include<string>

void Dispose(string s)
{
	vector<int> v;
	vector<int> v1;
	size_t size = s.size();
	size_t pos = 0;
	size_t pos1 = 0;
	while (1)
	{
		pos1 = s.find(',');
		if (pos1 < s.size())
		{
			v.push_back(atof(s.substr(pos, pos1 - pos).c_str()));
		}
		else
		{
			v.push_back(atof(s.substr(pos).c_str()));
		}
		v1.push_back(atol(s.substr(pos, 1).c_str()));
		if (pos1 < size)
		{
			s.erase(pos, pos1 - pos + 1);
		}
		else
		{
			break;
		}
	}
	for (int j = 0; j < v1.size(); j++)
	{
		int Min = 0;
		size_t sizev1 = v1.size();
		for (int i = 0; i < sizev1 - 1; i++)
		{
			if (v1[i] > v1[i + 1] && v1[i + 1] < 10)
			{
				Min = i + 1;
			}
		}
		cout << v[Min];
		v1[Min] = 10;
	}
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		Dispose(str);
	}
	return 0;
}
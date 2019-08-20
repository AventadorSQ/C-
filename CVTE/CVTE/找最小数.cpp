#include<iostream>
#include<string>
#include<vector>
using namespace std;

void Dispose(string str)
{
	vector<string> v;
	size_t size = str.size();
	size_t pos = 0;
	while (1)
	{
		pos = str.rfind(' ');
		v.push_back(str.substr(pos + 1));
		if (pos >= size || pos < 0)
		{
			break;
		}
		str.erase(pos);
	}
	for (auto e : v)
	{
		cout << e << " ";
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
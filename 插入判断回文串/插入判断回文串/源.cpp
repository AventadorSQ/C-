#include<iostream>
using namespace std;
#include<string>

void Dispose(string& a, string& b)
{
	string temp;
	int Count = 0;
	for (int i = 0; i <= a.size(); i++)
	{
		temp = a;
		//string::iterator it = temp.begin();
		//for (int j = 0; j < b.size(); j++)
		//{
			temp.insert(i, b);
		//}
		for (int x = 0; x < temp.size(); x++)
		{
			if (temp[x] == temp[temp.size() - x - 1])
			{
				if (x == temp.size() / 2)
				{
					Count++;
				}
			}
			else
			{
				break;
			}
		}
	}
	cout << Count << endl;
}

int main()
{
	string Sa;
	string Sb;
	while (getline(cin, Sa) && getline(cin, Sb))
	{
		Dispose(Sa, Sb);
	}
	return 0;
}
#include<iostream>
using namespace std;
#include<string>
#include<vector>

//2020届秋季校招美团点评编程一
//void Func()
//{
//	string s("ABAC");
//	int count = 0;
//	cin >> count;
//	size_t size = s.size();
//	for (int i = 0; i < count; i++)
//	{
//		cout << s[i%size];
//	}
//}

//MPMPCPMCMDEFEGDEHINHKLIN
//MPMPCPMCM DEFEGDE HINHKLIN

//2020届秋季校招美团点评编程2
void Func()
{
	vector<int> v;
	string s;
	cin >> s;
	int count = 0;
	int size = s.size();
	int MaxWei = 0;
	int Temp = 0;
	int i = 0;
	while (i < size && MaxWei < size)
	{
		for (; i <= MaxWei; i++)
		{
			int pos = s.rfind(s[i]);
			if (pos > MaxWei)
			{
				MaxWei = pos;
			}
		}
		v.push_back(MaxWei + 1 - Temp);
		Temp = MaxWei + 1;
		MaxWei++;
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

int main()
{
	Func();
	system("pause");
	return 0;
}
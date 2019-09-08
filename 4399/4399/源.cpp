#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>


class MapLei
{
public:
	string vKey;
	int vVal;
	int vtime;
};

//2
//10_123_50_A0 1566918054
//10_123_50_A1 1566918054
//10_123_50_A1 1566918055
//10_123_50_A3 1566918055
//10_123_50_A4 1566918056
//
//10_123_50_A0 1566918054
//10_123_50_A1 1566918055
void Dispose(map<string, int>& Map, vector<MapLei>& v, int size, map<string, int>& CoutMap)
{
	int lenthV = v.size();

	map<string, int>::iterator it;
	int Size = Map.size();
	string Key = v[lenthV -1].vKey;
	it = Map.find(Key);
	if (it != Map.end())
	{
		if (it->second < v[lenthV -1].vVal)
		{
			it->second = v[lenthV - 1].vVal;
			for (int i = 0; i < lenthV; i++)
			{
				if (v[i].vKey == Key)
				{
					v[i].vtime = v[lenthV - 1].vtime;
				}
			}
		}
	}
	else
	{
		if (Size < size)
		{
			Map.insert(make_pair(v[lenthV - 1].vKey, v[lenthV - 1].vVal));
		}
		else
		{
			int MinTime = 0;
			int temp = v[0].vtime;
			for (int i = 0; i < lenthV; i++)
			{
				if (v[i].vtime < temp)
				{
					MinTime = i;
					temp = v[i].vtime;

				}
			}
			string zhujian = v[MinTime].vKey;

			//for (auto i = v.begin(); i != v.end(); i++)
			//{
			//	if(i->vKey )
			//}

			for (int i = 0; i < v.size(); i++)
			{
				if (i != MinTime)
				{

					//vector<string>::iterator pos = find(v.begin(), v.end(), );
					if (v[i].vKey == v[MinTime].vKey)
					{
						//v.erase();
						for (int j = i; j < v.size() - 1; j++)
						{
							v[j] = v[j + 1];
						}
					}
					v.pop_back();
				}
			}
			it = Map.find(v[MinTime].vKey);
			CoutMap.insert(make_pair(v[MinTime].vKey, v[MinTime].vVal));
			Map.erase(it);
			Map.insert(make_pair(v[lenthV - 1].vKey, v[lenthV - 1].vVal));
		}
	}
}

int main()
{
	vector<MapLei> v;
	map<string, int> Map;
	map<string, int> CoutMap;
	int size;

	string Key = "as";
	int data;
	cin >> size;
	int i = 0;
	while (Key != "\n")
	{
		i++;
		cin >> Key >> data;
		MapLei M;
		M.vKey = Key;
		M.vVal = data;
		M.vtime = i;
		v.push_back(M);
		Dispose(Map, v, size, CoutMap);
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
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

//实现插入操作
void Dispose(map<string, int>& Map, vector<MapLei>& v, int size, map<string, int>& CoutMap)
{
	//计算源数据的大小，待插入的数据就是最后一个数据
	int lenthV = v.size();

	//计算map大小以备判断map是否已满
	int Size = Map.size();

	//拿出待插入的Key，
	string Key = v[lenthV -1].vKey;

	//迭代器去查找待查数据是否在Map里面
	map<string, int>::iterator it;
	it = Map.find(Key);

	//如果存在就看是否需要更新value
	if (it != Map.end())
	{
		//如果源value小就更新value
		if (it->second < v[lenthV -1].vVal)
		{
			it->second = v[lenthV - 1].vVal;

			//并且将放源数据的时间修改为最新事件，并且删除待插新元素
			for (int i = 0; i < lenthV; i++)
			{
				if (v[i].vKey == Key && (i != v.size() - 1))
				{
					v[i].vtime = v[lenthV - 1].vtime;
					v[i].vVal = v[lenthV - 1].vVal;
					v.pop_back();
					break;
				}
			}
		}
	}
	else//如果Map中没有待插数据
	{
		//如果Map的Size没满，直接插入
		if (Size < size)
		{
			Map.insert(make_pair(v[lenthV - 1].vKey, v[lenthV - 1].vVal));
		}
		else//如果满了，就需要剔除一个最久的数据
		{
			//用来标记存放最久的数据的位置
			int MinTime = 0;
			//存放最久的数据
			int temp = v[0].vtime;
			for (int i = 0; i < lenthV; i++)
			{
				if (v[i].vtime < temp)
				{
					MinTime = i;
					temp = v[i].vtime;
				}
			}
			//将最久值修改为未来值抽象改掉
			v[MinTime].vtime = 100000;
			//string zhujian = v[MinTime].vKey;

			//for (int i = 0; i < v.size(); i++)

			//{
			//	if (i != MinTime)
			//	{

			//		//vector<string>::iterator pos = find(v.begin(), v.end(), );
			//		if (v[i].vKey == v[MinTime].vKey)
			//		{
			//			//v.erase();
			//			for (int j = i; j < v.size() - 1; j++)
			//			{
			//				v[j] = v[j + 1];
			//			}
			//		}
			//		v.pop_back();
			//	}
			//}

			//查找最久的数据
			it = Map.find(v[MinTime].vKey);
			//淘汰的数据放入map以备输出
			CoutMap.insert(make_pair(v[MinTime].vKey, v[MinTime].vVal));
			//删除淘汰数据
			Map.erase(it);

			//****记得删除源数据vector中最久数据
			//将新数据插入
			Map.insert(make_pair(v[lenthV - 1].vKey, v[lenthV - 1].vVal));
		}
	}
}

int main()
{
	vector<MapLei> v;
	//建立插入的数据容器
	map<string, int> Map;
	//保存淘汰数据
	map<string, int> CoutMap;
	int size;

	string Key = "";
	int data;

	cin >> size;
	int i = 0;
	while (i < 5)
	{
		i++;
		cin >> Key >> data;
		MapLei M;
		M.vKey = Key;
		M.vVal = data;
		M.vtime = i;
		v.push_back(M);
		Dispose(Map, v, size, CoutMap);
		cin.clear();
	}

	cout << " 输出淘汰数据：" << endl;
	for (auto i : CoutMap)
	{
		cout << i.first << " " << i.second << endl;
	}
	system("pause");
	return 0;
}
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

//ʵ�ֲ������
void Dispose(map<string, int>& Map, vector<MapLei>& v, int size, map<string, int>& CoutMap)
{
	//����Դ���ݵĴ�С������������ݾ������һ������
	int lenthV = v.size();

	//����map��С�Ա��ж�map�Ƿ�����
	int Size = Map.size();

	//�ó��������Key��
	string Key = v[lenthV -1].vKey;

	//������ȥ���Ҵ��������Ƿ���Map����
	map<string, int>::iterator it;
	it = Map.find(Key);

	//������ھͿ��Ƿ���Ҫ����value
	if (it != Map.end())
	{
		//���ԴvalueС�͸���value
		if (it->second < v[lenthV -1].vVal)
		{
			it->second = v[lenthV - 1].vVal;

			//���ҽ���Դ���ݵ�ʱ���޸�Ϊ�����¼�������ɾ��������Ԫ��
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
	else//���Map��û�д�������
	{
		//���Map��Sizeû����ֱ�Ӳ���
		if (Size < size)
		{
			Map.insert(make_pair(v[lenthV - 1].vKey, v[lenthV - 1].vVal));
		}
		else//������ˣ�����Ҫ�޳�һ����õ�����
		{
			//������Ǵ����õ����ݵ�λ��
			int MinTime = 0;
			//�����õ�����
			int temp = v[0].vtime;
			for (int i = 0; i < lenthV; i++)
			{
				if (v[i].vtime < temp)
				{
					MinTime = i;
					temp = v[i].vtime;
				}
			}
			//�����ֵ�޸�Ϊδ��ֵ����ĵ�
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

			//������õ�����
			it = Map.find(v[MinTime].vKey);
			//��̭�����ݷ���map�Ա����
			CoutMap.insert(make_pair(v[MinTime].vKey, v[MinTime].vVal));
			//ɾ����̭����
			Map.erase(it);

			//****�ǵ�ɾ��Դ����vector���������
			//�������ݲ���
			Map.insert(make_pair(v[lenthV - 1].vKey, v[lenthV - 1].vVal));
		}
	}
}

int main()
{
	vector<MapLei> v;
	//�����������������
	map<string, int> Map;
	//������̭����
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

	cout << " �����̭���ݣ�" << endl;
	for (auto i : CoutMap)
	{
		cout << i.first << " " << i.second << endl;
	}
	system("pause");
	return 0;
}
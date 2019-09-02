#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void Dispose(int& PackSize, int& KindCount, vector<int>& KindG, vector<int>& KindV)
{
	vector<vector<int>> DisposeTable(KindCount + 1, vector<int>(PackSize + 1, 0));
	for (int i = 1; i <= KindCount; i++)
	{
		for (int j = 1; j <= PackSize; j++)
		{
			if (KindG[i - 1] > j)
			{
				DisposeTable[i][j] = DisposeTable[i][j -1];
			}
			else//�������װ��ȥ
			{
				//������Ʒװ��ȥ�����ֵ��С
				int NewData = DisposeTable[i - 1][j - KindG[i - 1]] + KindV[i - 1];
				//��װ�벻װ���бȽϣ�ȡ���ֵ
				DisposeTable[i][j] = max(NewData, DisposeTable[i - 1][j]);
			}
		}
	}
	cout << "������СΪ: " << PackSize << " ����װ������ֵ��: " << DisposeTable[KindCount][PackSize] << endl;
}

int main()
{
	int PackSize = 0;
	int KindCount = 0;
	vector<int> KindG;
	vector<int> KindV;
	while (cin >> PackSize >> KindCount)
	{
		int temp;
		for (int i = 0; i < KindCount; i++)
		{
			cin >> temp;
			KindG.push_back(temp);
		}
		for (int i = 0; i < KindCount; i++)
		{
			cin >> temp;
			KindV.push_back(temp);
		}
		if (PackSize > 0 && KindCount > 0)
		{
			Dispose(PackSize, KindCount, KindG, KindV);
		}
	}
	return 0;
}
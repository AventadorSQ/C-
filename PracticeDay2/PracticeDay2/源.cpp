//��.���
//1. ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��
//һ������Ϊn����������A, ��������һ�������ǰ�����A��Ϊ���ɶ�����������, ţţ��֪�������ٿ��԰����
//�����Ϊ��������������.
//��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, �������
//2
//����������
//����ĵ�һ��Ϊһ��������n(1 �� n �� 10 ^ 5)
//�ڶ��а���n������A_i(1 �� A_i �� 10 ^ 9), ��ʾ����A��ÿ�����֡�
//���������
//���һ��������ʾţţ���Խ�A���ٻ���Ϊ���ٶ�����������
//ʾ��1 :
//����
//6
//1 2 3 2 2 1
//���
//2

#include<iostream>
#include<vector>
using namespace std;

int DisposeData(vector<int>& V)
{
	int MaxFirstEqual = 0;
	int MaxLastEqual = 0;
	int MinFirstEqual = 0;
	int MinLastEqual = 0;
	int flag = 0;
	//��¼��ʼ��λ��
	int equal = 0;
	//��¼���ٿ��Էָ����������
	int num = 0;
	//�жϼ�ֵ����λ��
	for (size_t i = 1; i < V.size() - 1; i++)
	{
		//���������ͬ��һֱ�����ߡ�
		while (V[i] == V[i - 1])
		{
			i++;
			if (i >= V.size())
			{
				return 1;
			}
		}
		//�����������
		//�����ǰ���ݴ���ǰ�����ݣ���������һ���ֵ��ڵ�ǰ���ݣ�
		if (V[i] > V[i - 1] && V[i] == V[i + 1])
		{
			MaxFirstEqual = i;
			while (V[i] == V[i + 1])
			{
				i++;
				if (i >= V.size() - 1)
				{
					break;
				}

			}
			//���������ȵ����ݣ���ǰ���ݴ��ں����һ������˵���Ǽ���ֵ
			if (i < V.size() - 1)
			{
				if (V[i] > V[i + 1])
				{
					MaxLastEqual = i;
					num++;
				}
			}
		}
		//�����ǰ����С��ǰ�����ݣ���������һ���ֵ��ڵ�ǰ���ݣ�
		if (V[i] < V[i - 1] && V[i] == V[i + 1])
		{
			MinFirstEqual = i;
			while (V[i] == V[i + 1])
			{
				i++;
				if (i >= V.size() - 1)
				{
					break;
				}

			}
			//���������ȵ����ݣ���ǰ����С�ں����һ������˵���Ǽ���ֵ
			if (i < V.size() - 1)
			{
				if (V[i] < V[i + 1])
				{
					MinLastEqual = i;
					num++;
				}
			}
		}
		//��Сֵ
		if (V[i] < V[i - 1] && V[i] < V[i + 1])
		{
			MinFirstEqual = MinLastEqual = i;
			num++;
		}
		//����ֵ
		if (V[i] > V[i - 1] && V[i] > V[i + 1])
		{
			MaxFirstEqual = MaxLastEqual = i;
			num++;
		}
		//�жϼ�ֵ֮����û������
		//ÿ����num--��
		if (MaxFirstEqual - MinLastEqual == 1 || MaxLastEqual - MinFirstEqual == -1)
		{
			flag++;
			if (flag % 2 == 0)
			{
				num--;
			}
		}
	}
	//��ֵ������1���Ƿָ����������
	num++;
	return num;
}
int main()
{
	//�����С
	int count = 0;
	vector<int> v;
	cout << "��������Ҫ�����ݸ���:";
	cin >> count;
	cout << "������" << count << "������:";
	v.resize(count, 0);
	for (int i = 0; i < count; i++)
	{
		cin >> v[i];
	}
	int num = DisposeData(v);
	cout << "num = " << num << endl;
	system("pause");
	return 0;
}
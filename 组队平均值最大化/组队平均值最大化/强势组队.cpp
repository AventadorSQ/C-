//1.. ţţ�ٰ���һ�α�̱���, �μӱ�������3*n��ѡ��, ÿ��ѡ�ֶ���һ��ˮƽֵa_i.����Ҫ����Щѡ�ֽ������,
//һ�����n������, ��ÿ������3��.ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��
//���� :
//һ������������Ա��ˮƽֵ�ֱ���3, 3, 3.��ô�����ˮƽֵ��3
//һ������������Ա��ˮƽֵ�ֱ���3, 2, 3.��ô�����ˮƽֵ��3
//һ������������Ա��ˮƽֵ�ֱ���1, 5, 2.��ô�����ˮƽֵ��2
//Ϊ���ñ������п���, ţţ�밲�Ŷ���ʹ���ж����ˮƽֵ�ܺ����
//��������ʾ :
//���ţţ��6����Ա���ֵ���������
//�������Ϊ :
//team1: {1, 2, 5}, team2 : {5, 5, 8}, ��ʱ��ˮƽֵ�ܺ�Ϊ7.
//	���������Ϊ :
//	NOWCODER.COM
//	ţ������������������� / �������
//	ţ�ͳ�Ʒ - http ://www.nowcoder.com
//	team1 : {2, 5, 8}, team2 : {1, 5, 5}, ��ʱ��ˮƽֵ�ܺ�Ϊ10.
//	û�б��ܺ�Ϊ10����ķ���, �������10.
//	����������
//	����ĵ�һ��Ϊһ��������n(1 �� n �� 10 ^ 5)
//	�ڶ��а���3*n������a_i(1 �� a_i �� 10 ^ 9), ��ʾÿ������ѡ�ֵ�ˮƽֵ.
//	���������
//	���һ��������ʾ���ж����ˮƽֵ�ܺ����ֵ.
//	ʾ��1:
//	   ����
//		   2
//		   5 2 8 5 1 5
//		   ���
//		   10
#include<iostream>
using namespace std;

#if 0
//��������
void InsertSort(int Ptr[], int count)
{
	int i;
	int j;
	int temp;
	//ÿ��ȡһ����
	for (i = 1; i < count; i++)
	{
		temp = Ptr[i];
		//���бȽ�����
		for (j = i - 1; j >= 0; j--)
		{
			if (temp >= Ptr[j])
			{
				break;
			}
			else
			{
				Ptr[j + 1] = Ptr[j];
			}
		}
		//���������ŵ����յ�λ����
		Ptr[j + 1] = temp;
	}
}

//��ӡ����������
void PrintPtr(int Ptr[], int count)
{
	cout << "Ptr[" << count << "]:";
	for (int i = 0; i < count; i++)
	{
		cout << Ptr[i] << " ";
	}
	cout << endl;
}

//����ָ�����
int Dispose(int ptr[], int count)
{
	int Sum = 0;
	int Count = count / 3;
	for (int i = Count; i < count; i = i + 2)
	{
		Sum += ptr[i];
	}
	return Sum;
}

void Scanf()
{
	int count = 0;
	do
	{
		cout << "������һ����������";
		cin >> count;
	}
	while (count <= 0);
	int* ptr = (int*)malloc(sizeof(int) * count * 3);
	cout << "������" << 3 * count << "��������";
	for (int i = 0; i < 3 * count; i++)
	{
		cin >> ptr[i];
	}
	//��������
	InsertSort(ptr, 3 * count);

	//��ӡ����������
	PrintPtr(ptr, 3 * count);

	//����ָ�����
	int Sum = Dispose(ptr, 3 * count);
	cout << "Sum = " << Sum << endl;

}
#endif
//********************************************************************************************
#include<vector>
#include<algorithm>
//����ָ�����
int Dispose(int ptr[], int count)
{
	int Sum = 0;
	int Count = count / 3;
	for (int i = Count; i < count; i = i + 2)
	{
		Sum += ptr[i];
	}
	return Sum;
}

void ScanfS()
{
	int count = 0;
	do
	{
		system("cls");
		cout << "������һ����������";
		cin >> count;
	} while (count <= 0);
	vector<int> v(3 * count);
	cout << "������" << 3 * count << "��������";
	for (int i = 0; i < 3 * count; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	//����ָ�����
	int Sum = 0;
	for (int i = count; i < count * 3; i = i + 2)
	{
		Sum += v[i];
	}
	cout << "Sum = " << Sum << endl;

}
int main()
{
	ScanfS();
	system("pause");
	return 0;
}
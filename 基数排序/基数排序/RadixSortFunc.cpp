#include"RadixSort.h"

//��ӡ����������
void PrintArray(int array[], int size)
{
	for (int y = 0; y < size; y++)
	{
		cout << array[y] << " ";
	}
	cout << endl;
}

//2.����������
void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

// { 12,63,156,982,20,478,639,32,2315,123 };
//3.������������
int MaxNum(int array[], int size)
{
	int temp = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] > temp)
		{
			temp = array[i];
		}
	}
	return temp;
}

//4.�������ж���λ����¼��λ��
int MaxWeiShu(int num)
{
	int counts = 0;
	while (1)
	{
		if (num / 10 != 0)
		{
			num = num / 10;
			counts++;
		}
		else
		{
			break;
		}
	}
	return counts + 1;
}

//5.����������һ������
void OneSort(int array[], int size, int i)
{
	//��¼ÿ��Ͱ�д�ŵĸ���
	int arrk[10] = { 0 };
	//����10��Ͱ
	int arr[10][10000] = {0};

	//�����������д�Ž�Ͱ��
	for (int j = 0; j < size; j++)
	{
		//�ж�ÿһ������ͬλ�ϵ���
		int temp = (int)(array[j] / pow(10, i)) % 10;
		//cout << temp << endl;
		//�жϹ���������ĸ�Ͱ�У����Ž�ȥ
		for (int OneNum = 0; OneNum < 10; OneNum++)
		{
			if (temp == OneNum)
			{
				arr[OneNum][arrk[OneNum]] = array[j];
				arrk[OneNum] += 1;
				break;
			}
		}
	}
	int as = 0;
	//��ÿһ�������������·Ż�ԭ����
	for (int OneNum = 0; OneNum < 10; OneNum++)
	{
		//��ÿ��Ͱ�е��������ڷŻ�ԭ����
		for (int x = 0; x < arrk[OneNum]; x++)
		{
			array[as] = arr[OneNum][x];
			as++;
		}
	}

}

//6.��������
void RadixSort(int array[], int size)
{
	if (size <= 1)
	{
		return;
	}
	//������������
	int Max = MaxNum(array, size);

	//�������ж���λ����¼��λ��
	int count = MaxWeiShu(Max);

	//ȡ��ÿ������ÿ��λ�������С��������
	for (int i = 0; i < count; i++)
	{
		//һ������֮���˳��
		OneSort(array, size, i);
	}
}

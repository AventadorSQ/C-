#include"RadixSort.h"

//打印排序后的数组
void PrintArray(int array[], int size)
{
	for (int y = 0; y < size; y++)
	{
		cout << array[y] << " ";
	}
	cout << endl;
}

//2.交换两个数
void Swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

// { 12,63,156,982,20,478,639,32,2315,123 };
//3.数组中最大的数
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

//4.最大的数有多少位，记录其位数
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

//5.将基数进行一次排序
void OneSort(int array[], int size, int i)
{
	//记录每个桶中存放的个数
	int arrk[10] = { 0 };
	//创建10个桶
	int arr[10][10000] = {0};

	//将所有数进行存放进桶中
	for (int j = 0; j < size; j++)
	{
		//判断每一个数不同位上的数
		int temp = (int)(array[j] / pow(10, i)) % 10;
		//cout << temp << endl;
		//判断归类的数在哪个桶中，并放进去
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
	//将每一次排序后的数重新放回原数组
	for (int OneNum = 0; OneNum < 10; OneNum++)
	{
		//将每个桶中的数依次在放回原数组
		for (int x = 0; x < arrk[OneNum]; x++)
		{
			array[as] = arr[OneNum][x];
			as++;
		}
	}

}

//6.基数排序
void RadixSort(int array[], int size)
{
	if (size <= 1)
	{
		return;
	}
	//数组中最大的数
	int Max = MaxNum(array, size);

	//最大的数有多少位，记录其位数
	int count = MaxWeiShu(Max);

	//取出每个数的每个位数按其大小进行排序
	for (int i = 0; i < count; i++)
	{
		//一次排序之后的顺序
		OneSort(array, size, i);
	}
}

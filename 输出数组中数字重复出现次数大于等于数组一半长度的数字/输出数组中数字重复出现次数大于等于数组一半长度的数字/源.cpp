//2. 输入n个整数，输出出现次数大于等于数组长度一半的数。
//输入描述：
//每个测试输入包含 n个空格分割的n个整数，n不超过100，其中有一个整数出现次数大于等于n / 2。
//输出描述：
//输出出现次数大于等于n / 2的数。
//示例1 :
//输入
//3 9 3 2 5 6 7 3 2 3 3 3
//输出
//3

#include<iostream>
#include<vector>
using namespace std;


//打印排序后的数组
void PrintArray(vector<int>& array)
{
	int size = array.size();
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
int MaxNum(vector<int>& array)
{
	int size = array.size();
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
void OneSort(vector<int>& array, int i)
{
	int size = array.size();
	//记录每个桶中存放的个数
	int arrk[10] = { 0 };
	//创建10个桶
	int arr[10][10000] = { 0 };

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
void RadixSort(vector<int>& array)
{
	int size = array.size();
	if (size <= 1)
	{
		return;
	}
	//数组中最大的数
	int Max = MaxNum(array);
	//cout << "vector_size = " << array.size() << endl;
	//cout << "Max = " << Max << endl;
	//最大的数有多少位，记录其位数
	int count = MaxWeiShu(Max);
	//cout << "count = " << count << endl;
	//取出每个数的每个位数按其大小进行排序
	for (int i = 0; i < count; i++)
	{
		//一次排序之后的顺序
		OneSort(array, i);
	}
	//PrintArray(array);
}
void Dispose(vector<int>& V)
{
	//记录数字出现的最大次数
	size_t MaxCount = 0;
	//记录该整数
	int data = 0;
	//cout << "vector_size = " << V.size() << endl;
	RadixSort(V);
	//PrintArray(V);
	//2 2 3 3 3 3 3 3 5 6 7 9
	size_t size = V.size();
	for (size_t i = 0; i < size - 1; i++)
	{
		int dataS = V[i];
		size_t count = 1;
		while (V[i] == V[i + 1])
		{
			count++;
			i++;
		}
		if (count > MaxCount)
		{
			MaxCount = count;
			data = dataS;
		}
	}
	if (MaxCount >= size / 2)
	{
		cout << "出现次数不少于vector有效长度的一半的整数是：";
		cout << data << endl;
	}
	else
	{
		cout << "没有出现次数不少于vector有效长度的一半的整数" << endl;
	}
}
//3 9 3 2 5 6 7 3 2 3 3 3
int main()
{
	cout << "找寻一个数组中重复次数不小于数组一半长度的数字" << endl;
	cout << "请输入N个整数:";
	vector<int> l;

	int data;
	while (cin >> data)
	{
		l.push_back(data);
		if (cin.get() == '\n')
		{
			;
			break;
		}
		//l.push_back(data);
	}
	int count = l.size();
	cout << "vector_size = " << l.size() << endl;
	vector<int> L(l);

	Dispose(L);
	system("pause");
	return 0;
}
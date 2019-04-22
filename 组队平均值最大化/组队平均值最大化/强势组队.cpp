//1.. 牛牛举办了一次编程比赛, 参加比赛的有3*n个选手, 每个选手都有一个水平值a_i.现在要将这些选手进行组队,
//一共组成n个队伍, 即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
//例如 :
//一个队伍三个队员的水平值分别是3, 3, 3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是3, 2, 3.那么队伍的水平值是3
//一个队伍三个队员的水平值分别是1, 5, 2.那么队伍的水平值是2
//为了让比赛更有看点, 牛牛想安排队伍使所有队伍的水平值总和最大。
//如样例所示 :
//如果牛牛把6个队员划分到两个队伍
//如果方案为 :
//team1: {1, 2, 5}, team2 : {5, 5, 8}, 这时候水平值总和为7.
//	而如果方案为 :
//	NOWCODER.COM
//	牛客网·互联网名企笔试 / 面试题库
//	牛客出品 - http ://www.nowcoder.com
//	team1 : {2, 5, 8}, team2 : {1, 5, 5}, 这时候水平值总和为10.
//	没有比总和为10更大的方案, 所以输出10.
//	输入描述：
//	输入的第一行为一个正整数n(1 ≤ n ≤ 10 ^ 5)
//	第二行包括3*n个整数a_i(1 ≤ a_i ≤ 10 ^ 9), 表示每个参赛选手的水平值.
//	输出描述：
//	输出一个整数表示所有队伍的水平值总和最大值.
//	示例1:
//	   输入
//		   2
//		   5 2 8 5 1 5
//		   输出
//		   10
#include<iostream>
using namespace std;

#if 0
//进行排序
void InsertSort(int Ptr[], int count)
{
	int i;
	int j;
	int temp;
	//每次取一个数
	for (i = 1; i < count; i++)
	{
		temp = Ptr[i];
		//进行比较序列
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
		//将操作数放到最终的位置上
		Ptr[j + 1] = temp;
	}
}

//打印排序后的数据
void PrintPtr(int Ptr[], int count)
{
	cout << "Ptr[" << count << "]:";
	for (int i = 0; i < count; i++)
	{
		cout << Ptr[i] << " ";
	}
	cout << endl;
}

//处理分割数据
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
		cout << "请输入一个正整数：";
		cin >> count;
	}
	while (count <= 0);
	int* ptr = (int*)malloc(sizeof(int) * count * 3);
	cout << "请输入" << 3 * count << "个整数：";
	for (int i = 0; i < 3 * count; i++)
	{
		cin >> ptr[i];
	}
	//进行排序
	InsertSort(ptr, 3 * count);

	//打印排序后的数据
	PrintPtr(ptr, 3 * count);

	//处理分割数据
	int Sum = Dispose(ptr, 3 * count);
	cout << "Sum = " << Sum << endl;

}
#endif
//********************************************************************************************
#include<vector>
#include<algorithm>
//处理分割数据
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
		cout << "请输入一个正整数：";
		cin >> count;
	} while (count <= 0);
	vector<int> v(3 * count);
	cout << "请输入" << 3 * count << "个整数：";
	for (int i = 0; i < 3 * count; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	//处理分割数据
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
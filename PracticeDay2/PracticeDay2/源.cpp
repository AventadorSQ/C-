//二.编程
//1. 牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段子序列是非递增或者非递减排序的。牛牛有
//一个长度为n的整数数组A, 他现在有一个任务是把数组A分为若干段排序子序列, 牛牛想知道他最少可以把这个
//数组分为几段排序子序列.
//如样例所示, 牛牛可以把数组A划分为[1, 2, 3]和[2, 2, 1]两个排序子序列, 至少需要划分为2个排序子序列, 所以输出
//2
//输入描述：
//输入的第一行为一个正整数n(1 ≤ n ≤ 10 ^ 5)
//第二行包括n个整数A_i(1 ≤ A_i ≤ 10 ^ 9), 表示数组A的每个数字。
//输出描述：
//输出一个整数表示牛牛可以将A最少划分为多少段排序子序列
//示例1 :
//输入
//6
//1 2 3 2 2 1
//输出
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
	//记录开始等位置
	int equal = 0;
	//记录最少可以分割的子序列数
	int num = 0;
	//判断极值出现位置
	for (size_t i = 1; i < V.size() - 1; i++)
	{
		//如果数据相同就一直往后走。
		while (V[i] == V[i - 1])
		{
			i++;
			if (i >= V.size())
			{
				return 1;
			}
		}
		//两种特殊情况
		//如果当前数据大于前面数据，而后面有一部分等于当前数据，
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
			//如果走完相等的数据，当前数据大于后面第一个数据说明是极大值
			if (i < V.size() - 1)
			{
				if (V[i] > V[i + 1])
				{
					MaxLastEqual = i;
					num++;
				}
			}
		}
		//如果当前数据小于前面数据，而后面有一部分等于当前数据，
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
			//如果走完相等的数据，当前数据小于后面第一个数据说明是极大值
			if (i < V.size() - 1)
			{
				if (V[i] < V[i + 1])
				{
					MinLastEqual = i;
					num++;
				}
			}
		}
		//极小值
		if (V[i] < V[i - 1] && V[i] < V[i + 1])
		{
			MinFirstEqual = MinLastEqual = i;
			num++;
		}
		//极大值
		if (V[i] > V[i - 1] && V[i] > V[i + 1])
		{
			MaxFirstEqual = MaxLastEqual = i;
			num++;
		}
		//判断极值之间有没有数据
		//每两次num--；
		if (MaxFirstEqual - MinLastEqual == 1 || MaxLastEqual - MinFirstEqual == -1)
		{
			flag++;
			if (flag % 2 == 0)
			{
				num--;
			}
		}
	}
	//极值数量加1就是分割的数据数。
	num++;
	return num;
}
int main()
{
	//数组大小
	int count = 0;
	vector<int> v;
	cout << "请输入所要的数据个数:";
	cin >> count;
	cout << "请输入" << count << "个数据:";
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
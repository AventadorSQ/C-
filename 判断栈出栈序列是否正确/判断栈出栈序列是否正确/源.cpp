#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {

		if (pushV.size() != popV.size())
		{
			return false;
		}

		int size = pushV.size();
		for (int i = 0; i < size; i++)
		{
			int data = popV[i];
			//找出pop数据在入栈的位置
			int j = FindDataPos(pushV, data);
			if (j < 0)
			{
				return false;
			}
			//pop每个元素在push中前面的数据必须逆序，有一个不逆序就说明错误出栈
			while (j - 1 > 0)
			{
				//记录入栈前两个元素在出栈中的位置
				int PopBackLocat = FindDataPos(popV, pushV[j - 1]);
				//当个数相同而数据不一样时。就是数据对不上
				if (PopBackLocat < 0)
				{
					return false;
				}
				int PopFrontLocat = FindDataPos(popV, pushV[j - 2]);
				if (PopFrontLocat < 0)
				{
					return false;
				}
				//只能在当前出栈的后面来判断
				if (PopBackLocat > i && PopFrontLocat > i)
				{
					if (PopBackLocat > PopFrontLocat)
					{
						return false;
					}
				}
				j--;
			}
		}
		return true;
	}

	int FindDataPos(vector<int> v, int data)
	{
		size_t size = v.size();
		for (size_t i = 0; i < size; i++)
		{
			if (data == v[i])
			{
				return i;
			}
		}
		return -1;
	}
};

void Test()
{
	vector<int> pushV;
	vector<int> popV;
	int temp;
	cout << "数字不可重复" << endl;
	cout << "请输入入栈序列：";
	while (cin >> temp)
	{
		pushV.push_back(temp);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	cout << "请输入出栈序列：";
	while (cin >> temp)
	{
		popV.push_back(temp);
		if (cin.get() == '\n')
		{
			break;
		}
	}

	Solution S;
	bool b = S.IsPopOrder(pushV, popV);
	if (b == true)
	{
		cout << "出栈序列正确" << endl;
	}
	else
	{
		cout << "出栈顺序不正确" << endl;
	}
}

int main()
{
	Test();
	system("pause");
	return 0;
}

//bool IsPopOrder(vector<int> pushV, vector<int> popV) {
//	stack<int> st;
//	size_t pushIndex = 0, popIndex = 0;
//	while (pushIndex < pushV.size())
//	{
//		st.push(pushV[pushIndex++]);
//		while (!st.empty() && st.top() == popV[popIndex])
//		{
//			st.pop();
//			popIndex++;
//		}
//	}
//	return st.empty();
//}
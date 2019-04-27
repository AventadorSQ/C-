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
			//�ҳ�pop��������ջ��λ��
			int j = FindDataPos(pushV, data);
			if (j < 0)
			{
				return false;
			}
			//popÿ��Ԫ����push��ǰ������ݱ���������һ���������˵�������ջ
			while (j - 1 > 0)
			{
				//��¼��ջǰ����Ԫ���ڳ�ջ�е�λ��
				int PopBackLocat = FindDataPos(popV, pushV[j - 1]);
				//��������ͬ�����ݲ�һ��ʱ���������ݶԲ���
				if (PopBackLocat < 0)
				{
					return false;
				}
				int PopFrontLocat = FindDataPos(popV, pushV[j - 2]);
				if (PopFrontLocat < 0)
				{
					return false;
				}
				//ֻ���ڵ�ǰ��ջ�ĺ������ж�
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
	cout << "���ֲ����ظ�" << endl;
	cout << "��������ջ���У�";
	while (cin >> temp)
	{
		pushV.push_back(temp);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	cout << "�������ջ���У�";
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
		cout << "��ջ������ȷ" << endl;
	}
	else
	{
		cout << "��ջ˳����ȷ" << endl;
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
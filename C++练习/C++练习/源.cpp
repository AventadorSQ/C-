//#include<iostream>
//using namespace std;
////int main()
////{
////	int a = 1, b = 0, c = -1, d = 0;
////	d = ++a || ++b&&++c;
////	cout << d << endl;
////	system("pause");
////	return 0;
////}
//
#include<iostream>
using namespace std;

int Fibonacci(int num)
{
	static int BaseNum = 0;
	if (num == 0)
	{
		return num + 1;
	}
	int temp = num;
	num = num + BaseNum;
	BaseNum = temp;
	return num;
}

int main()
{
	int num = 0;
	int FibNum = 0;
	int FibNum1 = 0;
	int FibNum2 = 0;
	while (cin >> num)
	{
		while (1)
		{
			if (num > FibNum)
			{
				FibNum1 = FibNum;
				FibNum = Fibonacci(FibNum);
			}
			else
			{
				FibNum2 = FibNum;;
				break;
			}
		}

		int count1 = num - FibNum1;
		int count2 = FibNum2 - num;
		if (count1 < count2)
		{
			cout << count1 << endl;
		}
		else
		{
			cout << count2 << endl;
		}
	}
	system("pause");
	return 0;
}

//#include<stack>
//
//class Parenthesis {
//public:
//	bool chkParenthesis(string A, int n) {
//		// write code here
//		stack<char> sta;
//		if (A.size() % 2 != 0)
//		{
//			return false;
//		}
//		else
//		{
//			for (size_t i = 0; i < A.size(); i++)
//			{
//				if (A[i] != '(' && A[i] != ')')
//				{
//					return false;
//				}
//				if (A[i] == '(')
//				{
//					sta.push(A[i]);
//				}
//				else
//				{
//					if (sta.size() == 0)
//					{
//						return false;
//					}
//					if (sta.top() == '(')
//					{
//						sta.pop();
//					}
//					else
//					{
//						return false;
//					}
//				}
//			}
//			return true;
//		}
//	}
//};
//
//int main()
//{
//	Parenthesis s;
//	string str = "()()(((())))";
//	int i = s.chkParenthesis(str, 12);
//	cout << i << endl;
//	system("pause");
//	return 0;
//}
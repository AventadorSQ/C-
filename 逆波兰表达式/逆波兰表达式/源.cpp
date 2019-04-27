#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (const auto& str : tokens)
		{
			if (str == "+" || str == "-" || str == "*" || str == "/")
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				switch (str[0])
				{
				case '+':
					st.push(left + right);
					break;
				case '-':
					st.push(left - right);
					break;
				case '*':
					st.push(left * right);
					break;
				case '/':
					st.push(left / right);
					break;
				}
			}
			else
			{
				st.push(atoi(str.c_str()));
			}
		}
		return st.top();
	}
};

void Test()
{
	Solution S;
	vector<string> v;
	cout << "请输入后缀表达式：";
	string temp;
	while (cin >> temp)
	{
		v.push_back(temp);
		if (cin.get() == '\n')
		{
			break;
		}
	}
	cout << S.evalRPN(v) << endl;
}

int main()
{
	Test();
	system("pause");
	return 0;
}
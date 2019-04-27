#include<iostream>
#include<stack>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		Stk.push(x);
		if (MinStk.empty() || x <= MinStk.top())//二者条件不能颠倒否则崩溃，因为当栈为空时就不能去取数据比较大小
		{
			MinStk.push(x);
		}
	}

	void pop() {
		if (Stk.top() == MinStk.top())
		{
			MinStk.pop();
		}
		Stk.pop();
	}

	int top() {
		return Stk.top();
	}

	int getMin() {
		return MinStk.top();
	}
	stack<int> Stk;
	stack<int> MinStk;
};

void StackTest()
{
	MinStack Ms;
	Ms.push(5);
	Ms.push(3);
	Ms.push(4);
	Ms.push(2);
	Ms.push(7);
	while (!Ms.Stk.empty())
	{
		cout << Ms.getMin() << endl;
		Ms.pop();
		//cout << Ms.getMin() << endl;  不能放在pop后面否则崩溃，因为在取最后一个元素时会造成去取空元素
	}
}

int main()
{
	StackTest();
	system("pause");
	return 0;
}
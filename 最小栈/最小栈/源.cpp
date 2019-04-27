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
		if (MinStk.empty() || x <= MinStk.top())//�����������ܵߵ������������Ϊ��ջΪ��ʱ�Ͳ���ȥȡ���ݱȽϴ�С
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
		//cout << Ms.getMin() << endl;  ���ܷ���pop��������������Ϊ��ȡ���һ��Ԫ��ʱ�����ȥȡ��Ԫ��
	}
}

int main()
{
	StackTest();
	system("pause");
	return 0;
}
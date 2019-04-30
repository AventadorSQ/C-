#include<iostream>
#include<queue>
using namespace std;

namespace StackAndQueue
{
	//模拟实现栈
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		//1.构造函数
		stack()
		{}

		//2.压栈
		void push(const T& data)
		{
			Deque.push_back(data);
		}

		//3.弹栈
		void pop()
		{
			Deque.pop_back();
		}

		//4.返回栈顶元素
		T& top()
		{
			return Deque.back();
		}

		T& top()const
		{
			return Deque.back();
		}

		//5.判断栈是否为空
		bool empty()const
		{
			return Deque.empty();
		}

		//6.获取栈的数据个数
		size_t size()const
		{
			return Deque.size();
		}

		//7.析构函数
		~stack()
		{}
	private:
		Container Deque;
	};

	//模拟实现队列
	template<class T, class Contianer = deque<T>>
	class queue
	{
	public:
		//1.构造函数
		queue()
		{}

		//2.入队列
		void push(const T& data)
		{
			Deque.push_back(data);
		}

		//3.出队列
		void pop()
		{
			Deque.pop_front();
		}

		//4.获取队尾元素
		T& back()
		{
			return Deque.back();
		}

		T& back()const
		{
			return Deque.back();
		}
		//5.获取队首元素
		T& front()
		{
			return Deque.front();
		}

		T& front()const
		{
			return Deque.front();
		}
		//6.判断队列是否为空
		bool empty()
		{
			return Deque.empty();
		}
		//7.获取队列的数据个数
		size_t size()
		{
			return Deque.size();
		}
		//8.析构函数
		~queue()
		{}
	private:
		Contianer Deque;
	};
}

void TestStack()
{
	StackAndQueue::stack<int> S;
	cout << "stack empty = " << S.empty() << endl;
	S.push(0);
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	S.push(6);

	cout << "stack size = " << S.size() << endl;
	cout << "stack top = " << S.top() << endl;
	cout << "stack empty = " << S.empty() << endl;

	S.pop();
	cout << "stack popOne" << endl;
	cout << "stack size = " << S.size() << endl;
	cout << "stack top = " << S.top() << endl;
	cout << "stack empty = " << S.empty() << endl;
}

void TestQueue()
{
	StackAndQueue::queue<int> Q;
	cout << "queue empty = " << Q.empty() << endl;
	Q.push(0);
	Q.push(1);
	Q.push(3);
	Q.push(4);
	Q.push(5);
	Q.push(6);

	cout << "queue size = " << Q.size() << endl;
	cout << "queue back = " << Q.back() << endl;
	cout << "queue front = " << Q.front() << endl;
	cout << "queue empty = " << Q.empty() << endl;

	Q.pop();
	cout << "queue popOne" << endl;
	cout << "queue size = " << Q.size() << endl;
	cout << "queue back = " << Q.back() << endl;
	cout << "queue front = " << Q.front() << endl;
	cout << "queue empty = " << Q.empty() << endl;
}
int main()
{
	TestQueue();
	system("pause");
	return 0;
}
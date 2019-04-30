#include<iostream>
#include<queue>
using namespace std;

namespace StackAndQueue
{
	//ģ��ʵ��ջ
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		//1.���캯��
		stack()
		{}

		//2.ѹջ
		void push(const T& data)
		{
			Deque.push_back(data);
		}

		//3.��ջ
		void pop()
		{
			Deque.pop_back();
		}

		//4.����ջ��Ԫ��
		T& top()
		{
			return Deque.back();
		}

		T& top()const
		{
			return Deque.back();
		}

		//5.�ж�ջ�Ƿ�Ϊ��
		bool empty()const
		{
			return Deque.empty();
		}

		//6.��ȡջ�����ݸ���
		size_t size()const
		{
			return Deque.size();
		}

		//7.��������
		~stack()
		{}
	private:
		Container Deque;
	};

	//ģ��ʵ�ֶ���
	template<class T, class Contianer = deque<T>>
	class queue
	{
	public:
		//1.���캯��
		queue()
		{}

		//2.�����
		void push(const T& data)
		{
			Deque.push_back(data);
		}

		//3.������
		void pop()
		{
			Deque.pop_front();
		}

		//4.��ȡ��βԪ��
		T& back()
		{
			return Deque.back();
		}

		T& back()const
		{
			return Deque.back();
		}
		//5.��ȡ����Ԫ��
		T& front()
		{
			return Deque.front();
		}

		T& front()const
		{
			return Deque.front();
		}
		//6.�ж϶����Ƿ�Ϊ��
		bool empty()
		{
			return Deque.empty();
		}
		//7.��ȡ���е����ݸ���
		size_t size()
		{
			return Deque.size();
		}
		//8.��������
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
#include<iostream>
using namespace std;

#include<queue>

namespace S
{
	template<class T, class Container = deque<T>>
	class stack
	{
		stack()
		{}

		void push(const T& data)
		{
			_con.push.back(data);
		}

		void pop()
		{
			_con.pop_back();
		}

		T& top()
		{
			return _con.back();
		}

		const T& top()const
		{
			return _con.back();
		}

		size_t size()const
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};

	template<class T, class Container = deque<T>>
	class queue
	{
		queue()
		{}

		void push(const T& data)
		{
			Que.push_back(data);
		}

		void pop()
		{
			Que.pop_front();
		}

		T& front()
		{
			return Que.front();
		}

		T& front()const
		{
			return Que.front();
		}

		T& back()
		{
			return Que.back();
		}

		T& back()const
		{
			return Que.back();
		}

		size_t size()const
		{
			return Que.size();
		}
		bool empty()
		{
			return Que.empty();
		}
	private:
		Container Que;
	};
}

int main()
{
	system("pasue");
	return 0;
}
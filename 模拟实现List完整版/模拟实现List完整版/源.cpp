#include<iostream>
#include<list>
using namespace std;


//list底层结构：带头节点的双向循环链表
//为什么带头节点
//1.头部插入和删除比较简单
//2.区分begin(),和end()

namespace ListS
{
	template<class T>
	struct ListNode
	{
		ListNode(const T& data = T())
			:Prev(nullptr)
			, Next(nullptr)
			, data(data)
		{}
		ListNode<T>* Prev;
		ListNode<T>* Next;
		T data;
	};

	//迭代器当成像指针一样的方式使用：指针具有的操作 迭代器都必须支持

	//operator*()
	//operator->()
	//operator++()
	//operator--()：视具体结构对待
	//operator!=()
	//operator==()


	template<class T, class Ref, class Ptr>                //三个参数分别是什么意思各自的作用？？？
														   //template<class T, class Ref, class Ptr> 
														   //T 元素类型
														   //普通类型：
														   //Ref代表T&   Ptr代表T*
														   //const时
														   //Ref代表const T&，  Ptr代表const T*
														   //为了统一普通类型和const类型



														   //1.实现这个迭代器类是因为它不是原生态指针，底层是双向链表，空间不一定连续。
														   //2.在这个类中实现++，--，==，!=，*，->。操作（指针操作，迭代器都可以支持）
														   //3.直接在list类中内嵌对应迭代器类型使用。为简单取别名
														   //typedef ListIterator<> iterator

	struct ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
		typedef Ref Ref;
		typedef Ptr Ptr;
	public:
		ListIterator(PNode pNode = nullptr)
			:NodePtr(pNode)
		{}
		ListIterator(const Self& s)
			:NodePtr(s.NodePtr)
		{}

		Ref operator*()
		{
			return NodePtr->data;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			NodePtr = NodePtr->Next;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			NodePtr = NodePtr->Next;
			return temp;
		}

		Self& operator--()
		{
			NodePtr = NodePtr->Prev;
			return *this;
		}

		Self operator--(int)
		{
			Self temp(*this);
			NodePtr = NodePtr->Prev;
			return temp;
		}

		bool operator!=(const Self& s)
		{
			return NodePtr != s.NodePtr;
		}
		bool operator==(const Self& s)
		{
			return NodePtr == s.NodePtr;
		}
		//private:
		PNode NodePtr;
	};

	//反向迭代器
	//对正向迭代器的封装，迭代器适配器
	template<class Iterator>
	class ReverseIterator
	{
		//typedef ListIterator<T, T&, T*> iterator;
		typedef ReverseIterator<Iterator> Self;

		//typename : 告诉编译器Ref是Iterator类型中的内嵌类型，而不是静态的成员变量
		typename typedef Iterator::Ref Ref;
		typename typedef Iterator::Ptr Ptr;
	public:
		//构造函数
		ReverseIterator(Iterator it)
			:_it(it)
		{}

		//拷贝构造函数
		ReverseIterator(const Self& rit)
			:_it(rit._it)
		{}

		//重载各种反向迭代器操作
		Ref operator*()
		{
			Iterator& temp(_it);
			--temp;
			return *temp;
		}
		Ptr operator->()
		{
			return &(operator*());
		}
		Self& operator++()
		{
			--_it;
			return *this;
		}

		Self& operator++(int)
		{
			Self temp(*this);
			--_it;
			return temp;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}

		Self& operator--(int)
		{
			Self temp(*this);
			++_it;
			return temp;
		}

		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}

		bool operator==(const Self& s)
		{
			return _it == s._it;
		}

	public:
		Iterator _it;
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
	public:
		//**********************************************************************
		//1.链表创建操作

		list()
		{
			CreatHeadNode();
		}

		list(size_t n, const T& data = T())
		{
			CreatHeadNode();
			//Node* ptr = HeadPtr;
			for (size_t i = 0; i < n; ++i)
			{
				push_back(data);
			}
		}

		list(T* first, T* last)
		{
			CreatHeadNode();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//拷贝构造
		list(list<T>& L)
		{
			CreatHeadNode();
			for (const auto& e : L)
			{
				push_back(e);
			}
		}

		//运算符重载
		list<T>& operator=(const list<T>& L)
		{
			if (HeadPtr != &l)
			{
				for (const auto& e : L)
				{
					push_back(e);
				}
			}
		}

		~list()
		{
			clear();
			delete HeadPtr;
			HeadPtr = nullptr;
		}

		//**********************************************************************
		//2.容量操作

		//1.有效结点的个数
		size_t size()const
		{
			size_t count = 0;
			Node* ptr = HeadPtr->Next;
			while (ptr != HeadPtr)
			{
				count++;
				ptr = ptr->Next;
			}
			return count;
		}

		//2.判断是否为空
		bool empty()const
		{
			return HeadPtr == HeadPtr->Next;
		}

		//3.设置有效链表的长度
		void resize(size_t NewSize, const T& data = T())
		{
			size_t OldSize = size();
			if (NewSize > OldSize)
			{
				for (size_t i = OldSize; i < NewSize; i++)
				{
					push_back(data);
				}
			}
			else
			{
				for (size_t i = OldSize; i > NewSize; i--)
				{
					pop_back();
				}
			}
		}

		//**********************************************************************
		//3.元素访问操作

		//1.访问首元素
		T& front()
		{
			return HeadPtr->Next->data;
		}
		//1.1
		const T& front()const
		{
			return HeadPtr->Next->data;
		}

		//2.访问尾元素
		T& back()
		{
			return HeadPtr->Prev->data;
		}
		//2.1
		const T& back()const
		{
			return HeadPtr->Prev->data;
		}

		//***************************************************************
		//4.元素修改操作

		//1.尾插
		void push_back(const T& data)
		{
			insert(end(), data);
		}

		//2.尾删
		void pop_back()
		{
			erase(--end());
		}

		//3.头插
		void push_front(const T& data)
		{
			insert(begin(), data);
		}

		//4.头删
		void pop_front()
		{
			erase(begin());
		}

		//5.任意位置插入
		iterator insert(iterator position, const T& data)
		{
			Node* pos = position.NodePtr;
			Node* NewNode = new Node(data);

			NewNode->Next = pos;
			NewNode->Prev = pos->Prev;

			pos->Prev->Next = NewNode;
			pos->Prev = NewNode;

			return iterator(NewNode);
		}

		//6.任意位置删除
		iterator erase(iterator position)
		{
			Node* DelNode = position.NodePtr;
			if (DelNode == HeadPtr)
			{
				return iterator(HeadPtr);
			}
			Node* pRet = DelNode->Next;

			DelNode->Next->Prev = DelNode->Prev;
			DelNode->Prev->Next = DelNode->Next;
			delete DelNode;

			return iterator(pRet);
		}

		//7.清空list
		void clear()
		{
			Node* ptr = HeadPtr->Next;
			while (ptr != HeadPtr)
			{
				HeadPtr->Next = ptr->Next;
				delete ptr;
				ptr = HeadPtr->Next;
			}

			HeadPtr->Next = HeadPtr;
			HeadPtr->Prev = HeadPtr;
		}

		//***********************************************************************
		//5.迭代器操作

		//1.
		iterator begin()
		{
			return iterator(HeadPtr->Next);
		}

		iterator end()
		{
			return iterator(HeadPtr);
		}

		const const_iterator cbegin()const
		{
			return const_iterator(HeadPtr->Next);
		}

		const const_iterator cend()const
		{
			return const_iterator(HeadPtr);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(iterator(HeadPtr));
		}

		reverse_iterator rend()
		{
			return reverse_iterator(iterator(HeadPtr->Next));
		}

	private:
		void CreatHeadNode()
		{
			HeadPtr = new Node;
			HeadPtr->Next = HeadPtr;
			HeadPtr->Prev = HeadPtr;
		}
	private:
		Node * HeadPtr;
	};
}

template<class T>
void PrintList(ListS::list<T>& L)
{
	auto it = L.begin();
	while (it != L.end())
	{
		cout << *it << "--->";
		++it;
	}
	cout << "NULL" << endl;
}

int main()
{
	int array[] = { 1,2,3,4,5 };
	ListS::list<int> L(array, array + sizeof(array) / sizeof(array[0]));
	L.push_back(6);
	L.push_front(0);
	PrintList(L);

	//ListS::list<int>::reverse_iterator it = L.rbegin();

	auto it = L.rbegin();//

	while (it != L.rend())
	{
		cout << *it << "--->";
		//++it;
	}
	cout << "NULL" << endl;

	cout << L.front() << endl;
	cout << L.back() << endl;
	cout << L.size() << endl;

	L.pop_front();
	L.pop_back();
	PrintList(L);

	L.resize(10, 6);
	PrintList(L);

	L.resize(5);
	PrintList(L);

	L.clear();
	cout << L.size() << endl;
	system("pause");
	return 0;
}


//#include<iostream>
//#include<list>
//using namespace std;
//
//int main()
//{
//	list<int> L{ 1,2,3,4,5 };
//	auto it = L.begin();
//	//删除数据会导致当前迭代器失效，其它迭代器不受影响
//	//while (it != L.end())
//	//{
//	//	L.erase(it);
//	//	cout << *it << "--->";
//	//	++it;
//	//}
//	//cout << "NULL" << endl;
//	//插入不会导致迭代器失效
//	L.insert(L.begin(), 0);
//	//cout << *it << endl;
//		while (it != L.end())
//		{
//			cout << *it << "--->";
//			++it;
//		}
//		cout << "NULL" << endl;
//	system("pause");
//	return 0;
//}
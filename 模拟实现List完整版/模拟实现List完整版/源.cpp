#include<iostream>
#include<list>
using namespace std;


//list�ײ�ṹ����ͷ�ڵ��˫��ѭ������
//Ϊʲô��ͷ�ڵ�
//1.ͷ�������ɾ���Ƚϼ�
//2.����begin(),��end()

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

	//������������ָ��һ���ķ�ʽʹ�ã�ָ����еĲ��� ������������֧��

	//operator*()
	//operator->()
	//operator++()
	//operator--()���Ӿ���ṹ�Դ�
	//operator!=()
	//operator==()


	template<class T, class Ref, class Ptr>                //���������ֱ���ʲô��˼���Ե����ã�����
														   //template<class T, class Ref, class Ptr> 
														   //T Ԫ������
														   //��ͨ���ͣ�
														   //Ref����T&   Ptr����T*
														   //constʱ
														   //Ref����const T&��  Ptr����const T*
														   //Ϊ��ͳһ��ͨ���ͺ�const����



														   //1.ʵ�����������������Ϊ������ԭ��ָ̬�룬�ײ���˫�������ռ䲻һ��������
														   //2.���������ʵ��++��--��==��!=��*��->��������ָ�������������������֧�֣�
														   //3.ֱ����list������Ƕ��Ӧ����������ʹ�á�Ϊ��ȡ����
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

	//���������
	//������������ķ�װ��������������
	template<class Iterator>
	class ReverseIterator
	{
		//typedef ListIterator<T, T&, T*> iterator;
		typedef ReverseIterator<Iterator> Self;

		//typename : ���߱�����Ref��Iterator�����е���Ƕ���ͣ������Ǿ�̬�ĳ�Ա����
		typename typedef Iterator::Ref Ref;
		typename typedef Iterator::Ptr Ptr;
	public:
		//���캯��
		ReverseIterator(Iterator it)
			:_it(it)
		{}

		//�������캯��
		ReverseIterator(const Self& rit)
			:_it(rit._it)
		{}

		//���ظ��ַ������������
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
		//1.����������

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

		//��������
		list(list<T>& L)
		{
			CreatHeadNode();
			for (const auto& e : L)
			{
				push_back(e);
			}
		}

		//���������
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
		//2.��������

		//1.��Ч���ĸ���
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

		//2.�ж��Ƿ�Ϊ��
		bool empty()const
		{
			return HeadPtr == HeadPtr->Next;
		}

		//3.������Ч����ĳ���
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
		//3.Ԫ�ط��ʲ���

		//1.������Ԫ��
		T& front()
		{
			return HeadPtr->Next->data;
		}
		//1.1
		const T& front()const
		{
			return HeadPtr->Next->data;
		}

		//2.����βԪ��
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
		//4.Ԫ���޸Ĳ���

		//1.β��
		void push_back(const T& data)
		{
			insert(end(), data);
		}

		//2.βɾ
		void pop_back()
		{
			erase(--end());
		}

		//3.ͷ��
		void push_front(const T& data)
		{
			insert(begin(), data);
		}

		//4.ͷɾ
		void pop_front()
		{
			erase(begin());
		}

		//5.����λ�ò���
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

		//6.����λ��ɾ��
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

		//7.���list
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
		//5.����������

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
//	//ɾ�����ݻᵼ�µ�ǰ������ʧЧ����������������Ӱ��
//	//while (it != L.end())
//	//{
//	//	L.erase(it);
//	//	cout << *it << "--->";
//	//	++it;
//	//}
//	//cout << "NULL" << endl;
//	//���벻�ᵼ�µ�����ʧЧ
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
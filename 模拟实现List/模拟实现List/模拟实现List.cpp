#include<iostream>
#include<list>
using namespace std;


//list�ײ�ṹ����ͷ�ڵ��˫��ѭ������

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


	template<class T, class Ref, class Ptr>
	struct ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
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

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T, T&, T*> iterator;

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
		void resize(size_t NewSize, const T& data =T())
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

	private:
		void CreatHeadNode()
		{
			HeadPtr = new Node;
			HeadPtr->Next = HeadPtr;
			HeadPtr->Prev = HeadPtr;
		}
	private:
		Node* HeadPtr;
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
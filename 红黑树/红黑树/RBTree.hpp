#pragma once
#include<iostream>
using namespace std;

enum Color{RED, BLACK};

template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data = T(), const Color color = RED)
		:_Left(nullptr)
		,_Right(nullptr)
		,_Parent(nullptr)
		,_data(data)
		,_Color(color)
	{}
	RBTreeNode<T>* _Left;
	RBTreeNode<T>* _Right;
	RBTreeNode<T>* _Parent;
	T _data;
	Color _Color;
};

template<class T>
class RBTree
{
	typedef RBTreeNode<T> RBTreeNode;
public:
	RBTree()
	{
		_Head = new RBTreeNode;
		_Head->_Left = _Head;
		_Head->_Right = _Head;
		_Head->_Parent = nullptr;
	}

	~RBTree()
	{
		_Destroy(GetRoot());
	}
	bool Insert(const T& data)
	{
		RBTreeNode*& Root = GetRoot();
		if (Root == nullptr)
		{
			Root = new RBTreeNode(data, BLACK);
			Root->_Parent = _Head;
		}
		else
		{
			//���ն������������ʲ���
			//1.��λ��
			RBTreeNode* ptr = Root;
			RBTreeNode* Parent = nullptr;
			while (ptr)
			{
				Parent = ptr;
				if (ptr->_data > data)
				{
					ptr = ptr->_Left;
				}
				else if (ptr->_data < data)
				{
					ptr = ptr->_Right;
				}
				else
				{
					return false;
				}
			}

			//2.�����½ڵ�
			ptr = new RBTreeNode(data);
			if (Parent->_data > data)
			{
				Parent->_Left = ptr;
			}
			else
			{
				Parent->_Right = ptr;
			}
			ptr->_Parent = Parent;
			//3.���½ڵ���ɫ
			while (Parent != _Head && RED == Parent->_Color)
			{
				RBTreeNode* GrandFather = Parent->_Parent;
				if (Parent == GrandFather->_Left)
				{
					RBTreeNode* Uncle = GrandFather->_Right;
					//�����������Ϊ�죨���һ��
					if (Uncle && Uncle->_Color == RED)
					{
						Parent->_Color = BLACK;
						Uncle->_Color = BLACK;
						GrandFather->_Color = RED;

						ptr = GrandFather;
						Parent = ptr->_Parent;
					}
					else
					{
						//�ȴ��������Ϊ�����
						if (ptr == Parent->_Right)
						{
							RotateL(Parent);
							swap(ptr, Parent);
						}

						//�����
						Parent->_Color = BLACK;
						GrandFather->_Color = RED;
						RotateR(GrandFather);
					}
				}
				else
				{
					RBTreeNode* Uncle = GrandFather->_Left;
					if (Uncle && Uncle->_Color == RED)
					{
						Parent->_Color = BLACK;
						Uncle->_Color = BLACK;
						GrandFather->_Color = RED;

						ptr = GrandFather;
						Parent = ptr->_Parent;
					}
					else
					{
						if (ptr == Parent->_Left)
						{
							RotateR(Parent);
							swap(ptr, Parent);
						}

						Parent->_Color = BLACK;
						GrandFather->_Color = RED;
						RotateL(GrandFather);
					}
				}

			}
		}

		Root->_Color = BLACK;
		//����ͷ���ָ��������С�ڵ�
		_Head->_Left = LeftMost();
		_Head->_Right = RightMost();
		return true;
	}

	void InOrderPrint()
	{
		_InOrderPrint(GetRoot());
		cout << endl;
	}
private:
	RBTreeNode*& GetRoot()
	{
		return _Head->_Parent;
	}
	void _InOrderPrint(RBTreeNode* Root)
	{
		if (Root)
		{
			_InOrderPrint(Root->_Left);
			//cout << Root->_data << ":";
			cout << "[ " << Root->_data << ":";
			if (Root->_Color == 0)
			{
				cout << "Red ]\n";
			}
			else
			{
				cout << "Black ]\n";
			}
			_InOrderPrint(Root->_Right);
		}
	}

	void _Destroy(RBTreeNode*& Root)
	{
		if (Root)
		{
			_Destroy(Root->_Left);
			_Destroy(Root->_Right);
			delete Root;
			Root = nullptr;
		}
	}
	RBTreeNode* LeftMost()
	{
		RBTreeNode* ptr = GetRoot();
		if (ptr == nullptr)
		{
			return _Head;
		}
		while (ptr)
		{
			if (ptr->_Left != nullptr)
			{
				ptr = ptr->_Left;
			}
			else
			{
				break;
			}
		}
		return ptr;
	}

	RBTreeNode* RightMost()
	{
		RBTreeNode* ptr = GetRoot();
		if (ptr == nullptr)
		{
			return _Head;
		}
		while (ptr)
		{
			if (ptr->_Right != nullptr)
			{
				ptr = ptr->_Right;
			}
			else
			{
				break;
			}
		}
		return ptr;
	}

	void RotateL(RBTreeNode* Parent)
	{
		RBTreeNode* SubR = Parent->_Right;
		RBTreeNode* SubRL = SubR->_Left;

		Parent->_Right = SubRL;
		if (SubRL)
		{
			SubRL->_Parent = Parent;
		}

		SubR->_Left = Parent;

		RBTreeNode* PParent = Parent->_Parent;
		Parent->_Parent = SubR;
		SubR->_Parent = PParent;

		RBTreeNode*& Root = GetRoot();
		if (Root == Parent)
		{
			Root = SubR;
		}
		else
		{
			if (PParent->_Left == Parent)
			{
				PParent->_Left = SubR;
			}
			else
			{
				PParent->_Right = SubR;
			}
		}
	}

	void RotateR(RBTreeNode* Parent)
	{
		RBTreeNode* SubL = Parent->_Left;
		RBTreeNode* SubLR = SubL->_Right;

		Parent->_Left = SubLR;
		if (SubLR)
		{
			SubLR->_Parent = Parent;
		}

		SubL->_Right = Parent;
		RBTreeNode* PParent = Parent->_Parent;
		SubL->_Parent = PParent;

		RBTreeNode*& Root = GetRoot();
		if (Parent == Root)
		{
			Root = SubL;
		}
		else
		{
			if (PParent->_Left == Parent)
			{
				PParent->_Left = SubL;
			}
			else
			{
				PParent->_Right = SubL;
			}
		}
	}
private:
	RBTreeNode* _Head;
};
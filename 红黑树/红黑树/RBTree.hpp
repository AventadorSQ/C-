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
			//按照二叉搜索树性质插入
			//1.找位置
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

			//2.插入新节点
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
			//3.更新节点颜色
			while (Parent != _Head && RED == Parent->_Color)
			{
				RBTreeNode* GrandFather = Parent->_Parent;
				if (Parent == GrandFather->_Left)
				{
					RBTreeNode* Uncle = GrandFather->_Right;
					//叔叔结点存在且为红（情况一）
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
						//先处理情况三为情况二
						if (ptr == Parent->_Right)
						{
							RotateL(Parent);
							swap(ptr, Parent);
						}

						//情况二
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
		//更新头结点指向的最大最小节点
		_Head->_Left = LeftMost();
		_Head->_Right = RightMost();
		return true;
	}

	void InOrderPrint()
	{
		_InOrderPrint(GetRoot());
		cout << endl;
	}

	bool IsRBTree()
	{
		RBTreeNode* pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			return true;
		}
		if (RED == pRoot->_Color)
		{
			cout << "违反性质2：根节点为红色" << endl;
			return false;
		}
		size_t pathblack = 0;
		size_t blackCount = 0;
		RBTreeNode* ptr = pRoot;
		while (ptr)
		{
			if (ptr->_Color == BLACK)
			{
				blackCount++;
			}
			ptr = ptr->_Left;
		}
		return _IsRBTree(pRoot, blackCount, pathblack);
	}
private:
	bool _IsRBTree(RBTreeNode* pRoot, size_t blackCount, size_t pathblack)
	{
		if (nullptr == pRoot)
		{
			return true;
		}
		if (pRoot->_Color == BLACK)
		{
			pathblack++;
		}
		if (pRoot->_Color == RED && pRoot->_Parent &&pRoot->_Parent->_Color == RED)
		{
			cout << "违反性质3：红色结点连续" << endl;
			return false;
		}
		if (pRoot->_Left == nullptr && pRoot->_Right == nullptr)
		{
			if (pathblack != blackCount)
			{
				cout << "违反性质4：黑色结点数量不相同" << endl;
				return false;
			}
		}

		return _IsRBTree(pRoot->_Left, blackCount, pathblack) && _IsRBTree(pRoot->_Right, blackCount, pathblack);
	}
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
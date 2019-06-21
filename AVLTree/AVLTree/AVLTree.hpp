#pragma once

#include<iostream>
using namespace std;

template<class T>
class AVLTreeNode
{
public:
	AVLTreeNode(T& dataS)
		:_data(dataS)
		,_Left(nullptr)
		,_Right(nullptr)
		,_Parent(nullptr)
		,_count(0)
	{}
public:
	T _data;
	AVLTreeNode<T>* _Left;
	AVLTreeNode<T>* _Right;
	AVLTreeNode<T>* _Parent;
	int _count;
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> AVLTreeNode;
public:
	AVLTree()
		:_Root(nullptr)
	{}
	~AVLTree()
	{
		_Destory(_Root);
	}
	//1.插入数据
	bool Insert(T& data)
	{
		if (_Root == nullptr)
		{
			_Root = new AVLTreeNode(data);
			return true;
		}

		//1.1找到对应位置
		AVLTreeNode* ptr = _Root;
		AVLTreeNode* Parent = nullptr;
		while (ptr)
		{
			if (ptr->_data == data)
			{
				return false;
			}
			Parent = ptr;
			if (ptr->_data > data)
			{
				ptr = ptr->_Left;
			}
			else
			{
				ptr = ptr->_Right;
			}
		}
		//1.2.准备插入新节点
		ptr = new AVLTreeNode(data);
		if (Parent->_data > data)
		{
			Parent->_Left = ptr;
		}
		else
		{
			Parent->_Right = ptr;
		}
		ptr->_Parent = Parent;

		//1.3.更新平衡因子
		while (Parent)
		{
			if (ptr == Parent->_Left)
			{
				Parent->_count--;
			}
			else
			{
				Parent->_count++;
			}

			//1.4.向上判断平衡因子
			if (Parent->_count == 0)
			{
				break;
			}
			else if (Parent->_count == -1 || Parent->_count == 1)
			{
				ptr = Parent;
				Parent = Parent->_Parent;
			}
			else//平衡因子为2或-2时
			{
				if (Parent->_count == 2)
				{
					if (ptr->_count == 1)
					{
						RotateL(Parent);
					}
					else
					{
						RoateRL(Parent);
					}
				}
				else
				{
					if (ptr->_count == -1)
					{
						RotateR(Parent);
					}
					else
					{
						RoateLR(Parent);
					}
				}
				break;
			}
		}
		
		return true;
	}
	
	void InOrderPrint()
	{
		_InOrderPrint(_Root);
		cout << endl;
	}

	bool IsAVLTree()
	{
		return _IsAVLTree(_Root);
	}

private:
	int _Height(AVLTreeNode* Root)
	{
		if (Root == nullptr)
		{
			return 0;
		}

		int LeftHeight = _Height(Root->_Left);
		int RightHeight = _Height(Root->_Right);

		return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
	}

	bool _IsAVLTree(AVLTreeNode* Root)
	{
		if (Root == nullptr)
		{
			return true;
		}

		int LeftHeight = _Height(Root->_Left);
		int RightHeight = _Height(Root->_Right);
		if (abs(Root->_count)>1 || RightHeight - LeftHeight != Root->_count)
		{
			return false;
		}
		return _IsAVLTree(Root->_Left) && _IsAVLTree(Root->_Right);
	}

	//右单旋
	void RotateR(AVLTreeNode* Parent)
	{
		AVLTreeNode* SubL = Parent->_Left;
		AVLTreeNode* SubLR = SubL->_Right;

		Parent->_Left = SubLR;
		if (SubLR)
		{
			SubLR->_Parent = Parent;
		}

		SubL->_Right = Parent;
		SubL->_Parent = Parent->_Parent;
		Parent->_Parent = SubL;

		if (SubL->_Parent == nullptr)
		{
			_Root = SubL;
		}
		else
		{
			if (SubL->_Parent->_Left == Parent)
			{
				SubL->_Parent->_Left = SubL;
			}
			else
			{
				SubL->_Parent->_Right = SubL;
			}
		}

		Parent->_count = SubL->_count = 0;
	}

	//左单旋
	void RotateL(AVLTreeNode* Parent)
	{
		AVLTreeNode* SubR = Parent->_Right;
		AVLTreeNode* SubRL = SubR->_Left;

		Parent->_Right = SubRL;
		if (SubRL)
		{
			SubRL->_Parent = Parent;
		}

		SubR->_Left = Parent;
		SubR->_Parent = Parent->_Parent;
		Parent->_Parent = SubR;

		if (SubR->_Parent == nullptr)
		{
			_Root = SubR;
		}
		else
		{
			if (SubR->_Parent->_Left == Parent)
			{
				SubR->_Parent->_Left = SubR;
			}
			else
			{
				SubR->_Parent->_Right = SubR;
			}
		}

		Parent->_count = SubR->_count = 0;
	}
	//右左双旋
	void RoateRL(AVLTreeNode* Parent)
	{
		AVLTreeNode* SubR = Parent->_Right;
		AVLTreeNode* SubRL = SubR->_Left;
		int bf = SubRL->_count;

		RotateR(Parent->_Right);
		RotateL(Parent);

		if (bf == 1)
		{
			Parent->_count = -1;
		}
		else if (bf == -1)
		{
			SubR->_count = 1;
		}
	}
	//左右双旋
	void RoateLR(AVLTreeNode* Parent)
	{
		AVLTreeNode* SubL = Parent->_Left;
		AVLTreeNode* SubLR = SubL->_Right;
		int bf = SubLR->_count;

		RotateL(Parent->_Left);
		RotateR(Parent);

		if (bf == 1)
		{
			SubL->_count = -1;
		}
		else if (bf == -1)
		{
			Parent->_count = 1;
		}
	}

	void _InOrderPrint(AVLTreeNode* Root)
	{
		if (Root)
		{
			_InOrderPrint(Root->_Left);
			cout << Root->_data << " ";
			_InOrderPrint(Root->_Right);
		}
	}

	void _Destory(AVLTreeNode* Root)
	{
		if (Root)
		{
			_Destory(Root->_Left);
			_Destory(Root->_Right);
			delete Root;
			Root = nullptr;
		}
	}


private:
	AVLTreeNode* _Root;
};
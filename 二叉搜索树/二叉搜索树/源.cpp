#include"BinarySearchTree.hpp"

void TestFunc()
{
	BSTree<int> Tree;
	int array[] = { 5,3,4,1,7,8,2,6,0,9 };

	for (auto e : array)
	{
		Tree.Insert(e);
	}

	Tree.InOrderPrint();
	Tree.DeleteData(4);
	Tree.InOrderPrint();

	BSTNode<int>* ptr = Tree.FindNode(5);
	cout << ptr << " " << ptr->_data << endl;
	Tree.Destory();
}

int main()
{
	TestFunc();
	system("pause");
	return 0;
}
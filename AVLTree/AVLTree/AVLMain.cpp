#include"AVLTree.hpp"

void TestAVLTree()
{
	//int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	//int a[] = { 16,3,7,11,9,26,18,14,15};
	int a[] = { 4,2,6,1,3,5,15,7,16,14};
	AVLTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrderPrint();

	if (t.IsAVLTree())
	{
		cout << "AVLTree" << endl;
	}
	else
	{
		cout << "not AVLTree" << endl;
	}
}

int main()
{
	TestAVLTree();
	system("pause");
	return 0;
}
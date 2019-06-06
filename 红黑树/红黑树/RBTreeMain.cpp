#include"RBTree.hpp"

void TestRBTree()
{
	int a[] = { 4,2,6,1,3,5,15,7,16,14 };
	RBTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}

	t.InOrderPrint();
}

int main()
{
	TestRBTree();
	system("pause");
	return 0;
}
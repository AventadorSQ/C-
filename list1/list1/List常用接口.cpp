#include<iostream>
#include<list>
#include<vector>
using namespace std;

template<class T>


void PrintList(const list<T>& L)
{
	for (const auto& e : L)
		cout << e << "--->";
	cout << "NULL" << endl;
}

//构造list实例四种方法
void TestList1()
{
	list<int> L1;
	PrintList(L1);

	list<int> L2(6, 8);
	PrintList(L2);
	
	int array[] = { 1,2,3,4,5,6,67,8,9 };
	list<int> L3(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(L3);

	vector<int> v{ 1,2,3,4,5,6 };
	list<int> L4(v.begin(), v.end());
	PrintList(L4);
}

//容量相关操作
//元素访问操作
//list不支持随机访问
void TestList2()
{
	list<int> L{ 1,2,3,4,5 };
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.resize(10, 6);
	cout << L.size() << endl;
	PrintList(L);

	L.resize(3);
	cout << L.size() << endl;
	PrintList(L);
}
//元素修改操作
void TestList3()
{
	list<int> L{ 6,5,4,3,2,1,0 };
	L.push_back(-1);
	PrintList(L);

	L.pop_back();
	PrintList(L);

	L.push_front(7);
	PrintList(L);

	L.pop_front();
	PrintList(L);

	L.insert(L.begin(), -1);
	PrintList(L);

	L.insert(L.begin(), 5, 66);
	PrintList(L);

	vector<int> v{ 11,22,33,44,55,66,77,88 };
	L.insert(L.end(), v.begin(), v.end());
	PrintList(L);

	L.erase(find(L.begin(), L.end(), 77));
	PrintList(L);
	L.erase(L.begin(), L.end());
	PrintList(L);

	L.assign(6, 88);
	PrintList(L);

	L.assign(v.begin(), v.end());
	PrintList(L);

	L.clear();
	PrintList(L);
}

//去重
void TestList4()
{
	list<int> L{ 1,2,4,5,6,3,2,3,8,6,9 };
	L.sort();
	PrintList(L);

	L.unique();
	PrintList(L);

	L.reverse();
	PrintList(L);
}

//合并两个有序链表
void TestList5()
{
	list<int> L{ 1,2,4,5,6,3,2,3,8,6,9 };
	L.sort();
	PrintList(L);

	list<int> L1{ 1,56, 5,2,3,5,4,99,65};
	L1.sort();
	PrintList(L1);

	L.merge(L1);
	L.unique();
	PrintList(L);
}

//class ModN
//{
//public:
//	bool operator()(int data, int N)
//	{
//		if (data%N == 0)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//};
class ModN
{
public:
	bool operator()(int data)
	{
		if (data%2 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
//删除元素
void TestList6()
{
	list<int> L{ 1,2,3,4,5,6,7,8,9,10 };
	PrintList(L);

	L.remove_if(ModN());
	PrintList(L);

	ModN M;
	if (M(4))
	{
		cout << "能被2整除" << endl;
	}
	else
	{
		cout << "不能被2整除" << endl;
	}
}


int main()
{
	//TestList1();
	//TestList2();
	//TestList3();
	//TestList4();
	//TestList5();
	TestList6();
	system("pause");
	return 0;
}
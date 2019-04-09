#include<iostream>
using namespace std;

#include<vector>

#if 0
int main()
{
	vector<int> data1;
	vector<int> data2(10, 5);
	vector<int> data3(data2);
	
	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
	vector<int> data4(array, array + sizeof(array) / sizeof(array[0]));
	return 0;
}
#endif

#if 0
int main()
{
	size_t sz;
	vector<int> num;
	num.reserve(100);
	sz = num.capacity();
	cout << "num容量增长变化" << endl;
	for (int i = 0; i < 100; i++)
	{
		num.push_back(i);
		if (sz != num.capacity())
		{
			sz = num.capacity();
			cout << "capacity changed :" << sz << endl;
		}
	}
	system("pause");
	return 0;
}

#endif

int main()
{
	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
	vector<int> v1(array, array + sizeof(array) / sizeof(array[0]));
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//e是v1中每个元素的引用
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
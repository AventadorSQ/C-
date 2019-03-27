#include<iostream>
using namespace std;

#include<vector>
#include<string>

#if 0
int main()
{
	vector<int> v1;
	vector<int> v2(100, 6);
	int arr[] = { 1,2,3,4,5,6 };
	vector<int> v4(arr, arr + sizeof(arr) / sizeof(arr[0]));

	string s("hello");
	//迭代器：原生态的指针T*
	vector<char> v5(s.begin(), s.end());
	system("pause");
	return 0;
}
#endif


int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	vector<int>::iterator ptr = v1.begin();
	while (ptr != v1.end())
	{
		cout << *ptr++ << " ";
	}
	cout << endl;

	for (auto& e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
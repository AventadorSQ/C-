#include<iostream>
#include<map>
#include<set>
#include<unordered_set>
#include<time.h>
#include<vector>
using namespace std;

int main()
{
	set<int> set;
	unordered_set<int> Uset;
	int n;
	cin >> n;
	vector<int> v;
	srand((unsigned)time);
	for (int i = 0; i < n; i++)
	{
		v.push_back(rand());
	}
	size_t begin1 = clock();
	for (int i = 0; i < n; i++)
	{
		set.insert(v[i]);
	}
	size_t end1 = clock();
	size_t begin2 = clock();
	for (int i = 0; i < n; i++)
	{
		Uset.insert(v[i]);
	}
	size_t end2 = clock();

	cout << "RBTree insert time :" << end1 - begin1 << endl;
	cout << "Hash insert time :" << end2 - begin2 << endl;
	system("pause");
	return 0;
}
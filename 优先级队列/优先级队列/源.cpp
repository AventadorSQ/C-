#include<iostream>
#include<queue>
using namespace std;

//top K 问题 ---考虑专业堆
//在C++封装堆即优先级队列 priority_queue:
#include<vector>
#include<functional>

int main()
{
	//默认大堆   less<int>
	vector<int> v{ 3,2,1,6,5,4,9,8,7 };
	priority_queue<int> q(v.begin(), v.end());
	cout << q.top() << endl;

	//修改为小堆
	priority_queue<int, vector<int>, greater<int>> q1(v.begin(), v.end());
	cout << q1.top() << endl;
	system("pause");
	return 0;
}
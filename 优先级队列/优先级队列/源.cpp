#include<iostream>
#include<queue>
using namespace std;

//top K ���� ---����רҵ��
//��C++��װ�Ѽ����ȼ����� priority_queue:
#include<vector>
#include<functional>

int main()
{
	//Ĭ�ϴ��   less<int>
	vector<int> v{ 3,2,1,6,5,4,9,8,7 };
	priority_queue<int> q(v.begin(), v.end());
	cout << q.top() << endl;

	//�޸�ΪС��
	priority_queue<int, vector<int>, greater<int>> q1(v.begin(), v.end());
	cout << q1.top() << endl;
	system("pause");
	return 0;
}
#include<iostream>
#include<map>
using namespace std;
#include<string>
#include<set>

void TestMap()
{
	map<string, string> m;
	map<string, string> m2{ {"3","Æ»¹û"},{"4","½Û×Ó"},{"1","Ó£ÌÒ"} };

	m2.insert(pair<string, string>("6", "ÌÒ×Ó"));
	m2.insert(make_pair("8", "Àæ"));

	cout << "m2.size() = " << m2.size() << endl;
	cout << "m2[""] ="<<m2["3"] << endl;
	m2["3"] = "Ð¡Æ»¹û";
	m2["2"] = "Ïã½¶";

	map<string, string>::iterator it = m2.begin();
	auto itS = m2.begin();
	while (itS != m2.end())
	{
		cout << itS->first << "--->" << (*itS).second << endl;
		itS++;
	}
	for (auto& e : m2)
	{
		cout << e.first << "-->" << e.second << endl;
	}
}


void TestSet()
{
	int array[] = { 2,3,4,2,3,25,6,7,4,8,6,92,2,324,2,2 };
	set<int> s;
	for (auto& e : array)
	{
		s.insert(e);
	}

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << s.count(2) << endl;
}

void TestMultiset()
{
	int array[] = { 2,3,4,2,3,25,6,7,4,8,6,92,2,324,2,2 };
	multiset<int> s;
	for (auto& e : array)
	{
		s.insert(e);
	}

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << s.count(2) << endl;
}
int main()
{
	//TestMap();
	//TestSet();
	TestMultiset();
	system("pause");
	return 0;
}
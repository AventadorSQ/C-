//2. 输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are
//students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
//输入描述：
//每个测试输入包含2个字符串
//输出描述：
//输出删除后的字符串
//示例1 :
//输入
//They are students.aeiou
//输出
//Thy r stdnts

#include<iostream>
using namespace std;

#include<string>



int main()
{
	cout << "输入两个字符串。" << endl;
	cout << "请输入第一个字符串：";
	string s1;
	string s2;
	getline(cin, s1);
	cout << endl;
	cout << "请输入第二个字符串：";
	getline(cin, s2);
	cout << s2.size() << endl;
	cout << endl;
	//每删除一个s1的size()就会减一，所以此刻不能直接去替换
	//size_t SizeS1 = s1.size();
	//size_t SizeS2 = s2.size();
	for (size_t i = 0; i < s2.size(); i++)
	{
		for (size_t j = 0; j < s1.size(); j++)
		{
			if (s1[j] == s2[i])
			{
				s1.erase(j, 1);
			}
		}
	}
	cout << s1 <<endl;
	system("pause");
	return 0;
}
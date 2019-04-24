//2. 将一句话的单词进行倒置，标点不倒置。比如 I like beijing.经过函数后变为：beijing.like I
//输入描述：
//每个测试输入包含1个测试用例： I like beijing.输入用例长度不超过100
//输出描述：
//依次输出倒置之后的字符串, 以空格分割
//NOWCODER.COM
//牛客网·互联网名企笔试 / 面试题库
//牛客出品 - http://www.nowcoder.com
//示例1:
//输入
//I like beijing.
//输出
//beijing.like I

#include<iostream>
#include<string>
using namespace std;

void DisposeData(string& s)
{
	string s1;
	string s2;
	while (s.size() != 0)
	{

		size_t pos = s.rfind(' ', s.size());
		if (pos >= s.size())
		{
			pos = 0;
			s1 += s;
		}
		else
		{
			s2 = s.substr(pos + 1, s.size() - pos);
			s1 += s2;
			s1.push_back(' ');
		}
		s.erase(pos, s.size() - pos);
	}
	s += s1;
}

int main()
{
	string S;
	cout << "请输入英文句子：";
	getline(cin, S);
	DisposeData(S);
	cout << S.size() << endl;
	cout << "S = " << S << endl;
	system("pause");
	return 0;
}
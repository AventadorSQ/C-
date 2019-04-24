//1. 读入一个字符串str，输出字符串str中的连续最长的数字串
//输入描述：
//个测试输入包含1个测试用例，一个字符串str，长度不超过255。
//输出描述：
//在一行内输出str中里连续最长的数字串
//示例1:
//输入
//abcd12345ed125ss123456789
//输出
//123456789

#include<iostream>
#include<string>
using namespace std;

void Dispose(string& s1)
{
	//记录最大数字串长度第一个数字串位置
	size_t MaxPos = 0;
	//记录最大数字串长度
	size_t MaxCount = 0;
	size_t size = s1.size();
	for (size_t i = 0; i < size; i++)
	{
		//记录第一个数字串位置
		size_t pos = 0;
		//记录数字串长度
		size_t count = 0;
		if (s1[i] <= '9' && s1[i] >= '0')
		{
			pos = i;
			count++;
			while (s1[i] <= '9' && s1[i] >= '0')
			{
				if (i < size)
				{
					i++;
					count++;
				}
				else
				{
					break;
				}
			}
			if (count > MaxCount)
			{
				MaxPos = pos;
				MaxCount = count;
			}
		}
	}
	for (size_t i = MaxPos; i < MaxCount + MaxPos; i++)
	{
		cout << s1[i];
	}
	cout << endl;
}

int main()
{
	string s;
	cout << "查找字符串中最长的数字串并输出。" << endl;
	cout << "请输入一串字符:";
	getline(cin, s);
	Dispose(s);
	system("pause");
	return 0;
}
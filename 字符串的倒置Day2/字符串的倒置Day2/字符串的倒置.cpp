//2. ��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing.like I
//����������
//ÿ�������������1������������ I like beijing.�����������Ȳ�����100
//���������
//�����������֮����ַ���, �Կո�ָ�
//NOWCODER.COM
//ţ������������������� / �������
//ţ�ͳ�Ʒ - http://www.nowcoder.com
//ʾ��1:
//����
//I like beijing.
//���
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
	cout << "������Ӣ�ľ��ӣ�";
	getline(cin, S);
	DisposeData(S);
	cout << S.size() << endl;
	cout << "S = " << S << endl;
	system("pause");
	return 0;
}
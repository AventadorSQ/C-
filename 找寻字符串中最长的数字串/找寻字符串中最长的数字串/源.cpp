//1. ����һ���ַ���str������ַ���str�е�����������ִ�
//����������
//�������������1������������һ���ַ���str�����Ȳ�����255��
//���������
//��һ�������str��������������ִ�
//ʾ��1:
//����
//abcd12345ed125ss123456789
//���
//123456789

#include<iostream>
#include<string>
using namespace std;

void Dispose(string& s1)
{
	//��¼������ִ����ȵ�һ�����ִ�λ��
	size_t MaxPos = 0;
	//��¼������ִ�����
	size_t MaxCount = 0;
	size_t size = s1.size();
	for (size_t i = 0; i < size; i++)
	{
		//��¼��һ�����ִ�λ��
		size_t pos = 0;
		//��¼���ִ�����
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
	cout << "�����ַ�����������ִ��������" << endl;
	cout << "������һ���ַ�:";
	getline(cin, s);
	Dispose(s);
	system("pause");
	return 0;
}
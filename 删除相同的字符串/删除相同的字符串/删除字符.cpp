//2. ���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are
//students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
//����������
//ÿ�������������2���ַ���
//���������
//���ɾ������ַ���
//ʾ��1 :
//����
//They are students.aeiou
//���
//Thy r stdnts

#include<iostream>
using namespace std;

#include<string>



int main()
{
	cout << "���������ַ�����" << endl;
	cout << "�������һ���ַ�����";
	string s1;
	string s2;
	getline(cin, s1);
	cout << endl;
	cout << "������ڶ����ַ�����";
	getline(cin, s2);
	cout << s2.size() << endl;
	cout << endl;
	//ÿɾ��һ��s1��size()�ͻ��һ�����Դ˿̲���ֱ��ȥ�滻
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
#include"DateTime.h"

int main()
{
	struct tm *systime;
	time_t nowtime;
	time(&nowtime);
	//�õ���ǰϵͳʱ��
	systime = localtime(&nowtime);
	DateTime d(systime->tm_year + 1900, systime->tm_mon + 1, systime->tm_mday, systime->tm_hour, systime->tm_min, systime->tm_sec);
	cout << "��ǰʱ����:" << endl;
	cout << "        ";
	cout << d << endl;
	int i = -2;
	cout << endl;
	cout << "����2020���Ϧ���У�";
	DateTime d10(2020, 1, 24);
	cout << d10 - d << "��" << endl;
	cout << endl;
	while (i != -1)
	{
		DateTime Date;
		cout << "��ѡ���ѯ��ʽ" << endl;
		cout << " 0.ֱ���������ڲ�ѯ��    1.ֱ��������ղ�ѯ�� " << endl;
		cout << "-1.�˳���ѯ!!!" << endl;
		cout << endl;
		cout << "������:";
		cin >> i;
		if (i == 0)
		{
			//11.����������ѯ
			DateQuery(d, Date);
		}
		else if (i == 1)
		{
			string str;
			//12.ͨ�����ղ�ѯ
			FestivalQuery(d, str);

		}
	}
	//15.��ȡ��ǰϵͳʱ��
	GetDateTime();

	system("pause");
	return 0;
}
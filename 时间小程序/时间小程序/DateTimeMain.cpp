#include"DateTime.h"

int main()
{
	struct tm *systime;
	time_t nowtime;
	time(&nowtime);
	//拿到当前系统时间
	systime = localtime(&nowtime);
	DateTime d(systime->tm_year + 1900, systime->tm_mon + 1, systime->tm_mday, systime->tm_hour, systime->tm_min, systime->tm_sec);
	cout << "当前时间是:" << endl;
	cout << "        ";
	cout << d << endl;
	int i = -2;
	cout << endl;
	cout << "距离2020年除夕还有：";
	DateTime d10(2020, 1, 24);
	cout << d10 - d << "天" << endl;
	cout << endl;
	while (i != -1)
	{
		DateTime Date;
		cout << "请选择查询方式" << endl;
		cout << " 0.直接输入日期查询：    1.直接输入节日查询： " << endl;
		cout << "-1.退出查询!!!" << endl;
		cout << endl;
		cout << "请输入:";
		cin >> i;
		if (i == 0)
		{
			//11.用日期来查询
			DateQuery(d, Date);
		}
		else if (i == 1)
		{
			string str;
			//12.通过节日查询
			FestivalQuery(d, str);

		}
	}
	//15.获取当前系统时间
	GetDateTime();

	system("pause");
	return 0;
}
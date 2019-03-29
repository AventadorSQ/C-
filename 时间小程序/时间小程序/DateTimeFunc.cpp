#include"DateTime.h"

//1.���캯��DateTime
DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
	:_year(year)
	, _month(month)
	, _day(day)
	, _hour(hour)
	, _minute(minute)
	, _second(second)
{
	if (!(_year > 0 && _month > 0 && _month < 13 && day>0 && day <= GetDayS(_year, _month) &&
		_hour >= 0 && _hour < 24 && _minute >= 0 && _minute < 60 && _second >= 0 && _second < 60))
	{
		_year = 1900;
		_month = 1;
		_day = 1;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
}

//2.��ȡĳһ��ĳһ�µ�����
int DateTime::GetDayS(int year, int month)
{
	int ArrDayS[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (IsLeapYear(year) && month == 2)
	{
		ArrDayS[month] += 1;
	}
	return ArrDayS[month];
}

//3.�ж��ǲ�������
bool DateTime::IsLeapYear(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		return true;
	}
	return false;
}

//4.�Զ��忽�����캯��
DateTime::DateTime(const DateTime& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	_hour = d._hour;
	_minute = d._minute;
	_second = d._second;
}

//5.������������һ�������������
DateTime DateTime::operator+(int dayS)
{
	if (dayS < 0)
	{
		return operator-(0 - dayS);
	}
	int Getdays;
	_day += dayS;
	while (_day >(Getdays = GetDayS(_year, _month)))
	{
		_day = _day - Getdays;
		_month += 1;
		if (_month > 12)
		{
			_month = 1;
			_year += 1;
		}
	}
	return *this;
}

//6.�����������һ�������������
DateTime DateTime::operator-(int dayS)
{
	if (dayS < 0)
	{
		return operator+(-dayS);
	}
	_day -= dayS;
	while (_day <0)
	{
		_month -= 1;
		if (_month < 1)
		{
			_month = 12;
			_year -= 1;
		}
		_day = _day + GetDayS(_year, _month);
	}
	return *this;
}

//7.������������֮��ļ������
int DateTime::operator-(const DateTime& d)
{
	DateTime MinDate(d);
	DateTime MaxDate(*this);
	if (MinDate > MaxDate)
	{
		swap(MinDate, MaxDate);
	}
	int count = 0;
	while (MaxDate > MinDate)
	{
		count++;
		MaxDate = MaxDate - 1;
	}

	return count;
}

//8.�жϵ�ǰ�����Ƿ���ڸ�������
bool DateTime::operator>(const DateTime& d)
{
	return (_year > d._year) || (_year == d._year && _month > d._month) || (_year == d._year && _month == d._month && _day > d._day);
}

//9.�Զ�����������
DateTime::~DateTime()
{
	_year = 0;
	_month = 0;
	_day = 0;
	_hour = 0;
	_minute = 0;
	_second = 0;
}

//DateTime����Ԫ
//10.1�������
ostream& operator<<(ostream& _cout, const DateTime& d)
{
	if (d._second < 10)
	{
		_cout << d._year << "��" << d._month << "��" << d._day << "��" << d._hour << "ʱ" << d._minute << "��0" << d._second << "��";
	}
	else
	{
		_cout << d._year << "��" << d._month << "��" << d._day << "��" << d._hour << "ʱ" << d._minute << "��" << d._second << "��";
	}
	return _cout;
}
//10.2��������
istream& operator>>(istream& _cin, DateTime& d)
{
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}

//11����������ѯ
void DateQuery(DateTime& d, DateTime& Date)
{
	cout << "������Ҫ��ѯ������:";
	cin >> Date;
	cout << "��" << Date << "����";
	cout << Date - d << "��" << endl;
}

//12.ͨ�����ղ�ѯ
void FestivalQuery(DateTime& d, string& str)
{
	while (1)
	{
		cout << "������տ��Բ��򡮽ڡ���" << endl;
		cout << "������2019��Ҫ��ѯ�Ľ���:";
		cin >> str;

		//��ȡarr�ĳ���
		size_t ArrSize = arr.size();
		//���������ȥarr����ѭ��ƥ��
		for (size_t num = 0; num < ArrSize; num++)
		{
			//�ж��Ƿ��ҵ�
			if (arr[num].find(str) != string::npos)
			{
				//13.ͨ��������ƥ�䵽���ַ�������ȡ����������,�Ӷ�������������
				AnalysisStr(d, str, arr[num]);
				return;
			}
		}
		int numS = 0;
		cout << "����Ľ������󣡣��� " << endl;
		cout << "�˳����ղ�ѯ������:6    ������ѯ�����밴�������ּ�" << endl;
		cin >> numS;
		if (numS == 6)
		{
			return;
		}
		cout << "����������:" << endl;
	}
}

//13.ͨ��������ƥ�䵽���ַ�������ȡ����������,�Ӷ�������������
void AnalysisStr(DateTime& d, string& str, string ArrChild)
{
	int StrSize = ArrChild.size();
	//��ȡ��Ӧ���յ�����������
	int months = (ArrChild[0] - '0') * 10 + (ArrChild[1] - '0');
	int days = (ArrChild[4] - '0') * 10 + (ArrChild[5] - '0');
	//Ϊ���մ�����ʱ����
	DateTime TempDate(2019, months, days);
	//��������յ����ڼ��������
	int counts = d - TempDate;

	//14.��ӡͨ�����ջ�ȡ�ļ������
	PrintDayS(str, counts);
}

//14.��ӡͨ�����ջ�ȡ�ļ������
void PrintDayS(string& str, int counts)
{
	cout << "����2019��" << str << "����:" << counts << "��" << endl;
}

//15.��ȡ��ǰϵͳʱ��
void GetDateTime()
{
	while (1)
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
		Sleep(500);
		system("cls");
	}
}

//��Ҫƥ��Ľ���
vector<string> arr =
{
	    "04��01�գ����˽ڣ�", "04��05�գ������ڣ�", "04��16�գ�����ڣ�", "04��20�գ����꣩", "05��01�գ��Ͷ��ڣ�",
		"05��06�գ�����  ��", "05��12�գ�ĸ�׽ڣ�", "06��01�գ���ͯ�ڣ�", "06��06�գ�â�֣�", "06��07�գ�����ڣ�",
		"06��16�գ����׽ڣ�", "06��21�գ�����  ��", "07��07�գ�С��  ��", "07��23�գ����", "08��01�գ������ڣ�",
		"08��07�գ���Ϧ�ڣ�", "08��08�գ�����  ��", "08��23�գ�����  ��", "09��08�գ���¶��", "09��13�գ�����ڣ�",
		"09��23�գ����  ��", "10��01�գ�����ڣ�", "10��07�գ������ڣ�", "10��08�գ���¶��", "10��24�գ�˪��  ��",
		"11��08�գ�����  ��", "11��22�գ�Сѩ  ��", "11��28�գ��ж��ڣ�", "12��07�գ���ѩ��", "12��22�գ�����  ��",
		"12��24�գ�ƽ��ҹ��", "12��25�գ�ʥ���ڣ�", "11��11�գ��񻶽ڣ�"
};
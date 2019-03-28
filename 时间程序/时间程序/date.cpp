#if 1
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<time.h>
#include<Windows.h>

class Date
{
public:
	Date(int year = 1900, int month = 0, int day = 0, int hour = 0, int minute = 0, int second = 0)
		:_year(year)
		, _month(month)
		, _day(day)
		,_hour(hour)
		,_minute(minute)
		,_second(second)
	{
		if (!(_year > 0 && _month > 0 && _month < 13 && _day>0 && _day <= GetDays(_year, _month)))
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}

	}
	int GetDays(int year, int month)
	{
		int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && IsLeapYear(year))
		{
			days[month] += 1;
		}
		return days[month];
	}

	bool IsLeapYear(int year)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		{
			return true;
		}
		return false;
	}
	//������Ĭ�ϵĿ��������Լ���ֵ�ķ�ʽ��ǳ����
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{

	}
	//��ֵ�����
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_day = d._day;
			_month = d._month;
			_year = d._year;
		}
		return *this;
	}
	//���������
	Date operator+(int days)
	{
		if (days <= 0)
		{
			return *this - (0 - days);
		}
		int Days;
		Date temp(*this);
		temp._day += days;
		while (temp._day > (Days = GetDays(temp._year, temp._month)))
		{
			temp._day -= Days;
			temp._month += 1;
			if (temp._month > 12)
			{
				temp._year += 1;
				temp._month = 1;
			}
		}
		*this = temp;
		return *this;
	}

	Date operator-(int days)
	{
		if (days <= 0)
		{
			return *this + (0 - days);
		}
		Date temp(*this);

		temp._day -= days;
		while (temp._day < 0)
		{
			//temp._day += GetDays(temp._year, temp._month);
			temp._month -= 1;
			if (temp._month < 1)
			{
				temp._year -= 1;
				temp._month = 12;
			}
			temp._day += GetDays(temp._year, temp._month);
		}
		*this = temp;
		return *this;
	}
	//ǰ��++
	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}
	//����++
	Date operator++(int)
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;
	}
	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}
	Date operator--(int)
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;
	}
	//�������ڼ������
	int operator-(const Date& d)
	{
		Date MinDate(*this);
		Date MaxDate(d);
		if (MinDate > MaxDate)
		{
			swap(MinDate, MaxDate);
		}
		int count = 0;
		while (MinDate < MaxDate)
		{
			count = count + 1;
			MinDate = MinDate + 1;
		}
		return count;
	}

	bool operator>(const Date& d)
	{
		return (_year > d._year || (_year == d._year&&_month > d._month) || (_year == d._year&&_month == d._month&&_day > d._day));
	}
	bool operator<(const Date& d)
	{
		return (_year < d._year || (_year == d._year&&_month < d._month) || (_year == d._year&&_month == d._month&&_day < d._day));
	}
	bool operator==(const Date& d)
	{
		return !(*this > d || *this < d);
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}
	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year << "��" << d._month << "��" << d._day << "��" << " " << d._hour << "ʱ" << d._minute << "��" << d._second << "��" << endl;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;
	int _second;
};

int main()
{
	while (1)
	{
		struct tm *systime;
		time_t nowtime;
		time(&nowtime);
		systime = localtime(&nowtime);
		Date d(systime->tm_year + 1900, systime->tm_mon + 1, systime->tm_mday, systime->tm_hour, systime->tm_min, systime->tm_sec);
		cout << "������:" << endl;
		cout << d << endl;
		cout << "����2019�����ڻ��У�";
		Date d1(2019, 6, 7);
		cout << d1 - d << "��" << endl;
		cout << "����2019�����ڻ��У�";
		Date d2(2019, 10, 1);
		cout << d2 - d << "��" << endl;
		cout << "����2019������ڻ��У�";
		Date d3(2019, 9, 13);
		cout << d3 - d << "��" << endl;
		cout << "����2020���Ϧ���У�";
		Date d10(2020, 1, 24);
		cout << d10 - d << "��" << endl;
		Sleep(1000);
		system("cls");
	}
	system("pause");
	return 0;
}
#endif;

#if 0
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int array[] = { 0,1,2 };
	int num, count = 0;
	struct tm *systime;
	time_t nowtime;
	time(&nowtime);
	systime = localtime(&nowtime);
data:
	printf("����˵������������0\n");
	while (1)
	{
		printf("�����룺\n");
		scanf("%d", &num);
		count++;
		if (0 == num)
		{
			printf("����1��ʵ��ǰϵͳ���ڣ�����2��ʾ��ǰϵͳʱ�䣬�������������ַ������˳���ѯ\n");
		}
		else if (1 == num)
		{
			printf("��ǰϵͳ����:\n");
			printf("%d-%d-%d\n", systime->tm_year + 1900, systime->tm_mon + 1, systime->tm_mday);
		}
		else if (2 == num)
		{
			printf("��ǰϵͳʱ��:\n");
			printf("%d:%d:%d\n", systime->tm_hour, systime->tm_min, systime->tm_sec);
		}
		else
		{
			if (count < 2)
			{
				goto data;
			}
			printf("�˳���ѯ\n");
			break;
		}
	}
	system("pause");
	return 0;
}
#endif
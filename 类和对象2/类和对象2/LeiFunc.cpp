#include"Lei.h"
//�����ຯ��
void Date::SetDate(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
void Date::PrintDate()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

Date::Date()
{
	cout << "���캯��" << endl;
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

//ʱ���ຯ��
void Time::SetTime(int hour, int minute, int second)
{
	_hour = hour;
	_minute = minute;
	_second = second;
}
void Time::PrintTime()
{
	cout << _hour << ":" << _minute << ":" << _second << endl;
}

Time::Time()
{
	cout << "�Զ��幹�캯��" << endl;
}
void Date2::SetDate(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
void Date2::PrintDate()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

Date2::Date2(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
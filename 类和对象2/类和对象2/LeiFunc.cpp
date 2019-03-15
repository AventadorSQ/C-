#include"Lei.h"
//日期类函数
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
	cout << "构造函数" << endl;
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

//时间类函数
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
	cout << "自定义构造函数" << endl;
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
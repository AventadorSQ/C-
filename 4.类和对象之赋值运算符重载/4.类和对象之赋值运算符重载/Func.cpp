#include"赋值运算符重载.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
//加法
Date& Date::operator+(int days)
{
	_day += days;
	return *this;
}
//减法
Date& Date::operator-(int days)
{
	_day -= days;
	return *this;
}
//前置++
Date& Date::operator++()
{
	++_day;
	return *this;
}
//后置++
Date& Date::operator++(int)
{
	Date temp = *this;
	_day++;
	return temp;
}
//前置--
Date& Date::operator--()
{
	--_day;
	return *this;
}
//后置--
Date& Date::operator--(int)
{
	Date temp = *this;
	_day--;
	return temp;
}

void Date::PrintDate()
{
	cout << _year << " " << _month << " " << _day << endl;
}
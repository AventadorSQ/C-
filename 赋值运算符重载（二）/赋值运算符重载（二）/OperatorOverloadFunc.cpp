#include"OperatorOverload.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
void Date::PrintDate()
{
	cout << _year << " " << _month << " " << _day << endl;
}

//大于
bool Date::operator>(Date& Dates)
{
	if (this == &Dates)
	{
		return false;
	}
	if ((_year > Dates._year) || (_year == Dates._year&&_month > Dates._month) || (_year == Dates._year&&_month == Dates._month&&_day > Dates._day))
	{
		return true;
	}
	return false;
}
//大于等于
bool Date::operator>=(Date& Dates)
{
	if (this == &Dates)
	{
		return true;
	}
	if ((_year >= Dates._year) || (_year == Dates._year&&_month >= Dates._month) || (_year == Dates._year&&_month == Dates._month&&_day >= Dates._day))
	{
		return true;
	}
	return false;
}
//小于
bool Date::operator<(Date& Dates)
{
	if (this == &Dates)
	{
		return false;
	}
	if ((_year < Dates._year) || (_year == Dates._year&&_month < Dates._month) || (_year == Dates._year&&_month == Dates._month&&_day < Dates._day))
	{
		return true;
	}
	return false;
}
//小于等于
bool Date::operator<=(Date& Dates)
{
	if (this == &Dates)
	{
		return true;
	}
	if ((_year <= Dates._year) || (_year == Dates._year&&_month <= Dates._month) || (_year == Dates._year&&_month == Dates._month&&_day <= Dates._day))
	{
		return true;
	}
	return false;
}
//等于
bool Date::operator==(Date& Dates)
{
	if (this == &Dates)
	{
		return true;
	}
	if (_year == Dates._year&&_month == Dates._month&&_day == Dates._day)
	{
		return true;
	}
	return false;
}
//不等于
bool Date::operator!=(Date& Dates)
{
	if (this == &Dates)
	{
		return false;
	}
	if (_year != Dates._year||_month != Dates._month||_day != Dates._day)
	{
		return true;
	}
	return false;
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

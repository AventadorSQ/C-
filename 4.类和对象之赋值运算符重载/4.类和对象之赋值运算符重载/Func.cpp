#include"��ֵ���������.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}
//�ӷ�
Date& Date::operator+(int days)
{
	_day += days;
	return *this;
}
//����
Date& Date::operator-(int days)
{
	_day -= days;
	return *this;
}
//ǰ��++
Date& Date::operator++()
{
	++_day;
	return *this;
}
//����++
Date& Date::operator++(int)
{
	Date temp = *this;
	_day++;
	return temp;
}
//ǰ��--
Date& Date::operator--()
{
	--_day;
	return *this;
}
//����--
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
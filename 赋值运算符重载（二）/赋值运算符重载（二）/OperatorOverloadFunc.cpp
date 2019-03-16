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

//����
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
//���ڵ���
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
//С��
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
//С�ڵ���
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
//����
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
//������
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

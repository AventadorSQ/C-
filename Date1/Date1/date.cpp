#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 0, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		if (!(_year > 0 && _month > 0 && _month < 13 && _day>0 && _day <= GetDays(_year, _month)))
		{
			_year=1900;
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
	//编译器默认的拷贝构造以及赋值的方式是浅拷贝
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{

	}
	//赋值运算符
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
	//运算符重载
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
	//前置++
	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}
	//后置++
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
	//两个日期间隔天数
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
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(2019, 3, 19);
	cout << d << endl;
	d = d + 100;
	cout << d << endl;
	d = d - 100;
	cout << d << endl;
	Date d1(2020, 1, 24);
	cout << d1 - d << endl;
	system("pause");
	return 0;
}
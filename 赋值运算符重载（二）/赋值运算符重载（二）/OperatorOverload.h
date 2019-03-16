#pragma once

#include<iostream>
using namespace std;

class Date
{
public :
	Date(int year = 2019, int month = 3, int day = 16);
	void PrintDate();

	//大于
	bool operator>(Date& Dates);
	//大于等于
	bool operator>=(Date& Dates);
	//小于
	bool operator<(Date& Dates);
	//小于等于
	bool operator<=(Date& Dates);
	//等于
	bool operator==(Date& Dates);
	//不等于
	bool operator!=(Date& Dates);
	//加法
	Date& operator+(int days);
	//减法
	Date& operator-(int days);
	//前置++
	Date& operator++();
	//后置++
	Date& operator++(int);
	//前置--
	Date& operator--();
	//后置--
	Date& operator--(int);
private:
	int _year;
	int _month;
	int _day;
};
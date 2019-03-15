#pragma once

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2019, int month = 3, int day = 15);
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
	void PrintDate();
private :
	int _year;
	int _month;
	int _day;
};
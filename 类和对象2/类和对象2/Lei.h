#pragma once
#include<iostream>
using namespace std;

//日期类
class Date
{
public:
	void SetDate(int year, int month, int day);
	void PrintDate();
	Date();
	Date(int year, int month = 03, int day = 13);
private:
	int _year;
	int _month;
	int _day;
};

//********************************************************
//编译器要给Date2类生成默认的构造函数
//Date2：我们没有自定义构造函数
//Time：有构造函数，并且Time类构造函数是默认的构造函数
//如果我们自定义构造函数（此时编译器就不会自动生成构造函数）
//如果是有参并且是半缺省时，必须在创建类类型对象时至少赋完没有带默认值的参数，否则会报错

//时间类
class Time
{
public:
	void SetTime(int hour, int minute, int second);
	void PrintTime();
private:
	int _hour;
	int _minute;
	int _second;
};

//日期类
class Date2
{
public:
	void SetDate(int year, int month, int day);
	void PrintDate();
	Date2(int year, int month = 03, int day = 13);
private:
	int _year;
	int _month;
	int _day;
	Time _T;
};
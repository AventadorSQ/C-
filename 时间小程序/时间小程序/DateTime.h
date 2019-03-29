#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
#include<ctime>
#include<Windows.h>

#include<string>
#include<vector>

//需要匹配的节日
extern vector<string> arr;

//日期类
class DateTime
{
private:
	//重载输入输出
	friend ostream& operator<<(ostream& _cout, const DateTime& d);
	friend istream& operator>>(istream& _cin, DateTime& d);
public:
	//1.构造函数DateTime
	DateTime(int year = 1900, int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0);

	//2.获取某一年某一月的天数
	int GetDayS(int year, int month);

	//3.判断是不是闰年
	bool IsLeapYear(int year);

	//4.自定义拷贝构造函数
	DateTime(const DateTime& d);

	//5.计算输入增加一定天数后的日期
	DateTime operator+(int dayS);

	//6.计算输入减少一定天数后的日期
	DateTime operator-(int dayS);

	//7.计算两个日期之间的间隔天数
	int operator-(const DateTime& d);

	//8.判断当前日期是否大于给定日期
	bool operator>(const DateTime& d);

	//9.自定义析构函数
	~DateTime();
private:
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;
	int _second;
};

//DateTime的友元
//10.1重载输出
ostream& operator<<(ostream& _cout, const DateTime& d);
//10.2重载输入
istream& operator>>(istream& _cin, DateTime& d);

//11.用日期来查询
void DateQuery(DateTime& d, DateTime& Date);

//12.通过节日查询
void FestivalQuery(DateTime& d, string& str);

//13.通过解析所匹配到的字符串，来取得所在日期,从而计算出间隔天数
void AnalysisStr(DateTime& d, string& str, string ArrChild);

//14.打印通过节日获取的间隔天数
void PrintDayS(string& str, int counts);

//15.获取当前系统时间
void GetDateTime();
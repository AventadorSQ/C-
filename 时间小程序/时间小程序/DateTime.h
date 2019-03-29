#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
#include<ctime>
#include<Windows.h>

#include<string>
#include<vector>

//��Ҫƥ��Ľ���
extern vector<string> arr;

//������
class DateTime
{
private:
	//�����������
	friend ostream& operator<<(ostream& _cout, const DateTime& d);
	friend istream& operator>>(istream& _cin, DateTime& d);
public:
	//1.���캯��DateTime
	DateTime(int year = 1900, int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0);

	//2.��ȡĳһ��ĳһ�µ�����
	int GetDayS(int year, int month);

	//3.�ж��ǲ�������
	bool IsLeapYear(int year);

	//4.�Զ��忽�����캯��
	DateTime(const DateTime& d);

	//5.������������һ�������������
	DateTime operator+(int dayS);

	//6.�����������һ�������������
	DateTime operator-(int dayS);

	//7.������������֮��ļ������
	int operator-(const DateTime& d);

	//8.�жϵ�ǰ�����Ƿ���ڸ�������
	bool operator>(const DateTime& d);

	//9.�Զ�����������
	~DateTime();
private:
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;
	int _second;
};

//DateTime����Ԫ
//10.1�������
ostream& operator<<(ostream& _cout, const DateTime& d);
//10.2��������
istream& operator>>(istream& _cin, DateTime& d);

//11.����������ѯ
void DateQuery(DateTime& d, DateTime& Date);

//12.ͨ�����ղ�ѯ
void FestivalQuery(DateTime& d, string& str);

//13.ͨ��������ƥ�䵽���ַ�������ȡ����������,�Ӷ�������������
void AnalysisStr(DateTime& d, string& str, string ArrChild);

//14.��ӡͨ�����ջ�ȡ�ļ������
void PrintDayS(string& str, int counts);

//15.��ȡ��ǰϵͳʱ��
void GetDateTime();
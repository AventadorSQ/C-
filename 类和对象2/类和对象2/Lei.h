#pragma once
#include<iostream>
using namespace std;

//������
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
//������Ҫ��Date2������Ĭ�ϵĹ��캯��
//Date2������û���Զ��幹�캯��
//Time���й��캯��������Time�๹�캯����Ĭ�ϵĹ��캯��
//��������Զ��幹�캯������ʱ�������Ͳ����Զ����ɹ��캯����
//������вβ����ǰ�ȱʡʱ�������ڴ��������Ͷ���ʱ���ٸ���û�д�Ĭ��ֵ�Ĳ���������ᱨ��

//ʱ����
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

//������
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
#pragma once

#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2019, int month = 3, int day = 15);
	//�ӷ�
	Date& operator+(int days);
	//����
	Date& operator-(int days);
	//ǰ��++
	Date& operator++();
	//����++
	Date& operator++(int);
	//ǰ��--
	Date& operator--();
	//����--
	Date& operator--(int);
	void PrintDate();
private :
	int _year;
	int _month;
	int _day;
};
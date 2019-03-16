#pragma once

#include<iostream>
using namespace std;

class Date
{
public :
	Date(int year = 2019, int month = 3, int day = 16);
	void PrintDate();

	//����
	bool operator>(Date& Dates);
	//���ڵ���
	bool operator>=(Date& Dates);
	//С��
	bool operator<(Date& Dates);
	//С�ڵ���
	bool operator<=(Date& Dates);
	//����
	bool operator==(Date& Dates);
	//������
	bool operator!=(Date& Dates);
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
private:
	int _year;
	int _month;
	int _day;
};
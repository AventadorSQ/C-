#pragma once

#include<iostream>
using namespace std;

#include<cassert>
#include<malloc.h>
typedef int DataType;

class SeqList
{
public:
	SeqList(size_t capacity = 20);
	~SeqList();
private:
	DataType * _array;
	int _capacity;
	int _size;
};

//************************************
 //����������
//1.����
//2.����ʱ��
//3.���ã���ն������Դ����ֹ��Դй¶
//4.���ԣ�
//5.����Ĭ���鹹������
//     �������û���Զ���������������������������һ��Ĭ�ϵ���������


//*******************************************************************
//�������캯��
class Date
{
public:
	Date(int year = 2019, int month = 03, int day = 14);
	//Date(Date& d);
	Date(const Date& d);
	void PrintDate();
private:
	int _year;
	int _month;
	int _day;
};

//����ʹ�ñ������Զ����ÿ������캯������
//����������
class String
{
public:
	String(const char* ptr = "SUST");
	~String();

private:
	char* _ptr;
};
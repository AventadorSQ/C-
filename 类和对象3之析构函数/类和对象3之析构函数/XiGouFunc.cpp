#include"XiGou.h"

SeqList::SeqList(size_t capacity)
{
	cout << "��������" << this << endl;
	_array = (DataType*)malloc(sizeof(DataType) * 20);
	assert(_array);
	_capacity = 20;
	_size = 0;
}

//������������ǰ�������������Դ
//�빹�캯������
//��������û�в�����˲�������
//ֻ�ܴ���һ��
//
//Ϊʲôû�в�����
//��Ϊ������ǰ�������Դ��ֱ����գ����������

SeqList::~SeqList()
{
	if (_array)
	{
		free(_array);
		_array = nullptr;
		_capacity = 0;
		_size = 0;
	}
	cout << "��������" << this << endl;
}

//******************************************************************
//�������캯��
Date::Date(int year, int month, int day)
{
	cout << "Date " << this << endl;
	_year = year;
	_month = month;
	_day = day;
}
Date::Date(const Date& d)
{
	cout << "Date& d " << this << endl;
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
void Date::PrintDate()
{
	cout << _year << " " << _month << " " << _day << endl;
}

//****************************************************************
//����ʹ�ñ������Զ����ÿ������캯������
//����������
String::String(const char* ptr)
{
	if (ptr == nullptr)
		ptr = "";

	_ptr = (char*)malloc(sizeof(ptr) + 1);
	cout << "���캯��" << this << endl;
}

String::~String()
{
	cout << "��������" << this << endl;
	free(_ptr);
	_ptr = nullptr;
}
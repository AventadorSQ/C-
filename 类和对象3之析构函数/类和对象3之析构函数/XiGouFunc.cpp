#include"XiGou.h"

SeqList::SeqList(size_t capacity)
{
	cout << "创建对象" << this << endl;
	_array = (DataType*)malloc(sizeof(DataType) * 20);
	assert(_array);
	_capacity = 20;
	_size = 0;
}

//析构函数清理当前对象所管理的资源
//与构造函数区别：
//析构函数没有参数因此不能重载
//只能存在一个
//
//为什么没有参数？
//因为是清理当前对象的资源，直接清空，无需参数。

SeqList::~SeqList()
{
	if (_array)
	{
		free(_array);
		_array = nullptr;
		_capacity = 0;
		_size = 0;
	}
	cout << "析构函数" << this << endl;
}

//******************************************************************
//拷贝构造函数
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
//不能使用编译器自动调用拷贝构造函数例子
//测试用例：
String::String(const char* ptr)
{
	if (ptr == nullptr)
		ptr = "";

	_ptr = (char*)malloc(sizeof(ptr) + 1);
	cout << "构造函数" << this << endl;
}

String::~String()
{
	cout << "析构函数" << this << endl;
	free(_ptr);
	_ptr = nullptr;
}
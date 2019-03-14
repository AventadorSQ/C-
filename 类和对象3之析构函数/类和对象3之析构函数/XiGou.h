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
 //析构函数：
//1.概念
//2.调用时机
//3.作用：清空对象的资源。防止资源泄露
//4.特性：
//5.关于默认虚构函数：
//     如果我们没有自定义析构函数，编译器将会生成一个默认的析构函数


//*******************************************************************
//拷贝构造函数
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

//不能使用编译器自动调用拷贝构造函数例子
//测试用例：
class String
{
public:
	String(const char* ptr = "SUST");
	~String();

private:
	char* _ptr;
};
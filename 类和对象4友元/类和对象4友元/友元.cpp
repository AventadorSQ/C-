
#include<iostream>
using namespace std;

#if 0
//友元函数可以再类外访问私有成员变量
//
//友元函数：
//1.如果一个函数是类的友元函数，在该函数中可以直接访问类的私有成员
//2.友元函数不是类的成员函数
class date
{
private:
	//友元函数声明
	friend ostream& operator<<(ostream& _cout, const date& d);
public:
	date(int _year,int _month,int _day)
	{
		year = _year;
		month = _month;
		day = _day;
		
	}

private:
	int year = 2019;
	int month = 3;
	int day = 18;

};


//第一个参数不加const因为cout返回状态可能会改变。而d不需改变
ostream& operator<<(ostream& _cout, const date& d)
{
	_cout << d.year << " " << d.month << " " << d.day;
	return _cout;
}

int main()
{
	date d(2019,3,19);
	cout << d << endl;
	system("pause");
	return 0;
}
#endif

//友元类

class time
{
	friend class date;
public:
	time()
	{}
private:
	int hour = 20;
	int minute = 20;
	int second = 2;
};

class date
{
public:

	date(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
	}
	void PrintDate()
	{
		cout << year << "-" << month << "-" << day << "-" << t.hour << ":" << t.minute << ":" << t.second << endl;
	}
private:
	int year = 2019;
	int month = 3;
	int day = 18;
	time t;
};

//友元优点：
//        可以提高代码运行的效率
//缺点：
//        可以直接访问类中私有成员变量（不需通过公有方法）破坏类的封装性

int main()
{
	date d(2019, 3, 19);
	d.PrintDate();
	system("pause");
	return 0;
}

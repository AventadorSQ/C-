#include<iostream>
using namespace std;


//函数模板实例化：隐式类型转换
//在模板参数列表不能用struct来声明类型
//模板参数列表
//函数模板不是函数，它是编译器生成代码的模子

#if 0
template<typename Type1, class Type2>
Type1 Add(Type1 num1, Type2 num2)
{
	cout << typeid(Type1).name() << endl;
	return num1 + num2;
}

//推演实参的类型--->让编译器根据函数模板和传的参数类型来推演T的实际类型，从而生成具体类型的函数
int main()
{
	cout << Add(1.0, 2) << endl;
	cout << Add(1, 2) << endl;//int ---> Add<int>
	cout << Add(1.2, 2.2) << endl;//double ---> Add<double>
	cout << Add('1', '2') << endl;
	cout << Add('1', 2) << endl;//char
	cout << Add(1, '2') << endl;//int
	system("pause");
	return 0;
}
#endif

//实例化是在编译阶段，编译器通过推演实参类型来确定模板的参数列表中类型参数所代表的实际类型，
//再结合函数模板来生成处理具体类型的代码
//注意：隐式实例化一般情况下不会进行隐式类型转化

//显示实例化：明确给定模板参数列表中的类型Type
//注意：不需要进行参数推演，直接生成代码，可能会进行隐式类型转化（可能成功，也可能失败）

#if 0
template<typename Type1>
Type1 Add(Type1 num1, Type1 num2)
{
	cout << typeid(Type1).name() << endl;
	return num1 + num2;
}

//推演实参的类型--->让编译器根据函数模板和传的参数类型来推演T的实际类型，从而生成具体类型的函数
int main()
{
	//隐式实例化-大部分情况下不会进行类型转化
	//            如果参数类型不匹配，编译器将来可能会报错
	cout << Add(1, 2) << endl;//int ---> Add<int>
	cout << Add(1.2, 2.2) << endl;//double ---> Add<double>
	cout << Add('1', '2') << endl;

	//一旦根据类型生成函数，后面再调用相同类型的函数就不会再去生成函数，直接拿来调用
	cout << Add(1, (int)'2') << endl;//int
	//cout << Add(1, '2') << endl;
	//显式实例化---明确指定类型参数的实际类型
	// 可能会发生隐式类型转化
	cout << Add<int>(1, '2') << endl;
	cout << Add<int>(1, "acdv") << endl;
	system("pause");
	return 0;
}

#endif

#if 0
template<typename Type1>
Type1 Add(Type1 num1, Type1 num2)
{
	cout << typeid(Type1).name() << endl;
	return num1 + num2;
}
int Add(int num1, int num2)
{
	return num1 + num2;
}

int main()
{
	//优先调用自定义函数
	Add(1, 2);

	//若想调模板来生成,两种办法
	Add<int>(1, 3);

	//隐式实例化
	//让函数模板根据实参推演的实际类型生成一份代码
	Add<>(1, 3);
	//Add<>(1, 3.2);
	system("pause");
	return 0;
}
#endif

#if 0
//函数模板也可以自动类型转化
template<typename Type1>
void ArrFunc(Type1 array)
{
	cout << typeid(array).name() << endl;
}


int main()
{
	int arr[66];
	ArrFunc(arr);
	system("pause");
	return 0;
}
#endif


template<typename Type1>
Type1 Add(Type1& num1, Type1& num2)
{
	cout << typeid(Type1).name() << endl;
	return num1 + num2;
}

class Date
{
public:
	Date(int yearS,int monthS,int dayS)
		:year(yearS)
		,month(monthS)
		,day(dayS)
	{}
	Date operator+(const Date& d)
	{
		year += d.year;
		month += d.month;
		day += d.day;
		return *this;
	}
	void Print()
	{
		cout << year << "-" << month << "-" << day << endl;
	}
private:
	int year;
	int month;
	int day;
};

int main()
{
	Date d1(2019, 3, 22);
	d1.Print();
	Date d2(0, 0, 1);
	Add(d1, d2);
	d1.Print();
	system("pause");
	return 0;
}


//template<typename Type1>
//Type1 Add(const Type1 num1, const Type1 num2)
//{
//	cout << typeid(Type1).name() << endl;
//	return num1 + num2;
//}
//
//class Date
//{
//public:
//	Date(int yearS, int monthS, int dayS)
//		:year(yearS)
//		, month(monthS)
//		, day(dayS)
//	{}
//	//const类型的对象不能调普通类型的成员函数
//	Date operator+(const Date& d)const
//	{
//		return Date(year + d.year,
//			month + d.month,
//			day + d.day);
//	}
//private:
//	int year;
//	int month;
//	int day;
//};
//
//int main()
//{
//	Date d1(2019, 3, 22);
//	Date d2(0, 0, 1);
//	Add(d1, d2);
//	system("pause");
//	return 0;
//}



#include<iostream>
using namespace std;


//����ģ��ʵ��������ʽ����ת��
//��ģ������б�����struct����������
//ģ������б�
//����ģ�岻�Ǻ��������Ǳ��������ɴ����ģ��

#if 0
template<typename Type1, class Type2>
Type1 Add(Type1 num1, Type2 num2)
{
	cout << typeid(Type1).name() << endl;
	return num1 + num2;
}

//����ʵ�ε�����--->�ñ��������ݺ���ģ��ʹ��Ĳ�������������T��ʵ�����ͣ��Ӷ����ɾ������͵ĺ���
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

//ʵ�������ڱ���׶Σ�������ͨ������ʵ��������ȷ��ģ��Ĳ����б������Ͳ����������ʵ�����ͣ�
//�ٽ�Ϻ���ģ�������ɴ���������͵Ĵ���
//ע�⣺��ʽʵ����һ������²��������ʽ����ת��

//��ʾʵ��������ȷ����ģ������б��е�����Type
//ע�⣺����Ҫ���в������ݣ�ֱ�����ɴ��룬���ܻ������ʽ����ת�������ܳɹ���Ҳ����ʧ�ܣ�

#if 0
template<typename Type1>
Type1 Add(Type1 num1, Type1 num2)
{
	cout << typeid(Type1).name() << endl;
	return num1 + num2;
}

//����ʵ�ε�����--->�ñ��������ݺ���ģ��ʹ��Ĳ�������������T��ʵ�����ͣ��Ӷ����ɾ������͵ĺ���
int main()
{
	//��ʽʵ����-�󲿷�����²����������ת��
	//            ����������Ͳ�ƥ�䣬�������������ܻᱨ��
	cout << Add(1, 2) << endl;//int ---> Add<int>
	cout << Add(1.2, 2.2) << endl;//double ---> Add<double>
	cout << Add('1', '2') << endl;

	//һ�������������ɺ����������ٵ�����ͬ���͵ĺ����Ͳ�����ȥ���ɺ�����ֱ����������
	cout << Add(1, (int)'2') << endl;//int
	//cout << Add(1, '2') << endl;
	//��ʽʵ����---��ȷָ�����Ͳ�����ʵ������
	// ���ܻᷢ����ʽ����ת��
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
	//���ȵ����Զ��庯��
	Add(1, 2);

	//�����ģ��������,���ְ취
	Add<int>(1, 3);

	//��ʽʵ����
	//�ú���ģ�����ʵ�����ݵ�ʵ����������һ�ݴ���
	Add<>(1, 3);
	//Add<>(1, 3.2);
	system("pause");
	return 0;
}
#endif

#if 0
//����ģ��Ҳ�����Զ�����ת��
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
//	//const���͵Ķ����ܵ���ͨ���͵ĳ�Ա����
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




#include<iostream>
using namespace std;

#if 0
//��Ԫ�����������������˽�г�Ա����
//
//��Ԫ������
//1.���һ�������������Ԫ�������ڸú����п���ֱ�ӷ������˽�г�Ա
//2.��Ԫ����������ĳ�Ա����
class date
{
private:
	//��Ԫ��������
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


//��һ����������const��Ϊcout����״̬���ܻ�ı䡣��d����ı�
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

//��Ԫ��

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

//��Ԫ�ŵ㣺
//        ������ߴ������е�Ч��
//ȱ�㣺
//        ����ֱ�ӷ�������˽�г�Ա����������ͨ�����з������ƻ���ķ�װ��

int main()
{
	date d(2019, 3, 19);
	d.PrintDate();
	system("pause");
	return 0;
}

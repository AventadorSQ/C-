#include<iostream>
using namespace std;

class Data
{
public:
    void CinDay()
	{
	    cin >> _year >> _month >> _day;
		CountDay();
		//_year = year;
		//_month = month;
		//_day = day;
	}
	//istream & CinDay()
	//{
	//	return cin >> _year >> _month >> _day;
	//	//_year = year;
	//	//_month = month;
	//	//_day = day;
	//}
	void CountDay()
	{
		if ((_year % 100 == 0 && _year % 4 != 0) || (_year % 4 == 0))
		{
			if (_month >= 2)
			{
				CountFDayS += 1;
			}
			for (int i = 0; i < _month - 1; i++)
			{
				CountFDayS += array[i];
			}
			CountFDayS += _day;
			CountLDayS = 366 - CountFDayS + 1;
		}
		else
		{
			for (int i = 0; i < _month - 1; i++)
			{
				CountFDayS += array[i];
			}
			CountFDayS += _day;
			CountLDayS = 365 - CountFDayS + 1;
		}
	}

	void PrintfDayNum()
	{
		cout << _year << "��" << _month << "��" << _day << "��" << ":" << _year << "���" << CountFDayS << "��" << endl;
		cout << _year << "��" << _month << "��" << _day << "��" << ":" << _year << "�굹����" << CountLDayS << "��" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	int CountFDayS = 0;
	int CountLDayS = 0;
	int array[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
};

int main()
{
	Data d;
	d.CinDay();
	d.PrintfDayNum();
	//while (d.CinDay();)
	//{
	//	d.CinDay();
	//	d.PrintfDayNum();
	//}
	system("pause");
	return 0;
}
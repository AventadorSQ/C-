#include"OperatorOverload.h"

void TestDate()
{
	Date d1(2019, 2, 28);
	d1.PrintDate();
	d1 = d1 + 2;
	d1.PrintDate();
	d1 = d1 - 2;
	d1.PrintDate();
	d1 = d1++;
	d1.PrintDate();
	d1 = ++d1;
	d1.PrintDate();
	d1 = d1--;
	d1.PrintDate();
	d1 = --d1;
	d1.PrintDate();
	Date d2;
	d2.PrintDate();
	cout << "d1 " << &d1 << endl;
	cout << "d2 " << &d2 << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
}
int main()
{
	TestDate();
	system("pause");
	return 0;
}
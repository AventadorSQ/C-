#include"��ֵ���������.h"

int main()
{
	Date d;
	d = d + 10;
	d.PrintDate();
	d = d - 10;
	d.PrintDate();
	d = d++;
	d.PrintDate();
	d = ++d;
	d.PrintDate();
	d = d--;
	d.PrintDate();
	d = --d;
	d.PrintDate();
	system("pause");
	return 0;
}
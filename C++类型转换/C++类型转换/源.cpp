#include<iostream>
using namespace std;

int main()
{
	//const int data = 1;
	//int* ptr = (int*)&data;
	//*ptr = 66;
	//cout << data << endl;

	volatile const int data1 = 1;
	//int* ptr = (int*)&data1;
	int* ptr = const_cast<int*>(&data1);
	*ptr = 66;
	cout << data1 << endl;


	const volatile int dataS = 10;
	int* ptrS = (int*)&dataS;
	*ptrS = 66;
	cout << dataS << endl;

	system("pause");
	return 0;
}

//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	const int data = 1;
//	int* ptr = &data;
//	*ptr = 6;
//	printf("data = %d\n", data);
//	system("pause");
//	return 0;
//}
#include"RadixSort.h"
#include<ctime>
#include<Windows.h>
#define SIZE 10000

int main()
{
	//srand((unsigned int)time(NULL));
	//int array[SIZE];
	//for (int i = 0; i < SIZE; i++)
	//{
	//	array[i] = rand() % 1000000;
	//}
	//cout << "Î´ÅÅÐò:";
	//Sleep(1000);
	//PrintArray(array, SIZE);
	//Sleep(1000);
	//RadixSort(array, SIZE);
	//cout << "ÒÑÅÅÐò:";
	//Sleep(1000);
	//PrintArray(array, SIZE);
	int array[]= { 12,63,156,982,20,478,639,32,2315,123 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintArray(array, size);
	RadixSort(array, size);
	PrintArray(array, size);
	system("pause");
	return 0;
}

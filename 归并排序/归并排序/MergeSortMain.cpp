#include"MergeSort.h"

#define ARRA_YSIZE 100

int main()
{
	srand((unsigned int)time(NULL));
	int array[ARRA_YSIZE];
	for (int i = 0; i < ARRA_YSIZE; i++)
	{
		array[i] = rand() % 100;
	}
    int size = sizeof(array) / sizeof(array[0]);
	cout << "δ����";
	PrintMergeSort(array, size);
	MergeSort(array, size);
	cout << "�鲢����";
	PrintMergeSort(array, size);
	system("pause");
	return 0;
}
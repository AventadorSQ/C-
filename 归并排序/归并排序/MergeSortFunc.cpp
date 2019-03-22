#include"MergeSort.h"

//���������������кϲ�
void merge(int arr[], int small, int mid, int big)
{
	//����һ����ʱ�������洢������������
	int* ptr = (int*)malloc(sizeof(int)*(big - small + 1));
	int i = small;//0
	int j = mid + 1;//2
	int k = 0;
	while (i <= mid && j <= big)
	{
		if (arr[i] <= arr[j])
		{
			ptr[k++] = arr[i++];
		}
		else
		{
			ptr[k++] = arr[j++];
		}
	}
	while (i <= mid)
	{
		ptr[k++] = arr[i++];
	}
	while (j <= big)
	{
		ptr[k++] = arr[j++];
	}
	for (i = small, k = 0; i <= big; k++, i++)
	{
		arr[i] = ptr[k];
	}
	free(ptr);
	ptr = nullptr;
}

//����һ�������е�ȫ����
void OneMerge(int arr[], int length, int size)
{
	int i;
	for (i = 0; i + 2 * length - 1 < size; i = i + 2 * length)
	{
		merge(arr, i, i + length - 1, i + 2 * length - 1);
	}
	if (i + length - 1 < size)
	{
		merge(arr, i, i + length - 1, size - 1);
	}
}

//���й鲢����
void MergeSort(int arr[], int size)
{
	for (int i = 1; i <= size; i *= 2)
	{
		OneMerge(arr, i, size);
	}
}

//��ӡ
void PrintMergeSort(int array[], int size)
{
	int i = 0;
	while (i < size)
	{
		cout << array[i++] << " ";
	}
	cout << endl;
}
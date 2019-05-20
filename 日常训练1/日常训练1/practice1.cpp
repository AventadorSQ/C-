#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


void Swap(int* arr1, int* arr2)
{
	int temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}
void QuickSort(int arr[], int length)
{
	if (length <= 1)
	{
		return;
	}
	int mid = length - 1;
	int i = 0;
	int j = length - 1;
	while (i < j)
	{
		while ((i < j) && (arr[i] <= arr[mid]))
			i++;
		while ((i < j) && (arr[j] >= arr[mid]))
			j--;
		Swap(&arr[i], &arr[j]);
	}
	Swap(&arr[i], &arr[mid]);
	mid = i;
	QuickSort(arr, mid - 1);
	QuickSort(arr + mid + 1, length - mid - 1);
}

int MaxFunc(int arr[], int size)
{
	QuickSort(arr, size);
	int MaxData = 0;
	for (int i = (size / 3); i < 2 * (size / 3); i++)
	{
		MaxData += arr[i];
	}
	return MaxData;
}

int main()
{
	int n = 6;
	//int arr[3 * n];
	//while (cin >> n)
	//{
	//	for (int i = 0; i < 3 * n; i++)
	//	{
	//		cin >> arr[i];
	//	}
	//}
	int arr[18] = {5,2,8,5,1,5,8,4,7,8,9,6,44,5,22,1,23,65};
	if (n == 0)
	{
		cout << "处理无效" << endl;
		return -1;
	}
	int MaxData = MaxFunc(arr, 3 * n);
	for (int i = 0; i < 3 * n; i++)
	{
		cout << arr[i] << " ";
	}
	cout<<endl;
	cout << MaxData << endl;
	system("pause");
	return 0;
}
int main()
{
	vector<int> v;
	int n;
	while (cin >> n)
	{
		sort(v.begin(), v.end());
	}
	return 0;
}
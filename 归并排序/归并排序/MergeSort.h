#pragma once
#include<ctime>
#include<malloc.h>
#include<iostream>
using namespace std;

//将两个有序子序列合并
void merge(int arr[], int small, int mid, int big);

//进行一趟子序列的全排序
void OneMerge(int arr[], int length, int size);

//进行归并排序
void MergeSort(int arr[], int size);

//打印
void PrintMergeSort(int array[], int size);
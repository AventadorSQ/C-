#pragma once
#include<ctime>
#include<malloc.h>
#include<iostream>
using namespace std;

//���������������кϲ�
void merge(int arr[], int small, int mid, int big);

//����һ�������е�ȫ����
void OneMerge(int arr[], int length, int size);

//���й鲢����
void MergeSort(int arr[], int size);

//��ӡ
void PrintMergeSort(int array[], int size);
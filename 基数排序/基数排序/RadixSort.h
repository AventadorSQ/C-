#pragma once

//基数排序
//1.按照低位优先开始
//6 8 9 2 4 1 3 7

#include<stdlib.h>
#include<cmath>
#include<iostream>
using namespace std;

//1.打印排序后的数组
void PrintArray(int array[], int size);

//2.交换两个数
void Swap(int* num1, int* num2);

//3.数组中最大的数
int MaxNum(int array[], int size);

//4.最大的数有多少位，记录其位数
int MaxWeiShu(int num);

//5.将基数进行一次排序
void OneSort(int array[], int size, int i);

//6.基数排序
void RadixSort(int array[], int size);
#pragma once

//��������
//1.���յ�λ���ȿ�ʼ
//6 8 9 2 4 1 3 7

#include<stdlib.h>
#include<cmath>
#include<iostream>
using namespace std;

//1.��ӡ����������
void PrintArray(int array[], int size);

//2.����������
void Swap(int* num1, int* num2);

//3.������������
int MaxNum(int array[], int size);

//4.�������ж���λ����¼��λ��
int MaxWeiShu(int num);

//5.����������һ������
void OneSort(int array[], int size, int i);

//6.��������
void RadixSort(int array[], int size);
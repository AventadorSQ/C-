#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE* fp = fopen("./����a.txt", "a");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return -1;
	}
	else
	{
		printf("�����ɹ�\n");
	}
	fclose(fp);
	system("pause");
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE* fp = fopen("./测试a.txt", "a");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return -1;
	}
	else
	{
		printf("创建成功\n");
	}
	fclose(fp);
	system("pause");
	return 0;
}

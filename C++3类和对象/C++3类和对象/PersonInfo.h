#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
	void SetPersonInfo(const char* name, const char* gender, int age);
	void PrintPersonInfo();
	char _name[20];
	char _gender[20];
	int _age;
};
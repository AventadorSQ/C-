#include"PersonInfo.h"

void Person::SetPersonInfo(const char* name, const char* gender, int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}
void Person::PrintPersonInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}
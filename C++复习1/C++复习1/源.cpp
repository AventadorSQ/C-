#include<iostream>
using namespace std;

#if 0
namespace test1
{
	int numS = 66;
	int nums = 88;
	int Add(int num1 = numS, int num2 = nums)
	{
		return num1 + num2;
	}
}
namespace test1
{
	int numS1 = 22;
	int nums1 = 11;
	int AddS(int num1 = numS1, int num2 = nums1)
	{
		return num1 + num2;
	}
}

int main()
{
	int temp = test1::Add();
	cout << temp << endl;
	system("pause");
	return 0;
}

#endif

#if 0
namespace test1
{
	int numS1 = 22;
	int nums1 = 11;
	int AddS(int num1 = numS1, int num2 = nums1)
	{
		return num1 + num2;
	}
}
using test1::AddS;
int main()
{
	int temp = AddS();
	cout << temp << endl;
	system("pause");
	return 0;
}
#endif

#if 0
class test
{
public:
	test(int a = 10)
	{
		_a = a;
	}
	int Get_A()
	{
		return _a;
	}
private:
	int _a;
};

extern "C" void Print(int data)
{
	printf("data = %d\n", data);
}
int main()
{
	test s;
	int data = s.Get_A();
	Print(data);
	system("pause");
	return 0;
}
#endif 

#if 0
int& Add(int a, int b) {
	int c = a + b;
	return c;
}
int main()
{
	int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1, 2) is :" << ret << endl;
	system("pause");
	return 0;
}
#endif

int main()
{
	//int b = 10;
	//int& rb = b;
	//const double a = 5.5;
	//const int& ra = a;
	//cout << ra << endl;
	cout << sizeof(nullptr) << endl;
	system("pause");
	return 0;
}
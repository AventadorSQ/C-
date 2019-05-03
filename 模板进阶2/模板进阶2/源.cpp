#include<iostream>
using namespace std;
//
//////������ģ�����
////template<class T, size_t N>
////class Array
////{
////public:
////	void fun()
////	{
////		cout << "ģ�����" << endl;
////	}
////private:
////	T array[N];
////};
////
////int main()
////{
////	Array<int, 6> arr;
////	arr.fun();
////	system("pause");
////	return 0;
////}
//
////ע������
////1.����
////2.��������ڱ���ǰ����ȷ�Ͼ���ֵ
//

//*********************************************************************************
////����ģ����ػ�
//
//template<class T>
//T& Max(T& left, T& right)
//{
//	return left > right ? left : right;
//}
//
//template<class T>
//const T& Max(const T& left, const T& right)
//{
//	return left > right ? left : right;
//}
//
//template<>
//char*& Max<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) >= 0)
//	{
//		return left;
//	}
//	else
//	{
//		return right;
//	}
//}
//
//template<>
//const char*& Max<const char*>(const char*& left, const char*& right)
//{
//	if (strcmp(left, right) >= 0)
//	{
//		return left;
//	}
//	else
//	{
//		return right;
//	}
//}
//
//int main()
//{
//	const char* ptr1 = "hehe";
//	const char* ptr2 = "haha";
//	cout << Max(ptr2, ptr1) << endl;
//	system("pause");
//	return 0;
//}
//

//template<class T>
//T& Max(T& left, T& right)
//{
//	return left > right ? left : right;
//}
//
//template<class T>
//const T& Max(const T& left, const T& right)
//{
//	return left > right ? left : right;
//}
//
//
//char* Max(char* left, char* right)
//{
//	if (strcmp(left, right) >= 0)
//	{
//		return left;
//	}
//	else
//	{
//		return right;
//	}
//}
//
//
//const char* Max(const char* left, const char* right)
//{
//	if (strcmp(left, right) >= 0)
//	{
//		return left;
//	}
//	else
//	{
//		return right;
//	}
//}
//
//int main()
//{
//	const char* ptr1 = "hehe";
//	const char* ptr2 = "haha";
//	cout << Max(ptr2, ptr1) << endl;
//	system("pause");
//	return 0;
//}

//************************************************************************************
////ͨ�õĿ����㷨
//#include<string>
//bool IsPodType(const char* strType)
//{
//	const char* strTypes[] = { "char","short","int","long","long long", "flost", "double","long double" };
//	size_t count = sizeof(strTypes) / sizeof(strTypes[0]);
//	for (size_t i = 0; i < count; i++)
//	{
//		if (0 == strcmp(strType, strTypes[i]))
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//template<class T>
//void Copy(T* des, T* src, size_t size)
//{
//	//��������--->memcpy �Զ�������---for+=
//	//ȷ��T�������Ƿ�Ϊ��������
//	if (IsPodType(typeid(T).name()))
//	{
//		memcpy(des, src, sizeof(T)*size);
//		//�ŵ㣺Ч�ʸ�
//		//ȱ�㣺ǳ����
//	}
//	else
//	{
//		for (size_t i = 0; i < size; i++)
//		{
//			des[i] = src[i];
//		}
//		//�ŵ㣺�����������������
//		//ȱ�㣺Ч�ʵ�
//	}
//}
//
//int main()
//{
//	string s[] = { "666","9990","hehe" };
//	string s1[3];
//	Copy(s1, s, 3);
//
//	int arr[] = { 0,1,2,3,4,5,6 };
//	int array[10];
//	size_t size = sizeof(arr) / sizeof(arr[0]);
//	Copy(array, arr, size);
//	system("pause");
//	return 0;
//}

//*************************************************************
//ͨ�õĿ����㷨2
#include<string>
//��������
struct TrueType
{};

//�Զ�������
struct FalseType
{};

//*********************************************************
//��ģ�弰�ػ�
template<class T>
struct TypeTraits
{
	typedef FalseType PODTYPE;
};

template<>
struct TypeTraits<char>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<int>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<short>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<long>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<double>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<float>
{
	typedef TrueType PODTYPE;
};
//******************************************************************
//������������
template<class T>
void _Copy(T* des, T* src, size_t size, TrueType)
{
	memcpy(des, src, sizeof(T)*size);
}

//�����Զ�������
template<class T>
void _Copy(T* des, T* src, size_t size, FalseType)
{
	for (size_t i = 0; i < size; i++)
	{
		des[i] = src[i];
	}
}

//********************************************************************
//ͨ�ÿ����㷨
template<class T>
void Copy(T* des, T* src, size_t size)
{
	//typedef typename TypeTraits<T>::PODTYPE  PODTYPE;
	_Copy(des, src, size, TypeTraits<T>::PODTYPE());
}

int main()
{
	int arr[] = { 0,1,2,3,4,5,6 };
	int array[10];
	size_t size = sizeof(arr) / sizeof(arr[0]);
	Copy(array, arr, size);

	string s[] = { "666","9990","hehe" };
	string s1[3];
	Copy(s1, s, 3);

	system("pause");
	return 0;
}
#include<iostream>
#include<vector>
using namespace std;

namespace FirstVector
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef T* reverse_iterator;
	public:
		//******************************************************************************
		//第一种基本操作
		//1.构造
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}
		//1.2
		vector(size_t n, const T& data = T())
		{
			_start = new T[n];
			for (size_t i = 0; i < n; i++)
			{
				_start[i] = data;
			}
			_finish = _start + n;
			_endOfStorage = _finish;
		}
		//1.3
		vector(T*first, T*last)
		{
			size_t size = last - first;
			_start = new T[size];
			_finish = _start;
			T* First = first;
			while (First != last)
			{
				*_finish = *First;
				First++;
				_finish++;
			}
			_endOfStorage = _finish;
		}
		//拷贝构造函数
		//注意浅拷贝的问题
		vector(vector<T>& v)
		{
			size_t VSize = v.size();
			_start = new T[VSize];
			_finish = _start;
			for (size_t i = 0; i < VSize; i++)
			{
				*_finish++ = v[i];
			}
			_endOfStorage = _finish;
		}

		//赋值运算符的重载
		vector<T>& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				size_t VSize = v.size();
				_start = new T[VSize];
				_finish = _start;
				for (int i = 0; i < VSize; i++)
				{
					*_finish++ = v[i];
				}
				_endOfStorage = _finish;
			}
		}

		//析构
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = nullptr;
				_finish = nullptr;
				_endOfStorage = nullptr;
			}
		}
		//******************************************************************************
		//迭代器
		//1.返回首位置begin
		iterator begin()
		{
			return _start;
		}

		//2.返回末尾位置end
		iterator end()
		{
			return _finish;
		}

		//3.反向迭代器
		//首位置rbegin
		reverse_iterator rbegin()
		{
			return end();
		}

		//4.末尾位置rend
		reverse_iterator rend()
		{
			return begin();
		}
		//******************************************************************************
		//容量相关操作
		//1.获取容量有效元素的个数
		size_t size()const
		{
			return _finish - _start;
		}

		//2.获取容量的大小
		size_t capacity()const
		{
			return _endOfStorage - _start;
		}

		//3.判断有没有元素
		bool empty()
		{
			return _finish == _start;
		}

		//4.扩容
		void reserve(size_t NewCapacity)
		{
			size_t OldCapacity = capacity();
			if (NewCapacity > OldCapacity)
			{
				T* temp = new T[NewCapacity];
				size_t OldSize = size();
				if (_start)
				{
					//T：是否为内置类型？ typeid(T).name()
					//编译期间确定
					//深拷贝
					//优点：一定不会出粗
					//缺点：效率低
					for (size_t i = 0; i < OldSize; i++)
					{
						temp[i] = _start[i];
					}
					//浅拷贝
					//memcpy优点：效率高 缺陷：浅拷贝，遇到自定义对象可能会出错
					//memcpy(temp, _start, size()*sizeof(T));
					delete[] _start;
				}
				_start = temp;
				_finish = _start + OldSize;
				_endOfStorage = _start + NewCapacity;
			}
		}

		//5.设置有效元素个数
		void resize(size_t NewSize, const T& data = T())
		{
			size_t OldSize = size();
			size_t _Capacity = capacity();
			if (NewSize > OldSize)
			{
				if (NewSize > _Capacity)
				{
					reserve(NewSize);
				}
				
				for (size_t i = OldSize; i < NewSize; i++)
				{
					*(_finish++) = data;
				}

			}
			else if (NewSize < OldSize)
			{
				_finish = _start + NewSize;
			}
		}
		//*******************************************************************************
		//元素访问操作
		//const
		//1.随机访问
		T operator[](size_t index)
		{
			size_t OldSize = size();
			if (index >= OldSize)
			{
				return NULL;
			}
			//assert(index < OldeSize);
			return _start[index];
		}

		const T* operator[](size_t index)const
		{
			size_t OldSize = size();
			if (index >= OldSize)
			{
				return nullptr;
			}
			//assert(index < OldeSize);
			return _start[index];
		}

		//2.访问头部元素
		T& front()
		{
			return _start[0];
		}

		const T& front()const
		{
			return _start[0];
		}
		//3.访问尾部元素
		T& back()
		{
			return *(_finish - 1);
		}
		const T& back()const
		{
			return *(_finish - 1);
		}
		//********************************************************************************
		//元素修改操作
		//1.尾部插入元素
		void push_back(const T& data)
		{
			if (_finish == _endOfStorage)
			{
				size_t OldCapacity = capacity();
				reserve(2 * (OldCapacity + 1));
			}
			*(_finish++) = data;
		}

		//2.尾部删除元素
		void pop_back()
		{
			if (_finish == _start)
			{
				return;
			}
			_finish--;
		}

		//iterator
		//3.任意位置插入
		iterator insert(iterator position, const T& data)
		{
			if (_finish == _endOfStorage)
			{
				size_t OldCapacity = capacity();
				reserve(2 * (OldCapacity + 1));
			}
			size_t OldSize = size();
			if (position <= OldSize)
			{
				for (size_t i = OldSize; i > position; i--)
				{
					_start[i] = _start[i - 1];
				}
				_start[position] = data;
				_finish++;
			}
		}

		//iterator
		//4.任意位置删除
		iterator erase(iterator position)
		{
			size_t OldSize = size();
			if (position >= OldSize)
			{
				return;
			}
			for (size_t i = position; i < OldSize; i--)
			{
				_start[i] = _start[i + 1];
			}
			_finish--;
		}

	private:
		T* _start;
		T* _finish;
		T* _endOfStorage;
	};
}

//memset设置一个字节//

//打印vector
template<class T>
void PrintVector(FirstVector::vector<T>& v)
{
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

//测试三种构造函数以及容量相关操作
void TestVector()
{
	FirstVector::vector<int> v1;
	FirstVector::vector<int> v2(10, 5);
	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
	FirstVector::vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));

	cout << v1.empty() << endl;
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	PrintVector(v1);
	v1.resize(6);
	v1.reserve(10);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;

	cout << v2.empty() << endl;
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
	PrintVector(v2);
	v2.resize(6);
	v2.reserve(12);
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;


	PrintVector(v3);
	
}

//测试拷贝构造以及复制运算符重载
void TestVector1()
{
	FirstVector::vector<int> v1(10, 5);
	FirstVector::vector<int> v2(v1);
	FirstVector::vector<int> v3 = v1;
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
	cout << v3.size() << endl;
	cout << v3.capacity() << endl;
	PrintVector(v1);
	PrintVector(v2);
	PrintVector(v3);
}

//测试元素访问系列操作
void TestVector2()
{
	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
	FirstVector::vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));
	cout << v4[5] << endl;
	cout << v4.front() << endl;
	cout << v4.back() << endl;
	PrintVector(v4);
}

//测试元素修改系列操作
void TestVector3()
{
	FirstVector::vector<int> v5(15, 6);
	cout << v5.size() << endl;
	v5.push_back(8);
	cout << v5.back() << endl;
	cout << v5.size() << endl;

	v5.pop_back();
	cout << v5.back() << endl;
	cout << v5.size() << endl;
	PrintVector(v5);

	//FirstVector::vector<int>::iterator v6(10, 8);
}


//************************************************************************************************
//迭代器失效：迭代器本质：指针--->指针失效--->指针指向了非法的空间
//迭代器指向的空间改变，而迭代器依旧指向原来的空间
//1.容量发生改变（赋值，插入，resize，reserve等等）
//2.当前迭代器所指向的元素删除（erase）
void TestVector5()
{
	vector<int> v{ 1,2,3,4,5 };
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	vector<int>::iterator it = v.begin();
	v.reserve(16);
	it = v.begin();
	cout << "*it = " << *it << endl;
}

void TestVector6()
{
	vector<int> v{ 1,2,3,4,5 };
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		//v.erase(it);	
		it = v.erase(it);
		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
//it = v.erase(it);
//for (auto& e : v)
//{
//	cout << e << " ";
//}
//cout << endl;
int main()
{
	TestVector6();
	system("pause");
	return 0;
}
//********************************************************************************************

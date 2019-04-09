#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//模拟实现String类的常用接口
//1.默认的拷贝构造函数以及赋值运算符重载---按照浅拷贝方式
// 浅拷贝：值的拷贝，内存的拷贝，将一个对象中的数据原封不动的拷贝到另一个对象中。
// 现象：多个对象使用同一份资源，后果：在对象被销毁时，同一份资源被释放多次而引起程序崩溃
// 解决办法：+引用计数的方式
//             销毁计数：
//             1.先将资源的计数-1
//             2.检测计数是否为0
//                是0：当前对象时最后一个使用该资源的对象，该对象需要负责清理资源
//              不是0：出当前对象外，还有其他对象使用该资源，当前对象不能清理资源
// 深拷贝：让每个对象都独立拥有资源，将资源中的内容拷贝一份

//传统版：
//现代版：尽量复用写过的方法---交换

//传统版
#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
		{
			str = "";
		}
		//+1是加上string字串的最后一个\0
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* ptr = new char[strlen(s._str) + 1];
			strcpy(ptr, s._str);
			delete[] _str;
			_str = ptr;
		}
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

#endif

//现代版
#if 0
class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
		{
			str = "";
		}
		//+1是加上string字串的最后一个\0
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		//防止在下面代码执行后去释放临时对象时代码崩溃（因为在创建当前对象时_str可能是随机值,释放就会出现问题）
		:_str(nullptr)
	{
		String STemp(s._str);
		swap(_str, STemp._str);
	}

	//String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		String STemp(s);
	//		swap(_str, STemp._str);
	//	}
	//	return *this;
	//}

	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
#endif

//浅拷贝计数
//存在问题：改一个对象的数据，其它对象也会被修改
//写诗拷贝：修改时把当前对象独立出来
//注意：线程问题

#if 0
class String
{
public:
	String(const char* str = "")
		:count(new int(1))
	{
		if (str == nullptr)
		{
			str = "";
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(s._str)
		,count(s.count)
	{
		(*count)++;
	}

	String& operator=(const String& s)
	{
		_str = s._str;
		(*s.count)++;
		count = s.count;
		return *this;
	}
	char& operator[](size_t index)
	{
		if (*count > 1)
		{
			String STemp(_str);
			this->Swap(STemp);
		}

		return _str[index];
	}
	const char& operator[](size_t index)const
	{
		return _str[index];
	}

	~String()
	{
		if ((*count) == 1 && _str)
		{
			delete[] _str;
			_str = nullptr;

			delete count;
			count = nullptr;
			return;
		}
		(*count)--;
	}
private:
	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(count, s.count);
	}
private:
	char* _str;
    int* count;
};

int main()
{
	String s("hello");
	String s1(s);
	String s2("world");
	s2 = s;
	s2[0] = 'H';
	return 0;
}

#endif

//模拟实现string

namespace Str
{
	class string
	{
		//构造函数
		string(const char* str = "")
		{
			if (str == nullptr)
			{
				str = "";
			}
			_size = _capacity = strlen(str);
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//拷贝构造函数
		string(const string& s)
		{
			string strTemp(s._str);
			Swap(strTemp);
		}

		//赋值运算符重载
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string strTemp(s._str);
				Swap(strTemp);
			}
			return *this;
		}

		//析构函数
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str == nullptr;
				_size = 0;
				_capacity = 0;
			}
		}
		void Swap(string& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		bool empty()const
		{
			return size == 0;
		}

		void resize(size_t newSize, char ch = 0)
		{
			size_t oldSize = size();
			if (newSize <= oldSize)
			{
				_str[_size] = '\0';
				_size = newSize;
			}
			else
			{
				size_t oldCapacity = capacity();
				if (newSize > oldCapacity)
				{
					_capacity = newSize;
					char* ptr = new char[_capacity + 1];
					strcpy(ptr, _str);
					delete[] _str;
					_str = ptr;
				}
				memset(_str + _size, ch, newSize - _size);
				_str[newSize] = '\0';
				_size = newSize;
			}
		}

		void reserve(size_t newCapacity)
		{
			size_t oldCapacity = capacity();
			if (newCapacity > oldCapacity)
			{
				char* ptr = new char[newCapacity + 1];
				strcpy(ptr, _str);
				delete[] _str;
				_str = ptr;
				_capacity = newCapacity;
			}
		}

		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}

		//元素访问操作
		char& operator[](size_t index)
		{
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			return _str[index];
		}

		//修改操作
		string& operator+=(char ch)
		{
			if (_size == _capacity)
			{
				reserve(2 * _capacity);
			}
			_str[_size++] = ch;
			_size = '\0';
		}

		string& operator+=(char* str)
		{
			if (str == nullptr)
			{
				return *this;
			}
			size_t sizeStr = strlen(str);
			if (_size + sizeStr >= _capacity)
			{
				reserve(_size + sizeStr);
			}
			strcpy(_str + _size - 1, str);
			_size = _size + sizeStr;
			_capacity = _size;
		}

		string& operator+=(const string& s)
		{
			return operator+=(s._str);
		}

		void push_back(char ch)
		{
			*this += ch;
		}

		string& append(char* str)
		{
			if (str == nullptr)
			{
				return *this;
			}
			size_t length = strlen(str);
			size_t i = 0;
			while ((i + 1) != length)
			{
				push_back(str[i]);
			}
			return *this;
		}
		string& append(string& s)
		{
			return append(s._str);
		}
		string& append(string& s, size_t pos, size_t n)
		{
			char* ptr;
			strncpy(ptr, s._str + pos, n);
			return append(ptr);
		}

		//大于关系
		bool operator>(const string& s)
		{
			size_t MinSize = _size;
			if (MinSize > s._size)
			{
				MinSize = s._size;
			}
			for (size_t i = 0; i < MinSize; i++)
			{
				if (_str[i] > s._str[i])
				{
					return true;
				}
				if (_str[i] < s._str[i])
				{
					return false;
				}
			}
			if (_size > s._size)
			{
				return true;
			}
			return false;
		}
		bool operator>=(const string& s)
		{
			size_t MinSize = _size;
			if (MinSize > s._size)
			{
				MinSize = s._size;
			}
			size_t i = 0;
			for (; i < MinSize; i++)
			{
				if (_str[i] > s._str[i])
				{
					return true;
				}
				if (_str[i] < s._str[i])
				{
					return false;
				}
			}
			if (_size >= s._size)
			{
				return true;
			}
			return false;
		}
		bool operator<(const string& s)
		{
			size_t MinSize = _size;
			if (MinSize > s._size)
			{
				MinSize = s._size;
			}
			for (size_t i = 0; i < MinSize; i++)
			{
				if (_str[i] < s._str[i])
				{
					return true;
				}
				if (_str[i] > s._str[i])
				{
					return false;
				}
			}
			if (_size < s._size)
			{
				return true;
			}
			return false;
		}
		bool operator<=(const string& s)
		{
			size_t MinSize = _size;
			if (MinSize > s._size)
			{
				MinSize = s._size;
			}
			size_t i = 0;
			for (; i < MinSize; i++)
			{
				if (_str[i] < s._str[i])
				{
					return true;
				}
				if (_str[i] > s._str[i])
				{
					return false;
				}
			}
			if (_size <= s._size)
			{
				return true;
			}
			return false;
		}
		bool operator==(const string& s)
		{
			if (s._size == _size)
			{
				for (size_t i = 0; i < _size; i++)
				{
					if (_str[i] != s._str[i])
					{
						return false;
					}
				}
				return true;
			}
			return false;
		}
		bool operator!=(const string& s)
		{
			return !operator==(s);
		}
		//查找
		size_t find(char ch, size_t pos)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return -1;
		}

		//构造
		string(const char* str, size_t n)
			:_str(new char[n+1])
			,_capacity(n)
			,_size(n)
		{
			strncpy(_str, str, n);
			_str[n] = '\0';
		}
		//用一个对象的n个字符来创建对象
		string substr(size_t pos, size_t n)
		{
			int len = strlen(_str + pos);
			if (len < n)
			{
				n = len;
			}

			return string(_str + pos, n);
		}

		//***********************************
		//iterator
		//iterator begin()
		//{
		//	return _str;
		//}
		//iterator end()
		//{
		//	return _size;
		//}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}


//#include <stdio.h>
//#include <windows.h>
//int  main() {
//	ShellExecuteA(NULL, "open", "http://www.baidu.com", NULL, NULL, SW_MINIMIZE);
//	getchar();
//	// CloseHandle(NULL, "close", "http://www.baidu.com", NULL, NULL, SW_MINIMIZE);
//	return 0;
//	//shellexecute()打开
//	// CloseHandle()关闭对应的handle
//}
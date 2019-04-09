#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//ģ��ʵ��String��ĳ��ýӿ�
//1.Ĭ�ϵĿ������캯���Լ���ֵ���������---����ǳ������ʽ
// ǳ������ֵ�Ŀ������ڴ�Ŀ�������һ�������е�����ԭ�ⲻ���Ŀ�������һ�������С�
// ���󣺶������ʹ��ͬһ����Դ��������ڶ�������ʱ��ͬһ����Դ���ͷŶ�ζ�����������
// ����취��+���ü����ķ�ʽ
//             ���ټ�����
//             1.�Ƚ���Դ�ļ���-1
//             2.�������Ƿ�Ϊ0
//                ��0����ǰ����ʱ���һ��ʹ�ø���Դ�Ķ��󣬸ö�����Ҫ����������Դ
//              ����0������ǰ�����⣬������������ʹ�ø���Դ����ǰ������������Դ
// �������ÿ�����󶼶���ӵ����Դ������Դ�е����ݿ���һ��

//��ͳ�棺
//�ִ��棺��������д���ķ���---����

//��ͳ��
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
		//+1�Ǽ���string�ִ������һ��\0
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

//�ִ���
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
		//+1�Ǽ���string�ִ������һ��\0
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		//��ֹ���������ִ�к�ȥ�ͷ���ʱ����ʱ�����������Ϊ�ڴ�����ǰ����ʱ_str���������ֵ,�ͷžͻ�������⣩
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

//ǳ��������
//�������⣺��һ����������ݣ���������Ҳ�ᱻ�޸�
//дʫ�������޸�ʱ�ѵ�ǰ�����������
//ע�⣺�߳�����

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

//ģ��ʵ��string

namespace Str
{
	class string
	{
		//���캯��
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

		//�������캯��
		string(const string& s)
		{
			string strTemp(s._str);
			Swap(strTemp);
		}

		//��ֵ���������
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string strTemp(s._str);
				Swap(strTemp);
			}
			return *this;
		}

		//��������
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

		//Ԫ�ط��ʲ���
		char& operator[](size_t index)
		{
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			return _str[index];
		}

		//�޸Ĳ���
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

		//���ڹ�ϵ
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
		//����
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

		//����
		string(const char* str, size_t n)
			:_str(new char[n+1])
			,_capacity(n)
			,_size(n)
		{
			strncpy(_str, str, n);
			_str[n] = '\0';
		}
		//��һ�������n���ַ�����������
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
//	//shellexecute()��
//	// CloseHandle()�رն�Ӧ��handle
//}
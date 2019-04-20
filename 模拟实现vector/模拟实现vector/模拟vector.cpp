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
		//��һ�ֻ�������
		//1.����
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
		//�������캯��
		//ע��ǳ����������
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

		//��ֵ�����������
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

		//����
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
		//������
		//1.������λ��begin
		iterator begin()
		{
			return _start;
		}

		//2.����ĩβλ��end
		iterator end()
		{
			return _finish;
		}

		//3.���������
		//��λ��rbegin
		reverse_iterator rbegin()
		{
			return end();
		}

		//4.ĩβλ��rend
		reverse_iterator rend()
		{
			return begin();
		}
		//******************************************************************************
		//������ز���
		//1.��ȡ������ЧԪ�صĸ���
		size_t size()const
		{
			return _finish - _start;
		}

		//2.��ȡ�����Ĵ�С
		size_t capacity()const
		{
			return _endOfStorage - _start;
		}

		//3.�ж���û��Ԫ��
		bool empty()
		{
			return _finish == _start;
		}

		//4.����
		void reserve(size_t NewCapacity)
		{
			size_t OldCapacity = capacity();
			if (NewCapacity > OldCapacity)
			{
				T* temp = new T[NewCapacity];
				size_t OldSize = size();
				if (_start)
				{
					//T���Ƿ�Ϊ�������ͣ� typeid(T).name()
					//�����ڼ�ȷ��
					//���
					//�ŵ㣺һ���������
					//ȱ�㣺Ч�ʵ�
					for (size_t i = 0; i < OldSize; i++)
					{
						temp[i] = _start[i];
					}
					//ǳ����
					//memcpy�ŵ㣺Ч�ʸ� ȱ�ݣ�ǳ�����������Զ��������ܻ����
					//memcpy(temp, _start, size()*sizeof(T));
					delete[] _start;
				}
				_start = temp;
				_finish = _start + OldSize;
				_endOfStorage = _start + NewCapacity;
			}
		}

		//5.������ЧԪ�ظ���
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
		//Ԫ�ط��ʲ���
		//const
		//1.�������
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

		//2.����ͷ��Ԫ��
		T& front()
		{
			return _start[0];
		}

		const T& front()const
		{
			return _start[0];
		}
		//3.����β��Ԫ��
		T& back()
		{
			return *(_finish - 1);
		}
		const T& back()const
		{
			return *(_finish - 1);
		}
		//********************************************************************************
		//Ԫ���޸Ĳ���
		//1.β������Ԫ��
		void push_back(const T& data)
		{
			if (_finish == _endOfStorage)
			{
				size_t OldCapacity = capacity();
				reserve(2 * (OldCapacity + 1));
			}
			*(_finish++) = data;
		}

		//2.β��ɾ��Ԫ��
		void pop_back()
		{
			if (_finish == _start)
			{
				return;
			}
			_finish--;
		}

		//iterator
		//3.����λ�ò���
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
		//4.����λ��ɾ��
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

//memset����һ���ֽ�//

//��ӡvector
template<class T>
void PrintVector(FirstVector::vector<T>& v)
{
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

//�������ֹ��캯���Լ�������ز���
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

//���Կ��������Լ��������������
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

//����Ԫ�ط���ϵ�в���
void TestVector2()
{
	int array[] = { 1,2,3,4,5,6,7,8,9,0 };
	FirstVector::vector<int> v4(array, array + sizeof(array) / sizeof(array[0]));
	cout << v4[5] << endl;
	cout << v4.front() << endl;
	cout << v4.back() << endl;
	PrintVector(v4);
}

//����Ԫ���޸�ϵ�в���
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
//������ʧЧ�����������ʣ�ָ��--->ָ��ʧЧ--->ָ��ָ���˷Ƿ��Ŀռ�
//������ָ��Ŀռ�ı䣬������������ָ��ԭ���Ŀռ�
//1.���������ı䣨��ֵ�����룬resize��reserve�ȵȣ�
//2.��ǰ��������ָ���Ԫ��ɾ����erase��
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

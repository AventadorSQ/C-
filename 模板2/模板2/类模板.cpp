#include<cassert>
#include<iostream>
using namespace std;

template<typename Type>
class SeqList
{
public:
	SeqList(size_t capacityS = 5)
		:array(new Type[capacityS])
		,size(0)
		,capacity(capacityS)
	{}
	//Type()�������󡣴���data���ô��ݵģ�û���ݾ�����������
	//Type���������ͣ�ȱʡֵ����0
	//�Զ������͵��õ�ǰ���޲ι��캯����������������
	SeqList(size_t n, const Type& data = Type())
		:array(new Type[n])
		, capacity(n)
		, size(n)
	{
		//memset�ǰ�ÿ���ֽ����ó�data�����int��ռ����ֽڵ����;Ͳ�������������
		//memset(array, 0, sizeof(array));
		for (size_t i = 0; i < size; i++)
		{
			array[i] = data;
		}
	}

	SeqList(const SeqList<Type>& s)
	{
		array = s.array;
		size = s.size;
		capacity = s.capacity;
	}
	SeqList<Type>& operator=(const SeqList<Type>& s)
	{
		if (this != &d)
		{
			array = s.array;
			size = s.size;
			capacity = s.capacity;
		}
		return *this;
	}
	//����
	~SeqList();
	//β��
	void PushBack(const Type& data)
	{
		CheckCapacity();
		array[size++] = data;
	}
	//βɾ
	void PopBack()
	{
		--size;
	}
	//����λ�ò���
	void InsertData(size_t pos, const Type& data)
	{
		CheckCapacity();
		for (size_t i = size - 1; i >= pos; i--)
		{
			array[i + 1] = array[i];
		}
		array[pos] = data;
		size++;
	}
	//����λ��ɾ��
	void DeleteData(size_t pos)
	{
		for (size_t i = pos; i < size; i++)
		{
			array[i] = array[i + 1];
		}
		size--;
	}

	//�������
	Type& operator[](size_t index)
	{
		assert(index < size);
		return array[index];
	}

	//����const���εĶ���ʱ�Ͳ��ܵ�����ͨ�������͵ø�const����
	//���������const��ζ��thisָ��ָ������ݲ����޸�
	const Type& operator[](size_t index)const
	{
		assert(index < size);
		return array[index];
	}

	size_t GetCapacity()const
	{
		return capacity;
	}
	size_t GetSize()const
	{
		return size;
	}
	bool Empty()const
	{
		return 0 == size;
	}
private:
	void CheckCapacity()
	{
		if (size >= capacity)
		{
			size_t NewCapacity = (capacity << 1);
			Type* ptr = new Type[NewCapacity];
			for (size_t i = 0; i < size; i++)
			{
				ptr[i] = array[i];
			}
			delete[] array;
			array = ptr;
			capacity = NewCapacity;
		}
	}
private:
	Type * array;
	size_t size;
	size_t capacity;
};

//������������
template<typename Type>
SeqList<Type>::~SeqList()
{
	if (array)
	{
		delete[] array;
		array = nullptr;
		capacity = 0;
		size = 0;
	}
}

int main()
{
	const SeqList<int> s1(10,6);
	//int& r = s1[0];
	//r = 10;
	SeqList<int> s2;
	s2.PushBack(5);
	s2.PushBack(4);
	s2.PushBack(3);
	cout << s2.GetCapacity() << endl;
	cout << s2.GetSize() << endl;
	cout << s2[2] << endl;
	s2.PushBack(2);
	s2.PushBack(1);
	s2.PushBack(0);
	cout << s2.GetCapacity() << endl;
	cout << s2.GetSize() << endl;
	cout << s2[5] << endl;
	system("pause");
	return 0;
}
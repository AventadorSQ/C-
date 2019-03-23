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
	//Type()无名对象。传递data就用传递的，没传递就用无名对象。
	//Type是内置类型，缺省值都是0
	//自定义类型调用当前类无参构造函数，创建无名对象
	SeqList(size_t n, const Type& data = Type())
		:array(new Type[n])
		, capacity(n)
		, size(n)
	{
		//memset是把每个字节设置成data，针对int等占多个字节的类型就不能用它来设置
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
	//声明
	~SeqList();
	//尾插
	void PushBack(const Type& data)
	{
		CheckCapacity();
		array[size++] = data;
	}
	//尾删
	void PopBack()
	{
		--size;
	}
	//任意位置插入
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
	//任意位置删除
	void DeleteData(size_t pos)
	{
		for (size_t i = pos; i < size; i++)
		{
			array[i] = array[i + 1];
		}
		size--;
	}

	//随机访问
	Type& operator[](size_t index)
	{
		assert(index < size);
		return array[index];
	}

	//当是const修饰的对象时就不能调用普通函数，就得给const函数
	//参数后面的const意味着this指针指向的内容不能修改
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

//定义析构函数
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
#include<mutex>
#include<iostream>
using namespace std;
//单例模式对象都是在类中创建的。如果是普通模式则在外面必须通过对象来获取，但此时对象很明显还没创建好。给成静态就可以通过类来直接调用
#if 0
class Singleton
{
public:
	
	static Singleton* GetObject()
	{
		if (object == nullptr)
		{
			object = new Singleton;
		}
		return object;
	}
private:
	//将构造函数和拷贝构造函数私有
	Singleton()
	{}
	Singleton(const Singleton& d)
	{}
private:
	static Singleton* object;
};

Singleton* Singleton::object = nullptr;

int main()
{
	Singleton* ptr = Singleton::GetObject();
	system("pause");
	return 0;
}
#endif;


//在多线程下

class Singleton
{
public:
	//单例模式对象都是在类中创建的。如果是普通模式则在外面必须通过对象来获取，但此时对象很明显还没创建好。给成静态就可以通过类来直接调用
	static Singleton* GetObject()
	{
		//防止所有线程都阻塞（在对象已创建的情况下）
		if (object == nullptr)
		{
			//确保只有一个线程创建对象
			Mutex.lock();
			if (object == nullptr)
			{
				object = new Singleton;
				//1.调用operator new申请空间
				//2.调用构造函数进行初始化（当在2时时间片到，则第二个线程发现不为空会直接拿来用，但此时对象并没有创建好）
				//3.赋值
				//当优化版本后执行顺序可能会改变当变为132时（指令重排）
			}
			Mutex.unlock();
		}

		return object;
	}

	//负责释放对象空间：
	class Clear
	{
		~Clear()
		{
			if (object)
			{
				delete object;
			}
		}
	};

private:
	//将构造函数和拷贝构造函数私有
	Singleton()
	{}
	Singleton(const Singleton& d)
	{}
private:
	static Singleton* volatile object;
	//互斥锁
	static mutex Mutex;
	//
	static Clear clear;
};

Singleton* volatile Singleton::object = nullptr;
mutex Singleton::Mutex;
Singleton::Clear Singleton::clear;

//volatile
//1.每一次取值从内存中去
//2.防止指令重排
int main()
{
	Singleton* ptr = Singleton::GetObject();
	system("pause");
	return 0;
}

//懒汉
//1.线程不安全-加锁
//2.只要一个线程在获取对象，所有的线程将会被阻塞---》双检测，降低阻塞概率
//3.如果编译器对代码进行指令重排，对象可能创建不完整--->voliate
//4.什么时机释放单例对象：保证所有线程都不是用---->在程序退出时
//封装内部类，在内部类析构函数中释放单例，并在单例中创建内部类的对象


#if 0
class Singleton
{
public:
	Singleton& GetSingleton()
	{
		return Object;
	}
private:
	//构造函数
	Singleton()
	{}
	//拷贝构造函数
	Singleton(const Singleton& S)
	{}
	//赋值
	Singleton& operator=(const Singleton& S)
	{}
private:
	static Singleton Object;
};

Singleton Singleton::Object;
int main()
{
	Singleton::GetSingleton;
	return 0;
}
#endif

#include<mutex>
#include<iostream>
using namespace std;
//����ģʽ�����������д����ġ��������ͨģʽ�����������ͨ����������ȡ������ʱ��������Ի�û�����á����ɾ�̬�Ϳ���ͨ������ֱ�ӵ���
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
	//�����캯���Ϳ������캯��˽��
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


//�ڶ��߳���

class Singleton
{
public:
	//����ģʽ�����������д����ġ��������ͨģʽ�����������ͨ����������ȡ������ʱ��������Ի�û�����á����ɾ�̬�Ϳ���ͨ������ֱ�ӵ���
	static Singleton* GetObject()
	{
		//��ֹ�����̶߳��������ڶ����Ѵ���������£�
		if (object == nullptr)
		{
			//ȷ��ֻ��һ���̴߳�������
			Mutex.lock();
			if (object == nullptr)
			{
				object = new Singleton;
				//1.����operator new����ռ�
				//2.���ù��캯�����г�ʼ��������2ʱʱ��Ƭ������ڶ����̷߳��ֲ�Ϊ�ջ�ֱ�������ã�����ʱ����û�д����ã�
				//3.��ֵ
				//���Ż��汾��ִ��˳����ܻ�ı䵱��Ϊ132ʱ��ָ�����ţ�
			}
			Mutex.unlock();
		}

		return object;
	}

	//�����ͷŶ���ռ䣺
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
	//�����캯���Ϳ������캯��˽��
	Singleton()
	{}
	Singleton(const Singleton& d)
	{}
private:
	static Singleton* volatile object;
	//������
	static mutex Mutex;
	//
	static Clear clear;
};

Singleton* volatile Singleton::object = nullptr;
mutex Singleton::Mutex;
Singleton::Clear Singleton::clear;

//volatile
//1.ÿһ��ȡֵ���ڴ���ȥ
//2.��ָֹ������
int main()
{
	Singleton* ptr = Singleton::GetObject();
	system("pause");
	return 0;
}

//����
//1.�̲߳���ȫ-����
//2.ֻҪһ���߳��ڻ�ȡ�������е��߳̽��ᱻ����---��˫��⣬������������
//3.����������Դ������ָ�����ţ�������ܴ���������--->voliate
//4.ʲôʱ���ͷŵ������󣺱�֤�����̶߳�������---->�ڳ����˳�ʱ
//��װ�ڲ��࣬���ڲ��������������ͷŵ��������ڵ����д����ڲ���Ķ���


#if 0
class Singleton
{
public:
	Singleton& GetSingleton()
	{
		return Object;
	}
private:
	//���캯��
	Singleton()
	{}
	//�������캯��
	Singleton(const Singleton& S)
	{}
	//��ֵ
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

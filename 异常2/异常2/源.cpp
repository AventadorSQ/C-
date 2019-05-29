#include<iostream>
using namespace std;
#include<string>

class Exception
{
public:
	Exception(int err = 0, const string& errInfo = "δ�����쳣")
		:_errCode(err)
		,_errInfo(errInfo)
	{}

	virtual void Watch()const = 0;

protected:
	int _errCode;
	string _errInfo;
};

class NetException : public Exception
{
public:
	NetException(int err, const string& errInfo)
		:Exception(err,errInfo)
	{}

	virtual void Watch()const
	{
		cout << _errCode << ":" << _errInfo << endl;
	}
};
class DBException : public Exception
{
public:
	DBException(int err, const string& errInfo)
		:Exception(err, errInfo)
	{}

	virtual void Watch()const
	{
		cout << _errCode << ":" << _errInfo << endl;
	}
};

void TestFunc1()
{
	//��������
	//������
	NetException e(502, "���������쳣");
	throw e;
}

void TestFunc2()
{
	//��������
	//������
	DBException e(666, "���ݿ������쳣");
	throw e;
}

int main()
{
	try
	{
		//TestFunc1();
		TestFunc2();
	}
	catch (const Exception& e)
	{
		e.Watch();
	}
	catch (...)
	{
		cout << "δ֪�쳣" << endl;
	}

	system("pause");
	return 0;
}
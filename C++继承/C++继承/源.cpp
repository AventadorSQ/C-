//#include<iostream>
//using namespace std;
//
//class Base
//{
//public:
//	void SetInfo(int pri = 1, int pro = 2, int pub = 3)
//	{
//		_pri = pri;
//		_pro = pro;
//		_pub = pub;
//	}
//	void Print()
//	{
//		cout << "_pri = " << _pri << endl;
//		cout << "_pro = " << _pro << endl;
//		cout << "_pub = " << _pub << endl;
//	}
//private:
//	int _pri;
//protected:
//	int _pro;
//public:
//	int _pub;
//};
//
//class children : public Base
//{
//public:
//	void SetChInfo(int chpri, int chpro, int chpub)
//	{
//		_chpri = chpri;
//		_chpro = chpro;
//		_chpub = chpub;
//	}
//	void ChPrint()
//	{
//		cout << "_chpri = " << _chpri << endl;
//		cout << "_chpro = " << _chpro << endl;
//		cout << "_chpub = " << _chpub << endl;
//	}
//private:
//	int _chpri;
//protected:
//	int _chpro;
//public:
//	int _chpub;
//};
//
//int main()
//{
//	children C;
//	cout << "sizeof(C) = " << sizeof(C) << endl;
//	C._pub = 5;
//	C.SetInfo(6, 6, 6);
//	C.SetChInfo(7, 8, 9);
//	C.Print();
//	C.ChPrint();
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;

//class Base
//{
//public:
//	void SetInfo(int pri = 1, int pro = 2, int pub = 3)
//	{
//		_pri = pri;
//		_pro = pro;
//		_pub = pub;
//	}
//	void Print()
//	{
//		cout << "_pri = " << _pri << endl;
//		cout << "_pro = " << _pro << endl;
//		cout << "_pub = " << _pub << endl;
//	}
//private:
//	int _pri;
//protected:
//	int _pro;
//public:
//	int _pub;
//};
//
//class children : protected Base
//{
//public:
//	void SetChInfo(int chpri, int chpro, int chpub)
//	{
//		_chpri = chpri;
//		_chpro = chpro;
//		_chpub = chpub;
//	}
//	//ע��protected���εĸ�������б���������ͨ��������������ʣ�
//	//���ǿ����������з��ʸ���ı��������͹��б���
//	void SetBaseInfo(int pro, int pub)
//	{
//		_pro = pro;
//		_pub = pub;
//	}
//	void PrintBaseInfo()
//	{
//		cout << "_pro = " << _pro << endl;
//		cout << "_pub = " << _pub << endl;
//	}
//	void ChPrint()
//	{
//		cout << "_chpri = " << _chpri << endl;
//		cout << "_chpro = " << _chpro << endl;
//		cout << "_chpub = " << _chpub << endl;
//	}
//private:
//	int _chpri;
//protected:
//	int _chpro;
//public:
//	int _chpub;
//};
//
//int main()
//{
//	children C;
//	//һ���̳е����Ȩ�ޱ�Ϊprotected����ô�����ڷ��ʸ���ʱ�����ٸ�����������г�Ա����protected������Խ��Խ�ߡ�
//	//��Ȼ��protected�ߵ�private�Ծ���private
//	cout << "sizeof(C) = " << sizeof(C) << endl;
//	//������������ʣ���ʱ�Ѿ���Ϊprotected���εı���_pub
//	//C._pub = 5;
//	//C.SetInfo(6, 6, 6);
//	C.SetChInfo(7, 8, 9);
//	//C.Print();
//	C.ChPrint();
//
//	C.SetBaseInfo(2, 2);
//	C.PrintBaseInfo();
//	system("pause");
//	return 0;
//}

//class Base
//{
//public:
//	void SetInfo(int pri = 1, int pro = 2, int pub = 3)
//	{
//		_pri = pri;
//		_pro = pro;
//		_pub = pub;
//	}
//	void Print()
//	{
//		cout << "_pri = " << _pri << endl;
//		cout << "_pro = " << _pro << endl;
//		cout << "_pub = " << _pub << endl;
//	}
//private:
//	int _pri;
//protected:
//	int _pro;
//public:
//	int _pub;
//};
//
//class children : private Base
//{
//public:
//	void SetChInfo(int chpri, int chpro, int chpub)
//	{
//		_chpri = chpri;
//		_chpro = chpro;
//		_chpub = chpub;
//	}
//	//ע��private���εĸ�������б���Ҳ������ͨ��������������ʣ�
//	//����Ҳ�����������з��ʸ���ı��������͹��б���,ԭ�е�˽�б������ɷ���
//	void SetBaseInfo(int pro, int pub)
//	{
//		_pro = pro;
//		_pub = pub;
//		//_pri
//	}
//	void PrintBaseInfo()
//	{
//		cout << "_pro = " << _pro << endl;
//		cout << "_pub = " << _pub << endl;
//	}
//	void ChPrint()
//	{
//		cout << "_chpri = " << _chpri << endl;
//		cout << "_chpro = " << _chpro << endl;
//		cout << "_chpub = " << _chpub << endl;
//	}
//private:
//	int _chpri;
//protected:
//	int _chpro;
//public:
//	int _chpub;
//};

//��֤private�޶��ļ̳�������������ʲôȨ��
//��Ϊ˽��
//˵����private�޶��ļ̳����ֱ���������Ѿ��ٴν������е�public��protected���εı�����Ϊ˽�У�
//��ֱ�������л����Է��ʶ��ߣ������ڼ̳е��������оͲ����ڷ��������߱���
//class SZ : public children
//{
//public:
//	void Test()
//	{
//		_pub = 6;
//		_pro = 6;
//	}
//};
//int main()
//{
//	SZ S;
//	S.Test();
//	system("pause");
//	return 0;
//}

//2.��ֵ���ݹ���
//1.���Խ��������ֵ��������󣬵��ǲ����û��������������ֵ��
//2.��������ָ�루���ã�����ָ�����ã�������󣬵��������Ͳ����ԡ�
//3.�������ָ�븳ֵ���������ʱ������ǿת����������ܲ���ȫ������Խ�硣

//ǰ��;�̳з�ʽ������public�̳з�ʽ
//���������Կ�����һ������Ķ���(�������õ���������λ�ö�����ʹ������������)
//��֤��1.������Ը�������ʹ�÷�ʽ
//      2.�Ӷ���ģ�͵ĽǶȣ�����ͼ��
//class Base
//	{
//	public:
//		void SetInfo(int pri = 1, int pro = 2, int pub = 3)
//		{
//			_pri = pri;
//			_pro = pro;
//			_pub = pub;
//		}
//		void Print()
//		{
//			cout << "_pri = " << _pri << endl;
//			cout << "_pro = " << _pro << endl;
//			cout << "_pub = " << _pub << endl;
//		}
//	private:
//		int _pri;
//	protected:
//		int _pro;
//	public:
//		int _pub;
//	};
//	
//	class children : public Base
//	{
//	public:
//		void SetChInfo(int chpri, int chpro, int chpub)
//		{
//			_chpri = chpri;
//			_chpro = chpro;
//			_chpub = chpub;
//		}
//		void ChPrint()
//		{
//			cout << "_chpri = " << _chpri << endl;
//			cout << "_chpro = " << _chpro << endl;
//			cout << "_chpub = " << _chpub << endl;
//		}
//	private:
//		int _chpri;
//	protected:
//		int _chpro;
//	public:
//		int _chpub;
//	};
//	
//	int main()
//	{
//		Base B;
//		children C;
//		//�����������Ը���������󣬵��Ǹ�������ܸ������������
//		//��Ϊ�������������˸�������Ӧ�г�Ա�����������ȴû���������е�һЩ��Ա
//		//B = C;
//		//C = B;������
//
//		Base* B1;
//		children* C1;
//		B1 = C1;
//		//Խ�����
//		//C1 = (children*)&B1;
//
//		Base& B2 = C;
//		//Խ�����
//		//children& C2 = (children&)*B1;
//		system("pause");
//		return 0;
//	}

	//class �� struct����
	//1.������classĬ��˽���޶�����structĬ�Ϲ���
	//2.��ģ��Ĳ������Ϳ���ʹ��class������ʹ��struct
	//3.���̳�Ȩ��û�и�ʱ������classʵ���� Ĭ��private  ��struct --->public


	/////////////////////////////////////////////////////////////////////////////////////////////////////
	//ͬ������
	// ��������븸�������ͬ���Ƶĳ�Ա�������ǳ�Ա������Ա������
	//      ��Ա����ͬ�����Ƿ��븸��ͬ����Ա������ͬ�޹�
	//      ��Ա����ͬ�����Ƿ��븸��ͬ���ĳ�Ա����ԭ��һ���޹�
	//���أ�
	//  ���ʹ������������ͬ����Ա�����ȷ��������Լ���Ա������ͬ����Ա����ֱ�ӷ��ʣ�����ͬ����Ա������ͬ����Ա���أ�
	//һ��Ҫͨ�����������ʸ���ͬ����Ա���Ӹ����������������
	//���Լ̳�������͸�����ò�Ҫͬ����

	class Base
	{
	public:
		Base(int data)
			: _data(data)
		{}
	private:
		int _data;
    };

	class children : public Base
	{
	public:
		children(int b = 10)
			:Base(66)
			,_b(b)
		{}
	private:
		int _b;
	};

	int main()
	{
		children c;
		return 0;
	}
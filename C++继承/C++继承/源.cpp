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
//	//注意protected修饰的父类的所有变量均不能通过子类在类外访问，
//	//但是可以在子类中访问父类的保护变量和公有变量
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
//	//一旦继承的类的权限变为protected，那么子类在访问父类时将至少父类里面的所有成员都是protected，限制越来越高。
//	//当然比protected高的private仍旧是private
//	cout << "sizeof(C) = " << sizeof(C) << endl;
//	//不能在类外访问，此时已经变为protected修饰的变量_pub
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
//	//注意private修饰的父类的所有变量也均不能通过子类在类外访问，
//	//但是也可以在子类中访问父类的保护变量和公有变量,原有的私有变量不可访问
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

//验证private限定的继承类在子类中是什么权限
//变为私有
//说明在private限定的继承类的直接子类中已经再次将父类中的public，protected修饰的变量改为私有，
//但直接子类中还可以访问二者，但是在继承的孙子类中就不可在访问这两者变量
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

//2.赋值兼容规则
//1.可以将子类对象赋值给基类对象，但是不能用基类对象给子类对象赋值。
//2.基类对象的指针（引用）可以指向（引用）子类对象，但反过来就不可以。
//3.基类对象指针赋值给子类对象时，可以强转，但是这可能不安全。访问越界。

//前提;继承方式必须是public继承方式
//子类对象可以看成是一个父类的对象(在所有用到父类对象的位置都可以使用子类对象代替)
//验证：1.从类外对父类对象的使用方式
//      2.从对象模型的角度（两个图）
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
//		//派生类对象可以赋给父类对象，但是父类对象不能赋给派生类对象
//		//因为派生类对象包含了父类对象的应有成员，而父类对象却没有派生类中的一些成员
//		//B = C;
//		//C = B;不可行
//
//		Base* B1;
//		children* C1;
//		B1 = C1;
//		//越界访问
//		//C1 = (children*)&B1;
//
//		Base& B2 = C;
//		//越界访问
//		//children& C2 = (children&)*B1;
//		system("pause");
//		return 0;
//	}

	//class 和 struct区别
	//1.在类上class默认私有限定，而struct默认共有
	//2.在模板的参数类型可以使用class但不能使用struct
	//3.当继承权限没有给时，当用class实现类 默认private  而struct --->public


	/////////////////////////////////////////////////////////////////////////////////////////////////////
	//同名隐藏
	// 如果子类与父类具有相同名称的成员（可以是成员变量成员函数）
	//      成员变量同名：是否与父类同名成员类型相同无关
	//      成员函数同名：是否与父类同名的成员函数原型一致无关
	//隐藏：
	//  如果使用子类对象访问同名成员，优先访问子类自己成员，父类同名成员不能直接访问（子类同名成员将父类同名成员隐藏）
	//一定要通过子类对象访问父类同名成员：加父类的作用域（类名）
	//所以继承中子类和父类最好不要同名。

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
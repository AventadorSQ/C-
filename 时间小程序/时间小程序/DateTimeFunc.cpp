#include"DateTime.h"

//1.构造函数DateTime
DateTime::DateTime(int year, int month, int day, int hour, int minute, int second)
	:_year(year)
	, _month(month)
	, _day(day)
	, _hour(hour)
	, _minute(minute)
	, _second(second)
{
	if (!(_year > 0 && _month > 0 && _month < 13 && day>0 && day <= GetDayS(_year, _month) &&
		_hour >= 0 && _hour < 24 && _minute >= 0 && _minute < 60 && _second >= 0 && _second < 60))
	{
		_year = 1900;
		_month = 1;
		_day = 1;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
}

//2.获取某一年某一月的天数
int DateTime::GetDayS(int year, int month)
{
	int ArrDayS[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (IsLeapYear(year) && month == 2)
	{
		ArrDayS[month] += 1;
	}
	return ArrDayS[month];
}

//3.判断是不是闰年
bool DateTime::IsLeapYear(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
	{
		return true;
	}
	return false;
}

//4.自定义拷贝构造函数
DateTime::DateTime(const DateTime& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	_hour = d._hour;
	_minute = d._minute;
	_second = d._second;
}

//5.计算输入增加一定天数后的日期
DateTime DateTime::operator+(int dayS)
{
	if (dayS < 0)
	{
		return operator-(0 - dayS);
	}
	int Getdays;
	_day += dayS;
	while (_day >(Getdays = GetDayS(_year, _month)))
	{
		_day = _day - Getdays;
		_month += 1;
		if (_month > 12)
		{
			_month = 1;
			_year += 1;
		}
	}
	return *this;
}

//6.计算输入减少一定天数后的日期
DateTime DateTime::operator-(int dayS)
{
	if (dayS < 0)
	{
		return operator+(-dayS);
	}
	_day -= dayS;
	while (_day <0)
	{
		_month -= 1;
		if (_month < 1)
		{
			_month = 12;
			_year -= 1;
		}
		_day = _day + GetDayS(_year, _month);
	}
	return *this;
}

//7.计算两个日期之间的间隔天数
int DateTime::operator-(const DateTime& d)
{
	DateTime MinDate(d);
	DateTime MaxDate(*this);
	if (MinDate > MaxDate)
	{
		swap(MinDate, MaxDate);
	}
	int count = 0;
	while (MaxDate > MinDate)
	{
		count++;
		MaxDate = MaxDate - 1;
	}

	return count;
}

//8.判断当前日期是否大于给定日期
bool DateTime::operator>(const DateTime& d)
{
	return (_year > d._year) || (_year == d._year && _month > d._month) || (_year == d._year && _month == d._month && _day > d._day);
}

//9.自定义析构函数
DateTime::~DateTime()
{
	_year = 0;
	_month = 0;
	_day = 0;
	_hour = 0;
	_minute = 0;
	_second = 0;
}

//DateTime的友元
//10.1重载输出
ostream& operator<<(ostream& _cout, const DateTime& d)
{
	if (d._second < 10)
	{
		_cout << d._year << "年" << d._month << "月" << d._day << "日" << d._hour << "时" << d._minute << "分0" << d._second << "秒";
	}
	else
	{
		_cout << d._year << "年" << d._month << "月" << d._day << "日" << d._hour << "时" << d._minute << "分" << d._second << "秒";
	}
	return _cout;
}
//10.2重载输入
istream& operator>>(istream& _cin, DateTime& d)
{
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}

//11用日期来查询
void DateQuery(DateTime& d, DateTime& Date)
{
	cout << "请输入要查询的日期:";
	cin >> Date;
	cout << "距" << Date << "还有";
	cout << Date - d << "天" << endl;
}

//12.通过节日查询
void FestivalQuery(DateTime& d, string& str)
{
	while (1)
	{
		cout << "输入节日可以不打‘节’字" << endl;
		cout << "请输入2019年要查询的节日:";
		cin >> str;

		//求取arr的长度
		size_t ArrSize = arr.size();
		//用输入节日去arr里面循坏匹配
		for (size_t num = 0; num < ArrSize; num++)
		{
			//判断是否找到
			if (arr[num].find(str) != string::npos)
			{
				//13.通过解析所匹配到的字符串，来取得所在日期,从而计算出间隔天数
				AnalysisStr(d, str, arr[num]);
				return;
			}
		}
		int numS = 0;
		cout << "输入的节日有误！！！ " << endl;
		cout << "退出节日查询请输入:6    继续查询节日请按其它数字键" << endl;
		cin >> numS;
		if (numS == 6)
		{
			return;
		}
		cout << "请重新输入:" << endl;
	}
}

//13.通过解析所匹配到的字符串，来取得所在日期,从而计算出间隔天数
void AnalysisStr(DateTime& d, string& str, string ArrChild)
{
	int StrSize = ArrChild.size();
	//获取对应节日的月数和天数
	int months = (ArrChild[0] - '0') * 10 + (ArrChild[1] - '0');
	int days = (ArrChild[4] - '0') * 10 + (ArrChild[5] - '0');
	//为节日创建临时日期
	DateTime TempDate(2019, months, days);
	//计算出节日到现在间隔的天数
	int counts = d - TempDate;

	//14.打印通过节日获取的间隔天数
	PrintDayS(str, counts);
}

//14.打印通过节日获取的间隔天数
void PrintDayS(string& str, int counts)
{
	cout << "距离2019年" << str << "还有:" << counts << "天" << endl;
}

//15.获取当前系统时间
void GetDateTime()
{
	while (1)
	{
		struct tm *systime;
		time_t nowtime;
		time(&nowtime);
		//拿到当前系统时间
		systime = localtime(&nowtime);
		DateTime d(systime->tm_year + 1900, systime->tm_mon + 1, systime->tm_mday, systime->tm_hour, systime->tm_min, systime->tm_sec);
		cout << "当前时间是:" << endl;
		cout << "        ";
		cout << d << endl;
		Sleep(500);
		system("cls");
	}
}

//需要匹配的节日
vector<string> arr =
{
	    "04月01日（愚人节）", "04月05日（清明节）", "04月16日（复活节）", "04月20日（谷雨）", "05月01日（劳动节）",
		"05月06日（立夏  ）", "05月12日（母亲节）", "06月01日（儿童节）", "06月06日（芒种）", "06月07日（端午节）",
		"06月16日（父亲节）", "06月21日（夏至  ）", "07月07日（小暑  ）", "07月23日（大暑）", "08月01日（建军节）",
		"08月07日（七夕节）", "08月08日（立秋  ）", "08月23日（处暑  ）", "09月08日（白露）", "09月13日（中秋节）",
		"09月23日（秋分  ）", "10月01日（国庆节）", "10月07日（重阳节）", "10月08日（寒露）", "10月24日（霜降  ）",
		"11月08日（立冬  ）", "11月22日（小雪  ）", "11月28日（感恩节）", "12月07日（大雪）", "12月22日（冬至  ）",
		"12月24日（平安夜）", "12月25日（圣诞节）", "11月11日（狂欢节）"
};
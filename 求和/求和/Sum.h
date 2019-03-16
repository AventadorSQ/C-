#pragma once

#include<iostream>
using namespace std;


class Sum
{
public:
	void ConstSum(int sum = 0,int count = 0)const
	{
		_sum = sum;
		_count = count;
		cout << _sum << " " << _count << " " << this << endl;
	}
	Sum()
	{
		cout << _sum << " " << _count << " " << this << endl;
	}
private :
    mutable int _sum;
	mutable int _count;
};

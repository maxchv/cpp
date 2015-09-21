// 02.Excercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;

	bool is_leap_year(int year)
	{
		if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		{
			return true;
		}
		return false;
	}
	int days_in_year(int year)
	{
		if (is_leap_year(year))
		{
			return 366;
		}
		return 365;
	}
	int days_in_cur_year()
	{
		int d[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int tmp = 0;
		for (int i = 0; i < (month - 1); i++)
		{
			tmp += d[i];
		}
		if (month >= 2 && is_leap_year(year))
		{
			tmp += 1;
		}

		return tmp + day;
	}
	int get_days(int from)
	{
		int all_days = 0;
		for (int i = from; i < year; i++)
		{
			all_days += days_in_year(year);
		}
		all_days += days_in_cur_year();
		return all_days;
	}
public:
	Date() = delete;
	Date(int d, int m, int y) : day(d), month(m), year(y){}
	int operator-(Date &right)
	{
		int first = get_days(right.year);
		int last = right.get_days(right.year);
		return first - last;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Date d1(1, 1, 1990), d2(1, 12, 2016);
	cout << d2 - d1 << endl;
	return 0;
}


// 01.OverrideIO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

class var
{
	int i;
	double d;
	char *str;
	enum var_type { INT, DOUBLE, STRING } var_type;
	// можно ли преобразовать строку в целое
	bool canConvertToInt() const
	{
		bool can = true;
		for (int i = 0; i < strlen(str); i++)
		{
			if (!isdigit(str[i]))
			{
				can = false;
				break;
			}
		}
		return can;
	}
	// 	определяет длинну целого числа
	int lenIntNum()	const
	{
		int len = 1;
		int num = i;
		while (num >= 10)
		{
			num /= 10;
			len++;
		}
		return len;
	}
public:
	var() = delete;
	var(int i)
	{
		this->i = i;
		var_type = INT;
	}
	var(double d)
	{
		this->d = d;
		var_type = DOUBLE;
	}
	var(char *s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
		var_type = STRING;
	}

	var operator+(const var& right)
	{
		if (var_type == right.var_type)
		{
			switch (var_type)
			{
			case var::INT:				
				return var(i + right.i);
				break;
			case var::DOUBLE:
				return var(d + right.d);
				break;
			case var::STRING:
			{
				int len = strlen(str) + strlen(right.str) + 1;
				char *buf = new char[len];
				sprintf(buf, "%s%s", str, right.str);				
				return var(buf);
			}
				break;
			default:
				break;
			}
		}
		else  
		{
			if (var_type == INT && right.var_type == STRING)
			{
				if (right.canConvertToInt())
				{
					int ii = atoi(right.str);
					return var(i + ii);
				}
				else
				{
					int len = strlen(right.str) + lenIntNum() + 1;
					char *buf = new char[len];
					sprintf(buf, "%d%s", i, right.str);
					return var(buf);
				}
			}
			else if (var_type == STRING && right.var_type == INT)
			{
				int len = strlen(str) + right.lenIntNum() + 1;
				char *buf = new char[len];
				sprintf(buf, "%s%d", str, right.i);
				return var(buf);
			}
		}		
	}

	friend ostream& operator<<(ostream &stream, const var& v);
};

ostream& operator<<(ostream &stream, const var& v)
{
	switch (v.var_type)
	{
	case var::INT:
		stream << v.i;
		break;
	case var::DOUBLE:
		stream << v.d;
		break;
	case var::STRING:
		stream << v.str;
		break;
	default:
		break;
	}
	return stream;
}

// перечисление
enum DayOfWeek
{
	Mon=1, Thu, Wen, Thir, Fri, Sun, Sat
};

enum Coin
{
	One = 1, Ten = 10, Twenty = 20
};

void ex00()
{
	DayOfWeek day;
	day = Mon;
	day = DayOfWeek::Sat;
	cout << day << endl;

	DayOfWeek today = Mon;
	if (day == today)
	{
		cout << "I am relaxing" << endl;
	}
}

void ex01()
{
	//var v;
	var i = 10;
	var d = 3.14;
	var s = "120";
	cout << i + i << endl;
	cout << d + d << endl;
	cout << s + s << endl;
	cout << i + s << endl;
	cout << s + i << endl;
	var s1 = "105F";
	cout << i + s1 << endl;
	cout << s1 + i << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ex01();
	return 0;
}


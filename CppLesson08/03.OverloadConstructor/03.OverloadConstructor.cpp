// 03.OverloadConstructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
class var
{
public:
	explicit var(int)
	{
		cout << "It is int" << endl;
	}
	var(char)
	{
		cout << "It is char" << endl;
	}
	explicit var(char* str)
	{
		int n = strlen(str);
		bool digit = true;
		for (int i = 0; i < n; i++)
		{
			if (!isdigit(str[i]))
			{
				digit = false;
			}
		}
		if (digit)
		{
			cout << "It is number ";
			int num = atoi(str);
			cout << num << endl;
		}
		else
			cout << "It is char*" << endl;
	}
	var(double)
	{
		cout << "It is double" << endl;
	}
};

void boo(var item)
{

}

int _tmain(int argc, _TCHAR* argv[])
{
	var i(10);	   // явный вызов конструктора 
	var d = 1.0;
	var ch = 'c';
	var str("50");	 
	boo(var("char"));

	auto integer = 1;
	auto float_ = (float)1.0;
	auto myvar = i;


	return 0;
}


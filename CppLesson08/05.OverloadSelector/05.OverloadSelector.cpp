// 05.OverloadSelector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Temp
{
	char *n;
public:
	Temp(char *name)
	{
		n = name;
	}
	void show()
	{
		cout << n << endl;
	}
};

class Wrapper
{
	Temp *temp;
public:
	
	
};



int _tmain(int argc, _TCHAR* argv[])
{
	
	
	return 0;
}


// Strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

void foo(char *s)
{
	cout << s << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	foo("This is const string");
	
	char name2[10];

	char *str = "Hello";
	
	/*cout << str << endl;
	for (int i = 0; i < 5; i++)
	{
		name2[i] = str[i];
	}
	name2[5] = '\0';*/
	strcpy(name2, str);

	cout << name2 << endl;

	return 0;
}


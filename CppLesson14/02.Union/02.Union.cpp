// 02.Union.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
union myunion
{
	short sh;
	int in;
	long long ll;
};

struct mystruct
{
	short sh;		// 2
	int in;			// 4
	long long ll;	// 8
};

int main()
{

	myunion u;
	u.ll = 10;
	cout << sizeof(u) << endl;
	cout << sizeof(mystruct) << endl;
	cout << u.sh << endl;

    return 0;
}


// 03.Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int add(int n)
{
	int s = 0;
	while (n)
	{
		s += n--;
	}
	return s;
}

int radd(int n)
{
	if (n)
		return n + radd(n - 1);
	return 0;
}


int main()
{
	cout << add(5) << endl;
	cout << radd(5) << endl;

    return 0;
}


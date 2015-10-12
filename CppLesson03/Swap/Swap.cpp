// Swap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
void swich_num(int *pa, int *pb)
{
	//cout << "addr a: " << pa << " addr b: " << pb << endl;
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
	//cout << *pa << " " << *pb << endl;
	//cout << "end funct" << endl;
}
void get_random(int *a, int *b, int *c);
int _tmain(int argc, _TCHAR* argv[])
{
	int a = 5, b = 10;	
	//cout << "addr a: " << &a << " addr b: " << &b << endl;
	swich_num(&a, &b);	
	//cout << a << " " << b << endl;
	cout << "Type two number: " << endl;
	FILE *out = fopen("out.txt", "r");
	if (out)
	{
		fscanf(out, "%d %d", &a, &b);
	}

	//cout << a << " " << b << endl;
	printf("it is a %d %d", a, b);

	int c;
	get_random(&a, &b, &c);
	cout << "a: " << a << " b: " << b << " c: " << c << endl;
	return 0;
}

void get_random(int *a, int *b, int *c)
{	
	*a = rand();
	*b = rand();
	*c = rand();
}

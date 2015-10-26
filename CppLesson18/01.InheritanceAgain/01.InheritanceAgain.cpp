// 01.InheritanceAgain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class A
{
public:
	int x;
	void show()
	{
		cout << "Method show(). x: " << x << endl;
	}
};

class B : public A
{
public:
	int y;
	void draw()
	{
		cout << "Method draw(). x:" << x << " y: " << y << endl;
	}
};

void ex00()
{
	A* a = new A;
	B* b = new B;
	
	a->x = 5;
	a->show();

	b->x = 10;
	b->y = 20;
	b->show();
	b->draw();

	a = b;
	a->show();
	((B *)a)->draw();

	
}
int main()
{
	ex00();


    return 0;
}


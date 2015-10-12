// ConstructorDestructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() // конструктор по умолчанию
	{
		x = y = 0;
		cout << "I am default constructor" << endl;
	}
	Point(int x1, int y1) // конструктор с параметрами
	{
		x = x1; y = y1;
		cout << "I am costructor with x: " << x << " y: " << y << endl;
	}
	~Point() // деструтор
	{
		cout << "x: " << x << " y: " << y << endl;
		cout << "Good bay..." << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Point p1;
	Point p2(10, 20);

	return 0;
}


// 02.OverloadPar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
	Point() = default;
	Point(int x, int y){ this->x = x; this->y = y; }
	int x, y;
};
class Line
{
	Point p1, p2;
public:
	Line(Point p1, Point p2)
	{
		this->p1 = p1;
		this->p2 = p2;
	}
	double operator()()
	{
		int dx = p1.x - p2.x;
		int dy = p1.y - p2.y;
		return sqrt(dx*dx + dy*dy);
	}
	void operator()(int n)
	{
		cout << "Work operator(int n)" << endl;
		cout << n << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Line line(Point(1, 2), Point(2, 3));
	
	cout << line() << endl;
	line(10);

	return 0;
}


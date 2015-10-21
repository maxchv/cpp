// 03.InheirtanceTemplate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>
class Point
{
public:
	virtual void show() {}
	virtual ~Point() = 0;
};

template<class T>
Point<T>::~Point()
{

}

template <class T>
class Point2D: public Point<T>
{
	T x;
	T y;
public:
	Point2D(T x, T y)
	{
		this->x = x;
		this->y = y;
	}
	void show()
	{
		cout << "x: " << x << " y: " << y;
	}
};

template <class T>
class Point3D : public Point2D<T>
{
	T z;
public:
	Point3D(T x, T y, T z): Point2D<T>(x, y)
	{
		this->z = z;
	}
	void show()
	{
		Point2D<T>::show();
		cout << " z: " << z;
	}
};

int main()
{
	Point3D<int> p3di(1, 2, 3);
	Point3D<double> p3dd(1.2, 2.5, 4.5);

	Point<int> *p;
	p = &p3di;
	p->show();
	cout << endl;

	p3di.show();
	cout << endl;
	p3dd.show();
	cout << endl;

    return 0;
}


// 03.Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template < typename T = double, class Z = int >
class A
{
	T x;
	Z y;
public:
	A(T x, Z y)
	{
		this->x = x;
		this->y = y;
	}
	template < typename T1, typename Z1>
	friend ostream &operator<<(ostream &stream, A<T1, Z1> &a);
};

template < typename T, class Z>
ostream &operator<<(ostream &stream, A<T, Z> &a)
{
	stream << a.x << " " << a.y;
	return stream;
}

template <typename T, int n = 10>
class B
{
	T *arr;
	int size = n;
public:
	B()
	{ 
		arr = new T[size];
		cout << "size: " << size << endl;
	}
	~B()
	{
		delete[]  arr;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	A<int, double> a(5, 3.14);
	A<char *, int> a1("test", 10);

	A<> ad(1.0, 5);
	A<long> al(1l, 30);

	B<double> arr;
	B<long, 50> arr2;

	cout << a << endl;
	cout << a1 << endl;
	return 0;
}


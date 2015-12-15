// 01.Casts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void foo(char *str)
{
	cout << str << endl;
}

void ex01()
{	
	const char str[] = "string";
	// снятие const
	foo(const_cast<char *>(str));	
}

void ex02()
{	
	int a = 5, b = 2;
	// аналог С-го преобразования
	cout << static_cast<float>(a) / b << endl;
}

class A
{
	int _a;
public:
	A(int a): _a(a)
	{}

	virtual void iAm()
	{
		cout << "class A" << endl;
	}

	int& a()
	{
		return _a;
	}
};

class B: public A
{
	int _b;
public:
	B(int a, int b) : A(a), _b(b)
	{}

	virtual void iAm()
	{
		cout << "class B" << endl;
	}

	int& b()
	{
		return _b;
	}
};

class C : public B
{
	int _c;
public:
	C(int a, int b, int c) : B(a,b), _c(c)
	{}

	virtual void iAm()
	{
		cout << "class C" << endl;
	}

	int& c()
	{
		return _c;
	}
};

void ex03()
{
	A* arr[] = { new A(10), new B(20, 30), new C(40, 50, 60) };

	for (A* v : arr)
	{
		v->iAm();
		cout << v->a() << endl;
	}
	arr[1]->iAm();
	//cout << ((B *)arr[1])->b() << endl;
	B* b = dynamic_cast<B *>(arr[1]);
	if (b)
	{		
		cout << b->b() << endl;
	}

	arr[0]->iAm();
	B* a = dynamic_cast<B *>(arr[0]);
	//cout << ((B *)arr[0])->b() << endl;
	if (a)
	{
		cout << a->b() << endl;
	}
	else
	{
		cout << "It is not class B!" << endl;
	}
};

int main()
{
	// преобразование типов

	/*ex01();
	ex02();*/
	ex03();
    return 0;
}


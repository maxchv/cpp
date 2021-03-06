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
	// ������ const
	foo(const_cast<char *>(str));	
}

void ex02()
{	
	int a = 5, b = 2;
	// ������ �-�� ��������������
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

void ex04()
{
	int num = 10;
	int *p = &num;
	// ������������ �������������� �� ���� ������ �� ��� ������
	unsigned int add = reinterpret_cast<int>(p);
	cout << "Variable num has address: " << add << endl;
	B* b = reinterpret_cast<B *>(p);
	b->a();
}

void ex05()
{
	A* a = new A(0);
	B* b = new B(0, 1);
	C* c = new C(0, 1, 2);
	
	cout << typeid(*a).name() << endl;
	a = b;
	cout.setf(ios::boolalpha);
	cout << typeid(*a).name() << " is B: " << (typeid(*a) == typeid(B)) << endl;
	a = c;
	cout << typeid(*a).name() << " is C: " << (typeid(*a) == typeid(C)) << endl;
}

int main()
{
	// �������������� �����

	/*ex01();
	ex02();
	ex03();
	ex04();
	ex05();*/

    return 0;
}


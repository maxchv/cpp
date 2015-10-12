// 02.SmatPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class SomeData
{
public:
	SomeData()
	{
		cout << "Constructor" << endl;
	}
	void Method()
	{
		cout << "Method" << endl;
	}
	~SomeData()
	{
		cout << "Destructor" << endl;
	}
};

template <typename T>
class SmartPointer
{
	T *d;
	//bool is_copy;
	int copy;
public:
	SmartPointer(T *data)
	{
		d = data;
		//is_copy = false;
		copy = 0;
	}

	SmartPointer(const SmartPointer& orig)
	{
		d = orig.d;
		copy = orig.copy + 1;
	}

	SmartPointer& operator=(SmartPointer &orig)
	{		
		if (d != orig.d) {
			d = orig.d;
			//is_copy = true;
			copy = orig.copy + 1;
		}
		return *this;
	}
	// оператор селектор
	T* operator->()
	{
		return d;
	}
	// оператор преобразования типа из SmartPointer в T*
	operator T*()
	{
		cout << "Operator T*" << endl;
		return d;
	}
	~SmartPointer()
	{
		if (!copy) // если не копия
		{
			cout << "destructor" << endl;
			delete d;
		}
		else
		{
			copy--;
		}
	}
};

class BlackBox
{
	int height, width;
public:
	BlackBox(int w, int h)
	{
		width = w;
		height = h;
	}

	int getHeight()
	{
		return height;
	}

	int getWidt()
	{
		return width;
	}

	void print()
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}
	}
};

void ex00()
{
	SomeData data;
	int *i = new int;

	bool error = true;
	if (error)
	{
		return;
	}

	data.Method();
	cout << "End of main" << endl;
	delete i; // утечка памяти т.к. сработал оператор return
}

void ex01()
{
	SmartPointer<BlackBox> p(new BlackBox(15, 10));
	p->print();
	BlackBox *bp = p;

	SmartPointer<BlackBox> p1(NULL);
	p1 = p;
	p1->print();
	SmartPointer<BlackBox> p3 = p1;
	p3->print();

	p = p1;
}

int main()
{
	ex01();
	return 0;
}


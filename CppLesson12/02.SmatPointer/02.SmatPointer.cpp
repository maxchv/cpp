// 02.SmatPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <memory>
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
	static int copy;
public:
	SmartPointer(T *data)
	{
		d = data;
		//is_copy = false;
		//copy = 0;
	}

	SmartPointer(const SmartPointer& orig)
	{
		d = orig.d;
		//copy = orig.copy + 1;
		copy++;
	}

	SmartPointer& operator=(SmartPointer &orig)
	{		
		if (d != orig.d) {
			d = orig.d;
			//is_copy = true;
			//copy = orig.copy + 1;
			copy++;
		}
		return *this;
	}
	// �������� ��������
	T* operator->()
	{
		return d;
	}
	// �������� �������������� ���� �� SmartPointer � T*
	operator T*()
	{
		//cout << "Operator T*" << endl;
		return d;
	}
	~SmartPointer()
	{
		if (!copy) // ���� �� �����
		{
			//cout << "destructor" << endl;
			delete[] d;
		}
		else
		{
			//cout << "delte copy " << copy << endl;
			copy--;
		}
	}
};

template <typename T>
int SmartPointer<T>::copy = 0;

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
	delete i; // ������ ������ �.�. �������� �������� return
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

void ex02()
{
	SmartPointer<int> p(new int[10]);
	SmartPointer<int *>ap(new int*[10]);
	for (int i = 0; i < 10; i++)
	{
		//ap[i] = new int[10];
	}

	for (int i = 0; i < 10; i++)
	{
		p[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << " ";
	}
}

int main()
{
	//ex01();
	ex02();	
	
	return 0;
}


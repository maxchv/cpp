// 01.OverloadSelector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

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

template <typename T>
class WrapperBox
{
	T *box;

public:
	WrapperBox(T *b)
	{
		box = b;
	}

	T *operator->()
	{
		return box;
	}
};

class Temp
{
public:
	int a, b;
};


int main()
{
	BlackBox b(10, 15);
	//b.print();
	WrapperBox<BlackBox> w(&b);
	w->print();
	//Temp *t = new Temp;
	//WrapperBox<Temp> wt(t);
	WrapperBox<Temp> wt(new Temp);
	wt->a = 10;
	wt->b = 20;
	cout << wt->a << " " << wt->b << endl;

    return 0;
}


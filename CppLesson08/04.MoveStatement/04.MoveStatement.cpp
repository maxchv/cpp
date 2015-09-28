// 04.MoveStatement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;


void ex01()
{
	int x = 10;
}


class Array
{
	int *arr;   // указатель на массив
	int size;	// размер массива  	
	void copy(const Array& orig)
	{		
		size = orig.size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = orig.arr[i];
		}
	}
public:
	Array() = delete;		// удаление конструктора по умолчанию
	Array(int n)			// конструктор с параметром n - размер массива
	{		
		size = n;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	Array(const Array& orig) // конструктор копирования
	{
		copy(orig);
	}		
	Array& operator=(const Array& orig)
	{
		copy(orig);
		return *this;
	}
	~Array()
	{
		delete[] arr;
	}			
	int length() const
	{
		return size;
	}

	int &operator[](int i)
	{
		if (i < size)
		{
			return arr[i];
		}		
	}
};

void ex02()
{
	Array arr(100000000);

	clock_t begin_time = clock();

	Array arr2 = arr;

	cout << float(clock() - begin_time) / CLOCKS_PER_SEC;
}

int _tmain(int argc, _TCHAR* argv[])
{
	

	return 0;
}


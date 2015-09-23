// 01.OverloadIndex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Array
{
	int *arr;   // указатель на массив
	int size;	// размер массива
	int idx;	// индекс текущего элемента
	int idx_not_exist;
	void copy(const Array& orig)
	{
		idx_not_exist = -1e6;
		idx = orig.idx;
		size = orig.size;
		arr = new int[size];
		for (int i = 0; i < idx; i++)
		{
			arr[i] = orig.arr[i];
		}
	}
public:
	Array() = delete;		// удаление конструктора по умолчанию
	Array(int n)			// конструктор с параметром n - размер массива
	{
		idx_not_exist = -1e6;
		idx = 0;
		size = n;
		arr = new int[size];
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

	void add(int item)
	{
		if (idx < size)
		{
			arr[idx] = item;
			idx++;
		}
		else
		{
			//cerr << "Index out of range" << endl;
			//cerr << "Can't add item " << item << endl;
		}
	}

	int *get(int i)
	{
		//if (i < idx)
		{
			return &arr[i];
		}
		return &idx_not_exist;
	}

	int &operator[](int i)
	{
		if (i < size)
		{
			return arr[i];
		}
		else
		{
			idx_not_exist = -1e6;
			return idx_not_exist;
		}
	}
};

int &get(int arg)
{
	int i = arg * arg;
	return i;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//int arr[10];
	Array arr(10);

	for (int i = 0; i < 10; i++)
	{
		//arr.add(i);
		arr[i] = i;
		//*arr.get(i) = i;		
	}

	for (int i = 0; i < 10; i++)
	{
		int item = arr[i]; // arr.get(i);
		if (item != -1e6)
		{
			cout << item << endl;
		}
	}

	return 0;
}


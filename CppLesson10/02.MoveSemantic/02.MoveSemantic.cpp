// 02.MoveSemantic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <iostream>
using namespace std;

class Array
{
	int *arr;
	int size;
public:
	Array() = delete;
	Array(int n) //: size(n), arr(new int[size]) 
	{
		size = n;
		arr = new int[size];
	}
	// конструктор копирования
	Array(const Array& orig)
	{
		size = orig.size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = orig.arr[i];
		}
	}
	// оператор присваивания
	Array& operator=(Array& right)
	{
		delete[] arr;
		size = right.size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = right.arr[i];
		}
		return *this;
	}

	int length() const // константный метод
	{			
		return size;
	}
	
	int& operator[](int idx)
	{
		return arr[idx];
	}

	void swap(Array& other)
	{
		Array tmp = *this;
		*this = other;
		other = tmp;
	}		

	~Array()
	{
		delete[] arr;
	}

	// Конструктор перемещения
	Array(Array &&orig)
	{
		size = orig.size;
		arr = orig.arr;
		orig.size = 0;
		orig.arr = NULL;
	}

	// Оператор перемещения
	Array& operator=(Array&& right)
	{
		size = right.size;
		arr = right.arr;
		right.size = 0;
		right.arr = NULL;
		return *this;
	}

	// принимает rvalue ссылку
	void swap(Array&& other)
	{
		Array tmp = move(*this);
		*this = move(other);
		other = move(tmp);
	}
};

ostream& operator<<(ostream& stream, Array& arr)
{
	for (int i = 0; i < arr.length(); i++)
	{
		stream << arr[i];
		if(i != (arr.length() - 1))
			stream << ", ";
	}	
	return stream;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 1e8;
	Array a(n), b(n);
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
		b[i] = i + i;
	}

	//cout << "a: " << a << endl;
	//cout << "b: " << b << endl;
	clock_t start = clock();
	a.swap(move(b));
	clock_t end = clock();
	//cout << "a: " << a << endl;
	//cout << "b: " << b << endl;
	cout << "dt: " << (end - start)/* / CLOCKS_PER_SEC*/ << endl;
 
	return 0;
}


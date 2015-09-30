// 02.MoveSemantic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <iostream>
using namespace std;

template <typename T>
class Array
{
	T *arr;
	int size;
public:
	Array() = delete;
	Array(int n) //: size(n), arr(new int[size]) 
	{
		size = n;
		arr = new int[size];
	}
	// ����������� �����������
	Array(const Array& orig)
	{
		size = orig.size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = orig.arr[i];
		}
	}
	// �������� ������������
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

	int length() const // ����������� �����
	{			
		return size;
	}
	
	T& operator[](int idx)
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

	// ����������� �����������
	Array(Array &&orig)
	{
		size = orig.size;
		arr = orig.arr;
		orig.size = 0;
		orig.arr = NULL;
	}

	// �������� �����������
	Array& operator=(Array&& right)
	{
		size = right.size;
		arr = right.arr;
		right.size = 0;
		right.arr = NULL;
		return *this;
	}

	// ��������� rvalue ������
	void swap(Array&& other)
	{
		Array tmp = move(*this);
		*this = move(other);
		other = move(tmp);
	}
};

template<typename T>
ostream& operator<<(ostream& stream, Array<T>& arr)
{
	for (int i = 0; i < arr.length(); i++)
	{
		stream << arr[i];
		if(i != (arr.length() - 1))
			stream << ", ";
	}	
	return stream;
}

class Person
{
	
};

class Appartment
{
	//Person* persons;
	Array<Person> persons;
public:
	Appartment(int n) : persons(n)
	{
		
	}

};

class House
{
	Array<Appartment> appartments;
public:
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 1e8;
	Array<int> a(n), b(n);
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


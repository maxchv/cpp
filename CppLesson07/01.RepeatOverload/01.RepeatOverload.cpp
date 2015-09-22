// 01.RepeatOverload.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

class Number
{
	int data;
	char name[20];
public:
	// new in С++ 11
	Number() = default; // default - должен использоваться коснтруктор по умолчанию
					   //           предоставленый компилятором
	                   // delete  - создавать объект при помощи данного конструктора
					   //           запрещено. Ошибка на этапе компиляции
	Number(const Number&) = default;
	Number(int init)
	{
		strcpy(name, "Hello");
		data = init;
	}
	Number operator+(const Number& right)
	{
		Number res(this->data + right.data);
		return res;
	}
	Number& operator=(const Number& right) = default;
	/*{
		data = right.data;
		return *this;
	}*/

	Number& operator+=(const Number& right)
	{
		data += right.data;
		return *this;
	}

	Number& operator++() // перегрузка префиксного оператора
	{
		cout << "++Number" << endl;
		++data;
		return *this;
	}

	Number& operator++(int) // перегрузка префиксного оператора
	{
		cout << "Number++" << endl;
		data++;
		return *this;
	}

	void show()
	{
		cout << name << endl;
		cout << data << endl;
	}
	friend Number operator+(int, Number&);
	friend void foo(Number&);
};

void foo(Number &n)
{
	n.data = 10;
}

Number operator+(int left, Number &right)
{
	return Number(left + right.data);
}

void ex01()
{
	Number n1(10);  // для создания объекта n1 вызвается конструктор с параметрами
	Number n2 = n1; // для создания объекта n2 вызвается конструктор копирования

	Number n3;     // для создания объекта n3 вызвается конструктор по умолчанию
	n3 = n1 + n2;
	n2 += n3;
	n3 = n2;
	n2 = 1 + n3;
	n2.show();
	++n2;
	n2.show();
	n2++;
	n2.show();
}

void ex02()
{
	int i = 0;
	cout << "i:\t"	 << i << endl;		// 0
	cout << "i++:\t" << i++ << endl;	// 0
	cout << "i:\t"   << i << endl;		// 1
	cout << "++i:\t" << ++i << endl;	// 2
	cout << "i:\t"   << i << endl;		// 2

	int a;
	i = 10;

	a = i++;	//  10            11
	cout << "a: " << a << "i: " << i << endl;
	//i++ => i = i + 1
	a = ++i + i--;// 22            21
	cout << "a: " << a << "i: " << i << endl;

	int arr[] = { 1, 2, 3, 4, 5 };
	i = 0;
	while (i < 5)
	{
		cout << arr[i++] << endl; // i = 0
		// i = 1
	}
}

void ex03()
{
	// Пример применения дружественных функций
	Number n(0);
	n.show();
	foo(n);
	n.show();
}

void ex04()
{
	// Пример сохранения объектов в файлах
	Number n(100);
	FILE *f = fopen("number.bin", "wb");
	if (f != NULL)
	{
		fwrite(&n, sizeof(n), 1, f);
		fclose(f);
	} 
	else
	{
		cerr << "Error opening file: " << strerror(errno) << endl;
	}
}

void ex05()
{
	// Пример сохранения объектов в файлах
	Number n;
	FILE *f = fopen("number.bin", "rb");
	if (f != NULL)
	{
		//fwrite(&n, sizeof(n), 1, f);
		fread(&n, sizeof(n), 1, f);
		n.show();
		fclose(f);
	}
	else
	{
		cerr << "Error opening file: " << strerror(errno) << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//ex02();
	ex04();
	ex05();
	return 0;
}


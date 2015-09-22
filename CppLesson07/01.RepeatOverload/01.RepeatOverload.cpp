// 01.RepeatOverload.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Number
{
	int data;
public:
	// new in С++ 11
	Number() = default; // default - должен использоваться коснтруктор по умолчанию
					   //           предоставленый компилятором
	                   // delete  - создавать объект при помощи данного конструктора
					   //           запрещено. Ошибка на этапе компиляции
	Number(const Number&) = default;
	Number(int init)
	{
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
	void show()
	{
		cout << data << endl;
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	Number n1(10);  // для создания объекта n1 вызвается конструктор с параметрами
	Number n2 = n1; // для создания объекта n2 вызвается конструктор копирования

	Number n3;     // для создания объекта n3 вызвается конструктор по умолчанию
	n3 = n1 + n2;
	n2 += n3;
	n3 = n2;
	n2.show();
	return 0;
}


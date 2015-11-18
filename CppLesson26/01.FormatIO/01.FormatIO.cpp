// 01.FormatIO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

void ex01()
{
	cout.setf(ios::showpos); 
	cout << 10 << endl;  // +10 вывод с + пока не снимем флаг
	
	cout.unsetf(ios::showpos);
	cout << 5 << endl;
		
	cout.setf(ios::showpoint);
	cout << 10.0 << endl;

	cout.unsetf(ios::showpoint);
	cout << 10.0 << endl;

	cout.flags(ios::showbase|ios::uppercase); // основание системы исчисления 0х для 16-ти ричной, 0 для 8...
	cout.setf(ios::hex, ios::basefield); // вывод целых в 16-ти ричном виде
	for (int i = 0; i < 25; i++)
	{
		cout << i << endl;
	}	
}

void ex02()
{
	for (int i = 0; i < 20; i++)
	{
		cout.setf(ios::oct, ios::basefield); // 8
		cout << i << " ";
		cout.setf(ios::dec, ios::basefield); // 10
		cout << i << " ";
		cout.setf(ios::hex, ios::basefield); // 16
		cout << i << endl;
	}
	cout.setf(ios::fixed, ios::floatfield); // вывод по умолчанию
	cout << 0.001 << endl;

	cout.setf(ios::uppercase);
	cout.setf(ios::scientific, ios::floatfield); // вывод в научном виде с E
	cout << 0.001 << endl;

	cout.width(20); // ширина поля вывода в символах
	cout.setf(ios::right, ios::adjustfield);
	cout << 100 << endl;
	
	cout.width(20);
	cout << 20 << endl;

	cout.setf(ios::showpos);
	cout.setf(ios::dec, ios::basefield);
	cout.setf(ios::internal, ios::adjustfield);
	cout.width(10);
	cout << 15 << endl;
}

void ex03()
{
	cout.setf(ios::right, ios::adjustfield);
	for (int i = 1; i < 10; i++)
	{		
		cout.width(i);
		cout.fill('.');
		cout << '*' << endl;
	}

	for (int i = 0; i < 10; i++)	{
		cout.width(10);
		cout << i << endl;
	}

	cout.setf(ios::showpoint);
	cout.precision(12);
	cout << 1.00000001 << endl;
	cout << 1.00000001 << endl;
}

//  форматирование вывода через манипуляторы
void ex11()
{	
	cout << showpos << 10 << endl;  // +10 вывод с + пока не снимем флаг
		
	cout << noshowpos << 5 << endl;
		
	cout << showpoint << 10.0 << endl;
		
	cout << noshowpoint << 10.0 << endl;

	for (int i = 0; i < 25; i++)
	{
		cout << showbase << uppercase << hex << i << endl;
	}
}

void ex12()
{
	for (int i = 0; i < 20; i++)
	{		
		cout << oct << i << " "	
			 << dec << i << " "
			 << hex << i << endl;
	}
	
	cout << fixed << 0.001 << endl;
	cout << uppercase << scientific << 0.001 << endl;

	cout << setw(20) << right << 100 << endl;
	cout << setw(20) << 20 << endl;

	cout << showpos << dec << internal << setw(10) << 15 << endl;
}

void ex13()
{	
	for (int i = 1; i < 10; i++)
	{	
		cout << right << setw(i) << setfill('.') << '*' << endl;
	}

	for (int i = 0; i < 10; i++) {		
		cout << setw(10) << i << endl;
	}

	cout << showpoint << setprecision(12) << 1.00000001 << endl;
	cout << 1.00000001 << endl;
}

int main()
{
	//ex01();
	//ex02();
	//ex03();
	//ex11();
	//ex12();
	ex13();
    return 0;
}


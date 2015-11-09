// 01.Exception.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void ex00()
{
	int a, b, c;

	cout << "Type two numbers: ";
	cin >> a >> b;

	c = a / b; // �������� ������� �� 0, � ���� ������ ��������� �� ������������
	// ��� ���������� ������ �������� ���������� ������������� ������ ��������
	cout << "a / b = " << c << endl;
}

void ex01()
{
	int a, b, c;

	cout << "Type two numbers: ";
	cin >> a >> b;
	// C ������� ������� ��������
	if (b != 0)
	{
		c = a / b;
		cout << "a / b = " << c << endl;
	}
	else
	{
		cerr << "Error: divide by zero" << endl;
	}
}

// ���������� ���������� ����������� ��������� ��������:
// 0 - ������ ������� ���
// 1 - ��������� ������ �������
int error_div = 0;

// ������� ������� � ��������� �������� �� 0
int mydiv(int a, int b)
{
	if (b != 0)
	{
		return a / b;
	}
	else
	{
		error_div = 1;
		return 0;
	}
}

void ex02()
{
	int a, b, c;

	cout << "Type two numbers: ";
	cin >> a >> b;
	// C ������� ������� �������� ��� ������ � ���������
	c = mydiv(a, b);
	if (!error_div)
	{
		cout << "a / b = " << c << endl;
	}
}

void ex03()
{
	int a, b, c;

	cout << "Type two numbers: ";
	cin >> a >> b;
	// C++ (��������-���������������) ������� ������� ��������
	try // ���������� ��������� ������������ ���
	{
		if (b == 0)
		{
			throw b; // ������������� ���������� ��� int
		}
		c = a / b;
		cout << "a / b = " << c << endl;
	}
	catch(int err) // �������� ���������� ���� int
	{
		cerr << "Error: divide by zero" << endl;
	}
}

// ���������� ������� �������, ������� ���������� ����������
// � ������ ������������� ������ �������
int mysafediv(int a, int b)
{
	if (b == 0)
	{
		throw "Error divide by zero";  // ������������� ���������� ���� char*
	}
	return a / b;
}

void ex04()
{
	int a, b, c;

	cout << "Type two numbers: ";
	cin >> a >> b;
	// C++ (��) ������� ������� �������� ��� ������ � ���������
	try
	{
		c = mysafediv(a, b);
		cout << "a / b = " << c << endl;
	}
	catch(int err) // ������������� ������ ������������� ������
	{
		cerr << "Error :" << err << endl;
	}
	catch (char *err)
	{
		cerr << err << endl;
	}
}

void ex05()
{
	try 
	{
		char ch = 'e';
		short sh = 1;
		int i = 2;
		long l = 5;
		char *str = "Error";

		//throw ch;
		//throw sh;
		//throw i;
		//throw l;
		//throw str;
		throw 1.0;
	}
	catch (char err)
	{
		cerr << "I catch char error: " << err;
	}
	catch (short err)
	{
		cerr << "I catch short error: " << err;
	}
	catch (int err)
	{
		cerr << "I catch int error: " << err;
	}
	catch (long err)
	{
		cerr << "I catch long error: " << err;
	}
	catch (char* err)
	{
		cerr << "I catch string error: " << err;
	}
	catch (...) // ����������� ��� ��������� ����������
	{
		cerr << "General error";
	}
	cerr << endl;
}

int main()
{
	//ex00();
	//ex01();
	//ex02();
	//ex03();
	//ex04();
	ex05();

    return 0;
}


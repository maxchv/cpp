// 01.Exception.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void a()
{
	cout << "funcion a()" << endl;
	throw "char * error";
}

void b()
{
	try
	{
		a();
	}
	catch (char *err)	// перехват только сообщений типа char*
	{
		cerr << "Caught exception from a() " << err << endl;
		throw;
	}
	catch (...) // всех остальных сообщений
	{
		throw; // передача сообщения на уровень выше по стеку вызовов функций
	}
}

void c()
{
	try
	{
		b();
	}
	catch (char *err)
	{
		cerr << "Caught exception from b() " << err << endl;
	}
	catch (...) // всех остальных сообщений
	{
		throw; // передача сообщения на уровень выше по стеку вызовов функций
	}
}

int main()
{
	try
	{
		c();
	}
	catch (char *err)
	{
		cerr << "Caught exception from c() " << err << endl;
	}
	catch (int err)
	{
		cerr << "Caught exception from c() " << err << endl;
	}
	catch (...)
	{
		cerr << "Other exceptions" << endl;
	}

	return 0;
}


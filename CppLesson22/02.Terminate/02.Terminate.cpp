// 02.Terminate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <exception>
#include <iostream>
using namespace std;

void f() noexcept // запрет на генерирование исключения
{
	throw "Error";
}

void my_terminate()
{
	cerr << "My terminate function" << endl;
	exit(1);
}

int main()
{
	set_terminate(my_terminate); // задание своей функции terminate
	try
	{
		f();
	}
	catch (int err)
	{

	}
	catch (...)
	{

	}
	
	//terminate();

    return 0;
}


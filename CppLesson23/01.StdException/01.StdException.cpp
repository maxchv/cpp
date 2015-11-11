// 01.StdException.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <exception>
using namespace std;

class MyException: public exception
{
	//const char *msg; // сообщение о ошибке
	const char *file;
	const int line;

public:
	MyException(const char *err_msg, const int err_line, const char *where_file) :
		exception(err_msg), line(err_line), file(where_file)
	{}

	const char* what() const override
	{
		return exception::what();
	}

	const int what_line() const
	{
		return line;
	}
	const char * where() const
	{
		return file;
	}
};

void f()
{
	//__FUNCTION__;
	//throw MyException("Error message", __LINE__, __FILE__);
	//throw exception("Error message");
}

class FileError : public exception
{
public:
	FileError(const char* msg): exception(msg)
	{}
};

class ConnectError : public exception
{
public:
	ConnectError(const char *msg): exception(msg)
	{}
};

class InputError : public exception
{
public:
	InputError(const char *msg): exception(msg)
	{}
};

void boo(int i)
{
	switch (i)
	{
	case 1:
		throw FileError("Can't open file to read");
		break;
	case 2:
		throw ConnectError("Can't get file from site vk.com");
		break;
	case 3:
		throw InputError("Can't undestand you");
		break;
	default:
		throw "Error";
		break;
	}
}

void my_unexpected()
{
	cerr << "Unexpected behavior" << endl;
	exit(1);
}

void ex01()
{
	set_unexpected(my_unexpected);
	try
	{
		boo(4);
	}
	catch (FileError &err)
	{
		cerr << err.what() << endl;
	}
	catch (ConnectError &err)
	{
		cerr << err.what() << endl;
	}
	catch (InputError &err)
	{
		cerr << err.what() << endl;
	}
	catch (...)
	{
		unexpected(); // terminate();
	}
}

int main()
{
	ex01();
	try
	{
		f();
	}
	catch (MyException &ex)
	{
		cerr << " Line: " << ex.what_line() << " File: " << ex.where() << endl << ex.what() << endl;
	}
	catch (exception &ex)
	{
		cerr << ex.what() << endl;
	}

	try
	{
		//int * arr = new int[0x7ffffff];
	}
	catch (bad_alloc &ex)
	{
		cerr << ex.what() << endl;
	}
	catch (...)
	{
		cerr << "Other exception" << endl;
	}

    return 0;
}


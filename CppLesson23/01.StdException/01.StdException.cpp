// 01.StdException.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <exception>
using namespace std;
#pragma warning(disable: 4996)
class MyException: public exception
{
	//const char *msg; // ��������� � ������
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
#include <ctime>
void ex02()
{
	time_t t;
	time(&t);
	tm *_time;
	_time = localtime(&t);
	FILE* f = fopen("error.log", "w");
	if (f)
	{
		fprintf(f, "%d.%d.%d %d:%d:%d %s", _time->tm_mday, _time->tm_mon+1, _time->tm_year + 1900, _time->tm_hour, _time->tm_min, _time->tm_sec, "Error");
		fclose(f);
		system("error.log");
	}
}

void ex03()
{
	while (true)
	{
		time_t t;
		time(&t);
		tm *_time;
		_time = localtime(&t);
		cout << _time->tm_hour << ":" << _time->tm_min << ":" << _time->tm_sec << endl;
		_sleep(1000);
		system("cls");
	}
}


int main()
{
	ex03();
	ex02();
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


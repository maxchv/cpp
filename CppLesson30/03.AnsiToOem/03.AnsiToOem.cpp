// 03.AnsiToOem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;

class rus
{
	static char buff[256];
	const char *_str;
public:
	rus(const char *str): _str(str)
	{}

	friend ostream& operator<<(ostream& stream, const rus& r)
	{
		// конвертирование из cp1251 в 866
		AnsiToOem(r._str, r.buff);
		stream << r.buff;
		return stream;
	}
};

char rus::buff[256];

int main()
{
	char buff[256];
	AnsiToOem("Это текст", buff);
	cout << buff << endl;
	cout << rus("Это тестовая строка") << endl;
	cout << rus("Еще одна строка") << endl;
	
    return 0;
}


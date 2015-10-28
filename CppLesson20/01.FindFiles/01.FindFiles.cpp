// 01.FindFiles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <io.h>
#include <bitset>
#pragma warning (disable: 4996)

void ex01()
{
	char *path = "c:/"; // текущая папка
	char *mask = "*"; // искать только файлы с расширением txt
	char *buff = new char[20];
	strcpy(buff, path); // копирование строки 
	strcat(buff, mask); // конкатенация строк
	
	cout << buff << endl;
	
	_finddata_t findinfo;
	long h = _findfirst(buff, &findinfo); // поиcк первого файла
									      // если файл найден, но h != -1
	long done = h;
	while (done != -1)
	{
		if (findinfo.attrib & _A_SUBDIR)
		{
			cout << "<DIR>\t";
		}
		else
		{
			cout << findinfo.size/1024 << "kB\t";
		}
		cout << findinfo.name << endl;
		done = _findnext(h, &findinfo);

	}
	_findclose(h);
	
	delete buff;
}

void ex02()
{
	bitset<8> b;
	b = _A_ARCH;
	cout << "_A_ARCH: bin: " << b << " dec: " << _A_ARCH << endl;
	b = _A_HIDDEN;
	cout << "_A_HIDDEN: bin: " << b << " dec: " << _A_HIDDEN << endl;
	b = _A_NORMAL;
	cout << "_A_NORMAL: bin: " << b << " dec: " << _A_NORMAL << endl;
	b = _A_RDONLY;
	cout << "_A_RDONLY: bin: " << b << " dec: " << _A_RDONLY << endl;
	b = _A_SUBDIR;
	cout << "_A_SUBDIR: bin: " << b << " dec: " << _A_SUBDIR << endl;
	b = _A_SYSTEM;
	cout << "_A_SYSTEM: bin: " << b << " dec: " << _A_SYSTEM << endl;
}

int main()
{
	ex01();
	//ex02();
    return 0;
}


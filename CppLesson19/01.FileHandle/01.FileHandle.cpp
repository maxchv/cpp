// 01.FileHandle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <io.h>
#include <Windows.h>
#include <direct.h>
#include <bitset>
using namespace std;
#pragma warning(disable: 4996)

void ex01()
{	
	FILE* f = fopen("oldfile.txt", "w");
	fclose(f);
	rename("oldfile.txt", "newfile.txt"); // переименование файла
}

void ex02()
{
	remove("newfile.txt"); // удаление  файла
}

void ex03()
{
	// пример вывода файлов и папок текущей папки
	_finddata_t fileinfo;
	long handle = _findfirst("*", &fileinfo);
	long next_file = handle;
	bitset<16> b;
	b = _A_ARCH;
	cout << "_A_ARCH: " << b << endl;
	b = _A_HIDDEN;
	cout << "_A_HIDDEN: " << b << endl;
	b = _A_NORMAL;
	cout << "_A_NORMAL: " << b << endl;
	b = _A_RDONLY;
	cout << "_A_RDONLY: " << b << endl;
	b = _A_SUBDIR;
	cout << "_A_SUBDIR: " << b << endl;
	b = _A_SYSTEM;
	cout << "_A_SYSTEM: " << b << endl;
	while (next_file != -1)
	{	
		next_file = _findnext(handle, &fileinfo);		
		cout << fileinfo.name << " size: " << fileinfo.size << endl;
		AnsiToOem(fileinfo.name, fileinfo.name);
		b = fileinfo.attrib;		
		if (fileinfo.attrib & _A_SUBDIR)
		{
			cout << "it is directory" << endl;
		}
	}
	_findclose(handle);
}

void ex04()
{
	// создание директории
	_mkdir("newdir");
}

void ex05()
{
	_rmdir("newdir"); // удаление директории
}

void test_to_int()
{
	char buf[20];
	sprintf(buf, "%lli", pow(2, 31));
	cout << buf << endl;
	cout << pow(2, 31) << endl;
}

int main()
{
	//ex01();
	//ex02();
	//system("dir");
	//ex03();
	//ex04();
	//ex05();
	test_to_int();

    return 0;
}


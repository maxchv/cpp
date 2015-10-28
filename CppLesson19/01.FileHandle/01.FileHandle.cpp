// 01.FileHandle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <io.h>
#include <Windows.h>
#include <direct.h>
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
	while (next_file != -1)
	{		
		AnsiToOem(fileinfo.name, fileinfo.name);
		cout << fileinfo.name << " size: " << fileinfo.size << endl;
		next_file = _findnext(handle, &fileinfo);		
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

int main()
{
	//ex01();
	//ex02();
	//system("dir");
	//ex03();
	//ex04();
	//ex05();
	ex03();
    return 0;
}


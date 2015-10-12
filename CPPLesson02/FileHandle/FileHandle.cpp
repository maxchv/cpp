// FileHandle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

void write_to_file(char *filename)
{
	FILE *f;	
	int x = 10, y = 20;
	f = fopen(filename, "w"); // открытие файла на запись
	// режим открытия файлов:
	// w - write (запись)
	// r - read (чтение) 
	// a - append (добавление)
	// w+ - чтение и запись
	// r+ - чтение и запись
	// a+ - чтение и добавление
	// wb - запись в бинарном режиме
	// rb - чтение в бинарном режиме
	// ab - добавление в бинарном режиме
	if (f != NULL) // откыт ли файл, не было ли ошибки при откытии
	{
		fprintf(f, "%d %d", x, y);
		fclose(f); // закрытие файла
		//system(file);
	}
	else
	{
		cerr << strerror(errno)
			<< " error opening file: "
			<< filename << endl;
	}
}

void read_from_file(char *filename)
{
	FILE *f = fopen(filename, "r");
	if (f)
	{
		int x, y;
		//char line[256];
		while (!feof(f)) // пока не конец файла
		{
			//fgets(line, 255, f); // считываем строку 
			                     // максимальной длинны 255 символов
			//cout << line << endl;
			fscanf(f, "%d %d", &x, &y);
			cout << "x: " << x << " y: " << y << endl;
		}
		fclose(f);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//write_to_file("d:\\file.txt");
	read_from_file("d:\\file.txt");

	return 0;
}


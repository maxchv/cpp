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

void find_files(char *path, char *mask, int offset = 0)
{	
	char *find_path = new char[strlen(path) + strlen(mask) + 2];
	strcpy(find_path, path); // копирование строки 
	strcat(find_path, "\\");
	strcat(find_path, mask); // конкатенация строк

	cout << path << endl;
	
	// Поиск файлов по маске в текущей папке
	_finddata_t findinfo;
	long h = _findfirst(find_path, &findinfo); // поиcк первого файла
										  // если файл найден, но h != -1	
	long done = h;
	while (done != -1)
	{	
		for (int i = 0; i < offset + strlen(path) - 1; i++)
		{
			cout << " ";
		}
		cout << (char)192;
		cout << findinfo.name << endl;
		done = _findnext(h, &findinfo);
	}
	_findclose(h);

	// Рекурсивный поиск в поддиректориях
	strcpy(find_path, path); // копирование строки 
	strcat(find_path, "\\*"); // конкатенация строк d:\\temp\\*
	h = _findfirst(find_path, &findinfo);
	done = h;
	while (done != -1)
	{
		if (findinfo.attrib & _A_SUBDIR) // это папка?
		{
			if (!(strncmp(findinfo.name, ".", 1) == 0 || strncmp(findinfo.name, "..", 2) == 0))
			{
				char *nbuf = new char[strlen(path) + strlen(findinfo.name) + 2];
				strcpy(nbuf, path);
				strcat(nbuf, "\\");
				strcat(nbuf, findinfo.name);
				find_files(nbuf, mask, offset); // рекурсия
				delete nbuf;
			}
		}
		done = _findnext(h, &findinfo);
	}

	delete find_path;
}

void ex03()
{
	// текстовый режим - запись
	FILE *f = fopen("test.txt", "w"); // w - write, r - read, a - append |text|
									  // wb, rb, ab |binary|
									  // w+, r+, a+	
	if (f) // если файл открыт, то f!=NULL
	{
		fprintf(f, "Square: %d\n", 15); // форматированный вывод
		fputs("Cicrle: 10", f);         // вывод строки
		fputc('\n', f);					// вывод одиночного символа
		fclose(f);
	}
	char buff[256];
	// текстовый режим - чтение
	f = fopen("test.txt", "r");
	if (f)
	{
		int size;
		fscanf(f, "%s %d\n", buff, &size); // форматированный вывод
		cout << buff << " " << size << endl;
		fgets(buff, 255, f);			 // ввод строки
		cout << buff;
		cout << "i am here: " << ftell(f) << endl;
		fseek(f, 8, SEEK_SET);
		fscanf(f, "%d\n", &size);
		cout << "i am here: " << ftell(f) << endl;
		cout << "size again: " << size << endl;
		
		fseek(f, -3, SEEK_END);
		cout << "i am here: " << ftell(f) << endl;
		fscanf(f, "%d\n", &size);		
		cout << "size again: " << size << endl;
		
		fclose(f);
	}
}

void ex04()
{
	// вывод файла в виде кодов
	FILE *f = fopen("test.txt", "r");
	if (f)
	{
		char ch;
		int i = 0;
		while ((ch = fgetc(f)) != EOF) //  feof(f) - возвращает false если не достигнут конец файла
		{
			cout << ++i << ") " << (int)ch << ": " << ch << endl;
		}
	}
}

void copy_file(char *from, char *to)
{
	FILE *in = fopen(from, "rb");
	if (in)
	{
		FILE *out = fopen(to, "wb");
		if (out)
		{
			/*int handle = _fileno(in);
			long size = _filelength(handle);
			char *buff = new char[size];			
			fread(buff, sizeof(char), size, in);
			fwrite(buff, sizeof(char), size, out);*/

			int i = 0;
			while (!feof(in))
			{			
				char buff;
				fread(&buff, sizeof(char), 1, in);   // чтение данных в буффер				
				cout << ++i << ") " << (int)buff << ": " << buff << endl;
				fwrite(&buff, sizeof(char), 1, out); // запись данных в файл
			} 
			fclose(out);
		}
		fclose(in);
	}
}

int main()
{
	//ex01();
	//ex02();
	//find_files("d:\\temp", "*.txt");// d:\\temp\\*.txt
	//for (unsigned char c = 0; c < 255; c++)
	//{
	//	cout << (int)c << " c: " << c << endl;
	//}

	//ex03();
	//ex04();
	copy_file("copy.txt", "copy2.txt");
	return 0;
}


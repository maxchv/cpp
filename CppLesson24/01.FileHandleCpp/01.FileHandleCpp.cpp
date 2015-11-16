// 01.FileHandleCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

void ex01()
{
	
	char *filename = "out.txt";
	fstream f;//(filename, ios::out | ios::trunc);

			  // открытие файла на запись с усечением до 0 если файл существует
	f.open(filename, ios::out | ios::trunc);
	
	if (f.is_open()) // если файл открыт
	{
		f << "2+2" << endl;	 // вывод выражения
	}
	f.close();

	// открытие файла на чтение
	f.open(filename, ios::in);
	int num1, num2;
	char op;
	if (f.is_open())
	{
		f >> num1 >> op >> num2; // считываение данных из файла
		cout << num1 << op << num2 << " = " << (num1 + num2) << endl;
	}
}

class Equation
{
	int n1, n2;
	char op;
public:
	friend ostream& operator <<(ostream& stream, Equation& eq)
	{
		stream << eq.n1 << eq.op << eq.n2 << endl;
		return stream;
	}
	friend istream& operator >>(istream& stream, Equation &eq)
	{
		stream >> eq.n1 >> eq.op >> eq.n2;
		return stream;
	}
};

void ex02()
{
	Equation eq;
	cin >> eq;
	fstream out("eq.txt", ios::out | ios::trunc);
	if (out.is_open())
	{
		out << eq;
	}
	out.close();
	
	out.open("eq2.txt", ios::out | ios::trunc);
	if (out.is_open())
	{
		out << "2+2" << endl;
	}
	out.close();

	fstream in("eq2.txt", ios::in);
	if (in.is_open())
	{
		in >> eq;
		cout << eq << endl;
	}
}

void ex03()
{
	// для файлового вывода
	ofstream out("data.txt"); // по умолчанию файл открывается в режиме ios::out | ios::trunc
	int data = 5;
	out << data;
}

void ex04()
{
	// для файлового ввода
	ifstream input("eq.txt"); // по умолчанию режим открытия ios::in
	int n1, n2;
	char op;
	input >> n1 >> op >> n2;
	cout << n1 << op << n2 << " = ";
	switch (op)
	{
	case '+':
		cout << (n1 + n2);
		break;
	case '-':
		cout << (n1 - n2);
		break;
	case '*':
		cout << (n1 * n2);
		break;
	case '/':
		cout << (n1 / n2);
		break;
	default:
		break;
	}
	cout << endl;
}

void ex05(char *fname)
{
	ifstream in(fname);
	in.seekg(0, ios::end); // перемещение в конец файла (ios::end)
	streampos curr_pos = in.tellg(); // текущее положение указателя чтения
	cout << "size of file: " << curr_pos << endl;
}

void ex06()
{
	fstream f("test.txt", ios::out | ios::in | ios::trunc); // открытие на чтение из запись
	f << "2+2";
	f.seekg(0, ios::beg);// установить указатель считывания на начало файла
	cout << "tellg: " << f.tellg() << " tellp: " << f.tellp() << endl;
	
	char first, second, third;
	f.get(first);
	cout << first << endl;
	cout << "tellg: " << f.tellg() << " tellp: " << f.tellp() << endl;
	
	//f.putback('5');
	//f.unget();
	cout << (char)f.peek() << endl;
	f.get(second);
	cout << second << endl;
	cout << "tellg: " << f.tellg() << " tellp: " << f.tellp() << endl;
	
	f.get(third);	
	cout << third << endl;
	cout << "tellg: " << f.tellg() << " tellp: " << f.tellp() << endl;

	f.seekg(0, ios::beg);

	f.seekg(-1, ios::end); // на предпоследний символ с конца файла
	int end = f.get();
	cout << end << endl;
	cout.setf(ios::boolalpha);
	cout  << f.eof() << endl;
	cout << f.get() << endl; // возвращает EOF
}
// argc - кол-во аргументов передаваемых программе при запуске
// argv - массив аргументов (строк)
// 
// cmd> 01.FileHangleCpp.exe 10
//
// argc = 2
// argv = {"01.FileHangleCpp.exe", "10"};
int main(int argc, char* argv[]) // точка входа
{
	/*for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}*/
	//ex02();
	//ex04();
	
	//ex05(argv[0]);
	ex06();
    return 0;
}


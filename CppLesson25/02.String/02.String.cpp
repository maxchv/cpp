// 02.String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void ex00()
{
	char str[] = "String";
}

void show(char *oldstr)
{
	cout << oldstr << endl;
}

void ex01()
{
	string str = "Hello, string";
	string str2("It is string");

	cout << str << endl;

	str = "Hello ";
	str2 = "Cool C++";
	
	str += str2;// strcat
	cout << str << endl;

	//str = " ";
	//str.clear();			// стереть строку
	//str.shrink_to_fit();	// 
	cout << "size: " << str.size() << " length: " << str.length() << endl; // strlen	
	cout <<"capacity: " << str.capacity() << " max_size: " << str.max_size() << endl;

	for (int i = 0; i < str.size(); i++)
	{
		cout << i << ") " << (int)str[i] << " " << str[i] << endl;
	}

	show((char *)str.c_str());
}

int main()
{
	
	ex01();
    return 0;
}


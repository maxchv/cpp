#include "stdafx.h"
#include "Student.h"
#include <string.h>
#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

// реализация конструктора
Student::Student(char *f, char *l, int a, char *g)
{
	strcpy(fname, f);
	strcpy(lname, l);
	age = a;
	strcpy(group, g);
}

void Student::show()
{
	cout << "first name: " << fname << endl
		<< "last name: " << lname << endl
		<< "age: " << age << endl
		<< "group: " << group << endl;
}
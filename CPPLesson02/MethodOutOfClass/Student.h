#include "stdafx.h"
class Student
{
	char fname[20];
	char lname[20];
	int  age;
	char group[20];
public:
	Student(char *f, char *l, int a, char *g); // прототип конструктора
	void show(); // прототип метода
};
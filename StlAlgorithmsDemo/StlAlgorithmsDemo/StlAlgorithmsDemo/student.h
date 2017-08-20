#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

enum gender {
	MAN,
	WOMEN
};

class student
{
public:
	
private:
	string name;
	int age;
	gender gen;
public:
	student(string name, int age, gender gen);

	string getName();

	int getAge();

	gender getGender();

	friend ostream& operator<<(ostream& stream, const student& student);
};


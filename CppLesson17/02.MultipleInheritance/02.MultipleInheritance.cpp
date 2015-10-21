// 02.MultipleInheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// Множественное наследование, виртуальное наследование
class Animal
{
public:
	int age;
	virtual ~Animal() = 0;
};
Animal::~Animal(){}

class Human: virtual public Animal
{
protected:
	const char* name;
public:
	Human(const char *n): name(n)
	{}
};

class Horse: virtual public Animal
{
protected:
	int length_tail;
public:
	Horse(int l) : length_tail(l)
	{}
};

class Kentavr : public Human, public Horse
{
public:
	Kentavr(const char* name, int length): Human(name), Horse(length)
	{}
	void show()
	{
		cout << "Name: " << name << " length of tail: " << length_tail << endl;
	}
};

int main()
{
	Kentavr kent("Vasja", 1);
	kent.show();
	kent.age = 10;

    return 0;
}


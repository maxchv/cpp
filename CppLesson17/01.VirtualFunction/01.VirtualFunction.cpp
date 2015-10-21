// 01.VirtualFunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Animal
{
	const char* name;
public:
	Animal(const char *name)
	{
		this->name = name;
	}
	virtual void show()
	{
		cout << "It animal call " << name << endl;
	}
};

class Elephant: public Animal
{
	double length_proboscis; // длинна хобота
public:
	Elephant(double l) : Animal("Elephant")
	{
		length_proboscis = l;
	}
	virtual void show() // виртуальная функция
	{
		Animal::show();
		cout << "Length of proboscis: " << length_proboscis << "m" << endl;
	}
};

class Lion : public Animal
{
	int pride; // прайд
public:
	Lion(int p) : Animal("Lion")
	{
		pride = p;
	}

	void show()
	{
		Animal::show();
		cout << "Pride: " << pride  << endl;
	}
};

class Dolphin: public Animal
{
	double max_speed;
public:
	Dolphin(double s) : Animal("Dolphin"), max_speed(s)
	{}

	void show()
	{
		Animal::show();
		cout << "Max speed: " << max_speed << endl;
	}
};


int main()
{
	Animal *zoo[3]; // массив указателей на базовый класс
	zoo[0] = new Elephant(2);
	zoo[1] = new Lion(7);
	zoo[2] = new Dolphin(40);

	for (int i = 0; i < 3; i++)
	{
		zoo[i]->show();
	}

	for (int i = 0; i < 3; i++)
	{
		delete zoo[i];
	}

    return 0;
}


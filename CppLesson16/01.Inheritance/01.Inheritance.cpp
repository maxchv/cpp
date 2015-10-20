// 01.Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Animal
{
private:
	double weight; // вес
protected:
	char* kind;    // вид
	char* name;    // название
public:
	Animal(char * n)
	{
		kind = n;

		//std::cout << "Constructor Animal" << std::endl;
	}
	~Animal()
	{
		//std::cout << "Destructor Animal" << std::endl;
	}
	void setWeight(double w)
	{
		weight = w;
	}
	double getWeight()
	{
		return weight;
	}
	void show()
	{
		std::cout << "Show Animal" << std::endl;
	}
};

class Mammals : protected Animal
{
public:
	bool drink_milk;

	Mammals(char *k, char *name=NULL): Animal(k)
	{
		drink_milk = true;
		kind = "Mammals";
		setWeight(16);
		//std::cout << "Constructor Mammals" << std::endl;
	}
	~Mammals()
	{
		//std::cout << "Destructor Mammals" << std::endl;
	}
	void show()
	{
		Animal::show();
		std::cout << "Show Mammals" << std::endl;
	}
};

class Cats : public Mammals
{
public:
	Cats(): Mammals("Mammals")
	{
		show();
		setWeight(10);
		//std::cout << "Constructor Cats" << std::endl;
	}
	~Cats()
	{
		//std::cout << "Destructor Cats" << std::endl;
	}
};

int main()
{
	
	Mammals mammals("Mammals");
	mammals.show();
	// mammals.weight = 12; закрытое (private) свойство / метод родителя не доступно неследнику
	//mammals.setWeight(12);


	return 0;
}


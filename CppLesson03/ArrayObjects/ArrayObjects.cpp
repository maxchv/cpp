// ArrayObjects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
class Person
{
	char *fio;
	int age;
public:
	Person() 
	{
		fio = NULL;
		age = 0;
	}
	Person(char *fio, int age)
	{
		this->fio = new char[strlen(fio) + 1];
		strcpy(this->fio, fio);
		this->age = age;
	}
	Person(const Person &orig)
	{
		fio = new char[strlen(orig.fio) + 1];
		strcpy(fio, orig.fio);
		age = orig.age;
	}

	void add_fio(char *fio)
	{
		if (this->fio != NULL)
		{
			delete[] fio;
		}
		this->fio = new char[strlen(fio) + 1];
		strcpy(this->fio, fio);
	}

	char *get_fio()
	{
		return fio;
	}

	void add_age(int age)
	{
		this->age = age;
	}

	int get_age()
	{
		return age;
	}

	Person operator=(const Person& right)
	{
		fio = new char[strlen(right.fio) + 1];
		strcpy(fio, right.fio);
		age = right.age;
		return *this;
	}

	~Person()
	{
		delete[] fio;
	}

	void show()
	{
		cout << fio << " age: " << age << endl;
	}
};

class Apartment
{
	Person *people;
	int n_chamber;
	int n_person;
	int size;
	int num;
public:
	Apartment()
	{
		people = NULL;
		n_chamber = 0;
		n_person = 0;
		size = 0;
	}
	Apartment(int room, int n)
	{
		num = room;
		n_person = n;
		people = new Person[n_person];
		size = 0;
	}

	Apartment(const Apartment &orig)
	{
		num = orig.num;
		n_person = orig.n_person;
		size = orig.size;
		people = new Person[n_person];
		for (int i = 0; i < size; i++)
		{
			//people[i] = orig.people[i];
			people[i].add_fio(orig.people[i].get_fio());
			people[i].add_age(orig.people[i].get_age());
		}
	}

	void copy(const Apartment &orig)
	{
		num = orig.num;
		n_person = orig.n_person;
		size = orig.size;
		if (people)
		{
			delete[] people;
		}
		people = new Person[n_person];
		for (int i = 0; i < size; i++)
		{
			//people[i] = orig.people[i];
			people[i].add_fio(orig.people[i].get_fio());
			people[i].add_age(orig.people[i].get_age());
		}
	}

	~Apartment()
	{
		delete[] people;
	}
	void add_person(Person &new_person)
	{
		if (size < n_person)
		{
			//people[size] = new_person;
			people[size].add_fio(new_person.get_fio());
			people[size].add_age(new_person.get_age());
			size++;
		}
	}

	void show()
	{
		cout << "room " << num << " number of person: " << n_person << endl;
		for (int i = 0; i < size; i++)
		{
			people[i].show();
		}
	}
};

class House
{
	Apartment *apartments;
	char *address;
	int n_apartments;
	int size;
public:
	House()
	{
		apartments = NULL;
		n_apartments = 0;
		address = NULL;
		size = 0;
	}
	House(char *address, int n_apartments)
	{
		this->n_apartments = n_apartments;
		this->address = new char[strlen(address) + 1];
		strcpy(this->address, address);
		apartments = new Apartment[this->n_apartments];
		size = 0;
	}

	House(const House &orig)
	{
		this->n_apartments = orig.n_apartments;
		this->address = new char[strlen(orig.address) + 1];
		strcpy(this->address, address);
		apartments = new Apartment[this->n_apartments];
		size = orig.size;
		for (int i = 0; i < size; i++)
		{
			apartments[i].copy(orig.apartments[i]);
		}
	}
	~House()
	{
		delete[] address;
		delete[] apartments;
	}
	void add_apartment(Apartment &new_apartment)
	{
		if (size < n_apartments)
		{			
			apartments[size].copy(new_apartment);			
			size++;
		}
	}

	void show()
	{
		cout << "House " << address
			<< " number of apartments: " << n_apartments
			<< endl << endl;
		for (int i = 0; i < size; i++)
		{
			apartments[i].show();
			cout << endl;
		}
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	House km("Karla Marksa, 101", 10);

	Apartment room101(101, 3);
	room101.add_person(Person("Ivan Ivanovich Ivanov", 55));
	room101.add_person(Person("Petr Petrovich Petrov", 65));
	room101.add_person(Person("Semen Sevenovich Semenov", 15));
	km.add_apartment(room101);

	Apartment room102(102, 3);
	room102.add_person(Person("Lola Petrovna Ivanova", 15));
	room102.add_person(Person("Nika Petrovich Petrovna", 23));
	room102.add_person(Person("Dina Sevenovich Semenova", 17));
	km.add_apartment(room102);	
	
	km.show();

	return 0;
}


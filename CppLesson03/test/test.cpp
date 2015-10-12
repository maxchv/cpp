// Написал так, не смог придумать как реализовать ввод имени и возроста именно для каждой квартиры

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
	void addApartment(int room, int n)
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
	int get_room(){ return num; }
	Apartment operator=(const Apartment& right)
	{
		n_chamber = right.n_chamber;
		n_person = right.n_person;
		size = right.size;
		num = right.num;
		for (int i = 0; i < n_person; i++)
			people[i] = right.people[i];
		return *this;
	}
};
class home
{
	Apartment*n_ap;
	char*name;
	int size;
public:
	home()
	{
		n_ap = NULL;
		name = NULL;
	}
	home(char *nam, int kol)
	{
		size = kol;
		name = new char[strlen(nam) + 1];
		strcpy(name, nam);
		n_ap = new Apartment[kol];
	}

	home(const home &orig)
	{
		size = orig.size;
		name = new char[strlen(orig.name) + 1];
		strcpy(name, orig.name);
		for (int i = 0; i < size; i++)
			n_ap[i] = orig.n_ap[i];
	}
	~home()
	{
		delete[]n_ap;
		delete[]name;
	}
	void show()
	{
		cout << "name home " << name << " kol apartmetns " << size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "apartmen " << i + 1 << " of " << size << endl;
			n_ap[i].show();
			cout << endl;
		}
	}
	void addApartment(int room, int n)
	{
		for (int i = 0; i < size; i++)
			n_ap[i].addApartment(room, n);
	}
	void add_person(Person &new_person)
	{
		for (int i = 0; i < size; i++)
			n_ap[i].add_person(new_person);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	char num[30];
	cout << "select kol apartmens" << endl;
	cin >> n;
	cout << "select name hom" << endl;
	cin >> num;
	home h1(num, n);
	for (int i = 0; i < 5; i++)
		h1.addApartment(i, 5);
	h1.add_person(Person("Ivan Ivanovich Ivanov", 55));
	h1.add_person(Person("Petr Petrovich Petrov", 35));
	h1.add_person(Person("Vasia Pupkin Vital", 25));
	h1.add_person(Person("Petja Vasichkin Alexandrov", 15));
	h1.add_person(Person("Gena Korolev Genjadievich", 75));


	h1.show();


	return 0;
}




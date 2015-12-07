// 01.Sets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>
using namespace std;

void ex01()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(-1);
	s.insert(-10);
	s.insert(100);

	for (int i = 0; i < 10; i++)
	{
		s.insert(10);
	}

	for (int v : s)
	{
		cout << v << endl;
	}
}

void ex02()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(-1);
	s.insert(-10);
	s.insert(10);
	
	int count = s.count(10); // если существует - возвращает 1
	if (count != 0)
	{
		set<int>::iterator it = s.find(10); // вернет итератор на 10
		s.erase(it); // удалить элемент
	}

	for (int v : s)
	{
		cout << v << endl;
	}
}

void ex03()
{
	multiset<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(-1);
	s.insert(0);
	s.insert(0);
	s.insert(-10);
	s.insert(10);
	s.insert(50);
	s.insert(30);

	for (int v : s)
	{
		cout << v << " ";
	}
	cout << endl;

	// поиск элемента 
	set<int>::iterator l = s.lower_bound(0);
	cout << *l << endl;

	// поиск элемента 
	set<int>::iterator u = s.upper_bound(0);
	cout << *u << endl;
	s.erase(l, u);
	for (int v : s)
	{
		cout << v << " ";
	}
	cout << endl;
}

class Student
{
	string _name;
	int _age;
public:
	Student(string name, int age): _name(name), _age(age)
	{}
	friend ostream& operator<<(ostream &stream, Student& student)
	{
		stream << student._name << " " << student._age;
		return stream;
	}

	bool operator<(const Student& right) const
	{
		return (_name == right._name) ? _age < right._age: _name < right._name;
	}
};

void ex04()
{
	set<Student> group;
	group.emplace("Vasja", 19);
	group.emplace("Petja", 29);
	group.emplace("Mira", 23);
	group.emplace("Lola", 18);
	group.emplace("Arina", 17);
	group.emplace("Arina", 19);

	for (Student s : group)
	{
		cout << s << endl;
	}
}

// предикат - определяет порядок сортировки данных в set
class Comparer
{
public:
	bool operator()(int l, int r) const 
	{
		return l > r;
	}
};

// применение пользовательского порядка сортировки
void ex05()
{
	set<int, Comparer> s;
	for (int i = 0; i < 10; i++)
	{
		s.insert(rand() % 100);
	}
	for (int v : s)
	{
		cout << v << " ";
	}
	cout << endl;
}


int main()
{
	//ex01();
	//ex02();
	//ex03();
	//ex04();
	ex05();

    return 0;
}


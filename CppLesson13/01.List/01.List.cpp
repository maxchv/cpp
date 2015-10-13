// 01.List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

class Student
{
	char name[20]; // им€
	int aver_mark; // средн€€ оценка
public:
	Student *next; // указатель на следующего студента
	Student(char * n, int am)
	{
		next = NULL;
		strcpy(name, n);
		aver_mark = am;
	}
	friend ostream& operator << (ostream& stream, Student &s)
	{
		stream << s.name << " average mark: " << s.aver_mark;
		return stream;
	}	
};

class Group
{
	Student* head; // указатель на список студентов т.е. на первого студента
	Student* tail; // последний студент
	int count;
public:
	Group()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}

	// ƒобавление студента в начало списка
	void AddHeadStudent(char *name, int am)
	{
		// ≈сли список пуст, то добавить первый элемент
		// »наче, доавить пере первым элементом
	}

	// ƒобавление студента в середну после студента с именем after_student
	void InsertAfterStudent(char *after_student, char *name, int am)
	{

	}

	// добавление студента в хвост списка
	void AddStudent(char *name, int am)
	{
		Student* tmp = new Student(name, am); 
		if (head == NULL) // в списке нет студентов
		{
			head = tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
		count++;
	}

	friend ostream& operator<<(ostream& stream, Group &g)
	{
		Student *cur = g.head;
		while (cur != NULL)
		{
			stream << *cur << endl;
			cur = cur->next;
		}

		return stream;
	}
};


void ex01()
{
	Group group;
	group.AddStudent("Lola", 12);
	group.AddStudent("Masha", 11);
	group.AddStudent("Rita", 10);
	cout << group << endl;
}


int main()
{
	ex01();

	return 0;
}


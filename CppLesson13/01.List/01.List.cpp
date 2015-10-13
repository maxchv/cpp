// 01.List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
class Group;
class Student
{
	char name[20]; // имя
	int aver_mark; // средняя оценка
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
	friend class Group;
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

	// Добавление студента в начало списка
	void AddHeadStudent(char *name, int am)
	{
		Student* tmp = new Student(name, am);
		// Если список пуст, то добавить первый элемент
		if (!head)
		{
			head = tail = tmp;
		}
		else // Иначе, доавить пере первым элементом
		{
			tmp->next = head;
			head = tmp;
		}
		count++;
	}

	// Добавление студента в середну после студента с именем after_student
	void InsertAfterStudent(char *after_student, char *name, int am)
	{
		Student* tmp = new Student(name, am);
		// Поиск места вставки т.е. узла за которым вставлять данные
		Student *cur = head;
		while (cur != NULL && strcmp(cur->name, after_student) != 0)
		{
			cur = cur->next;
		}

		if (cur != NULL)
		{	
			tmp->next = cur->next;
			cur->next = tmp;
		}
		else
		{
			AddStudent(name, am);
		}

		count++;
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

	int Size()
	{
		return count;
	}
	// удаление первого студента из списка
	void DeleteHead()
	{

	}
	
	// удаление последнего элемента из списка
	void DeleteTail()
	{
		if (head) // не пуст ли список?
		{
			if (count == 1) // если единственны студент в списке
			{
				delete head;
				head = tail = NULL;
			}
			else
			{
				Student *prev = head;
				while (prev->next->next) // поиск предпоследнего элемента списка
				{
					prev = prev->next;
				}
				if (prev) // найден предпоследний элемент
				{
					delete tail;
					tail = prev;
					tail->next = NULL;
				}
			}
			count--;
		}		
	}

	// удаление студента с именем name
	void DeleteItem(char* name)
	{

	}

	~Group()
	{
		while (head != NULL)
		{			
			Student *next = head->next;
			delete head;
			head = next;
		}
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
	group.AddHeadStudent("Mila", 12);
	group.InsertAfterStudent("Lola", "Rima", 11);
	group.DeleteTail();
	cout << group << endl;
}


int main()
{
	ex01();

	return 0;
}


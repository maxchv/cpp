// 01.List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

class Student
{
	char name[20]; // ���
	int aver_mark; // ������� ������
public:
	Student *next; // ��������� �� ���������� ��������
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
	Student* head; // ��������� �� ������ ��������� �.�. �� ������� ��������
	Student* tail; // ��������� �������
	int count;
public:
	Group()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}

	// ���������� �������� � ������ ������
	void AddHeadStudent(char *name, int am)
	{
		// ���� ������ ����, �� �������� ������ �������
		// �����, ������� ���� ������ ���������
	}

	// ���������� �������� � ������� ����� �������� � ������ after_student
	void InsertAfterStudent(char *after_student, char *name, int am)
	{

	}

	// ���������� �������� � ����� ������
	void AddStudent(char *name, int am)
	{
		Student* tmp = new Student(name, am); 
		if (head == NULL) // � ������ ��� ���������
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


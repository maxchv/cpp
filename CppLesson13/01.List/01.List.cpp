// 01.List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
class Group;
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
	friend class Group;
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
		Student* tmp = new Student(name, am);
		// ���� ������ ����, �� �������� ������ �������
		if (!head)
		{
			head = tail = tmp;
		}
		else // �����, ������� ���� ������ ���������
		{
			tmp->next = head;
			head = tmp;
		}
		count++;
	}

	// ���������� �������� � ������� ����� �������� � ������ after_student
	void InsertAfterStudent(char *after_student, char *name, int am)
	{
		Student* tmp = new Student(name, am);
		// ����� ����� ������� �.�. ���� �� ������� ��������� ������
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

	int Size()
	{
		return count;
	}
	// �������� ������� �������� �� ������
	void DeleteHead()
	{

	}
	
	// �������� ���������� �������� �� ������
	void DeleteTail()
	{
		if (head) // �� ���� �� ������?
		{
			if (count == 1) // ���� ����������� ������� � ������
			{
				delete head;
				head = tail = NULL;
			}
			else
			{
				Student *prev = head;
				while (prev->next->next) // ����� �������������� �������� ������
				{
					prev = prev->next;
				}
				if (prev) // ������ ������������� �������
				{
					delete tail;
					tail = prev;
					tail->next = NULL;
				}
			}
			count--;
		}		
	}

	// �������� �������� � ������ name
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


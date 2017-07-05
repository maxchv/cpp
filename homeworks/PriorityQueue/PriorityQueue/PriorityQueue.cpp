// PriorityQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning(disable: 4996)

class Task
{
	static int count;
	int id;
	char* title;
	char* descr;
	int priority;

public:
	Task()
	{
		title = descr = nullptr;
		priority = 0;
	}

	Task(char* title, char* descr, int priority)
	{
		// FIXME: ����������� �����������
	}

	Task(const Task& task)
	{
		// FIXME: ����������� �����������
	}

	void setTitle(char* title)
	{
		if (this->title != NULL)
		{
			delete[] this->title;
		}
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
	}

	char* getTitle()
	{
		return title;
	}

	// FIXME: ����������� ������� � ������� ��� ��������� �����

	Task& operator=(const Task& right)
	{
		// FIXME: ����������� ��������
	}

	bool operator>(const Task& right)
	{
		// FIXME: ����������� ��������
	}

	bool operator<(const Task& right)
	{
		// FIXME: ����������� ��������
	}

	bool operator==(const Task& right)
	{
		// FIXME: ����������� ��������
	}

	bool operator!=(const Task& right)
	{
		// FIXME: ����������� ��������
	}

	~Task()
	{
		// FIXME: ����������� ����������
	}

	friend ostream& operator<<(ostream& ostream, const Task& task);
};

ostream& operator<<(ostream& stream, const Task& task)
{
	// FIXME: ����������� ��������
}

int Task::count = 0;


class PrioritQueue // ������� � �����������
{
	//Task* tasks;
	unique_ptr<Task[]> tasks;
	int size; // ������ ���������� ������ ��� ������ �����
	int count; // ������ ���������� �������� �������
public:
	PrioritQueue()
	{
		size = 10;
		tasks.reset(new Task[size]); // �������� ������ ��� 10 ��������� � �������
	}

	void add(const Task& new_task)
	{
		// FIXME: ����������� ������ ���������� ������ � tasks
		// ��� ���������� ������ ��������� ������!!!
	}

	Task get()
	{
		// FIXME: ����������� ������ ����������� ������ � ��������� �����������
		// ������ �� ������� ���������!!!
	}

	Task see()
	{
		// FIXME: ����������� ������ ��������� ������ � ��������� �����������
		// ������ �� ������� �� ���������!!!
	}

	bool empty()
	{
		// FIXME: ����������� ������
	}


	friend ostream& operator<<(ostream& ostream, const PrioritQueue& task);
};

ostream& operator<<(ostream& ostream, const PrioritQueue& task)
{
	// FIXME: ����������� ��������
}

void test()
{
	PrioritQueue todoList;
	
	todoList.add(Task("Watch TV", "Home", 3));
	todoList.add(Task("Check homework", "Work", 8));
	todoList.add(Task("Do homework in english", "Work", 5));
	todoList.add(Task("Play game", "Enjoy", 1));

	Task task = todoList.get();
	if (strcmp(task.getTitle(), "Check homework") != 0)
	{
		cerr << "Error check Title" << endl;
	}
	if (task.getPriority() != 8)
	{
		cerr << "Error check Priority" << endl;
	}
	if (strcmp(task.getDescription(), "Work") != 0)
	{
		cerr << "Error check Description" << endl;
	}
	if (task.getId() != 2)
	{
		cerr << "Error check Id" << endl;
	}

	if (strcmp(todoList.see().getTitle(), "Do homework in english") != 0)
	{
		cerr << "Error see new task" << endl;
	}

	if (todoList.see().getId() != 3)
	{
		cerr << "Error check Id" << endl;
	}

	if (strcmp(todoList.get().getTitle(), "Do homework in english") != 0)
	{
		cerr << "Error 3" << endl;
	}

	if (todoList.get().getPriority() != 3)
	{
		cerr << "Error check priority" << endl;
	}
	if (todoList.get().getId() != 1)
	{
		cerr << "Error check priority" << endl;
	}
}

int main()
{
	test();

    return 0;
}


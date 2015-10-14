// 01.DoubleList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
// ���� ������
struct Node // ��� � �����, ��� ���� �� ��������� �������
{
	int data;	// ������
	Node *next; // ��������� �� ��������� ����
	Node *prev; // ��������� �� ���������� ����

	Node(int d = 0) // ����������� �� ���������
	{
		next = prev = NULL;
		data = d;
	}	
};
// ���������� ������
class DList
{
	Node *head;  // ������ ������
	Node *tail;  // ����� ������
	int count;   // ������ ������
public:
	DList() : head(0), tail(NULL), count(0)
	{}

	// ���������� ������ ������
	void AddHead(int data)
	{
		Node *tmp = new Node(data);
		if (!head) // ������ ����
		{
			head = tail = tmp;
		}
		else
		{
			tmp->next = head;
			head->prev = tmp;
			head = tmp;
		}
	}

	// ���������� ������ ������
	void AddTail(int data)
	{

	}

	friend ostream& operator<<(ostream& stream, DList &l)
	{
		Node* cur = l.head;
		while (cur)
		{
			stream << cur->data << " ";
			cur = cur->next;
		}
		stream << endl;
		return stream;
	}
};

void ex01()
{
	DList list;
	list.AddHead(3);
	list.AddHead(2);
	list.AddHead(1);
	cout << list << endl;
}

int main()
{
	ex01();

    return 0;
}


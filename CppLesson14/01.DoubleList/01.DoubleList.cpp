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

	void AddTail(Node *tmp)
	{		
		if (!head) // ������ ����
		{
			head = tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tmp->prev = tail;
			tail = tmp;
		}
	}
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
		AddTail(new Node(data));		
	}

	// ������� �������� ����� �������� after
	void InsertAfter(int after, int data)
	{
		Node* tmp = new Node(data);
		if (!head) // ������ ����
		{
			head = tail = tmp;
		}
		else
		{
			Node* cur = head;
			// ����� ����� �������
			while (cur != NULL && cur->data != after)
			{
				cur = cur->next;				
			}
			
			if (!cur || cur == tail) // ��� ������ ��� ����� ������� - ��������� ������� ������
			{
				AddTail(tmp);
			}
			else // ������� � ��������
			{
				tmp->next = cur->next;
				tmp->prev = cur;
				cur->next = tmp;
				tmp->next->prev = tmp;
			}
		}
	}
	// ����������� ������ � �������� �������
	void showReverse()
	{
		Node* cur = tail;
		while (cur)
		{
			cout << cur->data << " ";
			cur = cur->prev;
		}
		cout << endl;
	}

	// �������� ������ ������
	void DeleteHead()
	{

	}

	// �������� ������ ������
	void DeleteTail()
	{

	}

	// �������� �������� ������ � ������� data
	void DeleteItem(int data)
	{

	}

	// ���������� - ������� ������ ���������� ��� �������� ������
	~DList()
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

	list.AddTail(5);
	list.AddTail(6);
	list.AddTail(7);

	list.InsertAfter(3, 4);

	cout << list << endl;

	list.DeleteHead();
	list.DeleteTail();
	list.DeleteItem(4);

	list.showReverse();
}

int main()
{
	ex01();

    return 0;
}


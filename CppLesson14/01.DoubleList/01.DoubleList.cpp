// 01.DoubleList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
// Узел списка
struct Node // как и класс, все поля по умолчанию открыты
{
	int data;	// данные
	Node *next; // указатель на следующий узел
	Node *prev; // указатель на предыдущий узел

	Node(int d = 0) // конструктор по умолчанию
	{
		next = prev = NULL;
		data = d;
	}	
};
// Двусвязный список
class DList
{
	Node *head;  // голова списка
	Node *tail;  // хвост списка
	int count;   // размер списка
public:
	DList() : head(0), tail(NULL), count(0)
	{}

	// добавление головы списка
	void AddHead(int data)
	{
		Node *tmp = new Node(data);
		if (!head) // список пуст
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

	// Добавление хвоста списка
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


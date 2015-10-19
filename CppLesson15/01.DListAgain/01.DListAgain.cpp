// 01.DListAgain.cpp : Defines the entry point for the console application.
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
	Node *head;		// голова списка
	Node *tail;		// хвост списка
	int	  count;	// размер списка

	void AddTail(Node *tmp)
	{
		if (!head) // список пуст
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

	void showReverse(Node *node)
	{
		if (node)// если node не NULL
		{
			cout << node->data << " ";
			showReverse(node->prev);
		}
		else
		{
			cout << endl;
		}
	}

	void removeAll(Node *node)
	{
		if (node)
		{
			removeAll(node->next);
			delete node;
		}
	}

public:
	DList() : head(NULL), tail(NULL), count(0)
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
		AddTail(new Node(data));
	}

	// вставка элемента после элемента after
	void InsertAfter(int after, int data)
	{
		Node* tmp = new Node(data);
		if (!head) // список пуст
		{
			head = tail = tmp;
		}
		else
		{
			Node* cur = head;
			// Поиск места вставки
			while (cur != NULL && cur->data != after)
			{
				cur = cur->next;
			}

			if (!cur || cur == tail) // нет данных или место вставки - последний элемент списка
			{
				AddTail(tmp);
			}
			else // вставка в середину
			{
				tmp->next = cur->next;
				tmp->prev = cur;
				cur->next = tmp;
				tmp->next->prev = tmp;
			}
		}
	}
	// Отображение списка в обратном порядке используя рекурсию
	void showReverse()
	{
		showReverse(tail); 
		/*Node* cur = tail;
		while (cur)
		{
			cout << cur->data << " ";
			cur = cur->prev;
		}
		cout << endl;*/
	}

	// Удаление головы списка
	void DeleteHead()
	{

	}

	// Удаление хвоста списка
	void DeleteTail()
	{

	}

	// Удаление элемента списка с данными data
	void DeleteItem(int data)
	{

	}

	// Деструктор - очистка памяти выделенной под хранение списка
	~DList()
	{
		removeAll(head);
	}

	
};

int main()
{
	DList list;

	list.AddHead(3);
	list.AddHead(2);
	list.AddHead(1);

	list.AddTail(5);
	list.AddTail(6);
	list.AddTail(7);

	list.InsertAfter(3, 4);

	list.showReverse();

    return 0;
}


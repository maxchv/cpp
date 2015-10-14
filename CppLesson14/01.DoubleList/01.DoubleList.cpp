// 01.DoubleList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
// ”зел списка
struct Node // как и класс, все пол€ по умолчанию открыты
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
// ƒвусв€зный список
class DList
{
	Node *head;  // голова списка
	Node *tail;  // хвост списка
	int count;   // размер списка

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

	// ƒобавление хвоста списка
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
			// ѕоиск места вставки
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
	// ќтображение списка в обратном пор€дке
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

	// ”даление головы списка
	void DeleteHead()
	{

	}

	// ”даление хвоста списка
	void DeleteTail()
	{

	}

	// ”даление элемента списка с данными data
	void DeleteItem(int data)
	{

	}

	// ƒеструктор - очистка пам€ти выделенной под хранение списка
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


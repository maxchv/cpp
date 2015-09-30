// 02.Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// Структура данных FIFO
class Queue
{
	int top, buttom; // индексы вершины и хвоста очереди
	int *queue;
	int size;		 // размер выделенной памяти
	// выделение дополнительной памяти
	void resize(int new_size)
	{
		cout << "Resize: " << new_size << endl;
		int *tmp = new int[new_size];
		// копирование очереди
		for (int i = top; i < buttom; i++)
		{
			tmp[i] = queue[i];
		}
		size = new_size;
		delete[] queue;	   // очищаем память старой очереди
		queue = tmp;
	}

	void reorder()
	{
		cout << "Reorder" << endl;
		int n = buttom - top;
		for (int i = 0; i <= n; i++)
		{
			queue[i] = queue[i + top];
		}
		top = 0;
		buttom = n;
	}
public:
	Queue()
	{
		size = 10;
		top = buttom = 0;
		queue = new int[size];
	}

	~Queue()
	{
		delete[] queue;
	}

	bool empty()
	{
		return top == buttom;
	}

	// вталкивание элемента item в очередь
	void enqueue(int item)
	{
		if (buttom >= size)
		{
			if (top > 0)
			{
				reorder(); // перераспределение очереди
			}
			else
			{
				resize(size + 10);
			}
		}
		queue[buttom++] = item;
	}

	// выталкивание элементов из очереди
	int dequeue()
	{
		return queue[top++];
	} 
};

void ex01()
{
	Queue q;
	for (int i = 0; i < 10; i++)
	{
		q.enqueue(i);
	}
	while (!q.empty())
	{
		cout << q.dequeue() << endl;
	}
	for (int i = 0; i < 10; i++)
	{
		q.enqueue(i);
	}
	while (!q.empty())
	{
		cout << q.dequeue() << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ex01();
	return 0;
}


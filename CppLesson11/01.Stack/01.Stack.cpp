// 01.Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string.h>
#pragma warning(disable: 4996)
// Стек - структура данных реализующая принцип LIFO
//		  Last In First Out
template<typename T>
class Stack
{
	int size;	  // размер стека
	int idx;	  // текущий индекс вершины стека
	T *stack;	  // указатель на динамический массив

	// выделение дополнительной памяти
	void resize(int new_size)
	{
		T *tmp = new T[new_size];
		// копирование стека
		for (int i = 0; i < idx + 1; i++)
		{
			tmp[i] = stack[i];
		}
		size = new_size;
		delete[] stack;	   // очищаем память старого стека
		stack = tmp;
	}
public:
	Stack()
	{
		size = 10;
		idx = -1;
		stack = new T[size];
	}
	Stack(int n)
	{
		size = n;
		idx = -1;
		stack = new T[size];
	}

	// вталкивает элемент item в стек
	void push(T item)
	{
		if (idx >= size - 1)   // если добавляем новый элемент, а памяти не хватает
		{
			resize(size + 10); // добавляем дополнительно память для хранения еще 10 элементов
		}
		stack[++idx] = item;
	}

	// выталкивает вершину стека т.е. последний добавленный элемент
	T pop()
	{
		return stack[idx--];
	}

	// возвращает вершину стека (сохраняет значение в стеке)
	T peek()
	{
		return stack[idx];
	}

	// возвращает true если стек пустой
	bool empty()
	{
		return idx == -1;
	}

	~Stack()
	{
		delete[] stack;
	}
};

void ex01()
{
	Stack<int> stack(20);
	for (int i = 0; i < 15; i++)
	{
		stack.push(i);
	}

	while (!stack.empty())
	{
		cout << stack.pop() << endl;
	}
}
 
int _tmain(int argc, _TCHAR* argv[])
{
	//ex01();
	
	return 0;
}


#pragma once

#include<iostream>

using namespace std;

//При размещении шаблонных методов класса в отдельном файле программа не компилировалась, 
//пришлось перенести все в заголовочный файл

template <typename T> class Stack
{
	int top;
	int size;
	T* stack;
public:
	Stack()
	{
		top = -1;
		size = 10;
		stack = (T*)malloc(sizeof(T) * size);
	}

	~Stack()
	{
		free(stack);
	}

	void push(T item)
	{
		if (top >= size - 1)
		{
			size *= 2;
			stack = (T*)realloc(stack, sizeof(T) * size);
		}
		stack[++top] = item;
	}

	T pop()
	{
		if (top < 0)
			return 0;
		return stack[top--];
	}

	T peek()
	{
		return stack[top];
	}

	bool isEmtpy()
	{
		return top == -1;
	}
};

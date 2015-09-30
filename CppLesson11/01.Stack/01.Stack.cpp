// 01.Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string.h>
#pragma warning(disable: 4996)
// ���� - ��������� ������ ����������� ������� LIFO
//		  Last In First Out
template<typename T>
class Stack
{
	int size;	  // ������ �����
	int idx;	  // ������� ������ ������� �����
	T *stack;	  // ��������� �� ������������ ������

	// ��������� �������������� ������
	void resize(int new_size)
	{
		T *tmp = new T[new_size];
		// ����������� �����
		for (int i = 0; i < idx + 1; i++)
		{
			tmp[i] = stack[i];
		}
		size = new_size;
		delete[] stack;	   // ������� ������ ������� �����
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

	// ���������� ������� item � ����
	void push(T item)
	{
		if (idx >= size - 1)   // ���� ��������� ����� �������, � ������ �� �������
		{
			resize(size + 10); // ��������� ������������� ������ ��� �������� ��� 10 ���������
		}
		stack[++idx] = item;
	}

	// ����������� ������� ����� �.�. ��������� ����������� �������
	T pop()
	{
		return stack[idx--];
	}

	// ���������� ������� ����� (��������� �������� � �����)
	T peek()
	{
		return stack[idx];
	}

	// ���������� true ���� ���� ������
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


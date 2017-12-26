#pragma once

#include<iostream>

#include"Stack.h"

using namespace std;

class MathEval
{
	Stack<double> args;
	Stack<char> ops;
	double solution;
	bool isOK;
	void do_operation();
	int get_priority(char c);
public:
	MathEval(char* equation);
	double eval();
	bool isSolved();
};


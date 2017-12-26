#include<iostream>

#include"MathEval.h"
#include"Stack.h"

using namespace std;

void main()
{
	MathEval eval("3+4-6/2");
	cout << eval.eval() << endl;
}
#include "MathEval.h"



MathEval::MathEval(char* equation)
{
	enum {NUMBER, OPERATOR, PRIORITY} last_added = OPERATOR;
	isOK = false;
	int i = 0;
	int level = 0;
	int length = strlen(equation);
	while (i < length)
	{
		if (isblank(equation[i]))						//Пробелы игнорируются
		{
			i++;
			continue;
		}
		if (isdigit(equation[i]))
		{
			if (last_added == NUMBER)					//Ошибка - пропущенный оператор
				return;
			args.push(atof(&equation[i]));
			last_added = NUMBER;
			do
			{
				i++;
			} while (i < length && (isdigit(equation[i]) || equation[i] == '.'));
			continue;
		}
		if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/') 
		{
			if ((last_added == PRIORITY && ops.peek() == '(') || last_added == OPERATOR)		//Проверка на пропущенное число
			{
				if (equation[i] == '+' || equation[i] == '-')		//Унарный + или -
				{
					if (equation[i] == '+')					//Выражение 1+-2 интерпертируется как 1+(-1)*2
						args.push(1);
					if (equation[i] == '-')
						args.push(-1);
					ops.push('*');
					i++;
					continue;
				}
				else
				{
					return;						//Ошибка - пропущенное число
				}
			}
			
			while (!ops.isEmtpy() && get_priority(ops.peek()) >= get_priority(equation[i]))
			{
				do_operation();
			}
			ops.push(equation[i]);
			last_added = OPERATOR;
			i++;
			continue;
		}
		if (equation[i] == '(') 
		{
			if (last_added == NUMBER)		//Выражение 2(1+3) интерпретируется как 2*(1+3)
				ops.push('*');
			ops.push(equation[i]);
			i++;
			level++;
			continue;
		}
		if (equation[i] == ')')
		{
			if (last_added == OPERATOR)		//Ошибка - пропущенное число перед закрывающей скобкой
				return;
			level--;
			if (level < 0)					//Ошибка -  лишняя закрывающая скобка
				return;
			while (ops.peek() != '(')
			{
				do_operation();
			}
			ops.pop();
			i++;
			continue;
		}
		return;						//Ошибка - не предусмотренный символ
	}
	if (level)						//Ошибка - не хватает закрывающих скобок
		return;
	while (!ops.isEmtpy())
	{
		do_operation();
	}
	solution = args.pop();
	if (args.isEmtpy())
		isOK = true;
}

void MathEval::do_operation()
{
	double la, ra;
	ra = args.pop();
	la = args.pop();
	switch (ops.pop())
	{
	case '+':
		args.push(la + ra);
		break;
	case '-':
		args.push(la - ra);
		break;
	case '*':
		args.push(la * ra);
		break;
	case '/':
		args.push(la / ra);
		break;
	}
}

int MathEval::get_priority(char c)
{
	switch (c)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '(':
		return 0;
	case ')':
		return 3;
	}
}

double MathEval::eval()
{
	return solution;
}

bool MathEval::isSolved()
{
	return isOK;
}


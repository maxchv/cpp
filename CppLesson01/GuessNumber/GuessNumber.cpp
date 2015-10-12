// GuessNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void game()
{
	int num = rand() % 100 + 1;
	int guess;
	int count = 0;
	do
	{
		cout << "����� ����� [1..100]: ";
		cin >> guess;
		if (guess > num)
		{
			cout << "���������� ����� ������. ��������� ���" << endl;
		}
		else if (guess < num)
		{
			cout << "���������� ����� ������. ��������� ���" << endl;
		}
		else
		{
			cout << "��, ��� ����� " << num << endl;
		}
		count++;
	} while (guess != num);
	cout << "�� ������ ����� � " << count << " �������" << endl;
}

class Point
{
	char* name;
private: // ��������
	int x, y;
protected: // ����������
public:	// ��������	
	void set_x(int i) { x = i; }
	void set_y(int i) { y = i; }
	int get_x() { return x;  }
	int get_y() { return y; }

	void input()
	{
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
	}

	void show() // ����� 
	{
		cout << "x: " << x
			<< " y: " << y << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	//setlocale(LC_ALL, "russian");
	//srand(time(NULL));
	//game();

	/*int i = 0;
	{
		cout << i << endl;
		int i = 1;
		{
			cout << i << endl;
			int i = 2;
			cout << i << endl;
		}
		cout << i << endl;
	}
	cout << i << endl;*/

	Point p1;
	/*p1.x = 10;
	p1.y = 20;
	p1.z = 20;*/
	p1.set_x(10);
	p1.set_y(20);

	cout << p1.get_x() << endl;

	p1.input();
	Point p2;
	p2.input();

	cout << "p1:" << endl;
	p1.show();

	cout << "p2:" << endl;
	p2.show();
	

	return 0;
}


// 01.Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Animal
{	
private:
	double weight; // ���
protected:
	char* kind;    // ���
	char* name;    // ��������
public:	
	Animal()
	{
	}
	void setWeight(double w)
	{
		weight = w;
	}
	double getWeight()
	{
		return weight;
	}
};

class Mammals : protected Animal
{
public:
	bool drink_milk;
	Mammals()
	{
		drink_milk = true;
		kind = "Mammals";
		setWeight(16);
	}
	void show()
	{
		
	}
};

class Cats : public Mammals
{
public:
	Cats()
	{
		show();
		setWeight(10);
	}
};

int main()
{
	Animal animal;
	
	Mammals mammals;
	// mammals.weight = 12; �������� (private) �������� / ����� �������� �� �������� ����������
	//mammals.setWeight(12);
	

    return 0;
}


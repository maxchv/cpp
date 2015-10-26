// 02.HomeWork17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
using namespace std;
#pragma warning(disable: 4996)

class Shape
{
public:	
	static Shape** Load(char *file);
	virtual void Save(char *file) = 0;
	virtual void Show() = 0;
	virtual ~Shape() = 0;
};
Shape::~Shape(){}

class Circle: public Shape
{
	double radius;
public:
	Circle(double r)
	{
		radius = r;
	}
	// Inherited via Shape
	virtual void Save(char * file) override
	{
		FILE *f = fopen(file, "a"); // открытие файла на добавление
		if (f)
		{
			fprintf(f, "c %g\n", radius);
			fclose(f);
		}
	}
	virtual void Show() override
	{
		cout << "Circle. Radius: " << radius << endl;
	}
};

class Rectangle : public Shape
{
	double height;
	double width;
public:
	Rectangle(double h, double w)
	{
		height = h;
		width = w;
	}
	// Inherited via Shape
	virtual void Save(char * file) override
	{
		FILE *f = fopen(file, "a"); // открытие файла на добавление
		if (f)
		{
			fprintf(f, "r %g %g\n", height, width);
			fclose(f);
		}
	}
	virtual void Show() override
	{
		cout << "Rectangle. Height: " << height << " Width: " << width << endl;
	}
};

class Ellipse : public Shape
{
	double height;
	double width;
public:
	Ellipse(double h, double w)
	{
		height = h;
		width = w;
	}
	// Inherited via Shape
	virtual void Save(char * file) override
	{
		FILE *f = fopen(file, "a"); // открытие файла на добавление
		if (f)
		{
			fprintf(f, "e %g %g\n", height, width);
			fclose(f);
		}
	}
	virtual void Show() override
	{
		cout << "Ellipse. Height: " << height << " Width: " << width << endl;
	}
};

class Square : public Shape
{
	double lengh;
public:
	Square(double l)
	{
		lengh = l;
	}
	// Inherited via Shape
	virtual void Save(char * file) override
	{
		FILE *f = fopen(file, "a"); // открытие файла на добавление
		if (f)
		{
			fprintf(f, "s %g\n", lengh);
			fclose(f);
		}
	}
	virtual void Show() override
	{
		cout << "Square. Length: " << lengh << endl;
	}
};


Shape** Shape::Load(char * file)
{
	Shape** shapes = nullptr;		
	FILE* f = fopen(file, "r");
	int count = 0; // количество строк в файле
	if (f)
	{
		while (!feof(f))
		{
			if (fgetc(f) == '\n') // 
			{
				count++;
			}
		}

		rewind(f); // переход на начало файла
		shapes = new Shape*[count]; // выделяем память под хранение count элементов	
		int i = 0;
		while (!feof(f))
		{
			char name = fgetc(f);
			if (name == 'c') // это окружность
			{
				double radius;
				fscanf(f, "%lf", &radius);
				shapes[i] = new Circle(radius);
			}
			else if (name == 'r')
			{
				double h, w;
				fscanf(f, "%lf %lf", &h, &w);
				shapes[i] = new Rectangle(h, w);
			}
			else if (name == 'e')
			{
				double h, w;
				fscanf(f, "%lf %lf", &h, &w);
				shapes[i] = new Ellipse(h, w);
			}
			else if (name == 's')
			{
				double length;
				fscanf(f, "%lf", &length);
				shapes[i] = new Square(length);
			}
			else
			{
				continue;
			}
			i++;
		}
		fclose(f);
	}
	return shapes;
}

int main()
{
	/*Shape* shapes[4] = { new Circle(10),
						 new Rectangle(5, 6),
						 new Square(15),
						 new Ellipse(2, 12) };*/
	char *file = "shapes.txt";
	//// очищаем файл перед записью
	//FILE* f = fopen(file, "w");
	//fclose(f);
	//
	//for (int i = 0; i < 4; i++)
	//{
	//	shapes[i]->Show();
	//	shapes[i]->Save(file);
	//}

	Shape** s = Shape::Load(file);
	for (int i = 0; i < 4; i++)
	{
		s[i]->Show();
	}

    return 0;
}




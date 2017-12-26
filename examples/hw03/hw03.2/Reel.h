#pragma once

#include<iostream>

using namespace std;

class Reel
{
	int position;
	int size;
public:
	Reel() = default;
	Reel(int size);
	void Rotate();
	int getPrevious();
	int getPosition();
	int getNext();
};


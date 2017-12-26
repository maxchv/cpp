#include "Reel.h"

Reel::Reel(int size) : size(size)
{
	position = rand() % size;
}

void Reel::Rotate()
{
	++position %= size;
}

int Reel::getPrevious()
{
	return (size + position - 1) % size;
}

int Reel::getPosition()
{
	return position;
}

int Reel::getNext()
{
	return (position + 1) % size;
}

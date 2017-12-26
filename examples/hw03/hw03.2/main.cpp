#include<iostream>


#include"SlotMachine.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	const int reel_count = 3;
	const char slot_symbols[] = "1+@#%&$7";
	SlotMachine sm(reel_count, slot_symbols);
	sm.Play();
	
	

}
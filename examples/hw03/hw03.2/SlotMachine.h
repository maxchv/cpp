#pragma once

#include<iostream>
#include<time.h>
#include<conio.h>
#include"Reel.h"

using namespace std;

class SlotMachine
{
	int reel_count;
	Reel* reels;
	int slot_count;
	char* slots;
	int score;
	int last_score;
	void Show();
	void Spin();
public:
	SlotMachine(const int reel_count, const char* symbols, int start_score = 10);
	void Play();
	~SlotMachine();
};


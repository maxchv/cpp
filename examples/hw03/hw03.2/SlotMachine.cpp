#include "SlotMachine.h"



SlotMachine::SlotMachine(const int reel_count, const char* symbols, int start_score) 
	: reel_count(reel_count), score(start_score)
{
	srand(time(0));
	last_score = -1;
	slot_count = strlen(symbols);
	slots = (char*)malloc(sizeof(char)*(slot_count + 1));
	strcpy(slots, symbols);
	reels = new Reel[reel_count];
	for (int i = 0; i < reel_count; i++)
		reels[i] = Reel(slot_count);
}

void SlotMachine::Show()
{
	system("cls");
	cout << "Деньги: " << score << " $" << endl;
	cout << endl;
	for (int i = 0; i < reel_count; i++)
	{
		cout << "\t" << slots[reels[i].getPrevious()];
	}
	cout << endl;
	cout << "->";
	for (int i = 0; i < reel_count; i++)
	{
		cout << "\t" << slots[reels[i].getPosition()];
	}
	cout << endl;
	for (int i = 0; i < reel_count; i++)
	{
		cout << "\t" << slots[reels[i].getNext()];
	}
	cout << endl;
}

void SlotMachine::Spin()
{
	const int rotate_count_min = 20;
	const int rotate_count_rand_max = 40;
	int *rotate_count = new int[reel_count];
	for (int i = 0; i < reel_count; i++)
	{
		rotate_count[i] = rand() % rotate_count_rand_max + rotate_count_min;
	}
	bool rotate;
	do
	{
		rotate = false;
		for (int i = 0; i < reel_count; i++)
		{
			if (rotate_count[i])
			{
				rotate_count[i]--;
				reels[i].Rotate();
				rotate = true;
			}
		}
		Show();
		_sleep(50);
	} while (rotate);
	int *count = (int*)calloc(slot_count , sizeof(int));
	for (int i = 0; i < reel_count; i++)
	{
		count[reels[i].getPosition()]++;
	}
	last_score = 0;
	for (int i = 0; i < slot_count; i++)
	{
		if (count[i] == reel_count)
		{
			last_score = pow(reel_count, i + 3) / (i + 1);
			break;
		}
		if (count[i] == reel_count - 1)
		{
			last_score = pow(reel_count - 1, i) / (i + 1);
			break;
		}
	}
	free(count);
	score += last_score;	
}

void SlotMachine::Play()
{
	char key;
	bool new_game = true;
	do
	{		
		Show();
		if (last_score >= 0)
			cout << "Выигрыш: " << last_score << " $" << endl;
		if (score)
		{
			cout << "Нажмите любую кнопку для новой игры (-1 $)" << endl;
			cout << "Esc - Выход" << endl;
			key = getch();
			if (key == 27)
			{
				new_game = false;
				system("cls");
				cout << "Выход" << endl;
			}
			else
			{
				score--;
				Spin();
			}
		}
		else
		{
			cout << "Закончились деньги (" << endl;
			cout << "Нажмите любую кнопку для выхода" << endl;
			new_game = false;
		}
	} while (new_game);
}

SlotMachine::~SlotMachine()
{
	free(slots);
	delete[] reels;
}

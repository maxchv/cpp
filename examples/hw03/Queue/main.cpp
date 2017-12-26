#include<iostream>

using namespace std;


class queue
{
	int idx_head;
	int idx_tail;
	int count = 10;
	int* arr;
public:
	queue() : idx_head(-1), idx_tail(-1) 
	{
		arr = (int*)malloc(sizeof(int)*count);
	}

	~queue()
	{
		free(arr);
	}

	void enqueue(int item)
	{
		if (idx_tail >= count - 1)
			if (idx_head > 0)
			{
				// устранить дырки в начале массива
				// домашнее задание
				for (int i = idx_head; i < count; i++)
				{
					arr[i - idx_head] = arr[i];
				}
				idx_tail -= idx_head + 1;
				idx_head = -1;
			}
			else
			{
				count *= 2;
				arr = (int*)realloc(arr, sizeof(int) * count);
			}
		arr[++idx_tail] = item;
	}

	int dequeue()
	{
		return arr[++idx_head];
	}

	int peek()
	{
		return arr[idx_head];
	}

	bool empty()
	{
		return idx_tail < 0 || idx_tail == idx_head;
	}
};

int main()
{
	queue q;
	for (int i = 0; i < 20; i++)
	{
		q.enqueue(i);
	}

	while (!q.empty())
	{
		cout << q.dequeue() << endl;
	}
	
	return 0;
}
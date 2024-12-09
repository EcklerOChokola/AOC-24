#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	string input;
	cin >> input;
	vector<int> blocks = vector(100000, -1);
	int last = 0;
	char free = 0;
	for(int i = 0; i < input.size(); i++)
	{
		int value = input[i] - '0';
		if(!free)
			for(int j = 0; j < value; j++)
				blocks[last + j] = i / 2;
		last += value;
		free = !free;
	}

	int max = last - 1;
	unsigned long long part_1 = 0;
	for(int min = 0; min <= max; min++)
	{
		if(blocks[min] == -1)
		{
			while(blocks[max] == -1) max--;
			part_1 += min * blocks[max];
			max--;
		}
		else
			part_1 += min * blocks[min];
	}
	int min = 0;
	for(max = last - 1; min <= max;)
	{
		while(blocks[min] != -1) min++;
		if(blocks[max] == -1) {
			max--;
			continue;
		}
		int size = 0;
		while(max - size >= 0 && blocks[max - size] == blocks[max]) size++;
		for(int i = 0; i < max;)
		{
			while(blocks[i] != -1) i++;
			if(i > max) 
			{
				max -= size;
				break;
			}
			int space = 0;
			while(blocks[i + space] == -1) space++;
			if(space < size)
				i += space;
			else
			{
				for(int j = 0; j < size; j++)
				{
					blocks[i + j] = blocks[max];
					blocks[max] = -1;
					max--;
				}
				break;
			}
		}
	}

	unsigned long long part_2 = 0;
	for(int i = 0; i < last; i++)
		part_2 += ((blocks[i] == -1) ? 0 : i * blocks[i]);

	cout << part_1 << '\n' << part_2 << '\n';

	return 0;
}




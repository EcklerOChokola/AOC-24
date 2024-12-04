#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int d_x[8] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int d_y[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

char letters[4] = { 'X', 'M', 'A', 'S' };

int is_letter(vector<string>* input, char c, int x, int y)
{
	if (x < 0 || y < 0 || x >= (*input).size() || y >= (*input).size()) return 0;
	return (*input)[x][y] == c;
}

int count_xmas(vector<string>* input, int x, int y)
{
	if((*input)[x][y] != 'X') return 0;
	int count = 0;
	for(int i = 0; i < 8; i++)
		if(is_letter(input, letters[1], x + d_x[i], y + d_y[i]) && is_letter(input, letters[2], x + (2 * d_x[i]), y + (2 * d_y[i])) && is_letter(input, letters[3], x + (3 * d_x[i]), y + (3 * d_y[i]))) count++;
	return count;
}

int is_x_mas(vector<string>* input, int x, int y)
{
	if((*input)[x][y] != 'A') return 0;

	for(int i = 4; i < 6; i++)
	{
		if(is_letter(input, 'M', x + d_x[i], y + d_y[i]) && is_letter(input, 'S', x - d_x[i], y - d_y[i]))
		{
			if(is_letter(input, 'M', x + d_x[i + 2], y + d_y[i + 2]) && is_letter(input, 'S', x - d_x[i + 2], y - d_y[i + 2])) return 1;
			if(is_letter(input, 'S', x + d_x[i + 2], y + d_y[i + 2]) && is_letter(input, 'M', x - d_x[i + 2], y - d_y[i + 2])) return 1;
		}
	}

	return 0;
}


int main(void)
{
	vector<string> input;
	
	while (true)
	{
		string line;
		getline(cin, line);
		if (line.empty()) break;
		input.push_back(line);
	}

	int part_1 = 0;
	int part_2 = 0;
	for(int i = 0; i < input.size(); i++)
		for(int j = 0; j < input[i].size(); j++)
		{
			part_1 += count_xmas(&input, i, j);
			part_2 += is_x_mas(&input, i, j);
		}

	cout << part_1 << '\n' << part_2 << '\n';

	return 0;
}

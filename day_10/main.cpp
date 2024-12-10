#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	string line;
	int height = 0;
	int width = 0;
	vector<vector<int>> input;
	vector<pair<int, int>> starts;
	while(getline(cin, line))
	{
		if(line.empty()) continue;
		vector<int> input_line;
		for(int i = 0; i < line.size(); i++)
		{
			int value = line[i] - '0';
			input_line.push_back(value);
			if(!value) starts.push_back(pair(height, i));
		}
		input.push_back(input_line);
		height++;
		width = line.size();
	}

	map<pair<int, int>, vector<pair<int, int>>> edges;
	for(int i = 0; i < input.size(); i++)
		for(int j = 0; j < input[i].size(); j++)
		{
			int value = input[i][j];
			vector<pair<int, int>> adj;
			if(i > 0 && value + 1 == input[i - 1][j]) adj.push_back(pair(i - 1, j));
			if(j > 0 && value + 1 == input[i][j - 1]) adj.push_back(pair(i, j - 1));
			if(i < input.size() - 1 && value + 1 == input[i + 1][j]) adj.push_back(pair(i + 1, j));
			if(j < input[i].size() - 1 && value + 1 == input[i][j + 1]) adj.push_back(pair(i, j + 1));
			edges[pair(i,j)] = adj;
		}

	int part_1 = 0;
	int part_2 = 0;
	for(auto& s : starts)
	{
		stack<pair<int, int>> to_visit;
		to_visit.push(s);
		set<pair<int, int>> ends;
		while(!to_visit.empty())
		{
			pair<int, int> pos = to_visit.top();
			to_visit.pop();
			if(input[pos.first][pos.second] == 9)
			{
				part_2++;
				ends.insert(pos);
			}
			else
				for(auto& adj : edges[pos])
					to_visit.push(adj);
		}
		part_1 += ends.size();
	}

	cout << part_1 << '\n' << part_2 << '\n';

	return 0;
}


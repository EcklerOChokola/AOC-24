#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
#include<vector>
#include<regex>

using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void)
{
	vector<string> input;
	pair<int,int> pos;
	string line;
	int idx = 0;
	while(getline(cin, line))
	{
		if(line.empty()) break;
		input.push_back(line);
		if(line.rfind("^") != string::npos)
			pos = pair(idx, line.rfind("^"));
		idx++;
	}
	pair<int,int> startpos = pos;

	vector<vector<int>> visited(input.size(), vector(input[0].size(), 0));
	vector<pair<int,int>> presses;

	int dir = UP;
	int nobstacles = 0;
	while(pos.first >= 0 && pos.first < input.size() && pos.second >= 0 && pos.second < input[0].size())
	{
		visited[pos.first][pos.second] = 1;
		pair<int,int> n_pos = pair(pos.first + dx[dir], pos.second + dy[dir]);
		if(n_pos.first < 0 || n_pos.first >= input.size() || n_pos.second < 0 || n_pos.second >= input[0].size()) break;
		if(input[n_pos.first][n_pos.second] == '#')
		{
			dir = (dir + 1) % 4;
			n_pos = pair(pos.first + dx[dir], pos.second + dy[dir]);
		}
		pos = n_pos;
	}
	
	int part_1 = 0;
	for(auto& v : visited)
		part_1 += accumulate(v.begin(), v.end(), 0);

	for(int i = 0; i < input.size(); i++)
	for(int j = 0; j < input[i].size(); j++)
	if(input[i][j] == '.' && visited[i][j])
	{
		pair<int,int> pos = startpos;
		int dir = UP;
		vector<pair<pair<int,int>,int>> visited(1, pair(pos,dir));
		input[i][j] = '#';
		while(pos.first >= 0 && pos.first < input.size() && pos.second >= 0 && pos.second < input[0].size())
		{
			pair<int,int> npos(pos.first + dx[dir], pos.second + dy[dir]);
			if(npos.first < 0 || npos.first >= input.size() || npos.second < 0 || npos.second >= input[0].size()) break;
			if(input[npos.first][npos.second] == '#') dir = (dir + 1) % 4;
			else pos = npos;
			if(find(visited.begin(), visited.end(), pair(npos, dir)) == visited.end()) visited.push_back(pair(npos,dir));
			else
			{
				nobstacles++;
				break;
			}
		}
		input[i][j] = '.';
	}

	cout << part_1 << '\n' << nobstacles << '\n';

	return 0;
}
	

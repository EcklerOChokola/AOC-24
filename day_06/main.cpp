#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#if defined(_OPENMP)
	#include<omp.h>
#endif

using namespace std;

#define UP 0

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void)
{
	#if defined(_OPENMP)
		omp_set_num_threads(omp_get_max_threads());
	#endif
	vector<string> input;
	pair<int,int> pos;
	string line;
	int idx = 0;
	while(getline(cin, line))
	{
		if(line.empty()) break;
		input.push_back(line);
		int s = line.rfind("^");
		if(s != string::npos)
			pos = pair(idx, s);
		idx++;
	}
	int sz = input.size();
	pair<int,int> startpos = pos;

	vector<vector<int>> visited(sz, vector(sz, 0));

	int dir = UP;
	int nobstacles = 0;
	while(pos.first >= 0 && pos.first < sz && pos.second >= 0 && pos.second < sz)
	{
		visited[pos.first][pos.second] = 1;
		pair<int,int> n_pos = pair(pos.first + dx[dir], pos.second + dy[dir]);
		if(n_pos.first < 0 || n_pos.first >= sz || n_pos.second < 0 || n_pos.second >= sz) break;
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

	for(int i = 0; i < sz; i++)
	#pragma omp parallel for
	for(int j = 0; j < sz; j++)
	if(input[i][j] == '.' && visited[i][j])
	{
		vector<string> ninput;
		for(auto& s : input) ninput.push_back(string(s));
		pair<int,int> pos = startpos;
		int dir = UP;
		vector<pair<pair<int,int>,int>> visited(1, pair(pos,dir));
		ninput[i][j] = '#';
		while(pos.first >= 0 && pos.first < sz && pos.second >= 0 && pos.second < sz)
		{
			pair<int,int> npos(pos.first + dx[dir], pos.second + dy[dir]);
			if(npos.first < 0 || npos.first >= sz || npos.second < 0 || npos.second >= sz) break;
			if(ninput[npos.first][npos.second] == '#') dir = (dir + 1) % 4;
			else pos = npos;
			if(find(visited.begin(), visited.end(), pair(npos, dir)) == visited.end()) visited.push_back(pair(npos,dir));
			else
			{
				nobstacles++;
				break;
			}
		}
		ninput[i][j] = '.';
	}

	cout << part_1 << '\n' << nobstacles << '\n';

	return 0;
}
	

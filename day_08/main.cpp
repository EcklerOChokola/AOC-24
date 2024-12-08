#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main(void)
{
	string line;
	int x = 0;
	int cols = 0;
	map<char, vector<pair<int, int>>> antennas;
	while(getline(cin, line))
	{
		if(line.empty()) break;
		for(int y = 0; y < line.size(); y++)
		{
			if(line[y] == '.') continue;
			if(antennas.count(line[y]))
				antennas[line[y]].push_back(pair(x, y));
			else antennas[line[y]] = vector(1, pair(x, y));
		}
		x++;
		cols = line.size();
	}
	vector<vector<int>> antinodes(x, vector(cols, 0));
	vector<vector<int>> AntiNodes(x, vector(cols, 0));
	for(auto& antenna : antennas)
	{
		vector<pair<int, int>> positions = antenna.second;
		for(int i = 0; i < positions.size() - 1; i++)
			for(int j = i + 1; j < positions.size(); j++)
			{
				pair<int, int> f = positions[i];
				pair<int, int> s = positions[j];
				AntiNodes[f.first][f.second] = 1;
				AntiNodes[s.first][s.second] = 1;
				int dx = s.first - f.first;
				int dy = s.second - f.second;
				pair<int, int> F = pair(f.first - dx, f.second - dy);
				if(F.first >= 0 && F.first < x && F.second >= 0 && F.second < cols) antinodes[F.first][F.second] = 1;
				pair<int, int> S = pair(s.first + dx, s.second + dy);
				if(S.first >= 0 && S.first < x && S.second >= 0 && S.second < cols) antinodes[S.first][S.second] = 1;
				while(F.first >= 0 && F.first < x && F.second >= 0 && F.second < cols)
				{
					AntiNodes[F.first][F.second] = 1;
					F = pair(F.first - dx, F.second - dy);
				}
				while(S.first >= 0 && S.first < x && S.second >= 0 && S.second < cols)
				{
					AntiNodes[S.first][S.second] = 1;
					S = pair(S.first + dx, S.second + dy);
				}
			}
	}

	int part_1 = 0;
	for(auto& a : antinodes)
		part_1 += accumulate(a.begin(), a.end(), 0);

	cout << part_1 << '\n';
	
	int part_2 = 0;
	for(auto& a : AntiNodes)
		part_2 += accumulate(a.begin(), a.end(), 0);

	cout << part_2 << '\n';
	
	return 0;
}

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main(void)
{
	vector<string> map;
	string line;
	while(getline(cin, line))
	{
		if(line.empty()) break;
		map.push_back(line);
	}
	vector<vector<int>> visited(map.size(), vector(map[0].size(), 0));
	int part_1 = 0;
	int part_2 = 0;
	for(int i = 0; i < map.size(); i++)
		for(int j = 0; j < map[i].size(); j++)
		{
			if(visited[i][j]) continue;
			int region_area = 0, region_perimeter = 0;
			stack<pair<int, int>> positions;
			vector<vector<int>> region(visited.size() + 2, vector(visited[i].size() + 2, 0));
			positions.push(pair(i, j));
			while(!positions.empty())
			{
				pair<int, int> position = positions.top();
				positions.pop();
				if(visited[position.first][position.second]) continue;
				visited[position.first][position.second] = 1;
				region[position.first + 1][position.second + 1] = 1;
				region_area++;
				region_perimeter += 4;
				for(int k = 0; k < 4; k++)
				{
					pair<int, int> new_position = pair(position.first + dx[k], position.second + dy[k]);
					if(new_position.first >= 0 && new_position.first < map.size() && new_position.second >= 0 && new_position.second < map[i].size() && map[position.first][position.second] == map[new_position.first][new_position.second])
					{
						positions.push(pair(new_position.first, new_position.second));
						region_perimeter--;
					}
				}
			}
			int region_cost_1 = region_area * region_perimeter;
			part_1 += region_cost_1;
			int sides = 0;
			for(int k = 0; k < region.size() - 1; k++)
			{
				vector<int> current_line = region[k];
				vector<int> next_line = region[k + 1];
				int diff = next_line[0] - current_line[0];
				if(diff) sides++;
				for(int l = 1; l < current_line.size(); l++)
				{
					int new_diff = next_line[l] - current_line[l];
					if(diff == new_diff) continue;
					diff = new_diff;
					if(diff) sides++;
				}
			}
			for(int k = 0; k < region[0].size() - 1; k++)
			{
				vector<int> current_col, next_col;
				for(int l = 0; l < region.size(); l++)
				{
					current_col.push_back(region[l][k]);
					next_col.push_back(region[l][k + 1]);
				}
				int diff = next_col[0] - current_col[0];
				if(diff) sides++;
				for(int l = 1; l < current_col.size(); l++)
				{
					int new_diff = next_col[l] - current_col[l];
					if(diff == new_diff) continue;
					diff = new_diff;
					if(diff) sides++;
				}
			}
			int region_cost_2 = sides * region_area;
			part_2 += region_cost_2;
		}
	cout << part_1 << endl << part_2 << endl;
	return 0;
}


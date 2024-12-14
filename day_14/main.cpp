#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Used to compute the position of the robots after k steps
pair<int, int> elapse(
		pair<pair<int, int>, pair<int, int>> robot,
		int k,
		int width,
		int height
		)
{
	int px = robot.first.first;
	int py = robot.first.second;
	int vx = robot.second.first;
	int vy = robot.second.second;
	px += vx * k;
	py += vy * k;
	px = ((px % width) + width) % width;
	py = ((py % height) + height) % height;
	return pair(px, py);
}

// Computes safety factor based on the positions
int score(vector<pair<int, int>> positions, int width, int height)
{
	int a, b, c, d;
	a = b = c = d = 0;
	for(auto& pos : positions)
	{
		int px = pos.first;
		int py = pos.second;
		if(px < width / 2 && py < height / 2) a++;
		if(px < width / 2 && py > height / 2) b++;
		if(px > width / 2 && py < height / 2) c++;
		if(px > width / 2 && py > height / 2) d++;
	}
	return a * b * c * d;
}

int main(int argc, char** argv)
{
	if(argc < 3)
	{
		cout << "Provide X and Y sizes for the grid (11 7 for sample and 101 103 for input) and 0 if you do not want to display the image for part 2\n";
		return 1;
	}
	int width, height, display = 1;
	stringstream(argv[1]) >> width;
	stringstream(argv[2]) >> height;
	if(argc > 3 && string(argv[3]) == "0") display = 0;

	string line;
	regex junk("(?:[pv]=)|,");
	int a, b, c, d;
	a = b = c = d = 0;
	vector<pair<pair<int, int>, pair<int, int>>> robots;
	while(getline(cin, line))
	{
		if(line.empty()) continue;
		line = regex_replace(line, junk, " ");
		pair<pair<int, int>, pair<int, int>> robot;
		stringstream(line) >> robot.first.first >> robot.first.second >> robot.second.first >> robot.second.second;
		robots.push_back(robot);
	}

	vector<pair<int, int>> elapsed;
	for(auto& robot : robots)
		elapsed.push_back(elapse(robot, 100, width, height));
	int part_1 = score(elapsed, width, height);
	cout << part_1 << endl;
	
	for(int k = 1; k < width * height * robots.size(); k++)
	{
		vector<pair<int, int>> next_robots;
		vector<vector<int>> occupied(height, vector(width, 0));
		for(auto& robot : robots)
		{
			auto pos = elapse(robot, k, width, height);
			occupied[pos.second][pos.first]++;
			next_robots.push_back(pos);
		}
		int s = score(next_robots, width, height);
		int c = 0;
		for(auto& row : occupied)
			c += count(row.begin(), row.end(), 1);
		// Found that this heuristic was the good one after testing with a different one
		// - Score < 80,000,000: Had a good filtering factor, and can easily be used to scroll through the possible solutions
		if(c == robots.size())
		{
			cout << k;
			// Display the solution robots position
			if(display)
				for(int i = 0; i < height; i++)
				{
					cout << endl;
					for(int j = 0; j < width; j++)
						cout << (occupied[i][j] ? '#' : ' ');
				}
			cout << endl;
			break;
		}
	}
	
	return 0;
}

#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
#include<vector>

#define vi vector<int>
#define s(X) sort(X.begin(), X.end())
#define abs(X) (X) > 0 ? (X) : -(X)

using namespace std;

int main(void)
{
	vi left;
	vi right;
	
	while (true)
	{
		string line;
		getline(cin, line);
		if (line.empty()) break;
		int a, b;
		istringstream(line) >> a >> b;
		left.push_back(a);
		right.push_back(b);
	}
	
	s(left);
	s(right);

	int distance = 0;
	int similarity = 0;

	for (size_t i = 0; i < left.size(); i++) 
	{
		distance += abs(left[i] - right[i]);
		similarity += left[i] * (count(right.begin(), right.end(), left[i]));
	}

	cout << distance << '\n';
	cout << similarity << '\n';
	return 0;
}

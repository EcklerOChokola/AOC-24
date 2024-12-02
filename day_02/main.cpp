#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
#include<vector>

#define vi vector<int>
#define abs(X) (X) > 0 ? (X) : -(X)

using namespace std;

char is_safe(vi r)
{
	char d;
	if (r.size() < 2) return 1;
	if (r[0] < r[1]) d = 0;
	else if (r[0] > r[1]) d = 1;
	else return 0;
	
	int current = r[0];
	for (int i = 1; i < r.size(); i++)
	{
		if (
			(d && current <= r[i]) ||
			(!d && current >= r[i])
		   ) return 0;
		int dist = abs(current - r[i]);
		if (dist < 1 || dist > 3) return 0;
		current = r[i];
	}
	return 1;
}

char is_safe_dampened(vi r)
{
	for (int i = 0; i < r.size(); i++)
	{
		vi cp = r;
		cp.erase(cp.begin() + i);
		if (is_safe(cp)) return 1;
	}
	return 0;
}

int main(void)
{
	vector<vector<int>> input;
	
	while (true)
	{
		string line;
		getline(cin, line);
		if (line.empty()) break;
		istringstream iss(line);
		vi report;
		while (true)
		{
			string value;
			getline(iss, value, ' ');
			if (value.empty()) break;
			int num;
			istringstream(value) >> num;
			report.push_back(num);
		}
		input.push_back(report);
	}

	cout << count_if(input.begin(), input.end(), is_safe) << '\n';

	cout << count_if(input.begin(), input.end(), is_safe_dampened) << '\n';

	return 0;
}

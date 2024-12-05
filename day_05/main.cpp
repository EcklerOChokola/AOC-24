#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
#include<vector>
#include<regex>

using namespace std;

int rules_apply(vector<int> line, vector<pair<int,int>> rules)
{
	vector<int> seen;
	for(auto page : line)
	{
		for(auto before : seen)
			if(find((rules).begin(), (rules).end(), pair(page, before)) != (rules).end()) return 0;
		seen.push_back(page);
	}
	return line[line.size()/2];
}

int apply_rules(vector<int> line, vector<pair<int,int>> rules)
{
	if(rules_apply(line, rules)) return 0;
	while(true)
	{
		vector<int> seen;
		for(int i = 0; i < line.size(); i++)
		{
			if(rules_apply(line, rules)) return line[line.size()/2];
			for(int j = 0; j < i; j++)
			{
				if(find((rules).begin(), (rules).end(), pair(line[i], line[j])) != (rules).end())
				{
					int a = line[j];
					line[j] = line[i];
					line[i] = a;
					break;
				}
			}
		}
	}
	return 0;
}

int main(void)
{
	vector<pair<int,int>> rules;
	regex num("(\\d+)\\|(\\d+)");
	
	string line;
	while(true)
	{
		getline(cin, line);
		if(line.empty()) break;
		smatch m;
		regex_match(line, m, num);
		if(m.size() == 0) break;
		pair<int,int> rule;
		istringstream(m[1]) >> rule.first;
		istringstream(m[2]) >> rule.second;
		rules.push_back(rule);
	}

	int part_1 = 0;
	int part_2 = 0;
	while(getline(cin, line))
	{
		if(line.empty()) continue;
		vector<int> v;
		istringstream iss(line);
		while(true)
		{
			string tmp;
			getline(iss, tmp, ',');
			if(tmp.empty()) break;
			int num;
			istringstream(tmp) >> num;
			v.push_back(num);
		}
		part_1 += rules_apply(v, rules);
		part_2 += apply_rules(v, rules);
	}

	cout << part_1 << '\n' << part_2 << '\n';
	
	return 0;
}
		
		

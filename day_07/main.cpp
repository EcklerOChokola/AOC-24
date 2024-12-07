#include<iostream>
#include<bits/stdc++.h>
#include<string>

#define L unsigned long long

using namespace std;

L line_calibration(L result, vector<L> inputs)
{
	for(int i = 0; i < (1 << (inputs.size() - 1)); i++)
	{
		L temp = inputs[0];
		for(int j = 1; j < inputs.size(); j++)
			if(1 << (j - 1) & i) temp += inputs[j];
			else temp *= inputs[j];
		if(temp==result) return result;
	}
	return 0;
}

L line_calibration_2(L result, vector<L> inputs)
{
	if(line_calibration(result, inputs)) return result;
	for(int i = 0; i < (1 << (2 * (inputs.size() - 1))); i++)
	{
		L temp = inputs[0];
		for(int j = 1; j < inputs.size(); j++)
		{
			int op = ((3 << (2 * (j - 1))) & i) >> (2 * (j - 1));
			if(!op) {
				temp = 0;
				break;
			}
			else if(op == 1) temp += inputs[j];
			else if(op == 2) temp *= inputs[j];
			else 
			{
				stringstream t;
				t << temp << inputs[j];
				t >> temp;
			}
		}
		if(temp==result) return result;
	}
	return 0;
}

int main(void)
{
	string line;
	L part_1 = 0;
	L part_2 = 0;
	while(getline(cin, line))
	{
		if(line.empty()) break;
		string r = line.substr(0, line.find(": "));
		line.erase(0, line.find(": ") + string(": ").length());
		stringstream s(r);
		L result;
		s >> result;
		stringstream i(line);
		string tmp;
		L t;
		vector<L> inputs;
		while(getline(i, tmp, ' '))
		{
			stringstream v(tmp);
			v >> t;
			inputs.push_back(t);
		}
		part_1 += line_calibration(result, inputs);
		part_2 += line_calibration_2(result, inputs);
	}
	cout << part_1 << '\n';
	cout << part_2 << '\n';
	return 0;
}





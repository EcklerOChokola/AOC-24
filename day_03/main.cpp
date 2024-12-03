#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<regex>
#include <string_view>

using namespace std;
using namespace std::literals;

int main(void)
{
	string input;
	string temp;
	while(getline(cin, temp))
	{
		input += temp;
	}
		
	regex mul_regex("(?:mul\\((\\d+),(\\d+)\\)|do\\(\\)|don't\\(\\))");
	auto mul_b = sregex_iterator(input.begin(), input.end(), mul_regex);
	auto mul_e = sregex_iterator();

	long part_1 = 0;
	long part_2 = 0;
	long should_add = 1;
	for(sregex_iterator i = mul_b; i != mul_e; i++)
	{
		smatch m = *i;
		string str = m.str();
		if (str.rfind("mul") == 0)
		{
			long a, b;
			istringstream(m[1].str()) >> a;
			istringstream(m[2].str()) >> b;
			part_1 += a * b;
			part_2 += a * b * should_add;
		}
		else {
			if (str.size() < 5)
			{
				should_add = 1;
			}
			else
			{
				should_add = 0;
			}
		}
	}

	cout << part_1 << '\n' << part_2 << '\n';

	return 0;
}

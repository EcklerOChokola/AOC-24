#include<iostream>
#include<bits/stdc++.h>
#define L unsigned long long
using namespace std;

map<L, vector<L>> transforms;

L stone_log10(L stone)
{
	L r = 0ULL;
	L p = 10ULL;
	while(p < stone)
	{
		r++;
		p *= 10ULL;
	}
	if(stone == p) r++; 
	return r;
}

L pow10(L e)
{
	L r = 10ULL;
	for(int i = 1; i < e; i++)
		r *= 10ULL;
	return r;
}

void compute_stone(L stone, L count, map<L, L>* carrier)
{
	if(transforms.count(stone))
	{
		for(auto& t : transforms[stone])
		{
			if(!carrier->count(t)) (*carrier)[t] = 0;
			(*carrier)[t] += count;
		}
		return;
	}
	L n_length = stone_log10(stone) + 1;
	if(n_length % 2 == 0)
	{
		L unit = pow10(n_length / 2);
		L left = stone / unit;
		L right = stone % unit;
		if(!carrier->count(left)) (*carrier)[left] = 0;
		(*carrier)[left] += count;
		if(!carrier->count(right)) (*carrier)[right] = 0;
		(*carrier)[right] += count;
		return;
	}
	L new_stone = stone * 2024ULL;
	if(!carrier->count(new_stone)) (*carrier)[new_stone] = 0;
	(*carrier)[new_stone] += count;

}

void process_state(map<L, L>* state)
{
	map<L, L> new_state;
	for(auto& entry : *state)
		compute_stone(entry.first, entry.second, &new_state);
	*state = new_state;
}

int main(void)
{
	map<L, L> state;
	string temp;
	L stone;
	while(getline(cin, temp, ' '))
	{
		if(temp.empty()) continue;
		stringstream t;
		t << temp;
		t >> stone;
		if(state[stone]) state[stone] = 0;
		state[stone]++;
	}
	transforms[0]=vector(1, 1ULL);

	for(int i = 0; i < 25; i++)
		process_state(&state);

	L part_1 = 0ULL;
	for(auto& t : state)
		part_1 += t.second;

	for(int i = 0; i < 50; i++)
		process_state(&state);

	L part_2 = 0ULL;
	for(auto& t : state)
		part_2 += t.second;
	cout << part_1 << endl << part_2 << endl;

	return 0;
}


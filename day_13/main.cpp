#include<iostream>
#include<bits/stdc++.h>
#define L long long
#define f first
#define s second
using namespace std;

L solve(pair<L, L> a, pair<L, L> b, pair<L, L> p)
{
	L y = (p.s * a.f - p.f * a.s) / (b.s * a.f - b.f * a.s);
	L x = (p.f - (b.f * y)) / a.f;
	return (a.f * x + b.f * y == p.f && a.s * x + b.s * y == p.s) * (x * 3 + y);
}

int main(void)
{
	string A;
	regex junk("(?:[XY][\\+=])|(?:Button [AB]: )|(?:Prize: )|\\,");
	L part_1 = 0;
	L part_2 = 0;
	L d = 10000000000000LL;
	while(getline(cin, A))
	{
		if(A.empty()) continue;
		string B;
		string P;
		getline(cin, B);
		getline(cin, P);
		A = regex_replace(A, junk, "");
		B = regex_replace(B, junk, "");
		P = regex_replace(P, junk, "");
		pair<L, L> a, b, p;
		stringstream(A) >> a.f >> a.s;
		stringstream(B) >> b.f >> b.s;
		stringstream(P) >> p.f >> p.s;
		part_1 += solve(a, b, p);
		p.f += d;
		p.s += d;
		part_2 += solve(a, b, p);
	}
	cout << part_1 << endl << part_2 << endl;
	return 0;
}


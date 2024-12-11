#include<iostream>
#include<bits/stdc++.h>
#define L unsigned long long
#define R return
#define K count
#define E e.second
#define I(X)if(!C->count(X))(*C)[X]=0;(*C)[X]+=c
using namespace std;map<L,vector<L>> T;L l(L s){L r=0;L p=10;while(p<s){r++;p*=10;}if(s==p)r++;R r;}L p(L e){L r=10;for(int i=1;i<e;i++)r*=10;R r;}void S(L s,L c,map<L,L>* C){if(T.K(s)){for(auto& t:T[s]){I(t);}R;}L n=l(s)+1;if(n%2==0){L u=p(n/2);L g=s/u;L d=s%u;I(g);I(d);R;}L v=s*2024;I(v);}void P(map<L,L>* s){map<L,L> n;for(auto& e:*s)S(e.first,E,&n);*s=n;}int main(){map<L,L> S;string t;L s;while(getline(cin,t,' ')){if(t.empty())continue;stringstream o;o<<t;o>>s;if(S[s])S[s]=0;S[s]++;}T[0]=vector(1,1ULL);for(int i=0;i<25;i++)P(&S);L O=0;for(auto& e:S)O+=E;for(int i=0;i<50;i++)P(&S);L T=0;for(auto& e:S)T+=E;cout<<O<<endl<<T<<endl;R 0;}


#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
#include<vector>
#include<regex>
#define V vector<int>
#define P vector<pair<int,int>>
#define S istringstream
#define X return
#define B break
#define E(X)if(X.empty())
#define I for(int i=0;i<l.size();i++)
#define J for(int j=0;j<i;j++)
#define F if(find(r.begin(),r.end(),pair(l[i],l[j]))!=r.end())
#define G getline(cin,l)
#define U int
#define W while(1)
#define L return l[l.size()/2]
using namespace std;
U R(V l,P r){I J F X 0;L;}U A(V l,P r){if(R(l,r))X 0;W I{if(R(l,r))L;J F{U a=l[j];l[j]=l[i];l[i]=a;B;}}X 0;}U main(){P r;regex n("(\\d+)\\|(\\d+)");string l;W{G;E(l)B;smatch m;regex_match(l,m,n);E(m)B;pair<U,U> t;S(m[1])>>t.first;S(m[2])>>t.second;r.push_back(t);}U O=0,T=0;while(G){E(l)continue;V v;S i(l);W{string T;getline(i,T,',');E(T)B;U n;S(T)>>n;v.push_back(n);}O+=R(v,r);T+=A(v,r);}cout<<O<<'\n'<<T<<'\n';X 0;}

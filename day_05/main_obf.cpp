#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
#include<vector>
#include<regex>
#define V vector<int>
#define P vector<pair<int,int>>
#define I istringstream
#define X return
#define B break
#define E(X)if(X.empty())
using namespace std;
int R(V l,P r){V s;for(auto p:l){for(auto b:s)if(find((r).begin(),(r).end(),pair(p, b))!=(r).end())X 0;s.push_back(p);}X l[l.size()/2];}int A(V l,P r){if(R(l,r))X 0;while(1)for(int i=0;i<l.size();i++){if(R(l,r))X l[l.size()/2];for(int j=0;j<i;j++)if(find((r).begin(),(r).end(),pair(l[i],l[j]))!=(r).end()){int a=l[j];l[j]=l[i];l[i]=a;B;}}X 0;}int main(){P r;regex n("(\\d+)\\|(\\d+)");string l;while(1){getline(cin,l);E(l)B;smatch m;regex_match(l,m,n);E(m)B;pair<int,int> t;I(m[1])>>t.first;I(m[2])>>t.second;r.push_back(t);}int O=0;int T=0;while(getline(cin,l)){E(l)continue;V v;I i(l);while(1){string T;getline(i,T,',');E(T)B;int n;I(T)>>n;v.push_back(n);}O+=R(v,r);T+=A(v,r);}cout<<O<<'\n'<<T<<'\n';X 0;}

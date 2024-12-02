#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
#include<vector>
#define v vector<int>
#define a(X)(X)>0?(X):-(X)
#define C(X,F)count_if(X.begin(),X.end(),F)
#define f(V,S)for(int i=S;i<V.size();i++)
#define u return
#define w while(1)
#define b(X)if(X.empty())break
#define t istringstream
using namespace std;char s(v r){char d;if(r.size()<2)u 1;if(r[0]<r[1])d=0;else if(r[0]>r[1])d=1;else u 0;int c=r[0];f(r,1){if((d&&c<=r[i])||(!d&&c>=r[i]))u 0;int D=a(c-r[i]);if(D<1||D>3)u(0);c=r[i];}u 1;}char S(v r){if(s(r))u 1;f(r,0){v R=r;R.erase(R.begin()+i);if(s(R))u 1;}u 0;}int main(){vector<v> I;w{string l;getline(cin,l);b(l);t i(l);v r;w{string x;getline(i,x,' ');b(x);int n;t(x)>>n;r.push_back(n);}I.push_back(r);}cout<<C(I,s)<<'\n'<<C(I,S)<<'\n';u 0;}

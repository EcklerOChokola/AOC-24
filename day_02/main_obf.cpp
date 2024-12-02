#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
#include<vector>
#define vi vector<int>
#define abs(X) (X)>0?(X):-(X)
#define ci(X,F) count_if(X.begin(),X.end(),F)
#define f(V,S) for(int i=S;i<V.size();i++)
#define r(X) return(X);
#define w while(true)
#define b(X) if(X.empty())break
#define is istringstream
using namespace std;char s(vi r){char d;if(r.size()<2)r(1);if(r[0]<r[1])d=0;else if(r[0]>r[1])d=1;else r(0);int c=r[0];f(r,1){if((d&&c<=r[i])||(!d&&c>=r[i]))r(0);int di=abs(c-r[i]);if(di<1||di>3)r(0);c=r[i];}r(1);}char sd(vi r){if(s(r))r(1);f(r,0){vi cp=r;cp.erase(cp.begin()+i);if(s(cp))r(1);}r(0);}int main(){vector<vi> I;w{string l;getline(cin,l);b(l);is i(l);vi r;w{string v;getline(i,v,' ');b(v);int n;is(v)>>n;r.push_back(n);}I.push_back(r);}cout<<ci(I,s)<<'\n';cout<<ci(I,sd)<<'\n';r(0);}

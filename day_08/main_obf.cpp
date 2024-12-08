#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define u first
#define U second
#define V vector
#define v pair
#define Y int
#define I(X)X.first>=0&&X.first<x&&X.second>=0&&X.second<c
#define X accumulate(a.begin(),a.end(),0)
using namespace std;int main(){string L;Y x=0;Y c=0;map<char,V<v<Y,Y>>> A;while(getline(cin,L)){if(L.empty())break;for(Y y=0;y<L.size();y++){if(L[y]=='.')continue;if(A.count(L[y]))A[L[y]].push_back(v(x,y));else A[L[y]]=V(1,v(x,y));}x++;c=L.size();}V<V<Y>> n(x,V(c,0));V<V<Y>> N(x,V(c,0));for(auto& a:A){V<v<Y,Y>> p=a.U;for(Y i=0;i<p.size()-1;i++)for(Y j=i+1;j<p.size();j++){v<Y,Y> f=p[i];v<Y,Y> s=p[j];N[f.u][f.U]=1;N[s.u][s.U]=1;Y d=s.u-f.u;Y D=s.U-f.U;v<Y,Y> F=v(f.u-d,f.U-D);if(I(F))n[F.u][F.U]=1;v<Y,Y> S=v(s.u+d,s.U+D);if(I(S))n[S.u][S.U]=1;while(I(F)){N[F.u][F.U]=1;F=v(F.u-d,F.U-D);}while(I(S)){N[S.u][S.U]=1;S=v(S.u+d,S.U+D);}}}Y p=0;for(auto& a:n)p+=X;Y P=0;for(auto& a:N)P+=X;cout<<p<<'\n'<<P<<'\n';return 0;}

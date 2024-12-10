#include<iostream>
#include<bits/stdc++.h>
#define A int
#define V vector
#define O pair
using namespace std;A main(){string L;A H=0;A W=0;V<V<A>> I;V<O<A,A>> S;while(getline(cin,L)){if(L.empty()) continue;V<A> l;for(A i=0;i<L.size();i++){A v=L[i]-'0';l.push_back(v);if(!v)S.push_back(O(H, i));}I.push_back(l);H++;W=L.size();}map<O<A,A>,V<O<A,A>>> E;for(A i=0;i<H;i++)for(A j=0;j<W;j++){A v=I[i][j];V<O<A,A>> a;if(i>0&&v+1==I[i-1][j])a.push_back(O(i-1,j));if(j>0&&v+1==I[i][j-1])a.push_back(O(i,j-1));if(i<H-1&&v+1==I[i+1][j])a.push_back(O(i+1,j));if(j<W-1&&v+1==I[i][j+1])a.push_back(O(i,j+1));E[O(i,j)] = a;}A p=0;A P=0;for(auto& s:S){stack<O<A,A>> v;v.push(s);set<O<A,A>> e;while(!v.empty()){O<A,A> o=v.top();v.pop();if(I[o.first][o.second]==9){P++;e.insert(o);}else for(auto& a:E[o])v.push(a);}p+=e.size();}cout<<p<<'\n'<<P<<'\n';return 0;}

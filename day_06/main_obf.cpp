#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#if defined(_OPENMP)
#include<omp.h>
#endif
#define c(X)X.first>=0&&X.first<sz&&X.second>=0&&X.second<sz
#define Q o=pair(O.first+X[d],O.second+Y[d])
#define R vector
#define b break
#define B pair<int,int>
#define e(X)X.begin(),X.end()
#define k(I,O)I[O.first][O.second]
#define K pair
#define a int
#define A string
using namespace std;a X[4]={-1,0,1,0};a Y[4]={0,1,0,-1};a main(){
#if defined(_OPENMP)
omp_set_num_threads(omp_get_max_threads());
#endif
R<A> I;B O;A l;a i=0;while(getline(cin,l)){if(l.empty())b;I.push_back(l);a s=l.rfind("^");if(s!=A::npos)O=K(i,s);i++;}a sz=I.size();B S=O;R<R<int>> V(sz,R(sz,0));a d=0;while(c(O)){k(V,O)=1;B Q;if(!(c(o)))b;if(k(I,o)=='#'){d=(d+1)%4;Q;}O=o;}a p=0;for(auto& v:V)p+=accumulate(e(v),0);a P=0;for(a i=0;i<sz;i++)
#pragma omp parallel for
for(a j=0;j<sz;j++)if(I[i][j]=='.'&&V[i][j]){R<A> n;for(A& s:I)n.push_back(A(s));B O=S;a d=0;R<K<B,a>> V(1,K(O,d));n[i][j]='#';while(c(O)){B Q;if(!(c(o)))b;if(k(n,o)=='#')d=(d+1)%4;else O=o;if(find(e(V),K(o,d))==V.end())V.push_back(K(o,d));else{P++;b;}}}cout<<p<<'\n'<<P<<'\n';return 0;}

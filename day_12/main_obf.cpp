#include<iostream>
#include<bits/stdc++.h>
#define I int
#define v vector
#define F first
#define S second
#define B push_back
#define Z size()
#define E continue
#define f for
using namespace std;I X[4]={0,1,0,-1};I Y[4]={1,0,-1,0};I main(){v<string> M;string L;while(getline(cin,L)){if(L.empty())break;M.B(L);}v<v<I>> V(M.Z,v(M[0].Z,0));I p=0;I P=0;f(I i=0;i<M.Z;i++)f(I j=0;j<M[i].Z;j++){if(V[i][j])E;I A=0,a=0;stack<pair<I,I>> O;v<v<I>> R(V.Z+2,v(V[i].Z+2,0));O.push(pair(i,j));while(!O.empty()){pair<I,I> o=O.top();O.pop();if(V[o.F][o.S])E;V[o.F][o.S]=1;R[o.F+1][o.S+1]=1;A++;a+=4;f(I k=0;k<4;k++){pair<I,I> n=pair(o.F+X[k],o.S+Y[k]);if(n.F>=0&&n.F<M.Z&&n.S>=0&&n.S<M[i].Z&&M[o.F][o.S]==M[n.F][n.S]){O.push(n);a--;}}}I c=A*a;p+=c;I s=0;f(I k=0;k<R.Z-1;k++){v<I> C=R[k];v<I> N=R[k+1];I d=N[0]-C[0];if(d)s++;f(I l=1;l<C.Z;l++){I D=N[l]-C[l];if(d==D)E;d=D;if(d)s++;}}f(I k=0;k<R[0].Z-1;k++){v<I> C,N;f(I l=0;l<R.Z;l++){C.B(R[l][k]);N.B(R[l][k+1]);}I d=N[0]-C[0];if(d)s++;f(I l=1;l<C.Z;l++){I D=N[l]-C[l];if(d==D)E;d=D;if(d)s++;}}I C=s*A;P+=C;}cout<<p<<endl<<P<<endl;return 0;}

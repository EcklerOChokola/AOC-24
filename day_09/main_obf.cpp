#include<iostream>
#include<bits/stdc++.h>
#define L unsigned long long
#define a int
#define w while
#define f(X,Y)for(int X=0;X<Y;X++)
using namespace std;
a main(){string I;cin>>I;vector<a> B=vector(100000,-1);a l=0;char f=0;f(i,I.size()){a v=I[i]-'0';if(!f)f(j,v)B[l+j]=i/2;l+=v;f=!f;}a M=l-1;L p=0;for(a m=0;m<=M;m++){if(B[m]==-1){w(B[M]==-1)M--;p+=m*B[M];M--;}else p+=m*B[m];}a m=0;for(M=l-1;m<=M;){w(B[m]!=-1)m++;if(B[M]==-1){M--;continue;}a s=0;w(M-s>=0&&B[M-s]==B[M])s++;for(a i=0;i<M;){w(B[i]!=-1)i++;if(i>M){M-=s;break;}a S=0;w(B[i+S]==-1)S++;if(S<s)i+=S;else{f(j,s){B[i+j]=B[M];B[M]=-1;M--;}break;}}}L P=0;f(i,l)P+=((B[i]==-1)?0:i*B[i]);cout<<p<<'\n'<<P<<'\n';return 0;}

#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
#include<vector>
#define v vector<string>
#define l int
#define R return
#define s(X)(X).size()
using namespace std;l X[8]={0,0,1,-1,1,-1,-1,1};l Y[8]={1,-1,0,0,1,-1,1,-1};l L(v* I,char c,l x,l y){if(x<0||y<0||x>=s(*I)||y>=s(*I))R 0;R (*I)[x][y]==c;}l m(v* I,l x,l y){if((*I)[x][y]!='X')R 0;l c=0;for(l i=0;i<8;i++)if(L(I,'M',x+X[i],y+Y[i])&&L(I,'A',x+(2*X[i]),y+(2*Y[i]))&&L(I,'S',x+(3*X[i]),y+(3*Y[i])))c++;R c;}l M(v* I,l x,l y){if((*I)[x][y]!='A')R 0;for(l i=4;i<6;i++)if(L(I,'M',x+X[i],y+Y[i])&&L(I,'S',x-X[i],y-Y[i]))if((L(I,'M',x+X[i+2],y+Y[i+2])&&L(I,'S',x-X[i+2],y-Y[i+2]))||(L(I,'S',x+X[i+2],y+Y[i+2])&&L(I,'M',x-X[i+2],y-Y[i+2])))R 1;R 0;}l main(){v I;while(1){string e;getline(cin,e);if(e.empty())break;I.push_back(e);}l p1=0;l p2=0;for(l i=0;i<s(I);i++)for(l j=0;j< s(I[i]);j++){p1+=m(&I,i,j);p2+=M(&I,i,j);}cout<<p1<<'\n'<<p2<<'\n';R 0;}

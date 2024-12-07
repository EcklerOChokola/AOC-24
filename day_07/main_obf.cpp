#include<iostream>
#include<bits/stdc++.h>
#include<string>
#define L unsigned long long
#define S stringstream
#define s string
#define U return
#define J for(int j=1;j<I.size();j++)
using namespace std;
L c(L R,vector<L> I){for(int i=0;i<(1<<(I.size()-1));i++){L T=I[0];J if(1<<(j-1)&i)T+=I[j];else T*=I[j];if(T==R)U R;}U 0;}L C(L R,vector<L> I){if(c(R,I))U R;for(int i=0;i<(1<<(2*(I.size()-1)));i++){L T=I[0];J{int o=((3<<(2*(j-1)))&i)>>(2*(j-1));if(!o){T=0;break;}else if(o==1)T+=I[j];else if(o==2)T*=I[j];else{S t;t<<T<<I[j];t>>T;}}if(T==R)U R;}U 0;}int main(){s l;L p=0;L P=0;while(getline(cin,l)){if(l.empty())break;s r=l.substr(0,l.find(": "));l.erase(0,l.find(": ")+s(": ").length());S u(r);L R;u>>R;S i(l);s t;L T;vector<L> I;while(getline(i,t,' ')){S v(t);v>>T;I.push_back(T);}p+=c(R,I);P+=C(R,I);}cout<<p<<'\n'<<P<<'\n';U 0;}




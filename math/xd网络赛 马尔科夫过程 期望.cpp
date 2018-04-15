//#include<bits/stdc++.h>
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<ctime>
#include<cstdlib>
 
using namespace std;
//typedef long long LL;
const int maxn=500+5;
 
//const int INF=1<<25;
const int MOD=1e9+7;
double eps=1e-6;
double e[maxn];
int n;
double E(int a)
{
    if(abs(e[a])>eps||a==0)
        return e[a];
    double tl=0.0;
    for (int k=a-1;k>=1;--k)
    {
        tl=tl+1.0/a*E(a%k);
        //cout<<a<<" "<<tl<<endl;
    }
 
    return e[a]=tl+1.0*n/a;
}
 
int main()
{
    double ans;
    while(~scanf("%d",&n))
    {
        ans=0.0;
        memset(e,0,sizeof(e));
        e[0]=0.0;
        e[1]=n;
        e[2]=1.0*n/2;
        for (int i=1;i<=n;++i)
        {
            ans=ans+E(i);
        }
        //cout<<e[0]<<" "<<" "<<e[1]<<" "<<e[2]<<" "<<e[3]<<endl;
        ans=ans/n;
 
        printf("%.2lf\n",ans+1);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1285
    User: 16020110047
    Language: C++
    Result: 正确
    Time:155 ms
    Memory:1704 kb
****************************************************************/

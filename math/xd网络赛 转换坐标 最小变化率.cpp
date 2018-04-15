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
typedef long long LL;
 
const int maxn=1000000+5;
 
//const int INF=1<<25;
//const int MOD=1e9+7;
 
int getint()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
 
int x[maxn],y[maxn];
 
bool cmp(int a,int b)
{
    return x[a]<x[b];
}
 
int main()
{
    int n,flag;
    double ans;
    while(~scanf("%d",&n))
    {
        ans=0.0;
        flag=0;
        for (int i=1;i<=n;++i)
        {
            x[i]=getint();
            y[i]=i;
        }
        sort(y+1,y+1+n,cmp);
        for (int i=2;i<=n;++i)
        {
            //cout<<" "<<y[i]<<endl;
            if(x[y[i]]==x[y[i-1]])
            {
                flag=1;
                break;
            }
            ans=max(ans,abs(1.0*(y[i]-y[i-1])/(x[y[i]]-x[y[i-1]])));
        }
        if(flag==1)
            printf("0.00\n");
        else
            printf("%.2lf\n",1.0/ans);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1289
    User: 16020110047
    Language: C++
    Result: 正确
    Time:532 ms
    Memory:9520 kb
****************************************************************/

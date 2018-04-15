比较简单的二分，check部分需要注意不要出错
//#include<bits/stdc++.h>
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
//#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<algorithm>
 
using namespace std;
//typedef long long LL;
const int maxn=100000+5;
 
//const int INF=1<<29;
//const int MOD=1000007;
 
 
int getint()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
 
int sq[maxn],num[1000005],mid,ma,n,m;
 
int check(int M)
{
    int w=0;
    for (int i=(n+1)/2;sq[i]==mid&&i<=n;++i)
        w+=(M-sq[i]);
    for (int i=mid+1;i<=M&&i<=ma;++i)if(num[i])
    {
        w+=(M-i)*num[i];
    }
    return w<=m;
}
 
int main()
{
    int x,y,M;
    while(~scanf("%d %d",&n,&m))
    {
        memset(num,0,4*maxn);
        for (int i=1;i<=n;++i)
        {
            sq[i]=getint();
            num[sq[i]]++;
            ma=max(ma,sq[i]);
        }
        sort(sq+1,sq+1+n);
        mid=sq[n/2];
        x=mid,y=m+mid;
        while(x<y)
        {
            M=(x+y+1)/2;
            if(check(M))
                x=M;
            else
                y=M-1;
        }
        printf("%d\n",x);
    }
    return 0;
}
 
/**************************************************************
    Problem: 1283
    User: 16020110047
    Language: C++
    Result: 正确
    Time:31 ms
    Memory:6000 kb
****************************************************************/

/*
其实还是没有懂为什么排序后再背包就是正确的策略，只能说自己的思维还不到位吧。。
实现倒是很简单，注意路径打印的方法，总是忘记这个
*/
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cctype>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long LL;
const int maxn=100+5;

int pre[maxn][2005];
int dp[maxn][2005];
int aq[105],ak;
int index[maxn];

struct node
{
    int t,d,p;
    node (){t=0,d=0,p=0;}
    node(int t,int d,int p):t(t),d(d),p(p){}
    bool operator<(struct node &rhs)const{return d<rhs.d;}
}goods[maxn];

int t[maxn],d[maxn],p[maxn];

struct cmpFunctor
{
    inline bool operator()(const int a,const int b)const
    {
        return d[a]<d[b];
    }
};

int main()
{
    int n,temp;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&t[i],&d[i],&p[i]);
        index[i]=i;
    }
    sort(index+1,index+1+n,cmpFunctor());
    //sort(goods+1,goods+1+n);
    memset(pre,-1,sizeof(pre));
    for(int i=1;i<=n;i++)
    {
        temp=index[i];
        for(int j=0;j<=2000;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j<d[temp]&&j-t[temp]>=0&&dp[i][j]<dp[i-1][j-t[temp]]+p[temp])
            {
                dp[i][j]=dp[i-1][j-t[temp]]+p[temp];
                pre[i][j]=j-t[temp];
            }
        }
    }
    int ans=0,pos=-1;
    for(int i=2000;i>0;i--)
    {
        if(dp[n][i]>ans)
        {
            ans=dp[n][i];
            pos=i;
        }
    }
    printf("%d\n",ans);
    for(int i=n;i>0;i--)
    {
        if(pre[i][pos]!=-1)
        {
            aq[ak++]=i;
            pos=pre[i][pos];
        }
    }
    printf("%d\n",ak);
    for(int i=ak-1;i>=0;--i)
        printf("%d ",index[aq[i]]);
    putchar('\n');
    return 0;
}


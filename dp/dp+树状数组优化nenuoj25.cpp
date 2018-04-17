
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

//const int maxn=200000+5;

//const int INF=1<<25;
const int MOD=1e8+7;

int getint()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}

int n,t[200005],dp[100010];
int lowbit(int x)
{
    return x&(-x);
}
void change(int x,int p)
{
    while(x<=n)
    {
        t[x]+=p;
        t[x]%=MOD;
        x+=lowbit(x);
    }
    return;
}
int sum(int k)
{
    int ans=0;
    while(k>0)
    {
        ans+=t[k];
        ans%=MOD;
        k-=lowbit(k);
    }
    return ans;
}
int ask(int l,int r)
{
    return sum(r)-sum(l-1);
}

int main()
{
    int T,temp,ans;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        memset(t,0,sizeof(t));
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
        {
            temp=getint();
            dp[i]=(ask(1,temp-1)+1+MOD)%MOD;
            ans=(ans+dp[i])%MOD;
            change(temp,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}


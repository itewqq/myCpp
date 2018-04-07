第一个状态压缩dp
紫书上好几个例子都是讲得同一种类型的，就是会跟集合有关
首先拿到之后画出状态转移的图吧，会帮助理解一点思路走向
其实搞清楚之后就是一个记忆化搜索，因为先询问a之后再询问b和先询问b之后在询问a是一样的，所以会有重合子问题
问题可以转化成，把所有的这些对象都检测出来最少需要多少个询问
这样的话一路往下问的过程中，是一定要问出来所有对象的结果的，关键是一个顺序问题
所以就是用某种方式找到这个决策树中最短的一个叶子的那一条路
所需要的状态信息，1已经操作过的询问2走到当前已经满足了的询问
根据这两个可以预处理出来s a确定的时候有多少个对象满足要求，就可以操作了
主要的问题：
1 如何表示状态 这里用的是查询过的操作和已经包含的操作，而自己想的一开始就是用已经确认过的集合和尚未确认过的集合来做
  自己想的有什么问题呢，就是每次询问过之后并不能直接得到这两个集合。而且其实这样的状态本身有多余的成分，因为其实知道了一路走来的操作就足够
  将满足条件的有多少个计算出来的，而并不需要知道他们确切的都是什么，因为是要找到所有的，所以不必纠结于对单个对象的查找，总会找到的
2 位操作的运算
//UVa1252
//#include<bits/stdc++.h>
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
using namespace std;
typedef long long LL;
const int maxm=11;
const int maxn=128+5;
//const int MOD=1000000007;
int M,N,cs;
char obs[maxn][maxm+1];
int cnt[1<<maxm][1<<maxm],d[1<<maxm][1<<maxm];//cnt[s][a]
int vis[1<<maxm][1<<maxm];

void Init()
{
    int feature;
    memset(cnt,0,sizeof(cnt));//what the hell?
    for (int i=1;i<=N;++i)
    {
        feature=0;
        for (int j=0;j<M;++j)
            if(obs[i][j]=='1')feature|=(1<<j);
        for (int s=0;s<(1<<M);++s)
            cnt[s][s&feature]++;
    }
    return ;
}

int dp(int s,int a)
{
    if(cnt[s][a]==2)return 1;
    if(cnt[s][a]<=1)return 0;
    int& ans=d[s][a];
    if(vis[s][a]==cs)return d[s][a];
    vis[s][a]=cs;
    ans=M;
    int ts,ta,need;
    for (int k=1;k<(1<<M);k=(k<<1))if(!(s&k))
    {
        ts=s|k;ta=a|k;
        need=max(dp(ts,ta),dp(ts,a))+1;
        ans=min(ans,need);
    }
    return ans;
}

int main()
{
    while(~scanf("%d %d",&M,&N)&&M)
    {
        cs++;
        for (int i=1;i<=N;++i)
            scanf(" %s",obs[i]);
        Init();
        printf("%d\n",dp(0,0));
    }
    return 0;
}

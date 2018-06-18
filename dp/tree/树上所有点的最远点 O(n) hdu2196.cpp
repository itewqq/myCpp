/*
题目有个结论：树上的一个点到最远的点，一定是树的直径两个端点中的一个
先任意找一个点，一次dfs搜索出到这个点的最远点v，然后对v进行一次dfs找出最远点w
然后对w进行一次dfs更新其他所有的点
由于这里是无向图所以要存双向边
然后就是实现上的一些细节：
  1 树的话可以不用vis数组的，把parent传下去就可以了
  2 这里用了一个max（）的操作，直接把三个不同的dfs都统一了，很值得学习和思考
  3 树上的，就某一个源点而言，带权最远和不带权一样，因为一个点到剩下的每个点都只有一条路！
  
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
#include<map>
//#include<unordered_set>
using namespace std;
typedef long long LL;
const int maxn=1e4+5;
const int MOD=1e9+7;

vector<pair<int ,int> > tree[maxn];

int dis[maxn];

int ma,mu;
void dfs(int k,int f,int d)//learn it
{
    //cout<<k<<" "<<f<<" "<<d<<endl;
    dis[k]=max(dis[k],d);//learn ! simplify the code!
    if(dis[k]>ma)
    {
        ma=dis[k];
        mu=k;
    }
    int len=tree[k].size(),v,w;
    for(int i=0;i<len;i++)
    {
        v=tree[k][i].first,w=tree[k][i].second;
        if(v==f)continue;
        dfs(v,k,d+w);
    }
    return;
}

int main()
{
    int n,pre,len;
    while(~scanf("%d",&n))
    {
        memset(tree,0,sizeof(tree));
        for(int i=2;i<=n;i++)
        {
            scanf("%d%d",&pre,&len);
            tree[pre].push_back(make_pair(i,len));
            tree[i].push_back(make_pair(pre,len));
        }

        ma=0,mu=-1;
        //memset(vis,-1,sizeof(vis));
        memset(dis,0,sizeof(dis));
        dfs(1,-1,0);
        //cout<<ma<<" fuck "<<mu<<endl;
        memset(dis,0,sizeof(dis));
        ma=0;
        dfs(mu,-1,0);
        dfs(mu,-1,0);
        for(int i=1;i<=n;i++)
            printf("%d\n",dis[i]);
    }
    return 0;
}
/*
2 5
100 110
1 4 5 5 6
*/


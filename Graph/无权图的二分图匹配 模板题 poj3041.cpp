把横纵坐标看成二分图的左右两支，求得answer实际上就是最小点覆盖的数量，而最小点覆盖等于最大二分图匹配数，也就是说只要二分图匹配计算一下就可以了
这是dfs版本的二分图匹配
细节问题是
1 怎么表示左右两边的点是属于哪一边的，我用的方法是右边的点统一＋N即可，这样只用一个2*N的数组就可以轻松解决
2 学到了memset的时候不一定要sizeof，可以自己手算一下字节数，似乎会更快

//poj3041
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;
typedef long long LL;
const int maxn=1100+5;


vector<int> G[maxn];
int matching[maxn];
int check[maxn];

int dfs(int u)
{
    int len=G[u].size();
    int v;
    for (int i=0;i<len;i++)
    {
        v=G[u][i];
        if(!check[v])
        {
            check[v]=1;
            if(matching[v]==-1||dfs(matching[v]))
            {
                matching[u]=v;
                matching[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int N,K,u,v;
    scanf("%d %d",&N,&K);
    
    for (int i=0; i<K; i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(N+v);
        G[N+v].push_back(u);
    }
    
    //hungrins
    int ans=0;
    memset(matching,-1,8*N+8);
    for (u=1;u<=N;u++)if(matching[u]==-1)
    {
        memset(check,0,8*N+1);//detail
        if(dfs(u))
            ++ans;
    }

    printf("%d\n",ans);
    return 0;
}

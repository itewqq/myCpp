/*
求次短路的题目。
分析解的性质是非常重要de!!!!!!!!!!!!!!
次短路只有可能是，前一个的最短路加上某一段，或者前一个的次短路加上某一段。
所以要在dij的过程中同时记录两个数据，最短路和次短路。
并没有理解挑战例程，在队列里的时候他只用了一个变量同时表示最短路和次短路，并不是很懂
自己用的是在队列里每个节点保存三个域，最短路，次短路和节点编号
优先队列按照最短路，次短路从小到大排序（似乎在这里没什么用？？？不知道具体优化了多少
但是有一个很奇特的点就是，判断一个点是否被搞定了，这里只有当队列里这个点的次短路不比当前已知的次短路更小时，队列里的这个节点就是无用的
dij本身的特点就是，一旦一个点被搞定了，那么之后的操作是不会让他变得更优的，但是在这里不能仅仅把有没有考虑过这个点当成搞定
因为一次可能搞不定啊。。。。。次短路还是要考虑到每一条边的
因为队列是按照最短路排序的，那么只能保证最短路每次搞过一个点之后是确定的，不能保证次短路是确定的
所以这中间会有一些，搞过的点又被再搞一次的现象
在这里不能用done数组，因为每个点可能被操作多次

*/
//#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<algorithm>
//freopen("1.txt","r",stdin);

using namespace std;
typedef long long LL;
const int INF = 10000000;
//const long long M=1e9+7;
const int maxn=50005;
/*
int dx[4]= {1,0,-1,0};
int dy[4]= {0,1,0,-1};
*/

/*
struct bb
{
    char c;
    int t;
};
*/
typedef struct node
{
    int d1,d2,to;
    node(int d1,int d2,int to):d1(d1),d2(d2),to(to){}
    bool operator<(const struct node& rhs)const
    {
        return d1>rhs.d1;
    }
} node;
typedef struct Edge
{
    int to,w;
    Edge(int to,int w):to(to),w(w){}
}Edge;

vector<Edge > G[maxn];
int dist1[maxn];
int dist2[maxn];
int done[maxn];

int main()
{
    int N,R,from,to,w;
    scanf("%d%d",&N,&R);
    for (int i=1;i<=R;++i)
    {
        scanf("%d%d%d",&from,&to,&w);
        G[from].push_back(Edge(to,w));
        G[to].push_back(Edge(from,w));
    }
    priority_queue<node >Q;
    fill(dist1,dist1+N+1,INF);
    fill(dist2,dist2+N+1,INF);
    memset(done,0,sizeof(done));
    dist1[1]=0;
    Q.push(node(0,INF,1));
    while(!Q.empty())
    {
        int flag=0;
        node nd=Q.top();Q.pop();
        int d1=nd.d1,d2=nd.d2,to=nd.to;

        if(dist2[to]<d2)continue;//what the hell????last error??
        //if(done[to])continue;
        //done[to]=1;
        for (int i=0;i<G[to].size();i++)
        {

            int dd1=G[to][i].w+d1,dd2=G[to][i].w+d2, dto=G[to][i].to;
            if(dist1[dto]>dd1)
            {
                //dist1[dto]=dd1;
                swap(dd1,dist1[dto]);
                flag=1;
                //swap(dist1[to],d2);
                //Q.push(node(dist1[to],to));
            }
            if(dist2[dto]>dd1&&dd1>dist1[dto])
            {
                dist2[dto]=dd1;
                 flag=1;
            }
            if(dist2[dto]>dd2&&dd2>dist1[dto])
            {
                dist2[dto]=dd2;
                flag=1;
            }

            if(flag)
                Q.push(node(dist1[dto],dist2[dto],dto));
            //cout<<dto<<" "<<dist1[dto]<<" "<<dist2[dto]<<endl;
        }
    }
    printf("%d\n",dist2[N]);
    return 0;
}

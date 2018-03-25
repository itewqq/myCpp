//poj3041
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
typedef long long LL;
const int maxn=100+5;
//const int MOD=1e9+7;
const int INF=1<<29;

typedef struct Edge
{
    int from,to,cap,flow;
    Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow){}
}Edge;

vector<Edge> edges;
vector<int> G[maxn+1];
int a[maxn+1];
int p[maxn+1];

void AddEdge(int from,int to,int cap)
{
    edges.push_back(Edge(from,to,cap,0));
    edges.push_back(Edge(to,from,0,0));
    int m=edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
}

int Maxflow(int s,int t)
{
    int flow=0,x;
    while(1)
    {
        memset(a,0,sizeof(a));
        queue<int> Q;
        Q.push(s);
        a[s]=INF;
        while(!Q.empty())
        {
            x=Q.front();Q.pop();
            //len=G[x].size();
            for(int i=0;i<G[x].size();++i)
            {
                Edge& e=edges[G[x][i]];
                if(!a[e.to]&&e.cap>e.flow)
                {
                    p[e.to]=G[x][i];
                    a[e.to]=min(a[x],e.cap-e.flow);
                    Q.push(e.to);
                }
            }
            if(a[t])break;
        }
        if(!a[t])break;
        for (int u=t;u!=s;u=edges[p[u]].from)
        {
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
        }
        flow+=a[t];
    }
    return flow;
}

int main()
{
    int n,np,nc,m,u,v,cap;
    while(~scanf(" %d %d %d %d",&n,&np,&nc,&m))
    {
        edges.clear();

        for (int i=0;i<=n;i++)
            G[i].clear();
        G[maxn].clear();
        G[maxn-1].clear();

        for (int i=0;i<m;++i)
        {
            scanf(" %*c%d%*c%d%*c%d",&u,&v,&cap);
            AddEdge(u,v,cap);
        }
        for (int i=0;i<np;++i)
        {
            scanf(" %*c%d%*c%d",&v,&cap);
            AddEdge(maxn,v,cap);
        }
        for (int i=0;i<nc;++i)
        {
            scanf(" %*c%d%*c%d",&u,&cap);
            AddEdge(u,maxn-1,cap);
        }

        cout<<Maxflow(maxn,maxn-1)<<endl;

    }
    return 0;
}

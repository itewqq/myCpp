//poj2253
//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>

using namespace std;
typedef long long ll;
const int INF = 1<<29;
const int maxn = 200 + 5;
//int dx[4]= {0,1,0,-1};
//int dy[4]= {1,0,-1,0};

/*
typedef struct Edge
{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d) {}
} Edge;
*/
typedef struct Node
{
    int u;
    double dist;
    Node(int u,double dist):u(u),dist(dist) {}
    bool operator<(const Node &rhs)const
    {
        return dist>rhs.dist;
    }
}Node;

int G[maxn+1][maxn+1];

typedef struct co
{
    int x,y;
    co(int x,int y):x(x),y(y) {}
} co;
vector<co> nodes;
double dist[maxn];
char vis[maxn];
double fa[maxn][maxn];

int main()
{
    int x,y,n,k=1;
    co s(0,0);
    while(~scanf("%d",&n)&&n!=0)
    {
        nodes.clear();
        scanf("%d %d",&x,&y);
        s.x=x,s.y=y;
        nodes.push_back(s);
        scanf("%d %d",&x,&y);
        s.x=x,s.y=y;
        nodes.push_back(s);

        for(int i=2; i<n; i++)
        {
            scanf("%d %d",&x,&y);
            nodes.push_back(co(x,y));
            dist[i]=INF;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            G[i][j]=1;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
        {
            int ax=nodes[i].x,ay=nodes[i].y,bx=nodes[j].x,by=nodes[j].y;
            fa[i][j]=sqrt(pow(ax-bx,2)+pow(ay-by,2));
        }
        dist[0]=0,dist[1]=fa[0][1];
        memset(vis,0,sizeof(vis));
        priority_queue<Node> Q;
        Q.push(Node(0,0));
        while(!Q.empty())
        {
            Node cur=Q.top();Q.pop();
            int u=cur.u;
            //cout<<u<<" "<<cur.dist<<endl;
            if(vis[u])continue;
            vis[u]=1;
            for(int i=0;i<=n;i++)if(!vis[i])
            {
                if(dist[i]>max(dist[u],fa[i][u]))
                {
                    dist[i]=max(dist[u],fa[i][u]);
                    Q.push(Node(i,dist[i]));
                }
            }
        }
        printf("Scenario #%d\n",k++);
        printf("Frog Distance = %.3f\n\n",dist[1]);
    }
    return 0;
}

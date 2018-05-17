/*
最后发现其实tsp的代码是没错的，竟然wa在了bfs上，呵呵
主要的教训就是，标记，两点之间不能到达，怎么也不能用0来表示，一定要用-1或者INF，fffffffffffuck
注意一开始就满足要求的这种特判，fuck
标记标记标记/px，唉
*/
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
//#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=+5;
//const int MOD=1e9+7;
const int INF=1<<29;

char board[17][17];
int M,N;
int dx[4]= {-1,0,1,0};
int dy[4]= {0,1,0,-1};
int u[17][2],v[17][2];

//int fr[17],tw[17],w[17];
int visit[17][17];
int dis[17][17][17];
int G[17][17];
typedef struct node
{
    int from,to,d;
    node(int from,int to,int d):from(from),to(to),d(d) {}
} node;

int p[17];
int done[16][(1<<15)+1];

void bfs(int s)
{
    memset(visit,0,sizeof(visit));
    int len=0;
    queue<node> Q;
    Q.push(node(v[s][0],v[s][1],0));
    dis[s][v[s][0]][v[s][1]]=0;//my last error
    while(!Q.empty())
    {
        node nn=Q.front();
        Q.pop();
        int cx=nn.from,cy=nn.to,cd=nn.d;
        if(visit[cx][cy])continue;
        visit[cx][cy]=1;
        for(int i=0; i<4; i++)
        {
            int xx=cx+dx[i],yy=cy+dy[i];
            if(!visit[xx][yy]&&0<xx&&xx<=N&&0<yy&&yy<=N&&board[xx][yy]!='#')
            {
                dis[s][xx][yy]=cd+1;
                Q.push(node(xx,yy,dis[s][xx][yy]));
            }
        }
    }
    return ;
}

void makeG()
{

    for(int i=1; i<=M; i++)
        for(int j=1; j<=M; j++)
            {
                if(i==j)
                    G[i][j]=0;
                else
                    G[i][j]=dis[i][u[j][0]][u[j][1]];
            }
}

int tsp(int k,int S)
{

    if(done[k][S]!=-1)
        return done[k][S];
    if(S==0)
        return done[k][S]=0;
    int ans=1<<29,nS;
    for(int i=0; i<M; i++)
    {
        if((i!=k-1)&&((1<<i)&S)&&G[k][i+1]!=-1)
        {
            nS=~(((1<<i))|(~S));
            ans=min(ans,tsp(i+1,nS)+G[k][i+1]);
        }
    }
    return done[k][S]=ans;
}

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    while(~scanf("%d%d",&N,&M))
    {
        memset(done,-1,sizeof(done));
        memset(dis,0,sizeof(dis));
        for(int i=0;i<16;i++)
            for(int j=0;j<16;j++)
                for (int k=0;k<16;k++)
                    dis[i][j][k]=-1;
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
            {
                scanf(" %c",&board[i][j]);
            }

        for(int i=1; i<=M; i++)
        {
            scanf("%d%d%d%d",&u[i][0],&u[i][1],&v[i][0],&v[i][1]);
        }
        for(int i=1; i<=M; i++)
            bfs(i);
        makeG();
        int ans=1<<29;
        for(int i=1; i<=M; i++)
        {
            int fuck=tsp(i,((1<<M)-1)^(1<<(i-1)));
            ans=min(ans,fuck);
        }
        if(ans==1<<29)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
}
/*
5 5
.....
.....
.....
.....
.....
1 2 3 4
3 5 4 5
1 1 4 1
2 2 5 5
4 2 3 2
5 2
....#
...#.
#####
.....
.....
1 1 1 2
3 3 3 4
*/

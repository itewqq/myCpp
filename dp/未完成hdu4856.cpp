//UVa1451
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
//int find(int x){return p[x]==x?x:p[x]=find(p[x]);}

void bfs(int s)
{
    memset(visit,0,sizeof(visit));
    int len=0;
    queue<node> Q;
    Q.push(node(v[s][0],v[s][1],0));
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
                //cout<<s<<" "<<xx<<" "<<yy<<" "<<dis[s][xx][yy]<<endl;
                Q.push(node(xx,yy,dis[s][xx][yy]));
            }
        }
    }
    return ;
}

void makeG()
{

    for(int i=1; i<=M; i++)
        for(int j=1; j<=M; j++)if(i!=j)
            {
                /*
                fr[E]=i,tw[E]=j,w[E]=dis[i][u[j][0]][u[j][1]];
                cout<<fr[E]<<" "<<tw[E]<<" "<<w[E]<<endl;
                E++;
                */
                G[i][j]=dis[i][u[j][0]][u[j][1]];
            }
}

//int cmp(int i,int j){return w[i]<w[j];}

/*
int Kruscal()
{
    int ans=0;
    for(int i=0;i<17;i++)p[i]=i;
    for(int i=0;i<E;i++)r[i]=i;
    sort(r,r+E,cmp);
    for(int i=0;i<E;i++)
    {
        int e=r[i];
        int x=find(fr[e]),y=find(tw[e]);
        if(x!=y){ans+=w[e];p[x]=y;}
    }
    return ans;
}
*/

int tsp(int k,int S)
{
    if(done[k][S])
        return done[k][S];
    if(S==0)
    {
        return 0;
    }
    int ans=1<<29,nS;
    for(int i=0; i<M; i++)
    {
        if((i!=k-1)&&((1<<i)&S)&&G[k][i+1])
        {
            nS=~(((1<<i))|(~S));
            if(done[i+1][nS])
                continue;
            //nS=~nS;
            //cout<<k<<" "<<i<<" "<<nS<<endl;
            //break;
            ans=min(ans,tsp(i+1,nS)+G[k][i+1]);
            //cout<<ans<<endl;
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
        memset(done,0,sizeof(done));
        memset(dis,0,sizeof(dis));
        memset(G,0,sizeof(G));
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
        /*
        for(int i=1; i<=M; i++)
            for(int j=1; j<=M; j++)
                if(i!=j&&!G[i][j])
                {
                    printf("-1\n");
                    return 0;
                }
        */
        for(int i=1; i<=M; i++)
        {
            //cout<<(((1<<M)-1)^(1<<(i-1)))<<endl;
            //cout<<(~(1<<i))<<endl;
            ans=min(ans,tsp(i,((1<<M)-1)^(1<<(i-1))));
            //cout<<"ans "<<ans<<endl;
        }
        if(ans==1<<29)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
}
/*
1
8
8 7 6 5 1 4 2 3
*/

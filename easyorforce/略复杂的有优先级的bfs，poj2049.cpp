又是一种，有优先级的bfs，而且表示也不是太好表示
要点：
1 通过辅助的dis来判断能否加入队列，实际上起到了优先级的作用
2 判断成功与否，忽然想到之前UVa fire那个题也是，不是在过程中直接判断是否走到了最小处，因为如果没有走完每一条路就无法判断是否最小
  而是在所有bfs完成之后再去考察对应的点是否被搜寻到
3 不需要判断是否走过，因为有dis实际上就确定了一种有没有走过，初始化为INF即可
4 最重要的一点是，学到了这种点与网格之间的映射关系的做法，这个代码是通过，把dis和墙的信息分开的方式，因为转换中判断是否可到达的方式是
  一定要考察墙的，这里包括了方向的问题，也是之前没有接触过的。
  这就是数据结构的重要性吧，先想清楚怎么表示数据，再做操作
5 确定了结构之后一定要时刻提醒，不然会在操作中出现想当然的错误
//poj2049
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
int dx[4]= {0,1,0,-1};
int dy[4]= {1,0,-1,0};

int dis[maxn][maxn];
int xa[maxn][maxn];
int ya[maxn][maxn];
int maxx,maxy;
struct cell
{
    int x,y;
    cell(int x,int y):x(x),y(y){}
};

typedef struct cell cell;

int getv(int x,int y,int dir)
{
    if(dir==0)return xa[x][y];
    if(dir==1)return ya[x][y];
    if(dir==2)return xa[x][y-1];
    return ya[x-1][y];
}

int bfs(int sx,int sy)
{
    int x,y,xx,yy,v;
    queue<cell> Q;
    Q.push(cell(1,1));

    for(int i=0;i<=maxx;i++)
        for(int j=0;j<=maxy;j++)
            dis[i][j]=INF;
    dis[1][1]=0;
    while(!Q.empty())
    {
        cell cur=Q.front();Q.pop();
        x=cur.x,y=cur.y;

        for(int i=0;i<4;i++)
        {
            v=getv(x,y,i);
            xx=x+dx[i],yy=y+dy[i];
            //cout<<" x "<<x<<" y "<<y<<" i "<<i<<" v "<<v<<endl;
            if(1<=xx&&xx<=maxx&&1<=yy&&yy<=maxy&&dis[x][y]+v<dis[xx][yy])
            {
                dis[xx][yy]=dis[x][y]+v;
                Q.push(cell(xx,yy));
            }
        }
    }
    return dis[sx][sy]==INF?-1:dis[sx][sy];
}

int main()
{
    int M,N,x,y,d,t;
    double sx,sy;
    while(~scanf("%d %d",&M,&N)&&!(M==-1&&N==-1))
    {
        memset(xa,0,sizeof(xa));
        memset(ya,0,sizeof(ya));
        maxx=-1,maxy=-1;
        for (int i=0; i<M; i++)
        {
            scanf("%d %d %d %d",&x,&y,&d,&t);
            if(d)
            {
                for(int i=1;i<=t;i++)
                    ya[x][y+i]=INF;
                maxy=max(maxy,y+t+1);;
                maxx=max(maxx,x+1);
            }
            else
            {
                for(int i=1;i<=t;i++)
                    xa[x+i][y]=INF;//第三个错误
                maxx=max(maxx,x+t+1);//最终的错误
                maxy=max(maxy,y+1);//第一个错误
            }
        }
        for(int i=0;i<N;i++)
        {
            scanf("%d%d%d",&x,&y,&d);
            if(d)
            {
                ya[x][y+1]=1;
            }
            else
            {
                xa[x+1][y]=1;//第三个错误
            }
        }
        scanf("%lf%lf",&sx,&sy);
        if(!(sx>=1 && sx<=199 && sy>=1 && sy<=199))//第二个错误
            printf("0\n");
        else
        {
            printf("%d\n",bfs((int)sx+1,(int)sy+1));
        }
        
    }
    return 0;
}

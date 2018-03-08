//poj3083
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

char maze[42][42];

int step[42][42];
int T,R,C;
struct cell
{
    int x,y;
    cell(int x,int y):x(x),y(y){}
};
typedef struct cell cell;
char vis[42][42];
void bfs(int x,int y)
{
    cell temp(0,0);
    int cx,cy,ct,xx,yy;
    queue<cell> Q;
    Q.push(cell(x,y));
    //memset(step,-1,sizeof(step));
    for (int i=0;i<42;i++)
        for(int j=0;j<42;j++)
        step[i][j]=-1;
    step[x][y]=1;
    while(!Q.empty())
    {
        temp=Q.front();Q.pop();
        cx=temp.x,cy=temp.y;
        for(int i=0;i<4;i++)
        {
            xx=cx+dx[i],yy=cy+dy[i];
            if(1<=xx&&xx<=R&&1<=yy&&yy<=C&&maze[xx][yy]!='#'&&step[xx][yy]==-1)
            {
                step[xx][yy]=step[cx][cy]+1;
                Q.push(cell(xx,yy));
            }
        }
    }
    return ;
}

int main()
{
    int x,y,sx,sy,ex,ey,dir,l,r,s,xx,yy,tdir;
    scanf("%d",&T);
    while(T--)
    {
        memset(maze,0,sizeof(maze));
        memset(vis,0,sizeof(vis));
        scanf("%d %d",&C,&R);
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
            {
                scanf(" %c",&maze[i][j]);
                if(maze[i][j]=='S')
                {
                    sx=i,sy=j;
                    if(i==1)
                    {
                        dir=2;
                        continue;
                    }
                    if(i==R)
                    {
                        dir=0;
                        continue;
                    }
                    if(j==1)
                    {
                        dir=1;
                        continue;
                    }
                    if(j==C)
                    {
                        dir=3;
                        continue;
                    }
                }
                if(maze[i][j]=='E')
                {
                    ex=i;
                    ey=j;
                }

            }

        //left
        l=1,x=sx,y=sy;
        while(maze[x][y]!='E')
        {
            for(int i=-1;i<=2;i++)
            {
                tdir=(dir+4+i)%4;
                xx=x+dx[tdir],yy=y+dy[tdir];
                if(1<=xx&&xx<=R&&1<=yy&&yy<=C&&maze[xx][yy]!='#')
                {
                    l++;
                    dir=tdir;
                    x=xx,y=yy;
                    break;
                }
            }
        }
        //right
        r=1,x=sx,y=sy;
        while(maze[x][y]!='E')
        {
            for(int i=1;i>=-2;i--)
            {
                tdir=(dir+4+i)%4;
                xx=x+dx[tdir],yy=y+dy[tdir];
                if(1<=xx&&xx<=R&&1<=yy&&yy<=C&&maze[xx][yy]!='#')
                {
                    r++;
                    dir=tdir;
                    x=xx,y=yy;
                    break;
                }
            }
        }
        bfs(sx,sy);
        printf("%d %d %d\n",l,r,step[ex][ey]);
    }
    return 0;
}
/*
        for(int i=0;i<=maxx;i++)
        {
            for(int j=0;j<=maxy;j++)
            cout<<xa[i][j]<<" ";
            cout<<endl;
        }
        for(int i=0;i<=maxx;i++)
        {
            for(int j=0;j<=maxy;j++)
            cout<<ya[i][j]<<" ";
            cout<<endl;
        }
        */

找不到tle的原因，udebug上千个数据都是对的，呵呵，放弃了
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

using namespace std;
typedef long long ll;
const int INF = 1000000000;
const int maxn = 1000 + 5;
int dx[4]= {1,0,-1,0};
int dy[4]= {0,1,0,-1};
struct node
{
    int x;
    int y;
    int t;
    node(int x, int y,int t):x(x),y(y),t(t) {}
};

typedef struct node node;


struct bb
{
    char c;
    int t;
};

struct bb board[maxn][maxn];
bool vis[maxn][maxn];
queue<node> FT;
queue<node> Q;
//int ans[700];
//int g=0;

int main()
{
    int T,R,C;
    cin>>T;
    //memset(ans,-1,sizeof(ans));
    while(T--)
    {
        //vector<node> fire;
        //fire.clear();

        scanf("%d %d",&R,&C);
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
            {
                scanf(" %c",&board[i][j].c);
                board[i][j].t=INF;
                if(board[i][j].c=='F')
                {
                    //fire.push_back(node{i,j,0});
                    board[i][j].t=0;
                    FT.push(node(i,j,0));
                }
                if(board[i][j].c=='J')
                {
                    Q.push(node(i,j,0));
                }
            }
        
        while(!FT.empty())
        {
            node cur=FT.front();
            FT.pop();
            //vis[cur.x][cur.y]=1;
            int tt=cur.t+1;
            for(int i=0; i<4; i++)
            {
                int xx=cur.x+dx[i],yy=cur.y+dy[i];
                if(board[xx][yy].t==INF&&1<=xx&&xx<=R&&1<=yy&&yy<=C&&board[xx][yy].c!='#')
                {
                    board[xx][yy].t=tt;
                    FT.push(node(xx,yy,tt));
                }
            }
        }
        

        //memset(vis,0,sizeof(vis));
        /*
        for(int k=0;k<fire.size();k++)
        {
        int x=fire[k].x,y=fire[k].y;
        for (int i=0;i<
        }
        */
        /*
        for(int i=0;i<=R;i++)
        {
            for(int j=0;j<=C;j++)
                cout<<board[i][j].t<<" ";
            cout<<endl;
        }
        */
        int flag=0;
        memset(vis,0,sizeof(vis));
        int xx,yy,tt,x,y;
        
        while(!Q.empty())
        {
            node cur=Q.front();
            Q.pop();
            x=cur.x,y=cur.y;
            vis[x][y]=1;

            if(x==1||x==R||y==1||y==C)
            {
                //cout<<cur.t+1<<endl;
                printf("%d\n",cur.t+1);
                //ans[g]=cur.t+1;
                flag=1;
                while(!Q.empty())Q.pop();
                break;
            }

            tt=cur.t+1;
            for(int i=0; i<4; i++)
            {
                xx=x+dx[i],yy=y+dy[i];
                //cout<<"next "<<xx<<" "<<yy<<" "<<tt<<endl;

                if(!vis[xx][yy]&&board[xx][yy].c!='#'&&tt<board[xx][yy].t&&1<=xx&&xx<=R&&1<=yy&&yy<=C)
                {
                    Q.push(node(xx,yy,tt));
                }

            }
        }
        
        if(flag==0)
        {
            printf("IMPOSSIBLE\n");
        }
        //g++;
        //cout<<"IMPOSSIBLE\n"<<endl;
    }
    return 0;
}
/*

*/

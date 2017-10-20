//UVa10603
#include <iostream>
#include <cstdio>
#include<cstring>
#include<queue>
#define maxn 205
using namespace std;

struct Node
{
    int v[3],dis;
    bool operator<(const Node& rhs)const
    {
        return dis>rhs.dis;
    }
};

int ans[maxn];
bool visit[maxn][maxn];
int da[maxn][maxn];
typedef struct Node Node;

void update_ans(Node &cur)
{
    int u=0;
    for(int i=0;i<3;i++)
    {
        u=cur.v[i];
        if(ans[u]<0||ans[u]>cur.dis)
            ans[u]=cur.dis;
    }
}

void solve(int a,int b,int c,int d)
{
    int cap[3];
    cap[0]=a,cap[1]=b,cap[2]=c;
    memset(ans,-1,sizeof(ans));
    memset(visit,0,sizeof(visit));
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
        da[i][j]=1<<30;
    Node start;
    start.v[0]=0,start.v[1]=0,start.v[2]=c,start.dis=0;
    da[0][0]=0;
    priority_queue<Node> Q;
    Q.push(start);
    while(!Q.empty())
    {
        Node cur=Q.top();
        Q.pop();
        update_ans(cur);
        if(ans[d]!=-1)
            break;
        if(visit[cur.v[0]][cur.v[1]])
            continue;
        visit[cur.v[0]][cur.v[1]]=1;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
        {
            if(i!=j)//why u
            {
                if(cur.v[i]==0||cur.v[j]==cap[j])
                    continue;
                int amount=min(cur.v[i],cap[j]-cur.v[j]);
                Node ne;
                memcpy(&ne,&cur,sizeof(cur));
                ne.v[i]-=amount;
                ne.v[j]+=amount;
                if(da[ne.v[0]][ne.v[1]]>da[cur.v[0]][cur.v[1]]+amount)
                {
                    ne.dis=da[ne.v[0]][ne.v[1]]=da[cur.v[0]][cur.v[1]]+amount;
                    Q.push(ne);
                }
            }
        }
    }
    while(d>=0)
    {
        if(ans[d]!=-1)
        {
            cout<<ans[d]<<" "<<d<<endl;
            return;
        }
        d--;
    }
}

int main()
{
    int a,b,c,d,T;
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c>>d;
        solve(a,b,c,d);

    }
    return 0;
}

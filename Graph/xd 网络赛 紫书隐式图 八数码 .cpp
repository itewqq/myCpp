//#include<bits/stdc++.h>
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<algorithm>
#include<ctime>
#include<cstdlib>
 
using namespace std;
//typedef long long LL;
 
typedef int State[9];
const int maxn=1000000+5;
 
State st[maxn],goal;
int d[maxn];
//const int INF=1<<25;
//const int MOD=1e9+7;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
//set<int> vis;
int vis[362880],fact[9];
 
int tryinsert(int s)
{
    int code=0;
    for (int i=0;i<9;++i)
    {
        int cnt=0;
        for (int j=i+1;j<9;++j)if(st[s][j]<st[s][i])cnt++;
        code+=fact[8-i]*cnt;
    }
    if(vis[code])return 0;
    return vis[code]=1;
}
 
void inittable()
{
    fact[0]=1;
    for (int i=1;i<9;++i)fact[i]=fact[i-1]*i;
    memset(d,0,sizeof(d));
    memset(vis,0,sizeof(vis));
}
 
int bfs()
{
    int x,y,z,newx,newy,newz;
    inittable();
    //vis.clear();
    //memset(st,0,sizeof(st));
 
    int front=1,rear=2;
    while(front<rear)
    {
        //cout<<front<<" "<<rear<<endl;;
        State& s=st[front];
        if(memcmp(goal,s,sizeof(s))==0)return front;
        for (z=0;z<9;++z)if(!s[z])break;
        x=z/3,y=z%3;
        for (int k=0;k<4;++k)
        {
            newx=x+dx[k];
            newy=y+dy[k];
            newz=newx*3+newy;
            if(newx>=0&&newx<3&&newy>=0&&newy<3)
            {
                State& t=st[rear];
                memcpy(&t,&s,sizeof(s));
                t[newz]=s[z];
                t[z]=s[newz];
                d[rear]=d[front]+1;
                if(tryinsert(rear))++rear;
            }
        }
        ++front;
    }
    return 0;
}
 
int main()
{
    int n,ans;
    for (int i=0;i<9;++i)goal[i]=i;
    scanf("%d",&n);
    while(n--)
    {
        memset(st,0,sizeof(st));
        for (int i=0;i<9;++i)scanf("%d",&st[1][i]);
        ans=bfs();
        if(ans)printf("%d\n",d[ans]);
        else printf("cannot\n");
    }
    return 0;
}
 
/**************************************************************
    Problem: 1288
    User: 16020110047
    Language: C++
    Result: 正确
    Time:300 ms
    Memory:42184 kb
****************************************************************/

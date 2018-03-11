//poj3292
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
//const int INF = 1<<28;
const int maxn = 1000000 + 5;
//const int MOD=1e9+7;
//int dx[4]= {0,1,0,-1};
//int dy[4]= {1,0,-1,0};
/*
typedef struct fenshu
{
    int P,Q;
    fenshu(int p,int q):P(p),Q(q){}
};
fenshu pro[2][maxn];
*/
/*
typedef struct Edge
{
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d) {}
} Edge;

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

typedef struct co
{
    int x,y;
    co(int x,int y):x(x),y(y) {}
} co;
*/

/*
int p[maxn];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
*/
//int d[maxn][maxn];
/*
void sush()
{
    int m=sqrt(maxn+0.5);
    for(int i=2;i<=m;i++)if(!vis[i])
        for(int j=i*i;j<=maxn;j+=i)vis[j]=1;
}
*/
/*
long long C[2070][2070];

void get_C(int m)
{
    C[0][0] = 1;
    for(int i=1;i<=m;i++)
    {
        C[i][0] = 1;
        for(int j=1;j<=i;j++)
            //C[i][j] = C[i-1][j]+C[i-1][j-1];
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
    }
}
*/

int n;
int is_prime[maxn];
int H_prime[maxn/10];
int is_Hsei[maxn];
int ac[maxn];

int main()
{
    int m=sqrt(maxn+0.5);
    for(int i=5;i<=m;i+=4)if(!is_prime[i])
    {

        for(int j=5*i;j<maxn;j+=i)is_prime[j]=1;
    }
    for(int i=5;i<maxn;i+=4)if(!is_prime[i])
    {
        H_prime[n++]=i;
    }
    //cout<<n<<endl;
    //for(int i=0;i<n;i++)cout<<H_prime[i]<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i&&H_prime[i]*H_prime[j]<maxn;j++)
    {
        is_Hsei[H_prime[i]*H_prime[j]]=1;
        //cout<<H_prime[i]*H_prime[j]<<endl;
    }
    for(int i=1;i<=maxn;++i)
        ac[i]=ac[i-1]+is_Hsei[i];
    int h;
    while(~scanf("%d",&h)&&h!=0)
    {
        printf("%d %d\n",h,ac[h]);
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
/*
1 4
10000 3 2
2 1
3 3
1000 2 2
4 1
3 1
1000 3 1
4 2
100 4 0

105
*/

昨天的题目，最终的错误是出在如何取到最小值上
应该是对n/d取模，因为最后的解是x0+i*(n/d),所以如果是负数的话也应该是在x0的基础上加n/d，也就是对其取两次模
而我一开始一直在对n进行操作，wa到怀疑人生
今天又和女朋友吵架了，唉😔做题又做不好，心累
//poj1601
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

ll ans[1005];

void ex_gcd(ll a,ll b,ll& d,ll& x,ll& y)
{
    if(!b){d=a;x=1;y=0;}
    else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int tk=0;

ll solve(ll a,ll b,ll n)
{
    ll ans;
    //cout<<a<<" "<<b<<" "<<n<<endl;
    ll d=0,x,y;
    ex_gcd(a,n,d,x,y);
    //cout<<a<<" "<<n<<" "<<d<<" "<<x<<" "<<y<<endl;
    if(b%d==0)
    {
        ans=((x*(b/d))%(n/d)+n/d)%(n/d);
        //ans=(x+n)%n;
        /*
        for(ll i=1;i<d;i++)if(x+i*n/d>0)
        {
            //cout<<x+i*n/d<<endl;
            ans=min(ans,x+i*n/d)%n;
        }
        */
        return ans;
    }
    else
        return -1;
}

int main()
{
    int T=1000;
    while(T--)
    {
    ll x,y,m,n,L;
    scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&L);
    /*
    if(n>m)
    {
        swap(m,n);
        swap(x,y);

    */
    ll Ans=solve(((m-n)%L+L)%L,((y-x)%L+L)%L,L);
    ans[tk++]=Ans;
    /*
    if(Ans==-1)
        printf("Impossible\n");
    else
        printf("%I64d\n",Ans);
    */
    }

    for(int i=0;i<tk;i++)
    {
        if(ans[i]!=-1)
            cout<<ans[i]<<endl;
        else
            cout<<"Impossible\n";
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
702 337 349 762 1908
413 1908 1 -559 121
20000050000
*/

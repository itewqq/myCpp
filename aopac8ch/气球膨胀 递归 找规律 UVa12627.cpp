/*
一开始也想到了递归求解
但是没有想到怎么处理区间的问题
后来发现区间更容易处理，而且当有一整块是可以直接用k^3算

*/
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
#include<bitset>
#include<algorithm>
//freopen("1.txt","r",stdin);

using namespace std;
typedef long long LL;
//const int INF = 1000000000;
//const long long M=1e9+7;
const long long maxn=1000005;
/*
int dx[4]= {1,0,-1,0};
int dy[4]= {0,1,0,-1};
*/

/*
struct bb
{
    char c;
    int t;
};
*/



//long long a[MAXL];
/*
long long Q(int n,long long t)
{
    if(n<0){cout<<n<<" "<<t<<endl; return t;}
    return (Q(n-1,t)%M+Q(n-1,t*a[n])%M)%M;
}
*/

LL pow3[35];

void cpow3()
{
    pow3[0]=1;
    for (int i=1;i<=30;++i)
    {
        pow3[i]=pow3[i-1]*3;
        //cout<<pow3[i]<<endl;
    }
}

LL cal(int k,int i)
{
    //cout<<k<<" "<<i<<" "<<endl;
    if(k==0)
        if(i==1)
            return 1;
        else
            return 0;
    if(i>(1<<(k-1)))
    {
        if(i==(1<<(k))) return pow3[k];
        return cal(k-1,i-(1<<(k-1)))+2*pow3[k-1];
    }
    else if(i==(1<<(k-1)))
    {
        return 2*pow3[k-1];
    }
    else
    {
        return 2*cal(k-1,i);
    }
}

int main()
{
    int n,k,a,b,cnt=0;
    cpow3();
    scanf("%d",&n);
    while(n--)
    {
        cnt++;
        scanf("%d%d%d",&k,&a,&b);
        printf("Case %d: %lld\n",cnt,cal(k,b)-cal(k,a-1));
    }
    return 0;
}

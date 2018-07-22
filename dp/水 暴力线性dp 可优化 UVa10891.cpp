/*
没什么好说的，线性暴力就好了。。
值得注意的是lrj的做法更简单（智商差距，而且可以优化到n^2
为什么没有想到他的那种做法呢，很大程度上是因为没有注意到总数是不变的所以可以对称来求，其次就是没有意识到自己定义的状态其实可以
做进一步的加强。。。
我自己定义的d(i,j)是i到j之间先手能最多净胜多少，他的是先手可以最多得多少分，可见有时候状态定义的简单点可以简化。。？emmmm
*/
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn=100+5;
const int MOD=1e9+7;

int S[maxn],arr[maxn],d[maxn][maxn],vis[maxn][maxn],N;

int cal(int i,int j)//lork
{
    if(vis[i][j])
        return d[i][j];
    vis[i][j]=1;
    if(i==j)
        return d[i][j]=0;
    int mn=-(1<<29),pos=0,flag=2;
    for (int k=j-1;k>=i;k--)
    {

        if(mn<S[j-1]-S[k-1]-cal(i,k))
        {
            mn=S[j-1]-S[k-1]-cal(i,k);
        }
    }
        //mn=min(mn,cal(i,k));
    for (int k=i+1;k<=j;k++)
    {

        if(mn<S[k-1]-S[i-1]-cal(k,j))
        {
            mn=S[k-1]-S[i-1]-cal(k,j);
        }
    }
    return d[i][j]=mn;
        //mn=min(mn,cal(k,j));
}

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    while(~scanf("%d",&N)&&N)
    {
        for (int i=1;i<=N;i++)
        {
            scanf("%d",&arr[i]);
            S[i]=S[i-1]+arr[i];
        }
        memset(vis,0,sizeof(vis));
        printf("%d\n",cal(1,N+1));
    }
    return 0;
}

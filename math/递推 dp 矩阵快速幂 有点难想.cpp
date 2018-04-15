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
typedef long long LL;
 
//const int maxn=1000000+5;
 
//const int INF=1<<25;
const int MOD=1e9+7;
 
 
 
 
 
LL b[3][3],a[3][3],c[3][3];
void mul1()
{
    memset(c,0,72);
    for(int i=0; i<3; i++)
    {
        for(int k=0; k<3; k++)
        {
            for(int j=0; j<3; j++)
                c[i][j] = ( c[i][j] + a[i][k] * b[k][j] ) % MOD;
        }
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            b[i][j]=c[i][j];
        }
    }
}
 
void mul2()
{
    memset(c,0,72);
    for(int i=0; i<3; i++)
    {
        for(int k=0; k<3; k++)
        {
            for(int j=0; j<3; j++)
                c[i][j] = ( c[i][j] + a[i][k] * a[k][j] ) % MOD;
        }
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            a[i][j]=c[i][j];
        }
    }
}
 
void solve_pow(int n)
{
    //int l=a.size();
    memset(b,0,72);
    for(int i=0; i<3; i++)
        b[i][i]=1;
    while(n>0)
    {
        if(n & 1)
            mul1();
        mul2();
        n >>= 1;
    }
    return ;
}
 
 
 
 
int main()
{
    LL prv[3]={4,2,1},ans[3], n;
    while(~scanf("%d",&n))
    {
        //mat a(3,vec(3));
        //memset(a,0,sizeof(a));
        a[0][0]=2,a[0][1]=-1,a[0][2]=1;
        a[1][0]=1,a[1][1]=0,a[1][2]=0;
        a[2][0]=0,a[2][1]=1,a[2][2]=0;
        //cout<<sizeof(a)<<endl;
        solve_pow(n-1);
 
        for (int i=0;i<3;++i)
        {
            for (int j=0;j<3;++j)
        {
            //cout<<a[i][j]<<" ";
            ans[i]=b[i][j]*prv[j]%MOD;
        }
        //cout<<endl;
        }
 
        //cout<<ans[0]<<" "<<ans[2]<<endl;
        printf("%lld\n",((2*ans[0]+ans[2])%MOD+MOD)%MOD);
    }
    return 0;
}
 
/*
1
2
4
7
12
21
*/
 
/**************************************************************
    Problem: 1281
    User: 16020110047
    Language: C++
    Result: 正确
    Time:117 ms
    Memory:1704 kb
****************************************************************/

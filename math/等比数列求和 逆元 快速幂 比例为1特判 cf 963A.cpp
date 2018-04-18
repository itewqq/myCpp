
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
//#include<ctime>
#include<cstdlib>

using namespace std;
typedef long long LL;

//const int maxn=200000+5;

//const int INF=1<<25;
const int MOD=1e9+9;

int pow1(int a,int b)
{
    int ret =1;
    int temp=a;
    while(b)
    {

        if(b&1)
            ret=1LL*ret*temp%MOD;
        temp=1LL*temp%MOD*temp%MOD;
        b>>=1;
    }
    return ret;
}

LL cir=0,ans=0,dech=0;

int main()
{
    int n,a,b,k,tt;
    char c;
    scanf("%d%d%d%d",&n,&a,&b,&k);

    getchar();

    for (int i=0; i<k; ++i)
    {
        c=getchar();
        tt=1LL*pow1(a,n-i)*pow1(b,i)%MOD;//cout<<"c "<<c<<endl;
        tt= c=='+'?tt:-tt;
        cir=(cir+tt+MOD)%MOD;
    }

    tt=(n+1)/k;
    LL up,down,res,invd;
    up=1LL*(pow1(a,n+1)-pow1(b,n+1)+MOD)%MOD;
    down=1LL*(pow1(a,n+1)-1LL*pow1(b,k)*pow1(a,n+1-k)+MOD)%MOD;
    invd=pow1(down,MOD-2);
    if(up==0)
    {
        ans=1LL*cir*tt%MOD;
    }
    else
    {
        ans=1LL*(cir*up%MOD*invd%MOD)%MOD;
    }
    cout<<(ans+MOD)%MOD<<endl;
    return 0;
}


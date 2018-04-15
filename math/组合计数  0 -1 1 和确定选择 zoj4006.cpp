本来觉得有点复杂因为要考虑重复，但是发现+1的个数一定是比-1要多的。。所以不可能出现重复选择，直接用组合数就行了
组合数需要分成上下两部分，下面需要用逆元，另外外面乘的概率也需要逆元
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
typedef long long LL;//不影响下面式子中的1LL
const int maxn=200000+5;
const int MOD=1e9+7;

int inv[maxn],fac[maxn],p[maxn];
int i;
inline int C(int n,int m){return n<m?0:1LL*fac[n]*inv[m]%MOD*inv[n-m]%MOD;}//last error??最后一个错误就是很傻逼的多加了括号。。加了
//之后就成了先算括号里的再乘1LL，所以括号里的可能会溢出
int main()
{
    int T,m,n;
    
    for (i=2,fac[0]=1,fac[1]=1;i<maxn;++i)fac[i]=1LL*i*fac[i-1]%MOD;//n!%MOD
    for (inv[0]=inv[1]=1,i=2;i<maxn;++i)inv[i]=1LL*(MOD-inv[MOD%i])*(MOD/i)%MOD;//inv of n
    for (p[0]=1,p[1]=inv[2],i=2;i<maxn;++i)p[i]=1LL*p[i-1]*p[1]%MOD;//inv of 2^n
    for (i=2;i<maxn;++i)inv[i]=1LL*inv[i]*inv[i-1]%MOD;//inv of n!
    int ans;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d %d",&n,&m);
        if(m<0)
            m=-m;
        for (i=0;i<=(n-m)/2;++i)
            ans=(ans+1LL*C(n,i)*C(n-i,m+i)%MOD*p[n+m+2*i]%MOD)%MOD;
        printf("%d\n",(ans+MOD)%MOD);
    }
    return 0;
}

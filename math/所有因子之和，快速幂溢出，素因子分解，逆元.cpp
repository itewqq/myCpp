第一个错误是没有分清每一步里是对谁取模，实际上利用逆元的时候是对mb取模，而其他运算的时候则是对MOD取模，这个是第一个错误
另外，需要对取模的结果加上模（为什么？
第二个就是没想到快速幂会中间结果会超出int64，因为这时候的模是mb，而mb可能相当大，即mb的平方是有可能超出int64的
记住模值超过int的话平方快速幂就可能超过int64！
此时用了一种神奇的类似于快速幂的二分乘法算法，解决了
//poj1845
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

const int MOD=9901;

ll multi(ll a,ll b,ll m)
{
    ll ans = 0;
    a %= m;
    while(b)
    {
        if(b & 1)
        {
            ans = (ans + a) % m;
            b--;
        }
        b >>= 1;
        a = (a + a) % m;
    }
    return ans;
}

ll qpow(ll a,ll b,ll mb)
{
    ll ans=1;
    a%=mb;
    while(b)
    {
        if(b&1)
            ans=multi(ans,a,mb);
        a=multi(a,a,mb);
        b>>=1;
    }
    return ans;
}

int p[10001];
int n[10001];

int main()
{
    ll A,B;
    cin>>A>>B;
    int k=0;
    if(A%2==0)
    {
        p[++k]=2;
        n[k]=0;
        while(!(A%2))
        {
            n[k]++;
            A/=2;
        }
    }
    for(int i=3;i*i<=A;i+=2)
    {
        if(A%i==0)
        {
            p[++k]=i;
            n[k]=0;
            while(!(A%i))
            {
                n[k]++;
                A/=i;
            }
        }
    }

    if(A!=1)
    {
        p[++k]=A;
        n[k]=1;
    }

    ll mb;
    ll ans=1;
    for(int i=1;i<=k;i++)
    {
        mb=(ll)MOD*(ll)(p[i]-1);
        ans*=(qpow(p[i],B*n[i]+1,mb)%mb+mb-1)/(p[i]-1);
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}


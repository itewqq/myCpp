话说xdoj的题目虽然少但是好像每做一道题都能学到东西的样子。。。。。。

这题是把大组合数取模搞得有点极限了，首先组合数本身很大，其次模不是质数
首先大组合数取模有个操作，Lucas定理，但是其要求模为质数，在这里不是质数
不是质数怎么办，将模质数分解，然后对每一个质数分别求，最后用CRT合并。。。
在这里由于1001是确定的，可以被分解，所以可以预处理Lucas（话说这个东西只要求出小于模值的cm就可以了？？），这样的话足够在时限之内解决问题

#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL long long
const int MOD=1001;

LL ML[3];
LL cm[20][20][3];

LL pow1(LL a,LL b,LL mod)
{
    if(b==0)return 1;
    LL res1=pow1(a,b/2,mod)%mod;
    res1=res1*res1%mod;
    if(b%2==1)res1=res1*a%mod;
    return res1;
}

void calcm(int k)
{

    LL p=ML[k];
    for (int n=0;n<20;n++)
        for (int j=0;j<20;j++)
    {
        int m=j;
        if(n<m){cm[n][m][k]=0;continue;}
        if(m>n-m)m=n-m;
        LL s1=1,s2=1;
        for (int i=0;i<m;++i)
        {
            s1=s1*(n-i)%p;
            s2=s2*(i+1)%p;
        }
        cm[n][j][k]=s1*pow1(s2,p-2,p)%p;
    }
}



LL Lucas(LL n, LL m,LL k) 
{
    LL mod=ML[k];
    if(m ==0)  return 1;
    else return  (cm[n%mod][m%mod][k]*Lucas(n/mod,m/mod,k))%mod;
}

LL Extended_Euclid(LL a,LL b,LL &x,LL &y)
{
    LL d;
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    d=Extended_Euclid(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
LL w[3]={7,11,13};
LL Chinese_Remainder(LL a[],LL w[],LL len)
{
    LL i,d,x,y,m,n,ret;
    ret=0;
    n=1;
    for (i=0; i<len; i++)
        n*=w[i];
    for (i=0; i<len; i++)
    {
        m=n/w[i];
        d=Extended_Euclid(w[i],m,x,y);
        ret=(ret+y*m*a[i])%n;
    }
    return (n+ret%n)%n;
}

int main()
{
    LL a[3];
    ML[0]=7,ML[1]=11,ML[2]=13;
    for (int i=0;i<3;i++)
        calcm(i);
    LL w[3]={7,11,13};
    int T,N;
    LL temp,ans;
    scanf("%d",&T);
    while(T--)
    {
        temp=1;
        scanf("%d",&N);
        scanf("%lld",&temp);
        ans=temp%MOD;
        for (int i=1;i<N;i++)
        {
            scanf("%lld",&temp);
            for (int j=0;j<3;j++)
            {
                a[j]=Lucas(N-1,i,j);
            }
            ans=(ans+temp*Chinese_Remainder(a,w,3))%MOD;
        }

        printf("%lld\n",ans);
    }
    return 0;
}

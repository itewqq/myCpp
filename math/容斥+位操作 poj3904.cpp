容斥定理的应用
这里有个要注意的就是可以不用化简容斥定理的式子，直接对其每个单个元素判断是该减去还是加上就行了！

错误的点
1 ==与=
2 位运算的优先级
3 要求出所有由单次质数相乘得到的合数的信息，这里用了位操作枚举
4 最后把n和序列最大值搞混了。。
5 计算C(4,n)其实不用打表，每次的计算都是常数时间
//#include<bits/stdc++.h>
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
//#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<algorithm>

using namespace std;
typedef long long LL;
const int maxn=10000+5;

//const int INF=1<<29;
//const int MOD=1000007;


int getint()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}

int num[maxn],flag[maxn],factor[20];

LL Cal(LL i)
{
    return  i*(i-1)*(i-2)*(i-3)/24;
}

void doit(int a)
{
    int aa=a,cnt=0;
    if(aa%2==0)
    {
        factor[++cnt]=2;
        while(!(aa%2))aa/=2;//youxianji ?
    }
    for (int i=3; i*i<=aa; i+=2)
    {
        if(aa%i==0)
        {
            factor[++cnt]=i;
            while(!(aa%i))aa/=i;//false completor
        }
    }
    if(aa>1)
    {
        factor[++cnt]=aa;
    }
    int mul;
    int f;
    for (int i=1; i<(1<<(cnt)); ++i)
    {
        mul=1;
        f=0;
        /*
        for (int k=1; k<=cnt; ++k)//also can from left to the right
        {
            if(i&(1<<(k-1)))
            {
                mul*=factor[k];
                ++f;
            }
        }
        */
        for (int j = 0; (i >> j) > 0; j++)
        {
            if ((i >> j) & 1)
            {
                mul*=factor[j+1];
                ++f;
            }
        }
        num[mul]++;
        flag[mul]=f;
    }
    return ;
}

int main()
{
    int n,a,ma;
    LL ans;
    while(~scanf("%d",&n))
    {
        ma=0;
        ans=0;
        memset(flag,0,40004);
        memset(num,0,40004);
        for (int i=1; i<=n; ++i)
        {
            a=getint();
            doit(a);
            ma=max(a,ma);
        }
        for (int i=2; i<=ma; i++)
        {
            if(flag[i]%2)
                ans+=Cal(num[i]);
            else
                ans-=Cal(num[i]);
        }
        ans=Cal(n)-ans;
        printf("%I64d\n",ans);
    }

    return 0;
}

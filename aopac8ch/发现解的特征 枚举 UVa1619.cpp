/*

这个题又是一个自己没想到的，不过很久没有做题了，拿来恢复一下手感。。
这个先要找解的特征，（并不是单调也不是dp
不要从区间开始找，从min值开始找对应的最大的区间比直接找区间要简单得多，为什么简单呢
那就是对于每一个值，他能搞到的最大值，一定得是向左向右能延伸到的最远处
而这个最远处可以不用遍历查找，而是利用结构的性质，一层一层跳过去，这里就是避免遍历导致n方复杂度的地方
*/
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cctype>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long LL;
const int maxn=100000+5;

int l[maxn],r[maxn],lt,n,rt;
LL sum[maxn],a[maxn];

int main()
{
    //freopen("1.txt","w",stdout);
    int ks=0;
    while(~scanf("%d",&n))
    {
        if(ks++)
            putchar('\n');
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i])
                flag=1;
        }

        l[1]=1;
        for(int i=1;i<=n;i++)
        {
            int cur=i;
            sum[i]=a[i]+sum[i-1];
            l[i]=i;
            if(i!=1)
            {
                if(a[i]>a[i-1])
                    l[i]=i;
                else
                    while(1)
                    {
                        cur=l[cur-1];
                        if(cur==1||a[i]>a[cur-1])
                        {
                            l[i]=cur;
                            break;
                        }

                    }
            }
        }
        r[n]=n;
        for(int i=n;i>=1;i--)
        {
            int cur=i;
            //sum[i]=a[i]+sum[i-1];
            r[i]=i;
            if(i!=n)
            {
                if(a[i]>a[i+1])
                    r[i]=i;
                else
                    while(1)
                    {
                        cur=r[cur+1];
                        if(cur==n||a[i]>a[cur+1])
                        {
                            r[i]=cur;
                            break;
                        }

                    }
            }
        }
        /*
        for(int i=1;i<=n;i++)
            cout<<l[i]<<" "<<r[i]<<endl;
        */
        int am=0,al=1,ar=n;
        LL as=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]*(sum[r[i]]-sum[l[i]-1])>as)
            {
                as=1LL*a[i]*(sum[r[i]]-sum[l[i]-1]);
                al=l[i],ar=r[i];
            }
        }
        if(flag)
        {
            printf("%lld\n",as);
            printf("%d %d\n",al,ar);
        }
        else
        {
            printf("0\n");
            printf("1 1\n");
        }

    }
    return 0;
}


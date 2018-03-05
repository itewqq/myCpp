//Uva 714
//用了几个小时得来的教训就是要正确的写二分。。很多细节，区间左右的开闭，取中公式的写法，最后取左还是取右，等等
//逆向输出保证顺序，没有证明，看了刘大爷的代码，直觉上可以理解，但是不知道怎么证明
//二分这种用法，没有想到 对于没有办法解决的事情，先给他定一个界限，其实这个界限也就是显然存在的一种东西
//比如说最大值最小化，那么就可以确定确实存在一个数，使得最大值小于这个数
#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<set>

using namespace std;
typedef long long LL;
int N,M,K;
LL sum;
bool last[505];
int seq[505];
bool p(LL x)
{
    //cout<<"x  "<<x<<endl;
    int m=K,i;
    LL temp=0;
    for(i=0; i<M&&m>1; i++)
    {
        temp+=seq[i];
        if(temp>x)
        {
            temp=seq[i];
            m--;
        }
        //cout<<"temp "<<temp<<endl;
    }

    //cout<<"m  "<<m<<endl;
    if(i!=M&&m==1)
    {
        for(; i<=M; i++)
            temp+=seq[i];
    }
    if(temp>x)
        return false;
    return true;

}
int main()
{
    int m;
    LL l=0,r,temp,mid;
    scanf("%d",&N);
    while(N--)
    {
        memset(last,0,sizeof(last));
        memset(seq,0,sizeof(seq));
        sum=0;
        l=1;
        int maxp=-1;
        scanf("%d %d",&M,&K);
        for (int i=0; i<M; i++)
        {
            scanf("%d",&seq[i]);
            sum+=seq[i];
            maxp=max(maxp,seq[i]);
        }
        r=sum;
        l=maxp;
        while(l<r)
        {
            mid=l+(r-l)/2;
            //cout<<"l "<<l<<"r "<<r<<endl;
            if(p(mid))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        //cout<<"r "<<r<<endl;
        temp=0;
        m=K;
        int i;
        for (i=M-1;i>=0;i--)
        {
            temp+=seq[i];
            //cout<<seq[i]<<endl;
            if(temp>l||m>i+1)
            {
                //cout<<"temp "<<temp<<endl;
                temp=seq[i];
                m--;
                last[i]=true;
            }
        }
        /*
        i--;
        for(;m!=1&&i>=0;m--,i--)
        {
            last[i]=true;
        }
        */
        for (int i=0;i<M-1;i++)
        {
            printf("%d ",seq[i]);
            if(last[i])
                printf("/ ");
        }
        printf("%d\n",seq[M-1]);
        //printf("\n");

    }
    return 0;
}

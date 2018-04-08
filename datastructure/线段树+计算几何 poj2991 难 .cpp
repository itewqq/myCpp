线段树
挑战dalao硬是把区间修改变成了点修改orz
这个看到现在要一下子完全想清楚也还是有点难度，真的非常复杂的一个题目。。。非常经典，非常经典
最后出错竟然出在数组开小了，为什么这个会有3倍多的节点呢？？？？
//poj2991
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
#define M_PI		3.14159265358979323846

using namespace std;
typedef long long LL;
const int maxn=20000+5;
//const int MOD=1000000007;
int sq[maxn];
double prev[maxn],vx[2*maxn], vy[2*maxn],ang[2*maxn],a;
int s;

void init(int k,int l,int r)
{
    //cout<<k<<" "<<l<<" "<<r<<endl;
    ang[k]=0.0;
    vx[k]=0.0;
    if(r==l)
        vy[k]=sq[l];
    else
    {
        int chl=2*k,chr=2*k+1,m=l+(r-l)/2;
        init(chl,l,m);
        init(chr,m+1,r);
        vy[k]=vy[chl]+vy[chr];
    }
    return ;
}

void change(int k,int l,int r)
{
    if(s<l)return ;
    else if(s<r)
    {
        int chl=2*k,chr=2*k+1,m=l+(r-l)/2;
            change(chl,l,m);
            change(chr,m+1,r);
            if(s<=m)ang[k]+=a;
            //double si,cs;
            double si=sin(ang[k]),cs=cos(ang[k]);
            vx[k]=vx[chl]+(cs*vx[chr]-si*vy[chr]);
            vy[k]=vy[chl]+(si*vx[chr]+cs*vy[chr]);
    }
    return ;
}

int main()
{
    int N,C,ta;
    while(~scanf("%d %d",&N,&C))
    {
        for (int i=1;i<=N;++i)
            scanf("%d",&sq[i]);

        init(1,1,N);
        for (int i=1;i<N;++i)prev[i]=M_PI;
        for (int i=0;i<C;++i)
        {
            scanf("%d %d",&s,&ta);
            a=1.0*ta/360.0*2*M_PI-prev[s];
            change(1,1,N);

            prev[s]=a+prev[s];
            printf("%.2f %.2f\n",vx[1],vy[1]);
        }
        printf("\n");
    }
    return 0;
}

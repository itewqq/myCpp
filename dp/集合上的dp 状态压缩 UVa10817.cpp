集合上的dp，就当时状态压缩吧。。
还是写的记忆化搜索，虽然感觉状态重合的不是那么多？？
主要还是减枝吧
第一类错误是没有memset d和sl，sl的忘记是个重大失误
第二类错误是位操作的错乱，首先应该明确每一步的对象与结果，新qq一开始不是直接赋0的。。以及最重要的~运算和！不是一回事！！！fuck！！
第三类就是数组越界，忘记了还有20个原来的老师
第四类是读入每个老师的list的时候的读法错乱，为什么不能在while()的括号里读？不解
//UVa 10817
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

using namespace std;
typedef long long LL;
const int maxn=100+5;

const int INF=1<<29;
const int MOD=1000007;

int s,m,n,c[maxn+20],sl[maxn+20],d[maxn+20][1<<8][1<<8];

int dp(int a,int q0,int q1,int q2)
{
    if(a>=m&&q2==(1<<s)-1)return d[a][q1][q2]=0;//保证原来的教师保留情况下的剪枝
    if(d[a][q1][q2])return d[a][q1][q2];//记忆化搜索
    if(a==m+n) return d[a][q1][q2]=INF;//如果能走到这儿说明还没有能够让所有课都有两个人教
    int aa,qq0=q0,qq1=q1,qq2=q2;
    aa=a+1;
    qq2|=q1&sl[aa];
    qq1|=q0&sl[aa];
    qq0|=q0&(~sl[aa]);
    if(aa<=m)
        return d[a][q1][q2]=dp(aa,qq0,qq1,qq2)+c[aa];
    else
        return d[a][q1][q2]=min(dp(aa,qq0,qq1,qq2)+c[aa],dp(aa,q0,q1,q2));
}

int main()
{
    char temp;
    while(~scanf("%d%d%d",&s,&m,&n)&&s)
    {
        for (int i=1; i<=m+n; ++i)
        {
            scanf("%d",&c[i]);
            sl[i]=0;
            
            temp=getchar();
            while(temp!=10)
            {
                temp=getchar();
                if(isdigit(temp))sl[i]|=(1<<(temp-'0'-1));
            }
        }
        printf("%d\n",dp(0,(1<<s)-1,0,0));
        memset(d,0,sizeof(d));
        //memset(sl,0,sizeof(sl));
    }
    return 0;
}

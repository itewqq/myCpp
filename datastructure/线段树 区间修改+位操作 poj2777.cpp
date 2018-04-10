做的第一个区间修改吧，算是第一次有点清楚了线段树这个神奇的操作。。
lazy真的很神奇，如果在update的时候需要递归，则将lazy下放，同时需要注意的是被传递标记的子树即使没有递归到也需要重新maintain，
因为影响到的所有节点都是需要maintain的
这里的神奇一点是标记就是值设置成为的值（似乎都是？
用二进制表示颜色，这样考虑左右节点的时候就可以用一个位操作的|来合并左右的结果
错误：
一个是在maintain的时候应该先考虑左右节点再考虑setv
另一个是读入颜色值的时候应该把它转化为二进制。。。竟然忘了导致了wa很久
//poj2777
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
const int maxn=100000+5;

//const int INF=1<<29;
//const int MOD=1000007;

/*
int getint()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
*/
int Col[4*maxn],setv[4*maxn],C,ans,y1,y2;

void maintain(int o,int L,int R)
{
    int lc=o*2,rc=o*2+1;
    if(R>L)//先考虑左右节点
        Col[o]=Col[lc]|Col[rc];
    if(setv[o]>0)//再考虑setv的影响
        Col[o]=setv[o];
    return ;
}

void pushdown(int o)//下放标记
{
    int lc=o*2,rc=o*2+1;
    if(setv[o]>0)
    {
        setv[lc]=setv[rc]=setv[o];
        setv[o]=0;
    }
    return ;
}

void update(int o,int L,int R)
{
    int lc=o*2,rc=o*2+1;
    if(y1<=L&&R<=y2)
    {
        setv[o]=C;
    }
    else
    {
        pushdown(o);
        int M=L+(R-L)/2;
        if(y1<=M)update(lc,L,M);else maintain(lc,L,M);
        if(M<y2)update(rc,M+1,R);else maintain(rc,M+1,R);
    }
    maintain(o,L,R);
    return ;
}

void query(int o,int L,int R)
{
    if(setv[o]>0)
    {
        ans|=setv[o];
    }
    else if(y1<=L&&R<=y2)
    {
        ans|=Col[o];
    }
    else
    {
        int M=L+(R-L)/2;
        if(y1<=M)query(o*2,L,M);
        if(M<y2)query(o*2+1,M+1,R);
    }
    return ;
}

int main()
{
    int L,T,O,tc,k;
    char temp;
    scanf("%d%d%d",&L,&T,&O);
    Col[1]=1;
    setv[1]=1;
    int out;
    while(O--)
    {
        ans=0;
        out=0;
        getchar();
        temp=getchar();
        if(temp=='C')
        {
            C=0;
            scanf("%d%d%d",&y1,&y2,&tc);
            C|=(1<<(tc-1));
            if(y1>y2)swap(y1,y2);
            update(1,1,L);
        }
        else if(temp=='P')
        {
            scanf("%d%d",&y1,&y2);
            if(y1>y2)swap(y1,y2);
            query(1,1,L);
            k=0;
            while(k<T)
            {
                if((1<<k)&ans)
                    ++out;
                ++k;
            }
            printf("%d\n",out);
        }
    }
    return 0;
}

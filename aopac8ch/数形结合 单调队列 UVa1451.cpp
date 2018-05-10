/*
这个题也是单调优化，话说这一章这几个题简直都叫做单调优化好了。。。
首先想暴力，先预处理出前缀和，然后遍历每个点，然后找出在他之前的与他距离大于等于L的
单调优化的一个特点就是把不可能为解的点直接排除在考虑范围之外。。当然这个有点难操作，想出来把什么点排除就有点难了/喷血
首先数形结合，确定了要保留的是一个单调递增的，凹图形，也就是一个单调栈
这样的话就只需要在单调栈中寻找对应的点就可以了
但是还有一个优化，就是每次找到一个点之后，他前面的点就不可能成为解了！这个是很重要的一点，也很难想到
这个直接使得复杂度变成了O(n)！但是这样的话就不是单调栈了，就成了单调队列，要在两端操作

需要注意的点
1 实现的时候尽量使用同一种风格，比如左闭右开的区间表示，初始化，开始的点，等等。自己一开始没搞清楚，浪费了很多时间
2 每个等号都玄学。。讲究的。因为他要考虑很多东西，在平均值最大的前提下要找到尽量短的，尽量靠前的段，因此小于和小于等于都是不一样的
3 最重要的最需要注意的一点是平均值并不是(sumi-sumj)/(i-j)，而是(sumi-sum[j-1])/(i-j+1)...也就是说要多算一个点
  也正因为这个没有看懂刘的代码，只能自己写了一个单单考虑斜率的程序，在最后把答案的左边界加上1就是正确答案了
*/
//UVa1451
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100000+5;
//const int MOD=1e9+7;

int sum[maxn],p[maxn];
char ori[maxn];

inline int cmp(int x1,int x2,int x3,int x4)
{
    return (sum[x2]-sum[x1])*(x4-x3)-(sum[x4]-sum[x3])*(x2-x1);
}

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int T,n,L,t1,c;
    char tmp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&L);
        getchar();
        gets(ori);
        for (int i=1;i<=n;++i)
        {
            sum[i]=sum[i-1]+ori[i-1]-'0';
        }
        int ansL=0,ansR=L,fr=1,nr=1;
        //p[i...j)
        for (int t=L;t<=n;t++)
        {
            t1=t-L;//这里其实就是已经多减了一个点了
            while(nr>fr+1&&cmp(p[nr-2],t1,p[nr-1],t1)>=0)nr--;
            p[nr++]=t1;
            while(nr>fr+1&&cmp(p[fr],t,p[fr+1],t)<=0)fr++;
            c=cmp(ansL,ansR,p[fr],t);
            if(c<0||(c==0&&t-p[fr]<ansR-ansL))
                ansL=p[fr],ansR=t;
        }
        printf("%d %d\n",ansL+1,ansR);
    }
}


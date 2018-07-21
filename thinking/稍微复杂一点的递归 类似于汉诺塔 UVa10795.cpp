/*
自己想到了两个状态往同一个中间状态变，也想到了取最大的变化的K
但是没想出来状态如何表示以及怎么计算cal(F,i,final);
这个有个很神奇的特性，可以说是无后效性？可能吧
也就是说，你k动还是不动跟k-1的这些毫无关系，当讨论k-1这一坨的时候就像比他们大的都不存在一样就可以了
另外，这个状态的表示也很神奇，用数组存下每个大小对应的盘子吗。。。
在递归过程中主要是得搞清楚，当前的状态怎么算完全取决第k个的前后两个安排是否发生变化
*/
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn=60+5;
const int MOD=1e9+7;

int ori[maxn],aft[maxn],N;

LL cal(int *P,int k,int f)
{
    if(k==1)
    {
        if(P[k]==f)
            return 0LL;
        else
            return 1LL;//not efficient ! should be  if(!k)return 0;
    }

    if(P[k]==f)
        return cal(P,k-1,f);
    else
        return cal(P,k-1,6-P[k]-f)+(1LL<<(k-1));// 1LL last error!
}

int main()
{
    int cnt=1;
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    while(~scanf("%d",&N)&&N)
    {
        for (int i=1;i<=N;i++)
            scanf("%d",&ori[i]);
        for (int i=1;i<=N;i++)
            scanf("%d",&aft[i]);
        int k,f1,f2;
        for (k=N;k>0;k--)
            if(ori[k]!=aft[k])
            {
                f1=ori[k],f2=aft[k];
                break;
            }
        //cout<<k<<endl;
        if(k>1)
            printf("Case %d: %lld\n",cnt,cal(ori,k-1,6-f1-f2)+cal(aft,k-1,6-f1-f2)+1);
        else
            printf("Case %d: %d\n",cnt,k);
        cnt++;
    }
    return 0;
}

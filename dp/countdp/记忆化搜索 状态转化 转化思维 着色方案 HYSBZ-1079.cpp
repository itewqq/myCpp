/*
这个题可以说很神奇，
如果solve函数有k个参数，肯定不现实，空间时间都无法实现。
我一开始想的是用i，j和五个二进制表示状态
后来看了AC代码之后发现其实不需要i，因为i已经隐含在五个二进制数当中
进一步发现甚至不需要用二进制数，只需要知道还有i个的油漆数有多少个就行了
那么是为什么呢？这里的要求满足的顺序性和无后效性是怎么体现出来的？
很简单，假如没有考虑这样的事，那么之后的肯定是每一种颜色都试一下。但是因为考虑到之前用过的颜色这次不能再用，所以需要从这种颜色所在的
类别里减去1
其实说白了就是，在这个问题里，到某个节点后，有多少种情况只和颜色在不同可使用次数中的分布有关系！和具体哪个颜色并无关系！这是非常重要的
在计数型的dp里可能会经常有这种思维吧。。还是自己做题太少
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
const int maxn=100+5;
const int MOD=1e9+7;


int cnt[6];
LL dp[16][16][16][16][16][6];

LL solve(int c1,int c2,int c3,int c4,int c5,int pre)
{
    //cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<" "<<c5<<endl;
    if(dp[c1][c2][c3][c4][c5][pre])return dp[c1][c2][c3][c4][c5][pre];
    if(!c1&&!c2&&!c3&&!c4&&!c5)return dp[c1][c2][c3][c4][c5][pre]=1;
    LL re=0;
    if(c1)re=(re+(c1-(pre==2))*solve(c1-1,c2,c3,c4,c5,1)%MOD)%MOD;
    if(c2)re=(re+(c2-(pre==3))*solve(c1+1,c2-1,c3,c4,c5,2)%MOD)%MOD;
    if(c3)re=(re+(c3-(pre==4))*solve(c1,c2+1,c3-1,c4,c5,3)%MOD)%MOD;
    if(c4)re=(re+(c4-(pre==5))*solve(c1,c2,c3+1,c4-1,c5,4)%MOD)%MOD;
    if(c5)re=(re+c5*solve(c1,c2,c3,c4+1,c5-1,5)%MOD)%MOD;
    //cout<<re<<endl;
    return dp[c1][c2][c3][c4][c5][pre]=re;
}

int main()
{
    int k,x;
    scanf("%d",&k);
    for (int i=0;i<k;++i)
    {
        scanf("%d",&x);
        cnt[x]++;
    }
    printf("%lld\n",solve(cnt[1],cnt[2],cnt[3],cnt[4],cnt[5],0));
    return 0;
}

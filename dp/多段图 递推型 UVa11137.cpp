这个题属于所谓多段图dp（或者说就是个递推？？
这种问题都是有着相似的结构，定义不同阶段的状态，一个阶段的某个状态只能转移到下一个阶段里的状态，类似于神经网络的前向传播
而就这个题来说一个优化是，可以从当前阶段的小状态中获取信息从而降低复杂度！
也就是dp[i][j]=dp[i-1][j]+dp[i][j-i^3]
本来应该是 for k=0:j/i^3 dp[i][j]=dp[i-1][j-k*i^3]
//UVa11137
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
//#include<cmath>
#include<cstring>
#include<string>
#include<set>
using namespace std;
typedef long long LL;
const int maxn=10000+5;
//const int MOD=1e9+7;

//LL pow[maxn];

LL d[25][maxn];

int main()
{
    int N;
    d[0][0]=1;
    for (int i=1;i<22;++i)
        for (int j=0;j<maxn;++j)
    {
        d[i][j]=d[i-1][j];
        if(j>=i*i*i)
            d[i][j]+=d[i][j-i*i*i];
    }
    while(~scanf("%d",&N))
    {
        printf("%lld\n",d[21][N]);
    }
    return 0;
}

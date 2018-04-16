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
#include<ctime>
#include<cstdlib>

using namespace std;

int T,N,M,num,noi;
int base[11],dp[11][1<<11],posb[1<<11];

void calp(int k,int state)//dfs来找到所有可能的状态，思路是如果前面有奇数个1当前就必须放1
{                         //否则 除非是遇到了M为奇数而且是最后一个了，之外的情况 放1或放0都可以的
    int ns=state;
    ns|=(1<<k);
    if(k==M)
    {
        posb[++num]=state;
        return ;
    }
    if(noi%2&&(state&1<<(k-1)))
    {
        noi++;
        calp(k+1,ns);
        noi--;
        return ;
    }
    calp(k+1,state);
    if(noi%2==0&&k>M-2)
        return ;
    noi++;
    calp(k+1,ns);
    noi--;
    return ;
}

int main()
{
    int cb,ans,temp,t2;
    scanf("%d",&T);
    while(T--)
    {
        num=0,ans=0;
        scanf("%d%d",&N,&M);
        for (int i=1; i<=N; ++i)
        {
            t2=0;
            for (int j=0; j<M; ++j)
            {
                scanf("%d",&temp);
                if(temp)
                    t2|=(1<<j);
            }
            base[i]=t2;
        }
        memset(dp,0,sizeof(dp));
        calp(0,0);
        for (int i=1; i<=num; ++i)
        {
            if((base[1]&base[2]&posb[i])==posb[i])
            {
                dp[2][base[2]&(~posb[i])]= __builtin_popcount(posb[i])/2;
            }
        }

        for (int i=3; i<=N; ++i)//each line
        {
            cb=base[i];
            for (int j=1; j<=num; ++j)// 对于当前行，可能有num种改变方式
            {
                if((cb&posb[j])!=posb[j])// 如果这种改变方式不能用于当前则continue
                    continue;
                for (int w=1; w<=num; ++w)// 在当前这种改变方式下，可以从前面的 base[i-1]的改变方式中得到，也就是枚举这一行可能从谁那里转移过来
                {
                    int k;
                    if((base[i-1]&posb[w])==posb[w])
                        k=base[i-1]&(~posb[w]);//k就是之前一行可能存在的改变后的state
                    else
                        continue;
                    if((k&posb[j])==posb[j])//如果前面一行的state兼容当前的change方式，则选择大的
                    {
                        dp[i][base[i]&(~posb[j])]=max(dp[i][base[i]&(~posb[j])],dp[i-1][k]+__builtin_popcount(posb[j])/2);
                    }
                    else//如果前面一行不兼容当前change方式，那么可以认为当前行没有新放方块，其实也可以不用这个，因为0000这种change方式是考虑过了的
                        dp[i][base[i]]=max(dp[i][base[i]],dp[i-1][k]);
                }
            }
        }
        for (int i=0; i<(1<<(M)); ++i)
            ans=max(ans,dp[N][i]);
        printf("%d\n",ans);
    }
    return 0;
}

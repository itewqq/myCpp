//最长公共上升子序列，WA了一二十发吧。。
//想象力还是差一点。
//强行定义状态，有时候状态里的一些特征可以被同一个数字描述，在不会丢失正确解的情况下就是这么操作。。。
//是怎么想到这个状态的，一开始就是纯粹的多个特征，全面描述了两个序列，这些其实也是一般线性结构上的动态规划的常用方法，然后进行化简，
//最后得到的就是一个这样的状态，很神奇。。
//主要是分阶段，一个i是一个阶段，如何从上一个阶段构造出下一个阶段，就是最重要的思想，我觉得有必要去看一下算导对于贪心算法的证明。。。
//出错的地方，在于状态转移时对于路径的记录，一开始想错了，不能单单通过j的转移就确定路径，因为这样的话不同的i对应的j可能会从不同的j转移过来，所以
//应该用一个二维数组来存储路径
//第二点搞错的地方就在于，我的状态转移的时候记录路径的方法是要依据之前的j，但是如果当前j之前的都扫描过了，没有能接上的，那就说明得新开一个子序列，这
//种情况是需要特殊处理的，之前一直没有考虑到所以一直出错/WA到喷血
#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string.h>
using namespace std;
int Aq[505],Bq[505],table[505][505];
int dp[505][505];
int fuck[505];
int Ans[700];
int main()
{
    int N,LA,LB,ans,af,s;
    cin>>N;
    while(N--)
    {
        ans=0;
        memset(Aq,0,sizeof(Aq));
        memset(Bq,0,sizeof(Bq));
        memset(table,-1,sizeof(table));
        memset(dp,0,sizeof(dp));
        memset(fuck,0,sizeof(fuck));

        cin>>LA;
        for (int i=1; i<=LA; i++)
            cin>>Aq[i];
        cin>>LB;
        for (int i=1; i<=LB; i++)
            cin>>Bq[i];

        for(int i=1; i<=LA; i++)
        {
            for (int j=1; j<=LB; j++)
            {
                int ma=0;
                if(Aq[i]!=Bq[j])
                    dp[i][j]=dp[i-1][j];
                else
                {
                    bool flag=false;
                    for (int k=1; k<j; k++)if(Bq[k]<Bq[j])
                        {
                            if(dp[i][j]<dp[i-1][k])
                            {
                                flag=true;
                                dp[i][j]=dp[i-1][k];
                                table[i][j]=k;
                            }
                        }
                    if(!flag)
                    {
                        table[i][j]=0;
                    }
                    dp[i][j]++;
                }
                if(ans<dp[i][j])
                {
                    ans=dp[i][j];
                    af=j;
                }
            }
        }
        cout<<ans<<endl;
        if(ans>0)
        {
            s=ans;
            for (int j=af,i=LA; i>0;i--)if(table[i][j]!=-1)
            {
                fuck[s--]=Bq[j];
                j=table[i][j];
            }
            printf("%d",fuck[1]);
            for (int i=2; i<=ans; i++)
            {
                printf(" %d",fuck[i]);
            }
            printf("\n");
        }

    }
    return 0;
}

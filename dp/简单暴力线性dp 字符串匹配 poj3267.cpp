暴力dp
//poj3267
//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>

using namespace std;
typedef long long LL;

char s[305];
char dic[605][30];
int dp[305];
int low[605];
int main()
{
    int W,L;
    scanf("%d %d",&W,&L);
    getchar();//过滤掉整数后的回车
    gets(s);
    for (int i=1; i<=W; i++)
    {
        gets(dic[i]);
        low[i]=strlen(dic[i]);
    }
    dp[L]=0;
    int flag,f,k;
    for (int u=L-1; u>=0; u--)
    {
        dp[u]=dp[u+1]+1;
        for (int j=1; j<=W; j++)
        {
            if(dic[j][0]==s[u])
            {
                flag=0,f=u;
                for(k=0; k<low[j]&&f<L; k++,f++)
                {
                    if(dic[j][k]==s[f])continue;
                    while(dic[j][k]!=s[f]&&f<L)f++;
                    if(f>=L&&k<low[j])break;//最后的错误点，这里会有一种情况是k到了最后一个，f没有扫到却也能输出结果，因为我每次最后都++了
                }
                if(k!=low[j])
                    continue;
                else
                {
                    dp[u]=min(dp[u],dp[f]+f-u-low[j]);
                }
            }
        }
    }
    printf("%d\n",dp[0]);
    return 0;
}

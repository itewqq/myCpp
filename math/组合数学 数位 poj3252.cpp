有一个思想是算比当前的长度小的可以很容易算出来
总之心态好一点，认真的取推导就是可以做出来的，笔纸一画一点也不复杂
//poj3252
//#include<bits/stdc++.h>
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
using namespace std;
typedef long long LL;
const int maxn=10;
const int MOD=1000000007;
int bin[50];
LL C[35][35];
void gen_C(int n)
{
    for (int i=0;i<=n;i++)
    {
        C[i][0]=1;
        for (int j=1;j<=i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    return ;
}


void d2b(int n)
{
    memset(bin,0,sizeof(bin));
    while(n)
    {
        bin[0]++;
        if(n&1)bin[bin[0]]=1;
        n/=2;
    }
    return ;
}

int solve(int n)
{
    int ans=0;
    d2b(n);

    for(int i=bin[0]-1;i>=1;i--)
    {
        for(int j=i-1;j>=(i+1)/2;j--)
        ans+=C[i-1][j];
    }

    int zero=0;
    for (int i=bin[0]-1;i>=1;i--)
    {

        if(bin[i])
        {
            for (int j=i-1;j+zero+1>=(bin[0]+1)/2;j--)//e1
                ans+=C[i-1][j];
        }
        else
            zero++;
    }
    return ans;
}

int main()
{
    gen_C(33);
    int S,F;
    scanf("%d %d",&S,&F);
    printf("%d\n",solve(F+1)-solve(S));
    return 0;
}

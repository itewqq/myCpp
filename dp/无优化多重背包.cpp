
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int dp[11][100005];

int main()
{
    int cash,N;
    int n[12]={0};
    int v[12]={0};
    while(cin>>cash>>N)
    {

    for(int i=1;i<=N;i++)
        cin>>n[i]>>v[i];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=N;i++)
        for(int j=0;j<=cash;j++)
        {
            dp[i][j]=dp[i-1][j];
            for(int k=0;k<=n[i];k++)
            {
                if(j-k*v[i]>=0&&dp[i-1][j-k*v[i]]+k*v[i]>=dp[i][j])
                dp[i][j]=dp[i-1][j-k*v[i]]+k*v[i];
            }
        }
    cout<<dp[N][cash]<<endl;
    }
    return 0;
}

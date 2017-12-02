#include<bits/stdc++.h>

using namespace std;

int dp[205][10100];

int main()
{
    int n,k,n2,n5,sum=0,mas=0;
    long long temp;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        n2=n5=0;
        cin>>temp;
        while(temp%2==0){n2++;temp/=2;}
        while(temp%5==0){n5++;temp/=5;}
        sum+=n5;
        for(int j=min(i,k);j>=1;j--)
        {
            for(int p=n5;p<=sum;p++)if(dp[j-1][p-n5]!=-1)
            {
                dp[j][p]=max(dp[j][p],dp[j-1][p-n5]+n2);
            }
        }
    }
    for(int i=0;i<=sum;i++)
        mas=max(mas,min(i,dp[k][i]));
    cout<<mas<<endl;
    return 0;
}

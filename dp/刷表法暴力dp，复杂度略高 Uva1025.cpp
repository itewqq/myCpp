//UVa 1025
//感觉自己做的是纯暴力而不是dp..
//但是不懂得是为什么,刘大爷倒过来推的方法就会降低复杂度???
//只考虑到最邻近的站?为什么?不懂

#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<set>

using namespace std;
typedef long long ll;

int tim[55];
int timel[55];
int timer[55];
bool has_train[205][55][2];
int dp[205][55];

int main()
{
    int N,T,ML,MR,ans,no=0;
    while(scanf("%d",&N)!=-1&&N!=0)
    {
        scanf("%d",&T);
        ans=0;
        memset(has_train,0,sizeof(has_train));
        for(int i=0; i<=T; i++)
            for(int j=0; j<=N; j++)
                dp[i][j]=205;

        for (int  i=1; i<N; i++)
            scanf("%d",&tim[i]);
        scanf("%d",&ML);
        for (int i=1; i<=ML; i++)
            scanf("%d",&timel[i]);
        scanf("%d",&MR);
        for (int i=1; i<=MR; i++)
            scanf("%d",&timer[i]);
        for (int i=1; i<=ML&&timel[i]<=T; i++)
        {
            int t=timel[i];
            has_train[t][1][1]=1;
            t+=tim[1];
            for (int j=1; j<N&&t<=T; j++,t+=tim[j])
            {
                has_train[t][j+1][1]=1;

            }
        }
        for (int i=1; i<=MR&&timer[i]<=T; i++)
        {
            int t=timer[i];
            has_train[t][N][0]=1;
            t+=tim[N-1];
            for (int j=N-1; j>0&&t<=T; j--,t+=tim[j])
            {
                has_train[t][j][0]=1;
            }
        }
        /*
        cout<<"ffffffffffffffffffffffffffffffffffffffffff"<<endl;
        for (int i=0; i<=T; i++)
        {
            for(int j=0; j<=N; j++)
                printf("%3d",has_train[i][j][1]);
            cout<<endl;
        }
        cout<<"ffffffffffffffffffffffffffffffffffffffffff"<<endl;
        cout<<"ffffffffffffffffffffffffffffffffffffffffff"<<endl;
        for (int i=0; i<=T; i++)
        {
            for(int j=0; j<=N; j++)
                printf("%3d",has_train[i][j][0]);
            cout<<endl;
        }
        cout<<"ffffffffffffffffffffffffffffffffffffffffff"<<endl;
        */
        dp[0][1]=0;
        for (int i=0; i<T; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(has_train[i][j][1])
                {
                    for(int k=j+1,t=tim[j]; k<=N&&i+t<=T; k++)
                    {
                        if(dp[i+t][k]>dp[i][j])
                            dp[i+t][k]=dp[i][j];
                        t+=tim[k];
                    }
                }
                if(has_train[i][j][0])
                {
                    for(int k=j-1,t=tim[j-1]; k>=1&&i+t<=T; k--)
                    {
                        if(dp[i+t][k]>dp[i][j])
                            dp[i+t][k]=dp[i][j];
                        t+=tim[k-1];
                    }
                }
                if(dp[i+1][j]>dp[i][j])
                {
                    dp[i+1][j]=dp[i][j]+1;
                }
            }
        }
        /*
        cout<<"ffffffffffffffffffffffffffffffffffffffffff"<<endl;
        for (int i=0; i<=T; i++)
        {
            for(int j=0; j<=N; j++)
                printf("%4d",dp[i][j]);
            cout<<endl;
        }
        cout<<"ffffffffffffffffffffffffffffffffffffffffff"<<endl;
        */
        no++;
        printf("Case Number %d: ",no);
        if(dp[T][N]!=205)
            printf("%d\n",dp[T][N]);
        else
            printf("impossible\n");
        //cout<<"ans "<<dp[T][N]<<endl;
    }
    return 0;
}
/*
4
18
1 2 3
5
0 3 6 10 12
6
0 3 5 7 12 15

2
30
20
1
20
7
1 3 5 7 11 13 17

11
117
14 4 20 2 5 16 17 14 17 7
16
0 7 51 72 103 117 121 122 125 126 128 154 158 227 230 250
22
16 28 42 44 49 52 68 81 88 109 115 117 137 140 156 161 183 186 206 216 228 250
*/

这个真的是写的心累，没想到关键思路很简单，但是实现起来这么难受，也算是一个小小的打击吧，花了很多时间没有成功
看了代码仓库，感觉自己的问题主要出在没有一个清晰的思路就开始敲代码，就会在之后的过程中无论是修改还是debug都会很迷，弄来弄去费了很多时间
再说边界问题，正如某网友所言，搞到后来就会很急，甚至是在猜边界的值，怎么能这样？？一个问题没有清晰的脉络，怎么能很好的得出正确的结果？？
很多东西敲着敲着就忘了，有时候又是一些下标的问题，总而言之就是对各种东西都没有一个很稳的把握，唉
话虽如此，还是应该继续努力
加油吧，搏一搏
//UVa1625
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
const int maxn=5000+5;
//const int MOD=1e9+7;
int a[maxn];
int b[maxn];
int tempi[30];
int temp[30];
int total[30];
int dist1[maxn][maxn];
int dist2[maxn][maxn];
int dp[maxn][maxn];

void cal(int la,int lb)
{
    set<int>S;
    for (int i=1;i<=la;i++)
    {
        tempi[a[i]]++;
        S.insert(a[i]);
        memcpy(temp,tempi,120);
        for (int j=1;j<=lb;j++)
        {
            for (set<int>::iterator it=S.begin();it!=S.end();it++)
                if(temp[*it]<total[*it])
                {
                    dist1[i][j]++;
                }
                else
                {
                    S.erase(*it);//?
                }
            temp[b[j]]++;
        }
    }
    S.clear();
    memset(temp,0,120);
    memset(tempi,0,120);
    for (int i=1;i<=lb;i++)
    {
        tempi[b[i]]++;
        S.insert(b[i]);
        memcpy(temp,tempi,120);
        for (int j=1;j<=la;j++)
        {
            for (set<int>::iterator it=S.begin();it!=S.end();it++)
                if(temp[*it]<total[*it])
                {
                    dist2[i][j]++;
                }
                else
                {
                    S.erase(*it);//?
                }
            temp[a[j]]++;
        }
    }
}

int main()
{
    int T,la,lb;
    char ta;
    scanf(" %d",&T);getchar();
    while(T--)
    {
        la=0;lb=0;

        while(scanf("%c",&ta)&&ta!='\n')
        {

            a[++la]=ta-'A';
            total[ta-'A']++;
        }

        while(scanf("%c",&ta)&&ta!='\n')
        {cout<<" ta "<<ta;
            b[++lb]=ta-'A';
            total[ta-'A']++;
        }
        cal(la,lb);
        memset(dp,0,sizeof(dp));///
        for (int i=1;i<=la;i++)
            for (int j=1;j<=lb;j++)
                dp[i][j]=min(dp[i][j-1]+dist1[i][j],dp[i-1][j]+dist2[i][j]);
        cout<<dp[la][lb]<<endl;
    }
    return 0;
}

/*

简单的直接逐个模拟是n^2算法肯定超时
这里有个特点是当从pos走到np走不下去之后，那么在pos到np之间的这些点都是不能走的，所以这些点可以直接跳过！
于是就变成了O(n)算法
*/
//#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<algorithm>
//freopen("1.txt","r",stdin);

using namespace std;
typedef long long LL;
//const int INF = 1000000000;
//const long long M=1e9+7;
const long long maxn=100005;
/*
int dx[4]= {1,0,-1,0};
int dy[4]= {0,1,0,-1};
*/

/*
struct bb
{
    char c;
    int t;
};
*/





int p[maxn],c[maxn],vis[maxn];



int main()
{
    int t,n,pos,np,flag,cnt=0;
    LL sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cnt++;
        for (int i=0; i<n; ++i)
            scanf("%d",&p[i]);
        for (int i=1; i<n; i++)
            scanf("%d",&c[i]);
        scanf("%d",&c[0]);
        sum=p[0];
        //fuck=1;
        for (pos=0; pos<n&&vis[pos]!=cnt; pos=np)
        {
            //fuck=0;
            vis[pos]=cnt;
            //cout<<pos<<" "<<endl;
            np=(pos+1)%n,flag=0,sum=p[pos];
            while(sum>=c[np])
            {
                //cout<<np<<" "<<sum<<" "<<c[np]<<endl;
                if(np==pos)
                {
                    flag=1;
                    break;
                }
                sum-=c[np];
                sum+=p[np];
                np=(np+1)%n;
            }
            if(flag)
            {
                printf("Case %d: Possible from station %d\n",cnt,pos+1);
                break;
            }
        }
        if(!flag)
            printf("Case %d: Not possible\n",cnt);
    }
    return 0;
}

/*

*/
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<map>
//#include<unordered_set>
using namespace std;
typedef long long LL;
const int maxn=1e6+5;
const int MOD=1e9+7;

int MF[2*maxn],MR[2*maxn];
char ori[maxn];
int cnt[maxn];
bool vis[2*maxn];
int main()
{
    int ans=0;
    while(~scanf(" %s",ori+1))
    {
        memset(vis,0,sizeof(vis));
        ans=0;
        int len=strlen(ori+1);
        for(int i=1;i<=len;i++)
        {
            if(ori[i]=='B')
                cnt[i]=cnt[i-1]+1;
            else
                cnt[i]=cnt[i-1]-1;
            MR[maxn+cnt[i]]=i;
            vis[maxn+cnt[i]]=1;
        }
        for(int i=len;i>=0;i--)
        {
            MF[maxn+cnt[i]]=i;
        }
        for(int i=len;i>=-len;i--)
        {
            if(vis[i+maxn]&&ans<MR[i+maxn]-MF[i+maxn])
            {
                ans=MR[i+maxn]-MF[i+maxn];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


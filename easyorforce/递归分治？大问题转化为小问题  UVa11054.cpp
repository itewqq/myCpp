/*
又是紫书第八章的题目，感觉自己的思维还是有局限性啊，要按照计算机的思想来思考问题！
就是大事化小小事化了
但是自己还是没有想到，继续加油！
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

//int sq[maxn];

int main()
{
    int n,prv,cur;
    LL ans;
    while(~scanf("%d",&n)&&n)
    {
        ans=0;
        prv=0;
        //memset(sq,0,4*maxn);
        for (int i=1;i<=n;++i)
        {
            scanf("%d",&cur);
            ans+=abs(prv+cur);
            prv=prv+cur;
            //cout<<prv<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

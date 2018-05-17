
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=+5;
//const int MOD=1e9+7;
const int INF=1<<29;
LL x;

void read()
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}

int judge(LL A)
{
    int k=0;
    if(A%2==0)
    {
        A/=2;
        if(A%2==0)
        {
            return 0;
        }
    }
    for(int i=3;i*i<=A;i+=2)
    {
        if(A%i==0)
        {
            A/=i;
            if(A%i==0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int T;
    LL sx,uy,dy,ans,i;
    scanf("%d",&T);
    while(T--)
    {
        i=0;
        read();

        sx=sqrt(x);
        if(sx*sx!=x)
        {
            while(sx*sx<x)sx++;
            uy=sx;
            dy=sx-1;
        }
        else
        {
            dy=uy=sx;
        }

        ans=0;
        int flag=0;
        while(1)
        {
            if(dy>1&&judge(dy))
            {
                flag=1;
                ans=abs(x-1LL*dy*dy);
            }
            if(uy>1&&judge(uy))
            {
                if(flag)
                    ans=min(ans,abs(1LL*uy*uy-x));
                else
                {
                    flag=1;
                    ans=abs(1LL*uy*uy-x);
                }
            }
            if(flag)
            {
                printf("%lld\n",ans);
                break;
            }
            uy++;
            dy--;
        }
    }
}
/*
5 5
.....
.....
.....
.....
.....
1 2 3 4
3 5 4 5
1 1 4 1
2 2 5 5
4 2 3 2
5 2
....#
...#.
#####
.....
.....
1 1 1 2
3 3 3 4
*/

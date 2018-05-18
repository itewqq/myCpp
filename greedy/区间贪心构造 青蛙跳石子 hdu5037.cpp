/*
先是自己的代码
果然别人都过了自己不能过的想不出来的一般都是贪心。。
这个题就是贪心的构造就ok了，每次尽可能往前往多了构造，策略就是与前前一个不能小于L+1的情况下尽量靠前！
然后我自己又多想了很多。。。比如向后的时候与后后一个不能小于L+1。。于是就写了一大堆特判
然后交了几发tle，忽然发现自己的算法ans是一个一个加的，然后M很大的时候就会很慢
所以在每两个指头之间找规律，发现可以用除以（L+1）来表示有多少个重复的循环，除完之后的余数一定小于等于L，所以后一个一定可以跳过去，
而这时候又要判定的就是我想到的与后后一个的关系了，别人的代码很聪明的值考虑pre与后一个的关系，我是傻傻的考虑当前的与后后一个的关系。。。
实际上这里的cur和pre是迭代等价的啊，所以只要判断一种就可以了！因为即使当前的cur没有判定出来不可行，当他成为pre的时候也就可以了，傻
告诉我们区间考虑一定要考虑周全，，注意迭代的性质
*/
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
const int maxn=200000+5;
//const int MOD=1e9+7;
const int INF=1<<29;

int sq[maxn];

int read()
{
    int x;
    int f=1;
    x=0;
    char s=getchar();
    while(s<'0'||s>'9')
    {
        if(s=='-')
            f=-1;
        s=getchar();
    }
    while(s>='0'&&s<='9')
    {
        x=x*10+s-'0';
        s=getchar();
    }
    x*=f;
    return x;
}


int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int T,N,M,L,cnt=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&M,&L);
        for(int i=1; i<=N; i++)
        {
            sq[i]=read();
            //scanf("%d",&sq[i]);
        }
        sort(sq+1,sq+1+N);
        sq[N+1]=M;
        sq[N+2]=sq[N+1]+L+1;
        sq[N+3]=sq[N+2]+L+1;
        if(L>=M)
        {
            printf("Case #%d: 1\n",cnt);
            cnt++;
            continue;
        }
        int pre=-L,cur=0,nt=sq[1],nnt=sq[2],ans=0,i=1;
        while(cur!=M)
        {
            if(nt-cur>L)
            {
                int tn=pre+L+1;
                if(nnt-tn<=L)
                {
                    ans++;
                    pre=cur;
                    cur=tn;
                    nt=nnt;
                    i++;
                    nnt=sq[i+1];
                }
                else
                {
                    int len=min(nnt-L-1,nt-1);
                    int p1=(len-cur)/(L+1);
                    if(p1)
                    {
                        ans+=2*p1;
                        pre=max(pre,p1*(L+1)+cur-(cur-pre));
                        cur=(L+1)*p1+cur;
                    }
                    else
                    {
                        ans++;
                        pre=cur;
                        cur=tn;
                    }

                    //ans++;

                    //i++;
                }
            }
            else
            {
                if(nt-pre<=L)
                {
                    //ans--;
                    cur=nt;
                    nt=nnt;
                    i++;
                    nnt=sq[i+1];
                    continue;
                }
                while(nnt-cur<=L)
                {
                    nt=nnt;
                    i++;
                    nnt=sq[i+1];
                }
                pre=cur;
                cur=nt;
                nt=nnt;
                i++;
                nnt=sq[i+1];
                ans++;
            }
            //cout<<i<<" "<<pre<<" "<<cur<<" "<<nt<<" "<<nnt<<" "<<ans<<endl;
        }
        printf("Case #%d: %d\n",cnt,ans);
        cnt++;
    }
}
/*
100
5 10 2
3 4 5 6 7
2 123456 7
6541 5987
*/
/*
别人的代码。。用for循环来做，每次判断特殊情况只考虑与后一个的距离
看来我还是想太多
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn=1000000+100;
int a[maxn];
int main()
{
    int t,n,m,l;
    scanf("%d",&t);
    int ca=1;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&l);
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
         int fr = 0;
        int ans = 0;
        a[n]=m;
        int pre = -l;
        int now;
        for (int i = 0;i <=n; i++)
        {
           now = a[i];
           int t2=(now-fr)/(l + 1);
           pre+=t2*(l + 1);
           ans+=t2 * 2;
           if (now- pre>l)
           {
               pre=fr + t2*(l + 1);
               fr= now;
               ans++;
          }
          else
          {
               fr = now;
          }
    }
        printf("Case #%d: %d\n",ca++,ans);
    }
    return 0;
}

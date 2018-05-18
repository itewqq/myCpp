/*
emmmmmm又是一道自己没想出来的贪心构造
想到了每个都得是最左边的，但是没想到这个过程中怎么去操作，还要考虑到不同操作的先后顺序
看了题解后才懂，原来每次操作只要把mp排序就行了。。。。。这样可以保证最左边的优先。。直觉证法？？
还有个知识点就是memcpy的第三个参数是字节数！不是多少个！竟然忘记了
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

/*
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
*/

int a[1005],b[1005],lm,rm;
int posa[1005],mp[1005],ori[1005];


int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int T,n,m,sd,flag;
    for(int i=0;i<1004;i++)
        ori[i]=i;
    scanf("%d",&T);
    while(T--)
    {
        flag=0;
        priority_queue<int,vector<int>,greater<int> > posa[1005];
        //memset(posa,0,sizeof(posa));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            a[i]=read();
        }

        for (int i=1;i<=n;i++)
        {
            b[i]=read();
            posa[b[i]].push(i);
        }
        for(int i=1;i<=n;i++)
        {
            if(!posa[a[i]].empty())
            {
                sd=posa[a[i]].top();posa[a[i]].pop();
                mp[i]=sd;
            }
            else
            {
                flag=1;
                break;
            }
        }
        /*
        for(int i=1;i<=n;i++)
            cout<<mp[i]<<" ";
        cout<<endl;
        */
        for(int i=0;i<m;i++)
        {
            lm=read();
            rm=read();
            //cout<<lm<<" "<<rm<<endl;
            sort(mp+lm,mp+rm+1);
        }
        /*
        for(int i=1;i<=n;i++)
            cout<<mp[i]<<" ";
        cout<<endl;
        */
        if(memcmp(mp+1,ori+1,4*(n))==0&&flag==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
/*
100
5 10 2
3 4 5 6 7
2 123456 7
6541 5987
*/

虽然知道了思路但是还是wa了一晚上，最后的错误出在一个等号上，shit
大概就是预处理，遍历序列，对于第i个数保留在他之前的比他结尾元素更小的最长的那个长度，就是很像LIS了
然后由于数据量，只能做nlogn的算法
这个nlogn的算法也是很有意思，大致思路就是，保存每个长度对应的最小的那个点
为什么是正确的呢？想想。。
//UVa1471
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
const int maxn=200000+5;
//const int MOD=1e9+7;



int f[maxn],g[maxn],sq[maxn],b[maxn],bi[maxn];

int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int Z,n,temp,pos,len,ans;
    scanf("%d",&Z);
    while(Z--)
    {
        scanf("%d",&n);
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        memset(b,0,sizeof(b));
        memset(bi,0,sizeof(bi));
        ans=0;
        f[1]=1;
        scanf("%d",&sq[1]);
        for (int i=2;i<=n;++i)
        {
            scanf("%d",&sq[i]);
            if(sq[i]>sq[i-1])
                f[i]=f[i-1]+1;
            else
                f[i]=1;
        }
        g[n]=1;
        for (int i=n-1;i>0;--i)
        {
            if(sq[i]<sq[i+1])
                g[i]=g[i+1]+1;
            else
                g[i]=1;
        }
        //bi[1]=1,b[1]=sq[1];
        ans=f[n];
        len=0;
        for (int i=1;i<=n;++i)
        {
            //cout<<b[len]<<" "<<sq[i]<<" "<<f[bi[len]]<<" "<<f[i]<<endl;
            if(b[len]<sq[i]&&f[bi[len]]<f[i])//?
            {
                len++;
                b[len]=sq[i],bi[len]=i;
                ans=max(ans,f[bi[len-1]]+g[i]);
            }
            else
            {
                pos=lower_bound(b+1,b+1+len,sq[i])-b;
                //pos=f[i];
                ans=max(ans,f[bi[pos-1]]+g[i]);
                if(f[bi[pos]]<=f[i])
                    b[pos]=sq[i],bi[pos]=i;

            }

            //cout<<i<<" "<<pos<<" "<<len<<" "<<ans<<endl;

        }
        printf("%d\n",ans);
    }
}

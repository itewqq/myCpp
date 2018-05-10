/*
虽然知道了思路但是还是wa了一晚上，最后的错误出在一个等号上，shit
大概就是预处理，遍历序列，对于第i个数保留在他之前的比他结尾元素更小的最长的那个长度，就是很像LIS了
然后由于数据量，只能做nlogn的算法
这个nlogn的算法也是很有意思，大致思路就是，保存每个长度对应的最小的那个点
为什么是正确的呢？想想。。
这里是分了三种操作的其实。
首先如果说新的sqi比队尾元素还大，而且他也比这个元素对应的向前连续长度长，那肯定是要把这个点添加到队尾，因为这说明能组成更长的连续序列了
除了这种之外就是在队列中的操作的了，有两种
第一种就是遍历到i的时候，在前面出现过的数字中找到小于他的最大的fi,
       这个操作的实现，就是lower_bound找到的位置，在这个位置之前的那个位置就是要找的fi的尾元素，ans=max（ans，f+g）
第二种是要不要把找到的位置的元素替换为当前元素？
       这个其实也很容易，首先队列里保存的是每个f对应的最小的sqi，但是既然说lower_bound找到了当前的元素，那首先说明在当前的之前的都不会被取代了
       因为那些比sqi要小，那之后的元素有没有可能呢，也是没有可能的，因为如果当前的这个f比后面的大，由于这个序列是递增的，那么之后的数一定是比他要大的
       由于考虑的都是连续的序列，所有在排当前这个元素之前一定有fi-1个元素已经在前面排好了，他不可能凭空出现一个很大的数！
*/
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
        ans=f[n];
        len=0;
        for (int i=1;i<=n;++i)
        {
            if(b[len]<sq[i]&&f[bi[len]]<f[i])//?
            {
                len++;
                b[len]=sq[i],bi[len]=i;
                ans=max(ans,f[bi[len-1]]+g[i]);
            }
            else
            {
                pos=lower_bound(b+1,b+1+len,sq[i])-b;
                ans=max(ans,f[bi[pos-1]]+g[i]);
                if(f[bi[pos]]==f[i])//the most important point!
                    b[pos]=sq[i],bi[pos]=i;
            }
        }
        printf("%d\n",ans);
    }
}

这个真的是写的心累，没想到关键思路很简单，但是实现起来这么难受，也算是一个小小的打击吧，花了很多时间没有成功
看了代码仓库，感觉自己的问题主要出在没有一个清晰的思路就开始敲代码，就会在之后的过程中无论是修改还是debug都会很迷，弄来弄去费了很多时间
再说边界问题，正如某网友所言，搞到后来就会很急，甚至是在猜边界的值，怎么能这样？？一个问题没有清晰的脉络，怎么能很好的得出正确的结果？？
很多东西敲着敲着就忘了，有时候又是一些下标的问题，总而言之就是对各种东西都没有一个很稳的把握，唉
话虽如此，还是应该继续努力

---------------------------------------
时隔三周再做这个题还是没有直接搞出来预处理，真的有点玄学
不过参考了代码仓库之后还是ac了
这个题目最难的就在于这个预处理找出状态转移中所要用到的dist[i][j]，这个东西的值一定要明确，他指的是已经开始尚未结束的颜色个数！！！颜色种类数！
这个东西怎么找呢？
一开始各种找法的错误就在于，没有考虑到i和j的循环顺序！！
没错，一般的dp，i和j这一些表示状态的参数总是互相有区别的，而在这里i和j是等价的，都是指，第x个元素
所以这里的做法，看上去是i外循环j内循环，实际上是先把j做好了，然后考虑每一个i添加上去的时候对于不同的j有什么影响
注意这个影响指的是集合中的颜色有没有变多或者变少（结束）
如果没有影响那么其实他和没有ai的时候是一样的
影响分为两种，多了一个和少了一个
多了一个只有可能是对于某个j来说j还没有到b中这种颜色出现的地方，而i却到了
少了一个只有可能是对于某个j来说在b中j已经移到了一个元素之后了，意思就是说在b中这个元素已经不会再出现了，但是此时i对应的a如果也正好是a中的最后一个
这种颜色，那么此时应该从集合中去掉一个，因为之后这种颜色再也不会出现了
神他妈烦的一个题！！！！
还有就是发现了memset的复杂度好像挺高的，搞不好很容易tle，此时可以想办法避免memset，也可以想办法把数组压缩，比如在这里其实只需要2*maxn的数组就可以了
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
int ba[30];
int bb[30];
int ea[30];
int eb[30];
int dist[maxn][maxn];

int dp[maxn][maxn];

void cal(int la,int lb)
{
    for (int i=0; i<=26; i++)
    {
        ba[i]=la+1;
        for (int k=1; k<=la; k++)
        {
            if(a[k]==i)
            {
                ba[i]=k;
                break;
            }
        }
        bb[i]=lb+1;
        for (int k=1; k<=lb; k++)
        {
            if(b[k]==i)
            {
                bb[i]=k;
                break;
            }
        }
        ea[i]=0;
        for (int k=la; k>0; k--)
        {
            if(a[k]==i)
            {
                ea[i]=k;
                break;
            }
        }
        eb[i]=0;
        for (int k=lb; k>0; k--)
        {
            if(b[k]==i)
            {
                eb[i]=k;
                break;
            }
        }
    }
    return ;
}

int main()
{
    int T,la,lb;
    char ta;
    scanf(" %d",&T);
    getchar();
    while(T--)
    {
        la=0;
        lb=0;

        while(scanf("%c",&ta)&&ta!='\n')
        {
            a[++la]=ta-'A';
        }

        while(scanf("%c",&ta)&&ta!='\n')
        {
            b[++lb]=ta-'A';
        }
        cal(la,lb);
        dp[0][0]=0;
        //memset(dist,0,4*maxn*maxn);
        dist[0][0]=0;
        for (int i=0,j=1; j<=lb; j++)
        {
            dist[i][j]=dist[i][j-1];
            dp[i][j]=dp[i][j-1]+dist[i][j-1];
            if(j==bb[b[j]]&&i<ba[b[j]])dist[i][j]++;
            if(j==eb[b[j]]&&i>=ea[b[j]])dist[i][j]--;
        }
        for (int i=1; i<=la; i++)
        {
            for (int j=0; j<=lb; j++)
            {
                dist[i][j]=dist[i-1][j];
                if(i==ba[a[i]]&&j<bb[a[i]])dist[i][j]++;
                if(i==ea[a[i]]&&j>=eb[a[i]])dist[i][j]--;
            }
        }

        for (int i=1; i<=la; i++)
            for (int j=0; j<=lb; j++)
            {
                if(j)
                    dp[i][j]=min(dp[i][j-1]+dist[i][j-1],dp[i-1][j]+dist[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j]+dist[i-1][j];
            }
        cout<<dp[la][lb]<<endl;
    }
    return 0;
}

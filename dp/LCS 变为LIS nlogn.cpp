本来是求LIS，但是，序列中没有出现过相同的元素，可以转化成求LIS
怎么转化呢，首先把A序列中出现过的重新编号，当读入B序列的时候就可以判断读入的数字是否在A中出现过，没有出现直接不存
然后得到了新B，，这时候只需要对新B求一次LIS即可
这里求LIS又用到了一个新的方法，可以使复杂度变为nlogn
就是用一个辅助数组g，g[i]表示长度为i的LIS的最小的尾元素（注意原序列中可能存在多个长度为i的子序列，而这里保存的是结尾数字最小的）
把g初始化为INF（其实也可以初始化为0，然后先令g1=B1？仔细想想好像不对，这个g是越来越长的），
然后由于这里只存在替换操作，所以可以用lower_bound(g+1,g+n+1,B[i])-g二分求出应该插入的位置，然后保存所有出现过的位置中最大的就是答案!
//UVa 10635
//#include<bits/stdc++.h>
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<algorithm>

using namespace std;
typedef long long LL;
const int maxn=255*255;
const int INF=1<<29;
//const int MOD=1000000007;

/*
int getint()
{
    int ret=0;
    char tmp;
    while(!isdigit(tmp=getchar()));
    do
    {
        ret=(ret<<3)+(ret<<1)+tmp-'0';
    }
    while(isdigit(tmp=getchar()));
    return ret;
}
*/

int getint()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}

int a[maxn],b[maxn],g[maxn];


int main()
{
    cin.sync_with_stdio(false);
    int T,n,p,q,t,c,k,ans,Case=1;
    scanf("%d",&T);

    while(T--)
    {
        ans=0;
        memset(a,0,sizeof(a));
        scanf("%d %d %d",&n,&p,&q);
        for (int i=1; i<=p+1; ++i)
        {
            //scanf("%d",&t);
            t=getint();
            a[t]=i;
        }
        c=0;
        for (int i=1; i<=q+1; ++i)
        {
            //scanf("%d",&t);
            t=getint();
            if(a[t])
                b[++c]=a[t];
        }
        //LIS
        for (int i=1; i<=c; ++i)g[i]=INF;
        for (int i=1; i<=c; ++i)
        {
            k=lower_bound(g+1,g+1+c,b[i])-g;
            g[k]=b[i];
            ans=max(k,ans);
        }
        printf("Case %d: %d\n",Case,ans);
        ++Case;
    }
    return 0;
}

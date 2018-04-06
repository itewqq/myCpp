自己想的是枚举球员，没想到能枚举裁判
枚举裁判之后由成分啊原理即可得出公式
此时只需要求出在ai之前比ai小的有多少个，这时候就用到了树状数组，没想到还可以这么用
需要注意的是这个树状数组不能预处理，因为逐一考虑裁判的时候求得是在原序列中在ai之前的那些元素中比ai小的，所以只能边修改边操作树状数组，求出Ci和Di
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
const int maxn=10;
const int MOD=1000000007;

int ma,num[100001],t[200001];
LL C[200001],D[200001];
int lowbit(int x)
{
    return x&(-x);
}
void change(int x,int p)
{
    while(x<=ma)
    {
        t[x]+=p;
        x+=lowbit(x);
    }
    return;
}
int sum(int k)
{
    int ans=0;
    while(k>0)
    {
        ans+=t[k];
        k-=lowbit(k);
    }
    return ans;
}

int ask(int l,int r)
{
    return sum(r)-sum(l-1);
}

int main()
{
    int T,N;
    LL ans;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        ma=0;
        scanf("%d",&N);

        for (int i=1;i<=N;++i)
        {
            scanf("%d",&num[i]);
            ma=ma>num[i]?ma:num[i];
        }
        memset(t,0,4*(ma+3));
        for (int i=1;i<=N;++i)
        {
            change(num[i],1);
            C[i]=sum(num[i]-1);
        }
        memset(t,0,4*(ma+3));
        for (int i=N;i>0;--i)
        {
            change(num[i],1);
            D[i]=sum(num[i]-1);
        }
        for (int i=2;i<N;++i)
        {
            ans+=C[i]*(N-i-D[i])+(i-C[i]-1)*D[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}

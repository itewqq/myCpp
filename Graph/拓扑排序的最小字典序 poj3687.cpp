重点在于字典序最小
一开始没有想到怎么操作，看了题解发现原来拓扑排序是把图中出度为0的点一个一个剔除的过程
这样的话结合优先队列就可以逐个把出度为0的节点中值最大的挑出来放到ans尾部，逆向输出即可
一开始感觉新进的节点会影响到之前的他的后代，但是后来想如果轮到了当前的节点，那么他的后代一定已经出队了。。。妙。。。
第二个要解决的问题就是，如何确定有环
一开始想的used数组，但是后来发现不能发现所有的环
后来想到如果有环那么环中的节点一定不会入队，所以只需要检查最后的ans中的元素个数是不是完全等于N就行了。。。
//poj3687
//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>

using namespace std;
typedef long long LL;
const int maxn = 200 + 5;


vector<int> pre[maxn];
int out[maxn];
int t;
int used[maxn];
int ans[maxn];
int ra[maxn];
int main()
{
    int T,N,M,a,b,cur,temp,flag;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        memset(out,0,4*(N+3));
        memset(used,0,sizeof(used));
        memset(pre,0,sizeof(pre));
        priority_queue<int> Q;
        for(int i=0;i<M;i++)
        {
            scanf("%d%d",&a,&b);
            pre[b].push_back(a);
            out[a]++;
        }
        for (int i=1;i<=N;i++)if(!out[i])Q.push(i);
        t=N;

        flag=1;
        while(!Q.empty()&&flag)
        {
            cur=Q.top();Q.pop();
            ans[t--]=cur;
            temp=pre[cur].size();
            for (int i=0;i<temp;i++)
            {
                out[pre[cur][i]]--;
                if(!out[pre[cur][i]])Q.push(pre[cur][i]);
            }
        }
        if(t!=0)
        {
            printf("-1\n");
            continue;
        }
        for (int i=1;i<=N;i++)
        {
            ra[ans[i]]=i;
        }
        printf("%d",ra[1]);
        for (int i=2;i<=N;i++)
            printf(" %d",ra[i]);
        printf("\n");

    }
    return 0;
}

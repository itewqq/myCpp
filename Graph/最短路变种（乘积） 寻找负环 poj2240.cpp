常规操作，检验负环，当然稍微有一点变化的是距离变成了乘积
挑战上的模板还是很好用的，但是还是有疑惑，为什么为什么把所有的d初始化为0即可查找出所有的负环
后来想想
1因为这样的话每个节点就没有区别了，也就不分谁是源头了
2这样的话只有在负环的时候才会进行松弛，其实bellman-ford本来就跟每个节点是个什么关系不大，加上1的性质那么大家就都一样了

//poj2240
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
const int INF = 1<<28;
const int maxn = 30 + 5;

typedef struct Edge
{
    int from,to;
    double w;
    Edge(int from,int to,double w):from(from),to(to),w(w){}
}Edge;

vector<Edge>edges;

double d[maxn+1];
map<string,int> s2i;
int g=1;

void add_edge(int from,int to,double w)
{
    edges.push_back(Edge(from,to,w));
    int l=edges.size();
    nodes[from].push_back(l-1);
}

int main()
{
    int n,k,m,from,to;
    string temp;
    double w;
    while(~scanf("%d",&n)&&n!=0)
    {
        s2i.clear();
        edges.clear();
        memset(nodes,0,sizeof(nodes));
        for(int i=1;i<=n;i++)
        {
            cin>>temp;
            s2i[temp]=i;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            cin>>temp;
            from=s2i[temp];
            cin>>w;
            cin>>temp;
            to=s2i[temp];
            add_edge(from,to,w);
        }
        //bell-man ford
        for (int i=1;i<=n;i++)
            d[i]=99999.0;//神奇的操作，仅限于查找负环
        int es=edges.size();
        char flag=0;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<es;i++)
            {
                Edge e=edges[i];
                if(d[e.to]<d[e.from]*e.w)
                {
                    d[e.to]=d[e.from]*e.w;
                    if(k==n-1)
                    {
                        flag=1;
                    }
                }
            }
        }
        if(flag)
            printf("Case %d: Yes\n",g++);
        else
            printf("Case %d: No\n",g++);
    }
    return 0;
}

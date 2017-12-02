#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct edge
{
    int u,v,w;
    bool operator<(struct edge& e)
    {
        return w<e.w;
    }
} edges[5005];
int p[105];
int n,m;
int find(int k)//并查集的find，记住每次寻找都应该用find，当时第一次出错
{
    return p[k]==k?k:p[k]=find(p[k]);
}

int main()
{
    int ans,cnt;
    while(scanf("%d %d",&n,&m)&&n!=0)
    {
        ans=1<<29;
        bool flag=false;
        for(int i=1; i<=m; i++)
            scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
        sort(edges+1,edges+1+m);
        for(int L=1; L<=m-(n-2); L++)
        {
            cnt=n;//集的数量，巧妙的判定
            for(int i=1; i<=n; i++)
                p[i]=i;
            for(int R=L; R<=m; R++)
            {
                int x=find(edges[R].u);
                int y=find(edges[R].v);
                if(x!=y)
                {
                    p[x]=y;
                    if(--cnt==1)
                    {
                        ans=min(ans,edges[R].w-edges[L].w);
                        break;
                    }
                }
            }
        }
        if(ans==1<<29)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}

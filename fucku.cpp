//poj3041
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;
typedef long long LL;
const int maxn=1000+5;
//const int MOD=1e9+7;

vector<int> G[maxn];
int matching[maxn];
int check[maxn];
int pre[maxn];

int main()
{
    int N,K,u,v;
    scanf("%d %d",&N,&K);
    for (int i=0; i<K; i++)
    {
        scanf("%d%d",&u,&v);
        --u;--v;
        G[u].push_back(N+v);
        G[N+v].push_back(u);
    }

    int ans=0;
    int flag=0;
    memset(matching,-1,sizeof(matching));
    memset(check,-1,sizeof(check));
    //queue<int> Q;
    for (int i=0; i<N; i++)
    {
        if(matching[i]==-1)
        {
            pre[i]=-1;
            queue<int> Q;
            //while(!Q.empty())Q.pop();
            Q.push(i);
            flag=0;
            while(!Q.empty()&&!flag)
            {
                u=Q.front();
                cout<<u<<endl;
                //if(check[u]==i)continue;
                Q.pop();
                int len=G[u].size();
                for (int i=0;i<len&&!flag;++i)
                {
                    v=G[u][i];
                    if(check[v]!=i)
                    {
                        check[v]=i;
                        Q.push(matching[v]);//important
                        if(matching[v]>=0)
                        {
                            pre[matching[v]]=u;
                            //Q.push(matching[v]);
                        }
                        else//change it into
                        {
                            flag=1;
                            int d=u,e=v;
                            while(d!=-1)
                            {
                                int t=matching[d];
                                matching[d]=e;
                                matching[e]=d;
                                d=pre[d];
                                e=t;
                            }
                        }
                    }
                }
            }
            if(matching[i]!=-1)++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}

//数据结构很乱，还没有仔细想过怎么优化，先ac了放这儿

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<cstring>
using namespace std;

int N, M, T, tn, u, v, cnt, dnode;
int del[400005];
int ans[400005];
int P[400005];
bool V[400005];
int edges[200005][2];
vector<vector<int> > link(200005);
int find(int x)
{
    return P[x] == x ? P[x] : P[x] = find(P[x]);
}

int numS()
{
    cnt = tn;
    for (int i = 0; i<N; i++)
        P[i] = i;
    for (int i = 0; i<M; i++)
    {
        int x = find(edges[i][0]), y = find(edges[i][1]);
        if ((!V[edges[i][0]]) && (!V[edges[i][1]]) && x != y)
        {
            P[x] = y;
            cnt--;
        }
    }
    return cnt;
}
int main()
{
    while(~scanf("%d %d", &N, &M))
    {
        link.clear();
        memset(V,0,sizeof(V));
        for (int i = 0; i<M; i++)
        {
            scanf("%d %d", &u, &v);
            edges[i][0] = u;
            edges[i][1] = v;
            link[u].push_back(v);
            link[v].push_back(u);
        }
        tn = N;
        scanf("%d", &T);
        cnt = tn;
        ans[0] = numS();
        for (int i = 0; i<T; i++)
        {
            tn--;
            scanf("%d", &dnode);
            del[i] = dnode;
            V[dnode] = true;
        }
        cnt = tn;
        ans[T] = numS();
        bool flag = false;
        for (int i = T - 1; i >= 0; i--)
        {
            flag = false;
            int x, y;
            V[del[i]] = false;
            for (int j = 0; j<link[del[i]].size(); j++)
            {
                x = find(link[del[i]][j]), y = find(del[i]);
                if (x != y && (!V[link[del[i]][j]]))
                {
                    P[x] = y;
                    if (!flag)
                    {
                        flag = true;
                        continue;
                    }
                    cnt--;
                }
            }
            if (!flag)
                cnt++;
            ans[i] = cnt;
        }
        for (int i = 0; i <= T; i++)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}

1 坑爹的是边读入边计算，导致了每一次读入一条新边都要重新toposort一下
2 一定要保证严格有序才可以输出确定顺序，加了一句判断搞定
3 前边的已经确定有序还是有环之后还需要把后面多余的输入gets掉，fuck
4 poj的discuss真神奇
//poj1094
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

vector<char> ans;

int G[30][30];
int exis[30];
int use[30];

int N;
bool dfs(int u)
{
    use[u]=-1;
    for (int v=0; v<26; v++)if(G[u][v])
        {
            if(use[v]<0)return false;
            else if(!use[v]&&!dfs(v)) return false;
        }
    use[u]=1;
    int temp=ans.size();
    if(!temp||(temp!=0&&G[u][ans[temp-1]-'A']))//这是确保序列一定是严格有序的一步！
        ans.push_back(u+'A');
    return true;
}

int main()
{
    int M,flag;
    char c,d;
    char fuck[10];
    while(~scanf("%d %d",&N,&M)&&N!=0&&M!=0)
    {

        flag=1;
        memset(G,0,sizeof(G));
        memset(exis,0,sizeof(exis));
        ans.clear();
        int u=0;
        for (; u<M; u++)
        {
            ans.clear();
            memset(use,0,sizeof(use));
            getchar();
            c=getchar();
            getchar();
            d=getchar();
            G[c-'A'][d-'A']=1;
            exis[c-'A']=1;
            for (int i=0; i<26; i++)if(exis[i]&&!use[i])
                {
                    if(!dfs(i))
                    {
                        flag=0;
                        for(int w=u;w<M;w++)gets(fuck);
                        break;
                    }
                }
            if(ans.size()==N)
            {
                for(int w=u;w<M;w++)gets(fuck);
                flag=2;
                break;
            }
            if(flag==0)
                break;
        }
        //output process
        if(flag==2)
        {
            printf("Sorted sequence determined after %d relations: ",u+1);
            for(int k=ans.size()-1;k>=0;k--)cout<<ans[k];
            printf(".\n");
            continue;
        }
        if(flag==0)
        {
            printf("Inconsistency found after %d ",u+1);
                printf("relations.\n");
        }
        if(flag==1)
        {
            printf("Sorted sequence cannot be determined.\n");
            continue;
        }
    }
    return 0;
}

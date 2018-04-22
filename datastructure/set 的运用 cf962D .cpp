校赛一波凉凉，让我感觉到了自己很多不足
首先是dp时候不能很好的根据题目搞出来正确的状态，因题而异，而自己只能想到一些显然的经典做法，还是思维没有打开
其次是，模板，自己没有带素数分解的模板可以说直接导致了少一个ac
然后是，数据结构，自己对于基本的数据结构是使用还是有所欠缺，应该注意加强
然后是，对于复杂度的分析不当，很多时候因为搞不清楚复杂度而做出了错误的判断，比如素数分解的复杂度
最后，还是自己对于比较复杂的题目的把握吧，整体上的把握还是欠缺很多。。代码能力还是不行
接下来准备省赛吧，先把自己的基本功，数据结构，dp，复杂度分析这些弄好。。校赛真的算是一次教训

//#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>

//freopen("1.txt","r",stdin);

using namespace std;
typedef long long LL;
//const int INF = 1000000000;
const int maxn = 150000 + 5;
/*
int dx[4]= {1,0,-1,0};
int dy[4]= {0,1,0,-1};
*/

/*
struct bb
{
    char c;
    int t;
};
*/



set<pair<LL ,int > > S;
int del[maxn],db[maxn],sq[maxn];

int main()
{
    int n,temp,k=0;
    scanf("%d",&n);
    for (int i=0;i<n;++i)
    {
        scanf("%d",&sq[i]);
        S.insert(make_pair(sq[i],i));
    }
    pair<LL ,int > x,y;
    set<pair< LL,int> > ::iterator it;
    while(S.size()>1)
    {
        it=S.begin();
        x=*(it);
        y=*(++it);
        //cout<<x.first<<" "<<x.second<<" "<<y.first<<" "<<y.second<<endl;
        if(x.first!=y.first)
        {
            ++k;
            S.erase(S.begin());
            continue;
        }
        else
        {
            S.erase(S.begin());
            S.erase(S.begin());
            S.insert(make_pair(2*y.first,y.second));
            del[x.second]=1;
            db[y.second]++;
        }
    }
    ++k;
    printf("%d\n",k);
    for (int i=0;i<n;++i)
    {
        //cout<<endl;
        //cout<<i<<" "<<pow(2,db[i])*sq[i]<<endl;
        if(del[i])
        {
            continue;
        }
        else if(db[i])
            printf("%lld ",(LL)(1LL*pow(2,db[i])*sq[i]));
        else
            printf("%d ",sq[i]);
    }
    return 0;
}

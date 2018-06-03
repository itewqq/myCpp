/*
这个思维是很清奇的，要找能被k整除的，那么就把每一个k对应的能整除的数都凑起来建立一棵trie。。也就是有1e5个trie
当然这时候就不能用数组实现了，需要用到链式结构。。第一次搞这种也是很迷


说一下学到的
1 求一个数的所有倍数可以反过来，在遍历i的时候把ni都添加上，这个想法是很巧妙的
2 链式结构一定要搞清楚，是到达一个点就处理还是离开之前再处理，比如我这里用的是离开之前处理，但是就会错
  因为循环的最后一次是不会有下一次的，所以这最后一个节点就没有被操作到。
3 链式结构的指针，一定是先对儿子处理过后再往那边转移，不然，的话等于指针没有接上！！！！！！！时刻记住！！！！！
4 怎么处理大小界限呢，让每棵树的每个节点都保存最小值就好了！这个mi保存的就是从当前节点能到达的节点的最小值是多少


*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include<map>
#include<vector>

using namespace std;
typedef long long LL;
const int maxn=1e5+5;
//Tire
struct node
{
    int mi;
    struct node* bit[2];
    node()
    {
        mi=1<<28;
        bit[0]=bit[1]=nullptr;
    }
}*trie[maxn];

vector<int> di[maxn];

void init()
{
    for(int i=1;i<maxn;i++)//wtf wa,not re?
    {
        for (int j=i;j<maxn;j+=i)
            di[j].push_back(i);
        trie[i]=new node();
    }

}

void add(int k,int u)
{
    node* cur=trie[k];
    int cb;
    cur->mi=min(cur->mi,u);
    for(int i=18;i>=0;i--)
    {
        cb=(u>>i)&1;
        if(cur->bit[cb]==nullptr)
            cur->bit[cb]=new node();
        cur=cur->bit[cb];cur->mi=min(cur->mi,u);//???order? last error

    }
}

int que(int x,int k,int s)
{
    if(x%k||trie[k]->mi>s-x)
        return -1;
    int ans=0,cb;
    node* cur=trie[k];
    for(int i=18;i>=0;i--)
    {
        cb= (x>>i)&1;;
        if(cur->bit[cb^1]!=nullptr&&cur->bit[cb^1]->mi <=s-x)
        {
            cur=cur->bit[cb^1];
            ans+= ((cb^1)<<i);
        }
        else
        {
            cur=cur->bit[cb];
            ans+= ((cb)<<i);
        }
    }
    return ans;
}
int check[maxn];
int main()
{
    int q,t,u,x,k,s;
    init();
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%d",&u);
            if(!check[u])
            {
                check[u]=1;
                for(int i:di[u])
                    add(i,u);
            }
        }
        else
        {
            scanf("%d%d%d",&x,&k,&s);
            printf("%d\n",que(x,k,s));
        }
    }
    return 0;
}


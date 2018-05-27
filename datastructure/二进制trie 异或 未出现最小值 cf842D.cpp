/*
第一道trie的题目吧，还是折腾了很久的，但是也有很大收获
二进制trie可以寻找距离目标数字最远的，最近的；
也可以寻找未出现的最小的（利用完全二叉树性质！）
真的很神奇！
民间题解用了lazy标记下放的操作。。没有看懂，应该是有统一的做法，类似于线段树？？
题解用的是并不真实的异或，而只是根据异或与否来控制顺着树往下走的过程中的转向（好厉害
细节非常多，pos代表的意义，rt和pos什么时候该判断谁
可能这就是数据结构题吧，不过真的很强大！！
这几天应该是要专心搞一下trie
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include<cstring>
using namespace std;

const int maxn=300000;
const int maxm=20;
int sq[maxn],len=1,trie[maxn*maxm][2],cnt[maxn*maxm];

void add(int rt,int x,int pos)
{
    //cout<<rt<<" "<<pos<<endl;
    if(pos<0)
    {
        cnt[rt]=1;
        return ;
    }
    int nxt=(x>>pos)&1;
    if(trie[rt][nxt]==-1)//-1 or 0 seemed no problem? not!= !!!
        trie[rt][nxt]=len++;
    add(trie[rt][nxt],x,pos-1);
    cnt[rt]=0;// ? try it
    if(trie[rt][0]!=-1)
    {
        cnt[rt]+=cnt[trie[rt][0]];
    }
    if(trie[rt][1]!=-1)
    {
        cnt[rt]+=cnt[trie[rt][1]];
    }
}

void get(int rt,int &as,int c,int pos)
{
    //cout<<"fuck!\n";
    if(rt==-1)//what is this pos? no pos? rt??
        return ;
    int tmp=((c>>pos)&1);
    if(cnt[trie[rt][tmp]]==(1<<pos))// <<pos or pos-1?
    {
        tmp=1-tmp;
    }
    as|=((tmp^((c>>pos)&1))<<pos);
    get(trie[rt][tmp],as,c,pos-1);
}

int main()
{
    //srand((int) time(NULL));
    //cout << setprecision(10) << fixed;
    int n,m,c=0,x,ans;
    scanf("%d%d",&n,&m);
    memset(trie,-1,sizeof(trie));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&sq[i]);
        add(0,sq[i],maxm-1);
    }
    for (int i=0;i<m;i++)
    {
        ans=0;
        scanf("%d",&x);
        c^=x;
        //cout<<"c "<<c<<endl;
        get(0,ans,c,maxm-1);
        cout<<ans<<endl;
    }

    //cerr << clock() << endl;

    return 0;
}

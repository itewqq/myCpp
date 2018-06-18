/*
暴力枚举所有可能的和，并且把每一种和对应的可能的二进制数凑存起来 map<int,vector<int> >
然后当遇到和为偶数的情况时，判定这个数除以二之后的数的vector是不是存在两个二进制数满足相&为0
如果满足则说明这两个二进制所代表的集合没有交集，那么这个偶数就是一个可行解了
*/
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<map>
//#include<unordered_set>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
const int MOD=1e9+7;


map<LL,vector<int> >M;

int b[17],p[17];
set<int> ans;

int main()
{
    int vec,up;
    long long temp;
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&p[i]);
        vec=0,up=1<<m;
        M.clear();
        ans.clear();
        while(vec<up)
        {
            temp=0;
            int flag=0;
            for(int i=0;i<m;i++)
            {
                if((vec>>i)&1)
                {
                    temp+=p[i];
                }
            }
            if(temp%2==0)
            {
                int son=temp/2;
                vector<int> & pt=M[son];
                if(pt.size() >=2)
                {
                    for(int i=0;i<pt.size()&&!flag;i++)
                        for(int j=i+1;j<pt.size();j++)
                        {
                            if(!(pt[i]&pt[j]))
                            {
                                flag=1;
                                break;
                            }
                        }
                }
            }
            M[temp].push_back(vec);
            if(flag)
            {
                for(int i=0;i<n;i++)
                    ans.insert(temp+b[i]);
            }
            vec++;
        }
        for(int i=0;i<n;i++)
            ans.insert(b[i]);
        for(set<int>::iterator it=ans.begin();it!=ans.end();it++)
        {
            printf("%d\n",(*it));
        }
    }
    return 0;
}
/*
2 5
100 110
1 4 5 5 6
*/


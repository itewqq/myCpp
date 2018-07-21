/*
LA 3708
这个题一开始本身是想到了做法
但是实现和证明就不知道怎么处理了，我竟然傻到用set去求最近点
看了lrj的代码之后惊叹，竟然可以用缩放坐标和四舍五入的思想来做那个最近点：因为可能存在的最近点的取值是有限个而且是确定的，所以可以用整数来代替
而用这种方式也可以轻松证明（真的吗）会不会有两座雕塑移动到同一个位置
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
const int maxn=1e6+5;
const int MOD=1e9+7;
int n,m;


int main()
{
    double ans,pos;
    while(~scanf("%d%d",&n,&m))
    {
        ans=0.0;
        for(int i=1;i<n;i++)
        {
            pos=1.0*i/n*(n+m);
            //cout<<pos-floor(pos+0.5)<<endl;
            ans+=abs(pos-floor(pos+0.5))/(n+m);

        }
        printf("%.4lf\n",ans*10000);
    }
    return 0;
}


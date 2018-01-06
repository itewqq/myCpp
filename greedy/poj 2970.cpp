//贪心+数据结构
//很长时间没有写过算法了感觉十分生疏，贪心的题目到现在还是没有一种很好的把握，
//是否可以参考动态规划的思想呢，唉
//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int T;
double X;
struct cts
{
    int a;
    int b;
    int d;
}C[100005];
typedef struct cts cts;
bool cmp(const cts &a,const cts&b)//注意需要const，这次竟然忘了
{
    return a.d<b.d;
};
struct tp
{
    int i;
    int a;
    bool operator<(const struct tp &b)const//两个const
    {
        return a<b.a;
    }
};
priority_queue<struct tp> J;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&C[i].a,&C[i].b,&C[i].d);
    }
    sort(C,C+n,cmp);
    for(int i=0;i<n;i++)
    {
        cts& cur=C[i];
        T+=cur.b;
        J.push(tp{i,cur.a});
        struct tp t1;
        while(T>cur.d)
        {
            t1=J.top();
            int t=t1.i;
            if(T-cur.d>C[t].b)
            {
                X+=1.0*C[t].b/C[t].a;
                T-=C[t].b;
                J.pop();
            }
            else
            {
                C[t].b-=T-cur.d;
                X+=1.0*(T-cur.d)/C[t].a;
                T=cur.d;//最终bug
            }
        }
    }
    printf("%.2f\n",X);
	return 0;
}
/*
10
15 15 61
15 14 15
15 48 11
1 4 12
15 16 19
11 12 10
1 4 8
6 8 9
4 6 5
1 3 2
*/

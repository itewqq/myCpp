//求出一个序列使得任一子集之和与原序列中相应子集之和均不相等
//经大佬点明看出来，只要间接排序后依次移动一位就可以，如1234移动为2341即可/px

#include<bits/stdc++.h>
using namespace std;
int N,ar[25],ori[25],temp[25];
bool cmp(int a,int b)
{
    return ar[a]<ar[b];
}
int  main()
{

    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&ar[i]);
        ori[i]=i;
    }
    sort(ori,ori+N,cmp);
    for(int i=0;i<N;i++)
        temp[ori[i]]=ar[ori[(i+1)%N]];
    for(int i=0;i<N;i++)
    {
        printf("%d",temp[i]);
        if(i!=N-1)
            printf(" ");
    }
    return 0;
}

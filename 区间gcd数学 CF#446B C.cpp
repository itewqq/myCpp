//如果有1，则一定是从1开始扩散的剩下的个数
//如果没有1，则是构造出1最少的操作数加上n-1，构造时枚举所有的区间，找出区间gcd为1（保证能构造出1）而且最短的区间（保证操作数最小）
//构造出1后回到第一行的操作即可
//如果所有区间都没有构造出1，即所有的元素都互为因子，则输出-1
#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int  main()
{
    int N,ar[2005],ones=0,ml,mr;
    scanf("%d",&N);
    for(int i=0; i<N; i++)
    {
        scanf("%d",&ar[i]);
        if(ar[i]==1)
            ones++;
    }
    bool flag =false;
    if(ones)
        printf("%d\n",N-ones);
    else
    {
        ml=0,mr=N;
        for(int i=0; i<N-1; i++)
        {
            int temp=ar[i];
            for(int j=i+1; j<N; j++)
            {
                if((temp=gcd(temp,ar[j]))==1&&(mr-ml)>(j-i))
                {
                    flag=true;
                    mr=j;
                    ml=i;
                }
            }
        }
        if(flag)
            printf("%d\n",N-1+mr-ml);
        else
            printf("-1\n");
    }
    return 0;
}

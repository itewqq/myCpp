//一开始没想到是动规，后来发现ijk是有序的
#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxd =100005;
long long  v[maxd],u[4][maxd];//u[i][j]为第i个系数下的处理到第j个数字的最大值
int main ()
{
    memset(u,0,sizeof(u));
    for(int i=0;i<4;i++)
        u[i][0]=-9e18;//坑
    int n;
    long long a[4];
    scanf("%d",&n);
    if(n==0)
    {
        printf("0\n");
        return 0;
    }
    for(int i = 1; i <=3; i++)
        scanf("%lld",&a[i]);
    for(int i = 1; i <= n; i++)
        scanf("%lld",&v[i]);
    for(int i =1 ; i <=n; i++)
    {
        for(int j = 1; j <=3; j++)
        {
            u[j][i] = max(a[j] * v[i] + u[j-1][i],u[j][i-1]);//要么不变，要么算上上一层
        }
    }
    printf("%lld\n",u[3][n]);
    return 0;
}

/*
其他的都很好想，重点在于怎么计算出来那个最大的矩形。
这里用了和求UVa1619相同的做法，先求出来tb[i][j]代表第i行第j列往上累积了多少个相同的字符
然后对于每一个点求出来左右能延伸到的最远点，相减乘起来就是面积了
遍历选最大的即可，复杂度n^2
预处理的话，还可以进一步优化，当上一个点和这一个点都是对应的字符的话，就直接等于上一个+1，在处理左右的时候也应该这么做
不然就会导致上升一阶复杂度
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
const int maxn=1e3+5;
const int MOD=1e9+7;

char board[1005][1005];
int a[1005][1005],b[1005][1005],c[1005][1005];
int m,n;

int solve(int tb[1005][1005])
{
    int ma=0;
    for(int k=1;k<=m;k++)
    {
        tb[k][0]=-1;
        tb[k][n+1]=-1;
        int l[n+2],r[n+2];

        for(int i=1;i<=n;i++)
        {
            l[i]=r[i]=i;
        }
        for(int i=2;i<=n;i++)
        {
            //cout<<i<<" "<<tb[k][i]<<endl;
            while(tb[k][l[i]-1]>=tb[k][i])l[i]=l[l[i]-1];
        }

        for(int i=n-1;i>0;--i)
            while(tb[k][r[i]+1]>=tb[k][i])r[i]=r[r[i]+1];
        for(int i=1;i<=n;i++)
        {
            int temp=tb[k][i]*(r[i]-l[i]+1);
            //cout<<"asd    "<<k<<" "<<i<<" "<<temp<<endl;
            if(ma<temp)
                ma=temp;
        }
    }

    return ma;
}

int main()
{

    while(~scanf("%d%d",&m,&n))
    {
        getchar();
        for(int i=1;i<=m;i++)
            gets(board[i]+1);

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]=0;
                for(int k=i;k>=1;k--)
                {
                    if(board[k][j]!='b'&&
                       board[k][j]!='c'&&
                       board[k][j]!='x')
                    {
                        a[i][j]++;
                    }
                    else
                        break;
                }
            }
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                b[i][j]=0;
                for(int k=i;k>=1;k--)
                {
                    if(board[k][j]!='a'&&
                       board[k][j]!='c'&&
                       board[k][j]!='y')
                    {
                        b[i][j]++;
                    }
                    else
                        break;
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                c[i][j]=0;
                for(int k=i;k>=1;k--)
                {
                    if(board[k][j]!='b'&&
                       board[k][j]!='a'&&
                       board[k][j]!='w')
                    {
                        c[i][j]++;
                    }
                    else
                        break;
                }
            }
        }
        /*
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<b[i][j]<<" ";
            cout<<endl;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<c[i][j]<<" ";
            cout<<endl;
        }
        */
        int as=solve(a),bs=solve(b),cs=solve(c);
        //cout<<as<<" "<<bs<<" "<<cs<<endl;
        printf("%d\n",max(as,max(bs,cs)));
    }
    return 0;
}

/*
3
[[3,7],6]
40
[[2,3],[4,5]
*/

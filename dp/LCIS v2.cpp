果然是第一次没有理解，当时写的n^3的算法
主要的，我发现和上交的书上的不一样，他那本书讲的奇奇怪怪的。。
本来很朴素的想法的话就是n^4的复杂度，但是把f(i,j)在不存在的时候的意义改成前i个而不是正好以i为结尾的就很好解释
这时候是很容易想到n^3算法（好吧对我来说也没那么容易），然后就是怎么从n^3到n^2转变，
其实如果能想到n^3，就会发现，这里的更新过程中，那个最内部的循环其实可以省略——只需要考虑，小于ai的那些bj都继承下来，等于的直接加上之前的维护的
max即可！这里的很重要的为什么能继承下来就是状态定义的问题，如果按照原来的定义当ai!=bj时不存在，那么就会很难操作。

另一个大问题就是打印路径，这个真的是有点伤了，一定要注意分清楚，一个点的前驱是从哪里来的。。。注意绝对不能用一维，不存在的。
我在设置的过程中设置的方法是没有前驱的话是0，但是这样会导致整个答案里的第一个数字无法打印，因为他之前什么都没有也是0.所以要用-1来表示那些不存在的

#include <iostream>
#include <cstdio>
#include <cstring>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<cctype>
#include<algorithm>

using namespace std;
typedef long long LL;
const int maxn=500+5;
int sa[maxn],sb[maxn];
int f[maxn][maxn],p[maxn][maxn];

vector<int> V;

int main()
{
    int T,la,lb,maxdp,pom,ans,len,mai;
    scanf("%d",&T);
    while(T--)
    {
        mai=0;
        V.clear();
        memset(f,0,sizeof(f));
        memset(p,-1,sizeof(p));
        scanf("%d",&la);
        for(int i=1;i<=la;i++)
            scanf("%d",&sa[i]);
        scanf("%d",&lb);
        for(int i=1;i<=lb;i++)
            scanf("%d",&sb[i]);
        for (int i=1;i<=la;i++)
        {
            maxdp=pom=0;
            for (int j=1;j<=lb;j++)
            {
                f[i][j]=f[i-1][j];
                //p[i][j]=j;
                if(sa[i]==sb[j]&&maxdp+1>f[i][j])
                {
                    f[i][j]=maxdp+1;
                    p[i][j]=pom;
                    //pom=j;

                }
                else if(sa[i]>sb[j]&&maxdp<f[i-1][j])
                {
                    maxdp=f[i-1][j];
                    pom=j;
                    //pom=j;
                }
            }
        }
        ans=0,f[la][0]=0;

        for(int i=1;i<=lb;i++)
        {
            //cout<<f[la][i]<<endl;
            if(f[la][i]>f[la][ans])
            {
                //cout<<"mother";
                ans=i;
            }
        }
        for (int i=la;i>0&&ans;i--)if(p[i][ans]!=-1)
        {
            V.push_back(sb[ans]);
            ans=p[i][ans];
        }
        //cout<<"-----------\n";
        if(V.empty())
        {
            cout<<"0\n";
            continue;
        }
        len=V.size();
        printf("%d\n",len);
        for(int i=len-1;i>=0;i--)
            printf("%d ",V[i]);
        putchar('\n');
    }
    return 0;
}


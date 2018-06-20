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

int a[maxn];
int mi[maxn],mif,mir;
int ma[maxn],maf,mar;

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        mif=maf=0;
        mir=mar=0;

        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(int i=1; i<=k; i++)
        {
            //if(a[i-1]==mi[mif])mif++;
            while(mir!=mif&&mi[mir-1]>a[i])
                mir--;
            mi[mir++]=a[i];
        }
        printf("%d",mi[mif]);
        for(int i=k+1; i<=n; i++)
        {
            if(a[i-k]==mi[mif])
                mif++;
            while(mir!=mif&&mi[mir-1]>a[i])
                mir--;
            mi[mir++]=a[i];
            printf(" %d",mi[mif]);
        }
        putchar('\n');

        for(int i=1; i<=k; i++)
        {
            //if(a[i-1]==mi[mif])mif++;
            while(mar!=maf&&ma[mar-1]<a[i])
                mar--;
            ma[mar++]=a[i];
        }
        printf("%d",ma[maf]);
        for(int i=k+1; i<=n; i++)
        {
            if(a[i-k]==ma[maf])
                maf++;
            while(mar!=maf&&ma[mar-1]<a[i])
                mar--;
            ma[mar++]=a[i];
            printf(" %d",ma[maf]);
        }
        putchar('\n');
    }
    return 0;
}
/*
3
[[3,7],6]
40
[[2,3],[4,5]
*/

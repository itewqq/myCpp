#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>
using namespace std;
typedef unsigned long long LL;
int geteular(int n)
{
    int ret = 1,i;
    for(i = 2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            n/=i;
            ret*=i-1;
        }
        while(n%i==0)
        {
            n/=i;
            ret*=i;
        }
    }
    if(n>1)
    {
        ret*=n-1;
    }
    return ret;
}
LL mul(LL a,LL b,LL c)
{
    LL ans = 0,temp = a%c;
    while(b)
    {
        //  cout<<"ans"<<endl;
        if(b&0x1)
        {
            if((ans+=temp)>=c)
            {
                ans-=c;
            }
        }
        if((temp<<=1)>=c)
        {
            temp-=c;
        }
        b>>=1;
    }
    return ans;
}
LL modPow(LL a,LL b,LL m)
{
    LL ret = 1;
    while(b)
    {
//      cout<<"ret"<<endl;
        if(b&1)
        {
            ret = mul(ret,a,m);
        }//ret = ret*a%m;
        //a = a*a%m;
        a = mul(a,a,m);
        b>>=1;
    }
    return ret;
}
char b[1100000];
int main()
{
    // a^b%c = a^( b%phic+phic )%c;
    LL a,c;
    while(cin>>a)
    {
        scanf("%s",b);
        //cout<<b<<endl;
        cin>>c;
        //cout<<a<<" "<<b<<" "<<c<<endl;
//      LL sum = modPow(a,b,c);
//      printf("%I64d\n",sum);
//  }
//
        int n = strlen(b);
        if(n<=10)
        {
            LL numb = 0;
            for(int i = 0; i<n; i++)
            {
                numb = numb*10 + b[i] - '0';
            }
            LL sum = modPow(a,numb,c);
            cout<<sum<<endl;
        }
        else
        {
            LL phic = geteular(c);
            LL numb = 0;
            for(int i = 0; i<n; i++)
            {
                numb = numb%phic;
                numb = numb*10 + b[i] - '0';
            }
            numb += phic;
            LL sum = modPow(a,numb,c);
            cout<<sum<<endl;
        }
    }
    return 0;
}

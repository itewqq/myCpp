水题wa好几次 MMP
主要思路和poj3252一样的，一位一位算
但是没有考虑到很多情况，导致了不停wa
首先第一个就是，计算长度小于len的数的时候我第一次只看考虑到了长度为len-1，实际上还有长度为len-2，len-3.。。。也就是类似于前导零
当只有一位事要另算，因为这时候没有prev，所以最后的公式不管用
最后一个错误犯的很低级就是把计算组合时把j写成了prev。。导致了当字符串连续变化的时候就会正确，不连续就会错误，而且貌似在len==2时没有这个bug。fuck！

//poj1850
//#include<bits/stdc++.h>
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
using namespace std;
typedef long long LL;
const int maxn=10;
//const int MOD=1000000007;
LL C[30][30];

void get_C()
{
    for(int i=0; i<=27; i++)
    {
        C[i][0]=1;
        for (int j=1; j<=i; j++)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    return ;
}


char S[13];
int main()
{
    int len,ans=0,prev;
    
    
    get_C();
    ans=0;
    scanf(" %s",S);
    len=strlen(S);
    if(len==1)
    {
        cout<<S[0]-'a'+1<<endl;
        return 0;
    }
    for (int j=1; j<len; j++)
        ans+=C[26][len-j];

    for (int j='a'; j<S[0]; ++j)
        ans+=C['z'-j][len-1];

    prev=S[0];
    for (int i=1; i<len-1; ++i)
    {
        if(S[i]<=prev)
        {
            cout<<"0\n";
            return 0;
        }
        for (int j=prev+1; j<S[i]; ++j)
        {
            ans+=C['z'-j][len-i-1];
        }
        prev=S[i];
    }
    if(S[len-1]<=prev)
    {
        cout<<"0\n";
        return 0;
    }
    ans+=S[len-1]-prev;
    cout<<ans<<endl;

    return 0;
}

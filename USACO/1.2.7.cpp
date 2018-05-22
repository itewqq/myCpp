/*
ID: qushipe1
TASK: beads
LANG: C++
*/
/*
模拟，注意全为w的特殊情况
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    int len,left,nx,right,cl,cr,ans=0;
    char lf,rf;
    scanf("%d",&len);
    char c[370];
    int vis[370];
    getchar();
    gets(c);
    //puts(c);
    //int len=strlen(c);
    char tmp=c[0];
    int m;
    for(m=1;m<len;m++)
    {
        if(tmp!=c[m])
        {
            break;
        }
    }
    if(m==len)
    {
        cout<<len<<endl;
        return 0;
    }
    for(int i=0;i<len;i++)
    {
        memset(vis,0,sizeof(vis));
        //ans=0;
        cl=cr=0;
        left=i,right=(i+1)%len;
        nx=(left-1+len)%len;
        //vis[left]=vis[right]=1;
        lf=c[left],rf=c[right];
        if(lf=='w')
            continue;
        if(rf=='w')
        {
            int i=right;
            while(rf=='w')
            {
                i=(i+1)%len;
                rf=c[i];
            }
        }
        while(left!=right)
        {
            cl++;
            vis[left]=1;
            nx=(left-1+len)%len;
            if(c[nx]!='w')
            {
                if(c[nx]!=lf)
                {
                    break;
                }
                else
                {
                    //cl++;
                    left=nx;
                }
            }
            else
            {
                //cl++;
                left=nx;
            }
        }
        //cout<<left<<" "<<right<<vis[right]<<endl;
        while(!vis[right])
        {
            cr++;
            vis[right]=1;
            nx=(right+1+len)%len;
            if(c[nx]!='w')
            {
                if(c[nx]!=rf)
                {
                    break;
                }
                else
                {
                    //cr++;
                    right=nx;
                }
            }
            else
            {
                //cr++;
                right=nx;
            }
        }
        //cout<<i<<" "<<cl<<" "<<cr<<endl;
        ans=max(ans,cr+cl);
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
//rwrwrwrwrwrwrwrwrwrwrwrwbwrwbwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwrwr

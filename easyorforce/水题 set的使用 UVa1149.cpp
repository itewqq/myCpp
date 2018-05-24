注意set的end，begin，rend，rbegin，
尤其是lower_bound的返回值！！！
当不存在的时候都是返回大的那个位置。。。因为这个wa了
还有最后的输出，最后一个空行是不能有的，不然会被判pe
//UVa1149
#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100000+5;
//const int MOD=1e9+7;
const int INF=1<<29;

/*
int read()
{
    int x;
    int f=1;
    x=0;
    char s=getchar();
    while(s<'0'||s>'9')
    {
        if(s=='-')
            f=-1;
        s=getchar();
    }
    while(s>='0'&&s<='9')
    {
        x=x*10+s-'0';
        s=getchar();
    }
    x*=f;
    return x;
}
*/
/*
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
*/

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int T,n,l,tmp;
    scanf("%d",&T);
    while(T--)
    {
        int ans=0;
        //memset(vis,0,sizeof(vis));
        multiset<int> Q;
        scanf("%d %d",&n,&l);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            Q.insert(tmp);
        }

        //sort(sq,sq+n);
        //int rear=n-1,cnt=n;
        set<int>::iterator it;
        set<int>::iterator rit;
        /*
        cout<<"mother fucker   \n";
        for(it=Q.begin();it!=Q.end();it++)
            cout<<*(it)<<" ";
        cout<<endl;
        */
        //cout<<*(Q.rbegin())<<endl;
        while(!Q.empty())
        {
            //cout<<"Q has "<<Q.size()<<endl;
            rit=Q.end();
            rit--;
            int last=*(rit);
            //cout<<last<<endl;
            Q.erase(rit);
            if(last<=l)
            {
                ans++;
                if(!Q.empty()&&last<l)
                {
                    it=Q.lower_bound(l-last);
                    if(*(it)!=l-last&&it!=Q.begin())
                        it--;
                    //cout<<"it "<<*(it)<<" "<<last<<endl;
                    if(it!=Q.end())
                    {
                        if(*(it)<=l-last)
                        {
                            Q.erase(it);
                        }
                    }
                    else
                    {
                        Q.erase(--it);
                    }
                }
            }
        }
        cout<<ans<<endl;
        if(T)
            cout<<endl;
    }
}
/*
100
5 10 2
3 4 5 6 7
2 123456 7
6541 5987
*/

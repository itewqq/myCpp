#include<bits/stdc++.h>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string.h>
#include<set>

using namespace std;

struct term
{
  int a,f;
  term(int a,int f):a(a),f(f){}
  bool operator<(const struct term&rhs)const
  {
    return   a<rhs.a;
  }
};
typedef struct term term;
set<term> S;
//int Ans[200005];
int k,z;
int seq[200005];
int f[200005];
int g[200005];
int main()
{
    bool keep;
    int Z,N,ans;
    scanf("%d",&Z);
    z=Z;
    while(Z--)
    {
        keep=true;
        S.clear();
        set<term>::iterator it;
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
            scanf("%d",&seq[i]);
        f[1]=1;
        for (int i=2;i<=N;i++)
        {
            if(seq[i]>seq[i-1])
                f[i]=f[i-1]+1;
            else
                f[i]=1;
        }
        g[N]=1;
        for (int i=N-1;i>0;i--)
        {
            if(seq[i]<seq[i+1])
                g[i]=g[i+1]+1;
            else
                g[i]=1;
        }
        S.insert(term{seq[1],f[1]});
        ans=1;
        for (int i=2;i<=N;i++)
        {
            keep=true;
            term c=term{seq[i],f[i]};
            it=S.lower_bound(c);
            if(it!=S.begin())
            {
                term temp=*(--it);
                int len=g[i]+temp.f;
                ans=max(len,ans);
                if(temp.f>f[i])
                    keep=false;
            }
            if(keep)
            {
                S.insert(c);
                it=S.find(c);
                it++;
                while(it!=S.end()&&it->a>=c.a&&it->f<=c.f)
                    S.erase(it++);
            }
        }
        printf("%d\n",ans);
        //Ans[k++]=ans;
    }
    /*
    for (int i=0;i<z;i++)
        cout<<Ans[i]<<endl;
    */
    return 0;
}

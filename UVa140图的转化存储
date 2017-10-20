#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>

using namespace std;
int G[10][10];
map<char,int> M;
map<int,char> TM;
char ans[10];
char Gans[10];
bool used[10];
int Gmin=1<<30;
int Lmin=0;
int num=0;

int cal(int k)
{
    int temp=Lmin;
    for(int i=1;i<k;i++)
    {
        if(G[M[ans[i]]][M[ans[k]]]&&(k-i>temp))
                temp=k-i;
    }
    return temp;
}

void doit(int k)
{
    int tt;
    if(k==num)
    {
        if(Gmin==Lmin)
        {
            Gmin=Lmin;
            if(strcmp(Gans+1,ans+1)>0)//final!!!!!!
            memcpy(Gans,ans,sizeof(ans));
        }
        else if(Gmin>Lmin)
        {
            Gmin=Lmin;
            memcpy(Gans,ans,sizeof(ans));
        }
        return;
    }
    for(int i=1;i<=num;i++)
    {
        if(!used[i])
        {
            ans[k+1]=TM[i];
            cal(k+1);
            if(cal(k+1)>Gmin)
            {
                continue;
            }
            used[i]=true;
            tt=Lmin;
            Lmin=cal(k+1);
            doit(k+1);
            Lmin=tt;
            used[i]=false;
        }
    }
    return;
}

int main()
{

    char temp,pre;
    bool flag=false;
    memset(G,0,sizeof(G));
    memset(used,0,sizeof(used));

    while(scanf("%c",&temp)&&temp!='#')
    {
        if(temp==':')
        {
            flag=true;
            continue;
        }
        if(temp==';')
        {
            flag=false;
            continue;
        }
        if(temp=='\n')
        {
            Lmin=0;
            Gmin=1<<30;
            memset(ans,0,sizeof(ans));
            memset(Gans,-1,sizeof(Gans));
            memset(used,0,sizeof(used));
            doit(0);
            for(int i=1;i<=num;i++)
                printf("%c ",Gans[i]);
            printf("-> %d\n",Gmin);
            memset(G,0,sizeof(G));
            M.erase(M.begin(),M.end());
            TM.erase(TM.begin(),TM.end());
            num=0;
            flag=false;
            continue;
        }
        if(M.find(temp)==M.end())
        {
            num++;
            M[temp]=num;
            TM[num]=temp;
        }
        if(!flag)
        {
            pre=temp;
            continue;
        }
        G[M[pre]][M[temp]]=1;
        G[M[temp]][M[pre]]=1;
    }
    return 0;
}

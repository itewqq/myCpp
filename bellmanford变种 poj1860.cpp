#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

struct state
{
    state(int a=0,int b=0,double r=0,double c=0):from(a),to(b),R12(r),C12(c){}
    int from,to;
    double R12,C12;
};
struct state edges[205];

double d[105];
int main()
{
    int N,M,S;
    double V,Rxy,Cxy,Ryx,Cyx;
    scanf("%d %d %d %lf",&N,&M,&S,&V);
    d[S]=V;
    for(int i=1,x,y;i<=M+M;i++)
    {
        scanf("%d %d",&x,&y);
        scanf("%lf %lf %lf %lf",&Rxy,&Cxy,&Ryx,&Cyx);
        struct state s1(x,y,Rxy,Cxy);
        edges[i]=s1;
        struct state s2(y,x,Ryx,Cyx);
        edges[++i]=s2;
    }
    bool flag=false;
    for(int i=1;i<=N;i++)
    {
        flag=false;
        for(int k=1;k<=M+M;k++)
        {
            if(d[edges[k].to]<(d[edges[k].from]-edges[k].C12)*edges[k].R12)
            {
                flag=true;
                d[edges[k].to]=(d[edges[k].from]-edges[k].C12)*edges[k].R12;
            }
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
	return 0;
}

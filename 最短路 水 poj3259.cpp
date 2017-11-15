//poj3259
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
int d[505];
int edges[5205][3];
int main()
{
    int F,N,M,W;
    cin>>F;
    while(F--)
    {
        cin>>N>>M>>W;
        for(int i=1; i<=M+M; i++)
        {
            cin>>edges[i][1]>>edges[i][2]>>edges[i][0];
            edges[i+1][2]=edges[i][1];
            edges[i+1][1]=edges[i][2];
            edges[i+1][0]=edges[i][0];
            i++;
        }
        for(int i=M+M+1; i<=W+M+M; i++)
        {
            cin>>edges[i][1]>>edges[i][2]>>edges[i][0];
            edges[i][0]=-edges[i][0];
        }

        for(int i=1; i<=N; i++)
            d[i]=1<<29;
        d[1]=0;
        int flag=true;
        for(int i=0; i<N-1; i++)
        {
            flag=false;
            for(int j=1; j<=M+M+W; j++)
            {
                if(d[edges[j][2]]>d[edges[j][1]]+edges[j][0])
                {
                    d[edges[j][2]]=d[edges[j][1]]+edges[j][0];
                    flag=true;
                }
            }
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

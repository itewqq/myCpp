#include<cstdio>
int n,k,m,s,num,q[100005],a[100005],sum[100005];
int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        q[i]=a[i]%m;
    }
    for(int i=1;i<=n;i++)
        sum[q[i]]++;
    bool flag=false;
    int i;
    for(i=0;i<m;i++)
        if(sum[i]>=k)
        {
            flag=true;
            break;
        }
    if(flag)
    {
        printf("Yes\n");
        num=i;
        for(int i=1;i<=n;i++)
            if(q[i]==num)
            {
                s++;
                if(s==k)
                {
                    printf("%d\n",a[i]);
                    break;
                }
                else
                    printf("%d ",a[i]);
            }
    }
    else
        printf("No\n");
    return 0;
}

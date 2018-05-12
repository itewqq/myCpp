/*
这里一开始纠结于以什么样的顺序，其实后来发现决定费用的不是顺序，而是最小生成树
一旦确定了最小生成树，那么他所包括的点，无论是从哪个点开始，只要一个一个的加入点，到最后结果都是一样的
而这个题也就变成了求最大权的森林，实际上求最小生成树的算法只不过是求得当森林只有一颗树的情况
至于性别之类并没有什么用处，属于设置了无用的陷阱的题目
*/
void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}


int p[maxn];
int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
int T,n,m,r,s[maxn],t[maxn],e[maxn],pos[maxn];

bool cmp(int a,int b)
{
    return e[a]<e[b];
}

int main()
{
    scanf("%d",&T);
    int ans;
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&r);
        
        ans=0;
        for (int i=0;i<r;++i)
        {
            //scanf("%d%d%d",&s[i],&t[i],&e[i]);
            read(s[i]);
            read(t[i]);
            read(e[i]);
            e[i]=-e[i];
            t[i]+=n;
            pos[i]=i;

        }
        for (int i=0;i<n+m;i++)
            p[i]=i;
        sort(pos,pos+r,cmp);
        //sort(t,t+n,cmp);
        //sort(pos,pos+n,cmp);
        for (int i=0;i<r;++i)
        {
            int u=s[pos[i]],v=t[pos[i]],x=find(u),y=find(v);
            if(x!=y)
            {
                ans+=e[pos[i]];
                p[x]=y;
            }
        }
        printf("%d\n",10000*(n+m)+ans);
    }
    return 0;
}

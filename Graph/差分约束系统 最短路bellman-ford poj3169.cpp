/*
第一道差分约束系统的题目吧
注意建模与转化就行了
最后一点是输出-1和-2，-1是无解也就是有负环，-2是任意数都是解也就是点1与点N不连通。
*/
typedef struct Edge
{
    int from,to,w;
    Edge(){}
    Edge(int from,int to,int w):from(from), to(to),w(w){}
}Edge;



vector<Edge> G(200005);
int dist[maxn];

int main()
{
    int n,ml,md,from,to,w,k=0,flag=0;
    scanf("%d%d%d",&n,&ml,&md);
    fill(dist,dist+n+1,INF);
    dist[1]=0;
    for (int i=0;i<ml;i++)
    {
        scanf("%d%d%d",&from,&to,&w);
        G[k++]=Edge(from,to,w);
    }
    for ( int i=0;i<md;i++)
    {
        scanf("%d%d%d",&to,&from,&w);
        G[k++]=Edge(from,to,-w);
    }
    for (int i=0;i<n&&!flag;++i)
    {
        for (int j=0;j<k;++j)
        {
            Edge e=G[j];
            //cout<<e.from<<" "<<e.to<<" "<<e.w<<endl;
            if(dist[e.from]!=INF&&dist[e.to]>dist[e.from]+e.w)
            {

                dist[e.to]=dist[e.from]+e.w;
                //cout<<dist[e.to]<<endl;
                if(i==n-1){flag=1;break;}
            }
        }
    }
    if(flag)
        printf("-1\n");
    else if(dist[n]==INF)
        printf("-2\n");
    else
        printf("%d\n",dist[n]);
    return 0;
}

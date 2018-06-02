/*
这个题可是让我头疼了两天。。
果然看不懂别人代码的时候自己写一下就能理解了，难点还是在于实现

题意的要求，首先是从上往下找到的第一个就满足，但是我们的我们在这里可以采用逆过来从后往前插入trie，然后在插入的过程中每次都覆盖之前的记录
这样的话最后查询到的一定是从上往下先找到的，这个思想很重要！

然后就是实现，这里一开始看不懂为什么他们要在轮到某个节点的时候先把这个节点的所有0-9的后继都创出来并且在这时候就把标记下放
然后自己写了一遍就意识到了问题所在：如果不这样做，那么就很难执行更新下放的操作，这里的更新下放指的是，如果一开始前缀为79，然而有个优先级更高的为
7920，那么这时候79就不是一个叶子了，但是791，793，794.。。这些仍然可以通过79来判定，所以在这样的操作的时候一定要更新下放。
然后这里的思想就是，与其说在需要更新的时候再操作，不如直接预处理就把所有的节点先下放一层，这样的话如果之后被覆盖也没关系，因为如果后面更新了下放，
那么这一步操作就把那个省掉了，如果之后没有更新下放，那么在第一个dfs的时候就会把这些节点收上来！所以不会影响最后结果，但是简化了代码。至于我一开始纠结
的这样下放后会不会对之后的建造和判断产生影响，事实上是不会的。因为构造树的过程是跟这个无关的，构造树的过程是在这之后的if else里面，按照逐位构建
然后判断的时候为什么不会受到影响？这时候我们只要两个判断就可以了，因为上面的操作过后其实是产生了两种叶子，第一种就是leaf!=-1的，第二种就是这些每个
原来的前缀尾巴”叶子“多下放下来的那些，而这些叶子是真正的存储结构上的叶子，他们的判断方法很简单，判断有没有后继即可——要有后继一定是从0到9都有后继（
因为我们多下放了一步的操作），所以判断任意一个后继是不是-1即可！
最后还有一个细节就是判断重复的时候一定要判断到第一个就break，这是最后的bug。因为他可能不止重复一次，而无论重复多少次我们都是只要优先级最高的哪一个

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;
const int  maxn=13;

char A[105][maxn],B[105][maxn],S[105][30];
int node[121050][13],leaf[121050];
int num[105];
int tot;
int valid[105];
void _insert(char* a,char* b,int num)
{
    int l=0,r=0,len=strlen(a);
    for(int i=0; i<len; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(node[l][j] == -1)
                node[l][j] = ++tot;
            if(node[r][j] == -1)
                node[r][j] = ++tot;
            if(leaf[l] !=-1)
                leaf[node[l][j]] = leaf[l];
            if(leaf[r] !=-1)
                leaf[node[r][j]] = leaf[r];
        }
        leaf[l]=leaf[r]=-1;
        if(l==r)
        {
            for(int j=a[i]-'0'+1; j<b[i]-'0'; j++)
            {
                leaf[node[l][j]]=num;
            }
        }
        else
        {
            for(int j=a[i]-'0'+1; j<10; j++)
            {
                leaf[node[l][j]]=num;
            }
            for(int j=0; j<b[i]-'0'; j++)
            {
                leaf[node[r][j]]=num;
            }
        }
        l=node[l][a[i]-'0'];
        r=node[r][b[i]-'0'];
    }
    leaf[l]=num;
    leaf[r]=num;
    return ;
}
int ans;
void dfs(int x)
{
    if(leaf[x]!=-1)
    {
        ans+=valid[leaf[x]];
        return ;
    }
    if(node[x][0]==-1)
        return ;
    bool f=true;
    for(int i=0;i<10;i++)
    {
            dfs(node[x][i]);
            if(leaf[node[x][i]]!=leaf[node[x][0]])
                f=false;

    }
    if(f&&valid[leaf[node[x][0]]]&&x)
    {
        ans-=9;
        leaf[x]=leaf[node[x][0]];
    }
    return ;
}

char s[30];
void dfs2(int u, int len)
{
    if(leaf[u]!=-1)
    {
        if(valid[leaf[u]])
        {
            for(int i = 0; i < len; i++)
            {
                putchar(s[i]);
            }
            putchar(' ');
            printf("%s\n", S[leaf[u]]);
        }
        return;
    }

    if(node[u][0] == -1)
        return;

    for(int i = 0; i < 10; i++)
    {
        s[len] = '0' + i;
        dfs2(node[u][i], len + 1);
    }
}

int main()
{
    int n;
    bool fuck=true;
    while(~scanf("%d",&n))
    {
        if(!fuck)
            putchar('\n');
        else
            fuck=false;
        memset(node,-1,sizeof(node));
        memset(leaf,-1,sizeof(leaf));
        memset(valid,0,sizeof(valid));
        tot=1;
        ans=0;
        for(int i=0; i<n; i++)
        {
            scanf("%s - %s %s",A[i],B[i],S[i]);

            int al=strlen(A[i]),bl=strlen(B[i]);
            for(int j=bl-1; j>=0; j--)
                B[i][al-(bl-j)]=B[i][j];
            for(int j=al-bl-1; j>=0; j--)
                B[i][j]=A[i][j];
        }
        for(int i=0; i<n; i++)
            num[i]=i;
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
            if(strcmp(S[j],S[i])==0)
            {
                num[i]=j;
                break;//last error
            }
                
        for(int i=0;i<n;i++)
            if(strcmp(S[i],"invalid")!=0)
                valid[i]=1;

        for(int i=n-1; i>=0; i--)
        {
            _insert(A[i],B[i],num[i]);
        }
        dfs(0);
        printf("%d\n",ans);
        dfs2(0,0);
    }
    return 0;
}
/*
8
7919 - 921 cell
7921800 - 999 priv
1 - 1 usa
760 - 9 rsv
7928 - 29 rsv
7600 - 7899 spec
73 - 77 invalid
7 - 7 cis
*/

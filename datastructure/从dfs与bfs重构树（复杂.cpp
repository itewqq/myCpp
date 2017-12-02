//这个东西是想了很久但是没有想出来具体什么是正确的策略
//参考了别人的博客感觉大致有点懂得原理，但是却无法给出正确性证明
//感觉数据结构还是弱项，需要强化
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>

using namespace std;

int bfs[1005];
vector<int> ans[1005];

int N;


int main()
{
    while(cin>>N)
    {
        stack<int >st;
        memset(ans,0,sizeof(ans));
        int temp,root,v;
        for(int i=1; i<=N; i++)
        {
            cin>>temp;
            bfs[temp]=i;
        }
        cin>>root;
        st.push(root);
        for(int i=2;i<=N;i++)
        {
            cin>>v;
            while(1&&!st.empty())
            {
                int u=st.top();
                if(bfs[u]+1<bfs[v]||u==root)//疑惑：具体什么是确切的v为u的孩子的条件，此处也可加上等于的条件bfs[u]+1]]bfs[v]&&u>v
                {                           //但我想不出正确性证明
                    ans[u].push_back(v);
                    st.push(v);
                    break;
                }
                else
                    st.pop();
            }
        }
        for(int i=1;i<=N;i++)
        {
            cout<<i<<":";
            for(int j=0;j<ans[i].size();j++)
                cout<<" "<<ans[i][j];
            cout<<endl;
        }
    }
    return 0;
}

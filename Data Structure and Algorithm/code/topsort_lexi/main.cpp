#include <iostream>
#include<queue>
using namespace std;
int G[200][200],n,m,Q,u,v,i,indeg[200];

int main()
{
   std::priority_queue<int> pq;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>Q;
        while(Q--)
        {
            cin>>v;
            G[v][u]=1;
            indeg[u]++;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            pq.push(i*-1);
        }
    }
    while(!pq.empty())
    {
        u=pq.top();
        u=u*-1;
        cout<<u<<" ";
        pq.pop();
        for(i=1;i<=n;i++)
        {
            if(G[u][i]==1)
            {
                indeg[i]--;
                G[u][i]=0;
                if(indeg[i]==0)
                pq.push(i*-1);
            }
        }
    }
    return 0;
}

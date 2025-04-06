#include <iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
typedef vector<int> VI;
vector<VI> G;
int indeg[10006];
int main()
{
    int n,m,u,v,l,i,cnt,ans[10006];
    std::priority_queue<int> pq;
    scanf("%d %d",&n,&m);
    G=vector<VI> (10001);
    while(m--)
    {
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        indeg[v]++;
    }
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            pq.push(i*-1);
        }
    }
    cnt=0;
    while(!pq.empty())
    {
     u=pq.top();
     u=u*-1;
     ans[cnt]=u;
     cnt++;
     pq.pop();
     l=G[u].size();
     for(i=0;i<l;i++)
     {
         indeg[G[u].back()]--;
         if(indeg[G[u].back()]==0)
         pq.push(G[u].back()*-1);
         G[u].pop_back();
     }
    }
    if(cnt==n)
    {
     for(i=0;i<cnt;i++)
     printf("%d ",ans[i]);
    }
    else
    printf("Sandro fails.");
    return 0;
}

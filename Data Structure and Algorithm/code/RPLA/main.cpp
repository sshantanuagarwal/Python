#include <iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
typedef vector<int> VI;
vector<VI> G;
int n,r,u,v,i,indeg[1004],T,rnk,l,sc;
int main()
{ std::priority_queue<int> pq;
sc=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&r);
        G=vector<VI>(n);
        for(i=0;i<n;i++)
        indeg[i]=0;
        while(r--)
        {
         scanf("%d %d",&u,&v);
         G[v].push_back(u);
         indeg[u]++;
        }
        for(i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                pq.push(i*-1);
            }
        }
        rnk=0;
        printf("Scenario #%d:\n",sc);
        sc++;
        while(!pq.empty())
    {    rnk++;
           while(!pq.empty())
        {
         u=pq.top();
         u=u*-1;
         indeg[u]=-1;
         pq.pop();
         printf("%d %d\n",rnk,u);
         l=G[u].size();
         for(i=0;i<l;i++)
         {
             indeg[G[u].back()]--;
             G[u].pop_back();
         }
        }
        for(i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                pq.push(i*-1);
            }
        }
    }
    }
    return 0;
}

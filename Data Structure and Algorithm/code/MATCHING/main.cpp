#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> G[100005];
int dist[100005],match[100005],n;
long long int INF=200000;
int NIL=0;
bool bfs()
{int u,v,i;
    queue<int> Q;
    for(i=1;i<=n;i++)
    {
        if(match[i]==NIL)
        {dist[i]=0;
        Q.push(i);
        }
        else
        dist[i]=INF;
    }
    dist[NIL]=INF;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        if(u!=NIL)
        {for(i=0;i<G[u].size();i++)
        {
            v=G[u][i];
            if(dist[match[v]]==INF)
            {
                dist[match[v]]=dist[u]+1;
                Q.push(match[v]);
            }
        }
        }
    }
    return (dist[NIL]!=INF);
}
 bool dfs(int u)
 {int i,v;
     if(u!=NIL)
     {for(i=0;i<G[u].size();i++)
     {
         v=G[u][i];
         if(dist[match[v]]==dist[u]+1)
         {
             if(dfs(match[v]))
             {
                 match[v]=u;
                 match[u]=v;
                 return true;
             }
         }
     }
     dist[u]=INF;
     return false;
     }
     return true;
 }
 int hopcroft()
 {int i,matching=0;
     while(bfs())
     {
      for(i=1;i<=n;i++)
      if(match[i]==NIL&&dfs(i))
      matching++;
     }
     return matching;
 }
int main()
{
int c1,c2,p,u,v;
scanf("%d %d %d",&c1,&c2,&p);
n=c1;
while(p--)
{
    scanf("%d %d",&u,&v);
    v+=c1;
    G[u].push_back(v);
    G[v].push_back(u);
}
printf("%d\n",hopcroft());
return 0;
}



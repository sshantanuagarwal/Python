#include <iostream>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;
int pr[100005];
int inf=1000,res;
struct Edge
{
    int org;
    int dest;
    int wt;
};
struct Comp{
bool operator()(Edge &t1, Edge &t2)
    {
        return t1.wt>t2.wt;
    }
};
typedef vector<Edge> VI;
vector<VI> G,H;
deque<Edge> d;
vector<int> mark;
int M[100][100],W[100][100];
void bfs(int u,int q)
 {int l,i;Edge v,x;
 mark[u]=1;
 l=H[u].size();
     for (i=0;i<l;i++)
    {v=H[u][i];
       if(!mark[v.dest])
       {
           mark[v.dest]=1;
           M[q][v.dest]=max(M[q][u],v.wt);
           d.push_back(v);
       }
    }
    while(!d.empty())
    {
          x=d.front();
          d.pop_front();
          bfs(x.dest,q);
    }
 }
int main()
{int n,m,i,u,v,w,l;long long int sum=0;
    std::priority_queue<Edge, std::vector<Edge>, Comp> pq;
    cin>>n>>m;
    G=vector<VI>(n+1);
    H=vector<VI>(n+1);
    Edge s;
   for(i=0;i<m;i++)
   {
       cin>>u>>v>>w;
       s.dest=v;
       s.wt=w;
       G[u].push_back(s);
       s.dest=u;
       s.wt=w;
       G[v].push_back(s);
   }
   l=G[1].size();
   pr[1]=1;
   Edge x,y;
   for(i=0;i<l;i++)
   {
       x.org=1;
       x.dest=G[1][i].dest;
       x.wt=G[1][i].wt;
       pq.push(x);
   }
   int j=0;sum=0;
   while(j<n-1)
   {
      y=pq.top();
      pq.pop();
      if(pr[y.dest]==0)
      {sum+=y.wt;j++;cout<<y.org<<" "<<y.dest<<endl;
      s.dest=y.dest;
      s.wt=y.wt;
      H[y.org].push_back(s);
      s.dest=y.org;
      s.wt=y.wt;
      H[y.dest].push_back(s);
      }
      else
      {
          W[y.org][y.dest]=y.wt;
          W[y.dest][y.org]=y.wt;
      }
      pr[y.dest]=1;
      l=G[y.dest].size();
      for(i=0;i<l;i++)
   {
       x.org=y.dest;
       x.dest=G[y.dest][i].dest;
       x.wt=G[y.dest][i].wt;
       if(pr[x.dest]==0)
       {pq.push(x);}
   }
   }
   cout<<sum<<endl;
   for(i=1;i<=n;i++)
   {
       mark=vector<int>(n+1,0);
       M[i][i]=0;
       bfs(i,i);
   }
   res=inf;
   for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
   {
       cout<<"M["<<i<<"]"<<"["<<j<<"]"<<"="<<M[i][j]<<endl;
       if(W[i][j]!=0)
       {
           res=min(res,W[i][j]-M[i][j]);
       }
   }
   cout<<"THE MINIMUM SPANNING TREE IS OBTAINED TO BE AS = "<<sum<<endl;
   cout<<"THE SECOND MINIMUM SPANNING TREE IS OBTAINED TO BE AS = "<<sum+res<<endl;
   return 0;
}
/*
9 14
1 2 4
2 3 8
3 4 7
4 5 9
5 6 10
6 7 2
7 8 1
8 1 8
2 8 11
8 9 7
7 9 6
3 6 4
4 6 14
3 9 2
*/

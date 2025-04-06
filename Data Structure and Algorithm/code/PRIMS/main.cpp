#include <iostream>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;
int pr[100005];
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
vector<VI> G;
int main()
{int n,m,i,u,v,w,l;long long int sum=0;
    std::priority_queue<Edge, std::vector<Edge>, Comp> pq;
    cin>>n>>m;
    G=vector<VI>(n+1);
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
      {sum+=y.wt;j++;}
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

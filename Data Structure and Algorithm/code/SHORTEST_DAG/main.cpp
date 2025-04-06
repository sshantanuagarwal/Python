//bellman ford == single source shortest path for both directed and undirected graph.
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct vertex
{
    int x;
    int wt;
};
struct z
{
    int a;
    int d;
    int f;
}t[100005];
typedef vector<vertex> VI;
vector<VI> G;
vector<int> mark;
int d[100005],cnt;
bool cmp(struct z x1,struct z x2)
{
    return x1.f>x2.f;
}
void dfs(int u)
 {vertex v;
 int l,i;
 mark[u]=1;t[u].d=cnt;cnt++;
 cnt++;
 l=G[u].size();
     for (i=0;i<l;i++)
    {v=G[u][i];
       if(!mark[v.x])
       dfs(v.x);
    }
    t[u].f=cnt;cnt++;
 }
int main()
{int n,m,st,u,v,w,i,j,inf=1000,l;
    cin>>n>>m>>st;
    G=vector<VI>(n);
    mark=vector<int>(n);
    vertex s;
    while(m--)
    {
        cin>>u>>v>>w;
        u--;v--;
        s.x=v;
        s.wt=w;
        G[u].push_back(s);
    }
    for(i=0;i<n;i++)
    t[i].a=i;
    for(i=0;i<n;i++)
    {
        if(!mark[i])
        {cnt=0;dfs(i);}
    }
    sort(t,t+n,cmp);
    for(i=0;i<n;i++)
    d[i]=inf;
    st--;
    d[st]=0;
    for(i=0;i<n;i++)
    {
        u=t[i].a;
        l=G[u].size();
        for(j=0;j<l;j++)
        {
            if(d[G[u][j].x]>d[u]+G[u][j].wt)
            d[G[u][j].x]=d[u]+G[u][j].wt;
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<"shortest distance from "<<st+1<<" to "<<i+1<<" is = "<<d[i]<<endl;
    }
    return 0;
}
/*
5 6 1
1 2 1
1 5 -3
1 4 -2
4 5 -2
2 3 2
5 3 -2
*/

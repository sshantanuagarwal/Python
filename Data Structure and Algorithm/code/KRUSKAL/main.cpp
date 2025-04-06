#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
struct z
{
    int org;
    int dest;
    int wt;
}edge[100005];
bool cmp(struct z a,struct z b)
{
    return a.wt<b.wt;
}
int p[100005],rank[100005];
int find(int x)
{
    if(x!=p[x])
    {
        p[x]=find(p[x]);
    }
    return p[x];
}
void link(int x,int y)
{
    if(rank[x]>rank[y])
    {
        p[y]=x;
        rank[x]+=rank[y];
    }
    else
    {
         p[x]=y;
        rank[y]+=rank[x];
    }
}
int main()
{int n,m,u,v,w,i;
long long int sum;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        p[i]=i;
        rank[i]=1;
    }
    for(i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        u--;
        v--;
        edge[i].org=u;
        edge[i].dest=v;
        edge[i].wt=w;
    }
   sort(edge,edge+m,cmp);
   sum=0;
   for(i=0;i<m;i++)
   {
       if(find(edge[i].org)!=find(edge[i].dest))
       {
           link(find(edge[i].org),find(edge[i].dest));
           //cout<<edge[i].org<<" "<<edge[i].dest<<endl;
           sum+=edge[i].wt;
       }
   }
   cout<<sum<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include<algorithm>
#include<cstdio>
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
char s[20];
int main()
{int n,m,u,v,w,i,k,j,T;
long long int sum;
scanf("%d",&T);
while(T--)
    {scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p[i]=i;
        rank[i]=1;
    }k=0;
    for(j=0;j<n;j++)
    {scanf("%s %d",s,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&v,&w);
        u=j;
        v--;
        edge[k].org=u;
        edge[k].dest=v;
        edge[k].wt=w;
        k++;
    }
    }
   sort(edge,edge+k,cmp);
   sum=0;
   for(i=0;i<k;i++)
   {
       if(find(edge[i].org)!=find(edge[i].dest))
       {
           link(find(edge[i].org),find(edge[i].dest));
           //cout<<edge[i].org<<" "<<edge[i].dest<<endl;
           sum+=edge[i].wt;
       }
   }
   printf("%lld\n",sum);
    }
    return 0;
}

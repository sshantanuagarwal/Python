#include <iostream>
#include<vector>
#include <cstdio>
using namespace std;
typedef vector<int> VI;
vector<VI> a;
VI mark,d,low,p;long long int tim,coun;int z[4000],l;
/*
void dfs(int u)
 {
 mark[u]=1;
 time++;
 d[u]=time;
     for (VI::iterator v = a[u].begin(); v != a[u].end(); v++)
    {
       if(!mark[*v])
       {   p[*v]=u;
       cout<<u<<" "<<*v<<endl;
           dfs(*v);
       }
    }
    mark[u]=2;
    time++;
    f[u]=time;
 }*/
 void findArticPts(int u)
 {
     mark[u]=1;
     low[u]=d[u]=++tim;
     //l=a[u].size();
     for (VI::iterator v = a[u].begin(); v != a[u].end(); v++)
     {
         if(!mark[*v])
         {
             p[*v]=u;
             findArticPts(*v);
             low[u]=min(low[u],low[*v]);
             if(u==0)
             {
                 if(p[*v]==0)
                 {l++;
                 if(l>=2)
                {z[u]=1;}
                }
             }
             else if(low[*v]>=d[u])
             {z[u]=1;
                 //coun++;
                 }
         }
         else if(*v!=p[u])
         {
             low[u]=min(low[u],d[*v]);
         }
         }
     }
int main()
{int i,n,T,u,v,K;
long long int m;
scanf("%d",&T);
    while(T--)
    {
        scanf("%d %lld %d",&n,&m,&K);
        for(i=0;i<n;i++)
        z[i]=0;
        a=vector<VI> (n);
        mark=VI(n,0);
        d=VI(n,0);
        low=VI(n,0);
        p=VI(n,-1);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            //u--;
            //v--;
            a[u].push_back(v);
            a[v].push_back(u);
        }//res=0;
        tim=0;coun=0;l=0;
        for(u=0;u<n;u++)
        {
            if(!mark[u])
            {
                //res++;
                findArticPts(u);
            }
        }
       for(i=0;i<n;i++)
        {
            if(z[i]==1)
            {//cout<<i;
                coun++;}
        }
        cout<<coun*K<<endl;
    }
    return 0;
}

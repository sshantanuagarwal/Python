#include <iostream>
#include<vector>
using namespace std;
typedef vector<long long int > VI;
vector<VI> G;
VI mark;long long int  cnt,ans1;
long long int  ans2,open[50004],f[50004],d[50004],par[50004],found,x,y;
void dfs(long long int  u)
 {
 mark[u]=1;
 d[u]=cnt;
 if(open[u]==1)
 {cnt++;}
     for (VI::iterator v = G[u].begin(); v != G[u].end(); v++)
    {
       if(!mark[*v])
       {
           par[*v]=u;
           dfs(*v);
       }
    }
    f[u]=cnt;
 }
int  main()
{long long int  n,m,i,u,v;
    cin>>n>>m;
    G=vector<VI> (n);
    mark=VI(n,0);
    for(i=0;i<n;i++)
    cin>>open[i];
    for(i=0;i<m;i++)
    {
        cin>>u>>v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans1=0;ans2=0;
    for(i=0;i<n;i++)
    {
        if(mark[i]!=1)
        {
            cnt=0;
            par[i]=-1;
            dfs(i);
            if(cnt>1)
            {
                ans1+=(cnt*(cnt-1))/2;
            }
        }
    }
   for(i=0;i<n;i++)
   {
   if(open[i]==0)
   {found=0;
       x=i;
      y=par[i];
       while(y!=-1)
       {
           //cout<<(f[y]-d[y])-(f[x]-d[x])<<" "<<x+1<<" "<<y+1<<endl;
           if((f[y]-d[y])-(f[x]-d[x])>0)
           {
               found=1;
               break;
           }
           x=y;
           y=par[x];
       }
       if(found==1&&f[i]-d[i]>0)
       {ans2++;//cout<<i+1<<endl;
       }
       if(found==0)
       {
           for (VI::iterator v = G[i].begin(); v != G[i].end(); v++)
            {
              if(par[i]!=*v)
              {
                  if(f[*v]-d[*v]<f[i]-d[i]&&f[*v]-d[*v]>0)
                  {
                      //cout<<"a"<<f[*v]-d[*v]<<"A"<<f[i]-d[i];
                      found=1;
                      break;
                  }
              }
            }
            if(found==1)
            {ans2++;//cout<<i+1<<endl;
            }
       }
   }
   if(open[i]==1)
   {found=0;
       x=i;
      y=par[i];
       while(y!=-1)
       {
           //cout<<(f[y]-d[y])-(f[x]-d[x])<<" "<<x+1<<" "<<y+1<<endl;
           if((f[y]-d[y])-(f[x]-d[x])>0)
           {
               found=1;
               break;
           }
           x=y;
           y=par[x];
       }
       if(found==1)
       {ans2++;
       //cout<<i+1<<endl;
       }
      else if(f[i]-d[i]>1)
        {ans2++;
        //cout<<i+1<<endl;
        }
   }
   }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}

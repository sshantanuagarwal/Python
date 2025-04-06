#include <iostream>
#include<vector>
#include<deque>
#include <cstdio>
using namespace std;
typedef vector<int> VI;
vector<VI> a;
typedef deque<int> d;
deque<d> b;
VI mark;long long int cnt;
void bfs(int u)
 {int x;
 mark[u]=1;
 cnt++;
     for (VI::iterator v = a[u].begin(); v != a[u].end(); v++)
    {
       if(!mark[*v])
       {
           mark[*v]=1;
           b[0].push_back(*v);
       }
    }
    while(!b[0].empty())
    {
          x=b[0].front();
          b[0].pop_front();
          bfs(x);
    }
 }
 long long int bfs(long long int a,long long int ans)
 {
     if(found==0)
     {if(ans%n==0)
     {
         found=1;
         return ans;
     }
     b.push_back(ans);
     b.push_back(ans+pow(10,a+1)*9);
     while(!b.empty())
    {
          x=b.front();
          b.pop_front();
          bfs(a+1,x);
    }
     }
 }
int main()
{int res,i,n,m,T,u,v;
long long int ans;
scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        a=vector<VI> (n);
        b=deque<d> (n);
        mark=VI(n,0);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            u--;
            v--;
            a[u].push_back(v);
            a[v].push_back(u);
        }res=0;ans=1;
        for(u=0;u<n;u++)
        {
            if(!mark[u])
            {
                res++;
                cnt=0;
                bfs(u);
                ans=(ans*cnt)%1000000007;
            }
        }
        printf("%d %lld\n",res,ans);
    }
    return 0;
}

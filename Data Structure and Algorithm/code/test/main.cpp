#include <iostream>
#include<vector>
#include <cstdio>
using namespace std;
typedef vector<int> VI;
vector<VI> a;
VI mark;long long int cnt;
void dfs(int u)
 {
 mark[u]=1;
 cnt++;
     for (VI::iterator v = a[u].begin(); v != a[u].end(); v++)
    {
       if(!mark[*v])
       {
           dfs(*v);

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
                dfs(u);
                ans=(ans*cnt)%1000000007;
            }
        }
        printf("%d %lld\n",res,ans);
    }
    return 0;
}

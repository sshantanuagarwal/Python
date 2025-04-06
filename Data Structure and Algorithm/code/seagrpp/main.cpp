#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 205
#define NIL 0
#define INF (1<<28)
#include <cstdio>
#include <queue>
#include <vector>
#include<iostream>
using namespace std;
typedef vector<int> VI;
vector<VI> a,G;
VI mark;
int n, m, p, match[MAX], dist[MAX],w[MAX],found,cntu,rd,bl,indegree[MAX];
// G = NIL[0] U G1[G[1---n]] U G2[G[n+1---n+m]]
int cnt;
bool bfs() {
    cnt++;
        int i, u, v, len;
        queue< int > Q;
        for(i=1; i<=n; i++) {
                if(match[i]==NIL) {
                        dist[i] = 0;
                        Q.push(i);
                        //cout<<cnt<<"   pushing "<<i<<" dist[] "<<dist[i]<<endl;
                }
                else {dist[i] = INF;}
        }
        dist[NIL] = INF;
        while(!Q.empty()) {
                u = Q.front(); Q.pop();
                if(u!=NIL) {
                        len = G[u].size();
                        for(i=0; i<len; i++) {
                                v = G[u][i];
                                //cout<<"parent "<<u<<"child "<<v<<" match[v] "<<match[v]<<" dist[match[v] "<<dist[match[v]];
                                if(dist[match[v]]==INF) {
                                        dist[match[v]] = dist[u] + 1;
                                        Q.push(match[v]);
                                        //cout<<" entered dist[match[v]] "<<dist[match[v]];
                                }
                              //cout<<endl;
                        }
                }
        }
        return (dist[NIL]!=INF);
}
bool dfs(int u) {
    cnt++;
        int i, v, len;
        if(u!=NIL) {
                len = G[u].size();
                for(i=0; i<len; i++) {
                        v = G[u][i];
                        if(dist[match[v]]==dist[u]+1) {
                                if(dfs(match[v])) {
                                        match[v] = u;
                                        match[u] = v;
                                       // cout<<cnt<<" dfs matched "<<v<<"and"<<u<<endl;
                                        return true;
                                }
                        }
                }
                dist[u] = INF;
                return false;
        }
        return true;
}

int hopcroft_karp() {
        int matching = 0, i;
        while(bfs())
                for(i=1; i<=n; i++)
                        if(match[i]==NIL && dfs(i))
                            {
                                matching++;
                               // cout<<i<<"matched";
                            }
        return matching;
}
void dfs1(int u)
{cntu++;
mark[u]=1;
for (VI::iterator v = a[u].begin(); v != a[u].end(); v++)
{
if(!mark[*v])
{
    dfs1(*v);
}
}
}
int main()
{int T,m,u,v,i;
    cin>>T;
    while(T--)
    {found=0;
    for(i=1;i<=n;i++)
        indegree[i]=0;
        cin>>n>>m;
        a=vector<VI> (n+1);
        G=vector<VI> (2*n+1);
      mark=VI(n+1,0);
        while(m--)
        {
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
            G[u].push_back(v+n);
            G[v].push_back(u+n);
            indegree[u]++;
            indegree[v]++;
        }
    for(i=1;i<=n;i++)
    {
        if(indegree[i]!=1)
            {break;}
    }
    if(n%2==0&&i>n)
        found=1;
      for(i=1;i<=n;i++)
      if(mark[i]==0)
      {cntu=0;
          dfs1(i);
          if(cntu%2==1)
          found=1;
      }
      for(i=0;i<=2*n;i++)
      match[i]=0;
      if(found==0)
      {
      if(hopcroft_karp()==n)
      cout<<"YES";
      else
      cout<<"NO";
      }
      else
      cout<<"NO";
        cout<<endl;
    }
return 0;
}

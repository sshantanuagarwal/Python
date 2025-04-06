//bellman ford == single source shortest path for both directed and undirected graph.
#include <iostream>
#include<vector>
using namespace std;
struct vertex
{
    int x;
    int wt;
};
typedef vector<vertex> VI;
vector<VI> G;
int d[100005];
int main()
{int n,m,st,u,v,w,i,j,k,found=0,inf=1000,l;
    cin>>n>>m>>st;
    G=vector<VI>(n);
    vertex s;
    while(m--)
    {
        cin>>u>>v>>w;
        u--;v--;
        s.x=v;
        s.wt=w;
        G[u].push_back(s);
    }vertex t;
    for(i=0;i<n;i++)
    d[i]=inf;
    st--;
    d[st]=0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n;j++)
        {
            l=G[j].size();
            for(k=0;k<l;k++)
            {
                t=G[j][k];
                if(d[t.x]>d[j]+t.wt)
                d[t.x]=d[j]+t.wt;
            }
        }
    }
    for(j=0;j<n;j++)
        {
            l=G[j].size();
            for(k=0;k<l;k++)
            {
                t=G[j][k];
                if(d[t.x]>d[j]+t.wt)
                found=1;
            }
        }
        if(found==0)
        {
            for(i=0;i<n;i++)
            cout<<"distance of "<<i+1<<" from "<<st+1<<" is = "<<d[i]<<endl;
        }
        else
        {
            cout<<"Shortest path undefined due to existance of negetive wt cycles."<<endl;
        }
    return 0;
}
/*
5 10 1
1 2 6
2 3 5
3 2 -2
5 3 7
4 3 -3
5 1 2
1 4 7
4 5 9
2 5 -4
2 4 8
*/

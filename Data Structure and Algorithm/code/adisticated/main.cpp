#include <iostream>
#include<vector>
#include<cstdio>
using namespace std;

int rank[100009],p[100009];
int find(int n)
{
    if(p[n]!=n)
    {
        p[n]=find(p[n]);
    }
    return p[n];
}
void link(int a,int b)
{if(rank[a]>rank[b])
    {p[b]=a;
    rank[a]+=rank[b];}
    else
    {p[a]=b;
    rank[b]+=rank[a];}
}
int main()
{int T,i,m,coun,a,b;
long long int ans;
    scanf("%d",&T);
    while(T--)
    {scanf("%d",&m);
    for(i=1;i<=27;i++)
    {p[i]=-1;
     rank[i]=1;
    }
    while(m--)
    {
        scanf("%d %d",&a,&b);
        if(p[a]==-1)
        p[a]=a;
        if(p[b]==-1)
        p[b]=b;
        cout<<" find[a]="<<find(a)<<" find[b]="<<find(b)<<" p[a]="<<p[a]<<" p[b]="<<p[b]<<endl;
        if(find(a)!=find(b))
        link(find(a),find(b));
        cout<<" find[a]="<<find(a)<<" find[b]="<<find(b)<<" rank[a]="<<rank[find(a)]<<" rank[b]="<<rank[find(b)]<<" parent[a]="<<p[a]<<" parent[b]="<<p[b]<<endl;
        cout<<" p[a]="<<p[a]<<" p[b]="<<p[b]<<endl;
    }
    coun=0;ans=0;
    for(i=1;i<=27;i++)
    {
        if(p[i]==i)
        {
            coun++;
            cout<<i<<" "<<rank[i]<<endl;
        }
    }
    }
    return 0;
}

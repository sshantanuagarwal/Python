#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int T,i,j,k,n,m,sum,extr,cost[1008][1008],ini[1008],maxi,inf=3000,cst,sto[1008],cnt,old[1008];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<n;i++)
    scanf("%d",&ini[i]);
    for(i=0;i<n;i++)
    {for(j=0;j<m;j++)
    {
        scanf("%d",&cost[i][j]);
    }
    old[i]=cost[i][ini[i]-1];
    sum+=cost[i][ini[i]-1];
    }
    //cout<<"sum is  "<<sum<<endl;
    for(i=0;i<n;i++)
    {
        maxi=-1*inf;
        for(j=0;j<m;j++)
    {
        scanf("%d",&cst);
       // cout<<cost[i][j]<<"-"<<cst<<"-"<<old[i]<<"  ";
        cost[i][j]=cost[i][j]-cst-old[i];
        maxi=max(maxi,cost[i][j]);
    }
    if(maxi>0)
    sto[i]=maxi;
    else
    sto[i]=-inf;
    //cout<<sto[i]<<endl;
    }
    sort(sto,sto+n);
    cnt=0;extr=0;
    for(i=n-1;i>=0&&cnt<k;i--)
    {
        if(sto[i]>0&&cnt<k)
        {
            extr+=sto[i];
            cnt++;
        }
    }
    printf("%d\n",sum+extr);
}
    return 0;
}

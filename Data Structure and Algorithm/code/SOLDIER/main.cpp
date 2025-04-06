#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
    struct c
    {
        int p;
        int q;
        int t;
    }a[105];
    bool cmp(struct c x,struct c y)
    {
        return x.t<y.t;
    }
int dp[105][1005],i,j,k,ans,cnt[105],n,m,inf,found;
int main()
{
    freopen ("inp.txt","r",stdin);
    found=0;
    scanf("%d %d",&n,&m);
    inf=10000000;
    for(i=0;i<n;i++)
    scanf("%d %d %d",&a[i].t,&a[i].p,&a[i].q);
    sort(a,a+n,cmp);
    cnt[a[0].t]=1;
    for(i=1;i<n;i++)
    {
        if(a[i].t==a[i-1].t)
        cnt[a[i].t]++;
        else
        cnt[a[i].t]=1;
    }
    for(i=0;i<=m;i++)
    dp[0][i]=inf;
    for(i=1;i<=6;i++)
    {
        if(cnt[i]==0)
            break;
    }
    if(i<=6)
    found=1;
    if(found==0)
    {
        i=0;
        while(i<n)
        {
            for(k=0;k<=m;k++)
            {ans=-1;
            for(j=i;j<i+cnt[a[i].t];j++)
            {
             if(k-a[j].p>=0)
             ans=max(ans,min(dp[a[j].t-1][k-a[j].p],a[j].q));
             else
             ans=max(ans,-1);
             dp[a[j].t][k]=ans;
            }
            }
            i=i+cnt[a[i].t];
        }
        //cout<<"l ";
        if(dp[6][m]>=0)
        printf("%d\n",dp[6][m]);
        else
        printf("0\n");
    }
    else
    printf("0\n");
    return 0;
}

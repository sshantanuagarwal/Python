#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
struct z
{
    long long int c;
    long long int l;
}a[506];
bool cmp(struct z x,struct z y)
{
    return x.l<y.l;
}
long long int T,i,j,w,e,f,n,inf,dp[10006],ans;
int main()
{
scanf("%lld",&T);
    inf=int(pow(10,9))+1;
    //cout<<inf;
    while(T--)
    {
        scanf("%lld %lld",&e,&f);
        w=f-e;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i].c);
            scanf("%lld",&a[i].l);
        }
        sort(a,a+n,cmp);
        dp[0]=0;
        for(i=1;i<=w;i++)
        {ans=inf;
            for(j=0;j<n;j++)
            {
                if(i>=a[j].l)
                ans=min(ans,dp[i-a[j].l]+a[j].c);
                else
                break;
            }
         dp[i]=ans;
         //cout<<dp[i]<<endl;
        }
        if(dp[w]>=inf)
        printf("This is impossible.");
        else
        printf("The minimum amount of money in the piggy-bank is %lld.",dp[w]);
        cout<<endl;
    }
    return 0;
}

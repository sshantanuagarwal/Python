#include <iostream>
#include<cmath>
using namespace std;
struct z
{
    int x;
    int y;
    int w;
}a[1005];
int dp[1005][25][85],i,j,k,x,y,n,inf,ans,T;
int main()
{
    inf=pow(10,6);
    cin>>T;
    while(T--)
    {
        cin>>x>>y;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].w;
        }
        for(i=0;i<=x;i++)
        for(j=0;j<=y;j++)
        dp[0][i][j]=inf;
        for(i=0;i<=n;i++)
        dp[i][0][0]=0;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=x;j++)
            {
                for(k=0;k<=y;k++)
                {
                    if(j-a[i].x>=0&&k-a[i].y>=0)
                    dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][j-a[i].x][k-a[i].y]+a[i].w);
                    else if(j-a[i].x<0&&k-a[i].y<0)
                    dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][0][0]+a[i].w);
                    else if(k-a[i].y<0)
                    dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][j-a[i].x][0]+a[i].w);
                    else
                    dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][0][k-a[i].y]+a[i].w);
                }
            }
        }
        cout<<dp[n][x][y]<<endl;
    }
    return 0;
}

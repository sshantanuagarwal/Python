#include <iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int s[505][505],r,c,i,j,inf=1000005,dp[505][505],T;
int solve(int x,int y,int &ret,int &ans)
{
    if(x==r&&y==c)
    {ret=s[x][y];
    ans=ret;
    dp[x][y]=ret;
    return ret;
    }
    if(x==r+1||y==c+1)
    {ret=-inf;
    return ret;
    }
    if(dp[x][y]!=-inf)
    {ret=dp[x][y];
    return ret;
    }
    ret=max(solve(x+1,y,ret,ans),solve(x,y+1,ret,ans));
    ans=min(ans,max(dp[x+1][y],dp[x][y+1]));
    ret+=s[x][y];
    dp[x][y]=ret;
    return ret;
}
int main()
{
    //freopen("amr11a.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
            {dp[i][j]=-inf;
            scanf("%d",&s[r-i+1][c-j+1]);
            }
    }
    for(i=1;i<=r;i++)
        dp[i][c+1]=0;
     for(i=1;i<=c;i++)
        dp[r+1][i]=0;
dp[r+1][c+1]=0;
    int ans1=0,ans2=inf;
    solve(1,1,ans1,ans2);
    if(ans2<0)
    printf("%d\n",int(fabs(ans2))+1);
    else
    printf("1\n");
    }
    return 0;
}
dp[i][k+1][j]=max(dp[i][k-1][j],dp[i][k][j]);

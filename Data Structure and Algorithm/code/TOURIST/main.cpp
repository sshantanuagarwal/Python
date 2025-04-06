#include <iostream>
#include<cstdio>
using namespace std;
int dp[50][50],n,m,i,inf=1000,j,dp1[50][50],ans,T;
char s[100][100],q[100][100];
int solve(int y,int x)
{
     if(x==n-1&&y==m-1)
    {
        if(s[y][x]!='*')
        dp[y][x]=0;
        else
        dp[y][x]=1;
        return dp[y][x];
    }
    if(x==n||y==m)
    {
        return -inf;
    }
    if(s[y][x]=='#')
    {
        dp[y][x]=-inf;
        return -inf;
    }
    if(dp[y][x]!=-1)
    return dp[y][x];
    if(s[y][x]=='*')
    dp[y][x]=max(solve(y,x+1),solve(y+1,x))+1;
    else
    dp[y][x]=max(solve(y,x+1),solve(y+1,x));
    return dp[y][x];
}
int solve1(int y,int x)
{
     if(x==n-1&&y==m-1)
    {
        if(q[y][x]!='*')
        dp1[y][x]=0;
        else
        dp1[y][x]=1;
        return dp1[y][x];
    }
    if(x==n||y==m)
    {
        return -inf;
    }
    if(q[y][x]=='#')
    {
        dp1[y][x]=-inf;
        return -inf;
    }
    if(dp1[y][x]!=-1)
    return dp1[y][x];
    if(q[y][x]=='*')
    dp1[y][x]=max(solve1(y,x+1),solve1(y+1,x))+1;
    else
    dp1[y][x]=max(solve1(y,x+1),solve1(y+1,x));
    return dp1[y][x];
}
int main()
{
    freopen("inp.txt","r",stdin);
    cin>>T;
    while(T--)
    {cin>>n>>m;
    //cout<<n<<" "<<m<<endl;
    for(i=0;i<m;i++)
    cin>>s[i];
    for(i=0;i<=m;i++)
        for(j=0;j<=n;j++)
        dp[i][j]=-1;
    cout<<solve(0,0)<<endl;
    ans=solve(0,0);
    if(ans!=0)
    {i=0;j=0;
    while(i!=m-1&&j!=n-1)
        {
            s[i][j]='.';
            if(dp[i+1][j]>=dp[i][j+1])
            i++;
            else
            j++;
        }
        for(i=0;i<=m;i++)
        {for(j=0;j<=n;j++)
        cout<<s[i][j]<<" ";
        cout<<endl;
        }
         for(i=0;i<m;i++)
            for(j=0;j<n;j++)
         {
             q[i][j]=s[m-i-1][n-j-1];
         }
         for(i=0;i<=m;i++)
        for(j=0;j<=n;j++)
        dp1[i][j]=-1;
         cout<<solve1(0,0)<<endl;
         ans+=solve1(0,0);
    }
         cout<<ans<<endl;
    }
    return 0;
}

#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,dp[1005][1005],i,j,l,a[1005];
char s1[1005],s2[1005];
int solve(int pos1,int pos2)
{
    if(pos1==n&&pos2==m)
    {
        dp[n][m]=0;
        return 0;
    }
    if(pos2==m)
    {
        dp[pos1][pos2]=solve(pos1+1,pos2)+1;
        return dp[pos1][pos2];
    }
    if(pos1==n)
    {
        dp[pos1][pos2]=solve(pos1,pos2+1)+1;
        return dp[pos1][pos2];
    }
    if(dp[pos1][pos2]!=-1)
    return dp[pos1][pos2];
    if(s1[pos1]!=s2[pos2])
    dp[pos1][pos2]=min(solve(pos1,pos2+1),min(solve(pos1+1,pos2+1),solve(pos1+1,pos2)))+1;
    else
    dp[pos1][pos2]=min(min(solve(pos1,pos2+1),solve(pos1,pos2+1))+1,solve(pos1+1,pos2+1));
   // if((s1[pos1+1]==s2[pos2]&&s1[pos1]==s2[pos2+1])&&pos1<=n-2&&pos2<=m-2)
   // dp[pos1][pos2]=min(dp[pos1][pos2],dp[pos1+2][pos2+2]+1);
    return dp[pos1][pos2];
}
int main()
{
    cin>>s2>>s1;
    while(strcmp(s1,"*")!=0||strcmp(s2,"*")!=0)
    {
    n=strlen(s1);
    m=strlen(s2);
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
        dp[i][j]=-1;
    solve(0,0);
    cout<<solve(0,0)<<endl;
    cin>>s2>>s1;
    }
    return 0;
}

#include <iostream>

using namespace std;
int n,k,s,t,i,j;
unsigned long long int dp[55][55];
int main()
{
    cin>>n>>k;
    while(n!=-1&&k!=-1)
    {cin>>s>>t;
    for(j=1;j<=n;j++)
    dp[j][1]=0;
    if(s==1)
    {dp[n][1]=1;dp[2][1]=1;}
    else if(s==n)
    {dp[1][1]=1;dp[n-1][1]=1;}
    else
    {dp[s-1][1]=1;dp[s+1][1]=1;}
    for(i=2;i<=k;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j==1)
            dp[j][i]=dp[n][i-1]+dp[j+1][i-1];
            else if(j==n)
            dp[j][i]=dp[j-1][i-1]+dp[1][i-1];
            else
            dp[j][i]=dp[j-1][i-1]+dp[j+1][i-1];
        }
    }
    cout<<dp[t][k]<<endl;
    cin>>n>>k;
    }
    return 0;
}

#include <iostream>

using namespace std;
long long int n,f[100],dp[100][100];
long long int solve(long long int pos,long long int open)
{
    if(pos==n)
    return (open==0);
    if(open<0)
    return 0;
    if(dp[pos][open]!=-1)
        return dp[pos][open];
    if(f[pos]==1)
    dp[pos][open]=solve(pos+1,open+1);
    else
    dp[pos][open]=solve(pos+1,open+1)+solve(pos+1,open-1);
    return dp[pos][open];
}
int main()
{long long int i,j,T,k,a;
cin>>T;
while(T--)
    {
        cin>>n>>k;

        for(i=0;i<=n;i++)
        f[i]=0;
    f[0]=1;
    while(k--)
    {
        cin>>a;
        f[a-1]=1;
    }
    for(i=0;i<=n;i++)
    for(j=0;j<=n;j++)
    dp[i][j]=-1;
    cout<<solve(0,0)<<endl;
    }
    return 0;
}

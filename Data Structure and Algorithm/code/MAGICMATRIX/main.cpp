#include <iostream>

using namespace std;
int dp[10][10],r,c,T,i,j;
int solve(int x,int y)
{
    if(x==r+1||y==c+1)
     return 0;
    if(dp[x][y]!=-1)
    return dp[x][y];
    if(x==r&&y==c)
    {
        dp[x][y]=1;
        return 1;
    }
    dp[x][y]=solve(x+1,y)+solve(x,y+1);
    return dp[x][y];
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>c>>r;
        c++;
        r++;
        if(r!=0&&c!=0)
        {for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
            dp[i][j]=-1;
        solve(1,1);
        cout<<dp[1][1]<<endl;
        }
        else
        cout<<"0"<<endl;
    }
    return 0;
}

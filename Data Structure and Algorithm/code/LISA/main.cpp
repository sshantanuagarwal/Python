#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;
unsigned long long int T,i,n,k1,k,dp[103][103],l,num[103],j,in,dp1[103][103];
char s[205],op[103];
int main()
{
    in=pow(2,64)-1;
    //cout<<in;
    cin>>T;
    while(T--)
    {
        cin>>s;
        l=strlen(s);
        k=0;k1=0;
        for(i=0;i<l;i++)
        {
            if(s[i]<=57&&s[i]>=48)
          {num[k]=int(s[i]-48);k++;}
          else
            {op[k1]=s[i];k1++;}
        }
        n=k;
        for(i=0;i<n;i++)
        {
            dp[0][i]=dp1[0][i]=num[i];
            //cout<<dp[0][i]<<endl;
        }
        for(i=1;i<n;i++)
        {
            for(j=0;j<n-i;j++)
            {dp[i][j]=0;dp1[i][j]=in;
                for(k=0;k<i;k++)
                {
                    if(op[j+k]=='*')
                    {dp[i][j]=max(dp[i][j],(dp[k][j]*dp[i-k-1][j+k+1]));
                    dp1[i][j]=min(dp1[i][j],(dp1[k][j]*dp1[i-k-1][j+k+1]));
                    }
                    else
                     {dp[i][j]=max(dp[i][j],(dp[k][j]+dp[i-k-1][j+k+1]));
                       dp1[i][j]=min(dp1[i][j],(dp1[k][j]+dp1[i-k-1][j+k+1]));
                     }
                }
            }
        }
        cout<<dp[n-1][0]<<" "<<dp1[n-1][0]<<endl;
    }
    return 0;
}

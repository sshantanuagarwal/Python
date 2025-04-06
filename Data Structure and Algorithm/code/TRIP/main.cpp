#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int len1,len2,lcslen,dp[103][103];
char s1[100],s2[100],ans[100];

void printy(int na,int nb,int d)
{bool done;int i,j;char ch;
    if(d==lcslen)
    {
        ans[d]='\0';
        cout<<ans<<endl;
    }
    if(na==len1||nb==len2)
        return;
    for(ch='a';ch<='z';ch++)
    {done=false;
        for(i=na;i<len1;i++)
        {
            if(ch==s1[i])
            {
                for(j=nb;j<len2;j++)
                {
                    if(ch==s2[j])
                    {
                        if(d+dp[i+1][j+1]+1==lcslen)
                        {
                            ans[d]=ch;
                            printy(i+1,j+1,d+1);
                          done=true;
                          break;
                        }
                    }
                }
                if(done)break;
            }
        }
    }
}
int main()
{int T,i,j;
    cin>>T;
    while(T--)
     {cin>>s1>>s2;
     len1=strlen(s1);
     len2=strlen(s2);
     for(i=0;i<=len1;i++)
        dp[i][len2]=0;
     for(i=0;i<=len2;i++)
        dp[len1][i]=0;
     for(i=len1-1;i>=0;i--)
        for(j=len2-1;j>=0;j--)
     {
         if(s1[i]==s2[j])
         dp[i][j]=dp[i+1][j+1]+1;
         else
         dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
     }
     lcslen=dp[0][0];
     printy(0,0,0);
     }
    return 0;
}

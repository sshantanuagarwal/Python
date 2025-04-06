#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAX 1005
using namespace std;
struct z
{
    int f;
    int s;
}stacka[MAX];
int n,m,i,j,k,dp[MAX][MAX],lefta[MAX],righta[MAX],arr[MAX][MAX],a[MAX][MAX],l,h,sz,sum,len,row[MAX],Q;
int main()
{
    scanf("%d %d",&n,&m);
    //computing heights
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        a[i][j]=0;
    scanf("%d",&k);
    while(k--)
    {
        cin>>l>>h;
        a[l][h]=1;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i][j]==0)
            arr[i][j]=arr[i-1][j]+1;
        else
            arr[i][j]=0;
    }
    //computing lefta
   for(i=1;i<=n;i++)
    {
        memset( lefta, 0, sizeof(lefta) );
      memset( righta, 0, sizeof(righta) );

        sz=-1;
        for(j=1;j<=m;j++)
        {sum=0;
          while(sz>=0)
          {
              //cout<<i<<" "<<j<<endl;
           if(stacka[sz].f>=arr[i][j])
           {sum+=stacka[sz].s;sz--;}
           else
            break;
          }
          sz++;
          stacka[sz].f=arr[i][j];
          stacka[sz].s=sum+1;
          lefta[j]=sum+1;
          //cout<<arr[i][j]<<" "<<sz<<" "<<endl;
        }
   sz=-1;
       for(j=m;j>=1;j--)
       {sum=0;
           while(sz>=0)
           {
               if(stacka[sz].f>=arr[i][j])
               {
                   sum+=stacka[sz].s;
                   sz--;
               }
               else
                break;
           }
           sz++;
           stacka[sz].f=arr[i][j];
           stacka[sz].s=sum+1;
           righta[j]=sum+1;
       }
      memset( row, 0, sizeof(row) );
       for(j=1;j<=m;j++)
       {
          row[arr[i][j]]=max(row[arr[i][j]],lefta[j]+righta[j]-1);
       }
      len=0;
       for(j=1;j<=i;j++)
       {
           len=max(len,row[i-j+1]);
           dp[i][j]=len*(i-j+1);
           //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
       }
       for(j=i;j>=1;j--)
       {
           dp[i][j]=max(max(dp[i][j],dp[i-1][j]),dp[i][j+1]);
           //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
       }
   }
   scanf("%d",&Q);
   while(Q--)
   {
       scanf("%d %d",&l,&h);
       printf("%d\n",dp[h][l]);
   }
    return 0;
}

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long int stlg[205][205],i,T,n,k1,a[205],has[205],j,mod=1000000009,k,r,ans;
int main()
{
    stlg[0][0]=1;
    stlg[1][0]=0;
    for(i=1;i<=203;i++)
    {
        for(j=1;j<=203;j++)
        {
            stlg[i][j]=(stlg[i-1][j-1]%mod+(((i-1)%mod)*(stlg[i-1][j]%mod))%mod)%mod;
            //cout<<stlg[i][j]<<" ";
        }
        //cout<<endl;
    }
    cin>>T;
    while(T--)
    {ans=0;
        cin>>n>>k1;
        for(i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
        has[1]=0;j=1;k=a[0];
        for(i=0;i<n;i++)
        {
            if(k!=a[i])
            {
                j++;
                has[j]=i;
                k=a[i];
            }
        }
        if(j-k1+1>=1&&j-k1+1<=j)
        r=n-has[j-k1+1];
        else if(j-k1+1<1)
        r=n-has[1];
        for(i=1;i<=r;i++)
        ans=(ans%mod+stlg[n][i]%mod)%mod;
        cout<<ans<<endl;
    }
    return 0;
}

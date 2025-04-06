#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long int T,m,n,j,i,y[1000006],x[1000006],h,v,sum,mod=1000000009;
int main()
{
    cin>>T;
    while(T--)
    {
        sum=0;
        cin>>m>>n;
        for(i=0;i<m-1;i++)
            cin>>y[i];
        for(i=0;i<n-1;i++)
            cin>>x[i];
        sort(y,y+m-1);
        sort(x,x+n-1);
        i=n-2;
        j=m-2;
        h=0;
        v=0;
        while(i>=0&&j>=0)
        {
            if(x[i]>=y[j])
            {sum=((x[i]%mod*(v+1)%mod)%mod+sum%mod)%mod;i--;h++;}
            else
            {sum=((y[j]%mod*(h+1)%mod)%mod+sum%mod)%mod;j--;v++;}
        }
        while(j>=0)
        {
            sum=((y[j]%mod*(h+1)%mod)%mod+sum%mod)%mod;j--;v++;
        }
        while(i>=0)
        {
            sum=((x[i]%mod*(v+1)%mod)%mod+sum%mod)%mod;i--;h++;
        }
        cout<<sum%mod<<endl;
    }
    return 0;
}

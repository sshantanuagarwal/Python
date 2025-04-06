#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a[2000006],sto[2000006],prob[2000006],i,j,k,n,res,inf=2000006;
int main()
{
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(sto[a[i]]==0)
            sto[a[i]]=inf;
        sto[a[i]]=min(sto[a[i]],min(i+1,n-i));
    }
     res=inf;
    for(i=0;i<n;i++)
    {
        if(k-a[i]>=0)
        {if(a[i]*2!=k&&sto[k-a[i]]!=0)
        res=min(res,max(sto[a[i]],sto[k-a[i]]));
        }
    }
    if(res==inf)
    cout<<"-1";
    else
    cout<<res;
    return 0;
}

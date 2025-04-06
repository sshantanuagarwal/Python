#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long int mod_exp(long long int a,long long int x,long long int mod)
{
    if(x==0)
    return 1;
    else if(x==1)
    return a%mod;
    else if(x%2==0)
    return mod_exp(((a%mod)*(a%mod)),x/2,mod)%mod;
    else
    return ((a%mod)*mod_exp(a,x-1,mod)%mod)%mod;
}
long long int mod=1000000007,T,i,n,a[100005],cnt,st;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
        st=a[n-1];cnt=0;
        for(i=n-1;i>=0;i--)
            {
                if(st==a[i])
                    cnt++;
                else
                    break;
            }
            cout<<(mod_exp(2,cnt,mod)-1+mod)%mod<<endl;
    }
    return 0;
}

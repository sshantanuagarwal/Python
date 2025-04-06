#include <iostream>
#include<cstdio>
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
long long int a,r,n,T,mod=1000003;int cnt;
int main()
{
    cnt=0;
    cin>>T;
    while(T--)
    {
        cnt++;
        cin>>a>>r>>n;
        printf("Case #%d: ",cnt);
        cout<<(mod_exp(r,n,mod)%mod-1+mod)%mod<<endl;
    }
    return 0;
}

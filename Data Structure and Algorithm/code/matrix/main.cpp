#include <iostream>
#include<cstdio>
using namespace std;
long long int mod=1000000007;
long long int mod_exp(long long int a,long long int x,long long int p)
{
    if(a==0)
    return 0;
    if(x==0)
    return 1;
    else if(x==1)
    return a%p;
    else if(x%2==0)
    return mod_exp(((a%p)*(a%p))%p,x/2,p)%p;
    else
    return ((mod_exp(a%p,x-1,p)%p)*(a%p))%p;
}
long long int T,n,m,ans,i,fact[2000005];
int main()
{
    fact[0]=1;
    fact[1]=1;
    for(i=2;i<=2000000;i++)
    fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
    scanf("%lld",&T);
    while(T--)
    {
      scanf("%lld %lld",&n,&m);
      n--;
      m--;
      ans=fact[n+m];
      ans=((ans%mod)*(mod_exp(fact[n]%mod,mod-2,mod)%mod))%mod;
      ans=((ans%mod)*(mod_exp(fact[m]%mod,mod-2,mod)%mod))%mod;
      //cout<<mod_exp(fact[n],mod-2,mod)<<" "<<mod_exp(fact[m],mod-2,mod)<<" "<<fact[m+n]<<endl;
      cout<<ans%mod<<endl;
    }
    return 0;
}

#include <iostream>

using namespace std;
long long int mod=1000000007,t,n,k,i,T[100005];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0;i<k;i++)
        {
            T[i]=1;
        }
        for(i=k;i<=n;i++)
        {
            T[i]=(T[i-1]%mod+T[i-k]%mod)%mod;
        }
        cout<<T[n]%mod<<endl;
    }
    return 0;
}

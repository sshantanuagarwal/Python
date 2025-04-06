#include <iostream>
#include<math.h>
using namespace std;
long long int prime[10005],sto[10005];
long long int dig(long long int x)
{
    long long int cnt=0;
    while(x!=0)
    {
        cnt++;
        x=x/10;
    }
    return cnt;
}
long long int hcf(long long int a,long long int b)
{
    long long int r;
    while(a!=0)
    {r=b%a;
    b=a;
    a=r;
    }
    return b;
}
long long int mod_exp(long long int a,long long int x)
{
    if(x==0)
    return 1;
    else if(x==1)
    return a;
    else if(x%2==0)
    return mod_exp(((a)*(a)),x/2);
    else
    return ((a)*mod_exp(a,x-1));
}
int main()
{long long int i,k,j,T,n,m,p,ans,res;
    sto[0]=2;k=1;
    prime[0]=prime[1]=1;prime[2]=0;
    for(i=3;i<=10000;i+=2)
    {
        if(!prime[i])
        {sto[k]=i;k++;
        for(j=i*i;j<=10000;j+=2*i)
        {
            prime[j]=1;
        }
        }
    }
    cin>>T;
    while(T--)
    {
        cin>>n;
        p=dig(n);
        m=mod_exp(10,p)-1-n;
        ans=int(fabs(m-n));
        //cout<<ans<<endl;
        if(ans!=1)
        {for(i=0;i<k;i++)
        {
            if(ans%sto[i]==0)
            {res=sto[i];break;}
        }
       if(i==k)
        res=ans;
        }
        else
        res=-1;
        cout<<res<<endl;
    }
    return 0;
}

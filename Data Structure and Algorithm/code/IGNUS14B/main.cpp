#include <iostream>

using namespace std;
int sto[100005],prime[100005];
int main()
{
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
        cin>>s;

    }
    return 0;
}

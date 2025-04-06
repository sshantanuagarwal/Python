#include <iostream>

using namespace std;
long long int prime[100005],i,n,j,k,sto[100005];
int main()
{
    cin>>n;
    sto[0]=2;k=1;
    for(i=3;i<n;i+=2)
    {
        if(prime[i]==0)
        {sto[k]=i;k++;
            for(j=i*i;j<n;j+=2*i)
                prime[j]=1;
        }
    }
    for(i=0;i<k;i++)
        cout<<i<<" "<<sto[i]<<endl;
    return 0;
}

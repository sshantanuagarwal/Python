#include <iostream>

using namespace std;
int s[2005],a[2005],b[2005],carry[2005];
long long int x,y;
void mul(long long int a,long long int b)
{
    long long int c,d,l,l1,l2;
    c=x;
    k=0;
    while(c!=0)
    {
        a[k]=c%10;
        k++;
        c=c/10;
    }
    l1=k;
    c=y;
    k=0;
    while(c!=0)
    {
        b[k]=c%10;
        k++;
        c=c/10;
    }
    l2=k;
    k=0;
    carry[0]=0;
    for(i=0;i<40;i++)
        s[k]=0;
    for(j=0;j<l2;j++)
    {k=j;
      for(i=0;i<l1;i++)
      {
        l=a[i]*b[j]+carry[j];
        s[k]+=l%10;
        carry[j+1]=l/10;
      k++;
      }
    }
    if(carry[k]!=0)
        s[k]=carry[k];
        if(s[k]!=0)
    {for(i=0;i<=k;i++)
    {
     sum+=s[i]*mod_exp(10,i,mod);
    }
    }
}
int main()
{
    cin>>x>>y>>mod;
    mul(x,y);
    return 0;
}

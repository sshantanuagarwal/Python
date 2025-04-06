#include <iostream>

using namespace std;
long long int n,i,j,k,sum,sum1,ans,a[20004],b[20004],f1[20004],f2[20004],m;
int main()
{
    cin>>n;
    while(n!=0)
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        cin>>m;
        for(i=0;i<m;i++)
            cin>>b[i];
            a[n]=0;b[m]=0;
            j=0;i=0;k=1;
        while(i<n&&j<m)
        {
            if(a[i]<b[j])
                i++;
            else if(b[j]<a[i])
                j++;
            else
            {
                f1[k]=i;
                f2[k]=j;
                k++;
                i++;j++;
            }
        }
        f1[0]=f2[0]=-1;ans=0;
        f1[k]=n;f2[k]=m;
        for(i=1;i<=k;i++)
        {sum=0;sum1=0;
            for(j=f1[i-1]+1;j<=f1[i];j++)
            {
                sum+=a[j];
            }
            for(j=f2[i-1]+1;j<=f2[i];j++)
            {
                sum1+=b[j];
            }
            ans+=max(sum,sum1);
            //cout<<max(sum,sum1)<<endl;
        }
        cout<<ans<<endl;
        cin>>n;
    }
    return 0;
}

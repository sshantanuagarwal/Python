#include <iostream>

using namespace std;
int n,T,i,a[100005],d,t,m,found;
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    cin>>m;
    while(m--)
    {found=0;
        cin>>t>>d;
        for(i=0;i<n-1;i++)
            {
             if(a[i]+d<a[i+1])
            break;
            }
            if(i<n-1)
            {if(a[i]<t&&a[i+1]>t)
            {cout<<"1";found=1;}
            }
            else if(i==n-1&&a[i]<t)
            {cout<<"1";found=1;}
            if(found==0)
            {
                for(i=0;i<n;i++)
                {
                    if(a[i]>t)
                    break;
                }
                if(i<n)
                cout<<i;
                else
                cout<<n;
            }
            cout<<endl;
    }
    return 0;
}

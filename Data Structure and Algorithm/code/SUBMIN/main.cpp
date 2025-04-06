#include <iostream>

using namespace std;
int T,n,i,a[60],m,j,st,en,Q,sum;
int main()
{
        cin>>n;
        for(i=0;i<n;i++)
            {cin>>a[i];}
        cin>>Q;
        while(Q--)
        {
            cin>>m;
            j=0;
            sum=0;
            while(j<n)
            {
                for(i=j;i<n;i++)
                if(a[i]==m)
                break;
                //cout<<"found at "<<i<<endl;
                j=i;
                for(i=j;i>=0;i--)
                if(m>a[i])
                break;
                st=i+1;
                for(i=j;i<n;i++)
                if(m>a[i])
                break;
                en=i-1;
                for(i=j;i<=en;i++)
                {
                    if(a[i]==m)
                    {sum+=(en-i+1)*(i-st+1);
                    st++;
                    }
                }
                j=en+1;
                //cout<<st<<" "<<en<<endl;
            }
            cout<<sum<<endl;
        }
    return 0;
}

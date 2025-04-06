#include <iostream>

using namespace std;
long long int a[100][100],n,m,i,j,cnt,p[100][100],arr[10000],k,ans,l,t;
long long int lcm(long long int x,long long int y)
{long long int a,b,r;
    a=x;
    b=y;
    while(a!=0)
    {
        r=b%a;
        b=a;
        a=r;
    }
    return (x*y/b);
}
int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        cin>>p[i][j];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        cin>>a[i][j];
        cnt=0;
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    {
            k=p[i][j]-a[i][j]%p[i][j];
            arr[cnt]=k;
            cnt++;
    }
    ans=lcm(arr[0],arr[1]);
    for(i=2;i<n*m;i++)
    {
     ans=lcm(ans,arr[i]);
    }
    l=ans/10000;
    t=ans%10000;
    cout<<l+1<<endl;
    for(i=0;i<l;i++)
    {
        cout<<1<<" "<<1<<" "<<n<<" "<<m<<" "<<10000<<endl;
    }
    cout<<1<<" "<<1<<" "<<n<<" "<<m<<" "<<t<<endl;
    return 0;
}

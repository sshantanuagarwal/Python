#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long int  inf=2000006;
long long int  has[2000006];
struct z
{
    long long int  num;
    long long int  pos;
}a[2000006];
bool cmp(struct z x,struct z y)
{
    if(x.num!=y.num)
    return x.num<y.num;
    else
    return x.pos<y.pos;
}
long long int  n,k,i,res,l;
long long int  binsrch(long long int  x,long long int  y)
{long long int  ans,ans1;
    long long int  low=y,high=n,mid=(low+high)/2;
    while(low<mid)
    {
        if(x<=a[mid].num)
        high=mid;
        else
        low=mid;
        mid=((low+high)/2);
    }
    if(a[mid].num==x)
    ans=a[mid].pos+1;
    else if(a[mid+1].num==x&&mid+1<n)
    ans=a[mid+1].pos+1;
    else
    ans=-1;
    low=y;high=n;mid=(low+high)/2;
    while(low<mid)
    {
        if(x<a[mid].num)
        high=mid;
        else
        low=mid;
        mid=((low+high)/2);
    }
    if(a[mid+1].num==x&&mid+1<n)
    ans1=n-a[mid+1].pos;
    else if(a[mid].num==x)
    ans1=n-a[mid].pos;
    else
    ans1=-1;
    return min(ans,ans1);
}
int main()
{
    cin>>n>>k;
    for(i=0;i<n;i++)
    {cin>>a[i].num;
    a[i].pos=i;
    }
    sort(a,a+n,cmp);
    res=inf;
    //cout<<binsrch(3)<<"adi"<<endl;
    for(i=0;i<n&&a[i].num*2<=k;i++)
    {
            l=binsrch(k-a[i].num,i+1);
            //cout<<l<<" "<<i+1<<" "<<n-i<<endl;
            if(l!=-1)
            res=min(res,max(l,min(a[i].pos+1,n-a[i].pos)));
    }
    if(res!=inf)
    cout<<res<<endl;
    else
    cout<<"-1"<<endl;
    return 0;
}

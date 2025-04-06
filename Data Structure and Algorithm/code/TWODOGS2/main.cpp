#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int i,n,j,k,ans;
struct z
{
    int  num;
    int  pos;
}a[2000006];
bool cmp(struct z x,struct z y)
{
    if(x.num!=y.num)
    return x.num<y.num;
    else
    return x.pos<y.pos;
}
int main()
{
    cin>>n>>k;
    for(i=0;i<n;i++)
    cin>>a[i].num;
    sort(a,a+n,cmp);
    i=0;j=n-1;
    ans=0;
    while(i<j)
    {
        if(a[i].pos+a[j].pos==k)
        {
            ans=min(ans,max(min(a[i].pos+1,n-a[i].pos),min(a[j].pos+1,n-a[j].pos)));

        }
        else if(a[i].pos+a[j].pos<k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    if(ans==0)
    cout<<"-1";
    else
    cout<<ans;
    return 0;
}

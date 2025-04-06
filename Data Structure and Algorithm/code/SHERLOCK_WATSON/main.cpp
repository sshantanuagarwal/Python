#include <iostream>

using namespace std;
int a[100005],b[100005],n,k,Q,i,x;
int main()
{
    cin>>n>>k>>Q;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    b[(i+k)%n]=a[i];
    while(Q--)
    {
        cin>>x;
        cout<<b[x]<<endl;
    }
    return 0;
}

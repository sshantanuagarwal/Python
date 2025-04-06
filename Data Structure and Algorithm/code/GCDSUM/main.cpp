#include <iostream>

using namespace std;
unsigned long long int x,y,ans,n,T;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>x>>y;
        n=y-x+1;
        ans=(n*(n-1))/2;
        cout<<ans<<endl;
    }
    return 0;
}

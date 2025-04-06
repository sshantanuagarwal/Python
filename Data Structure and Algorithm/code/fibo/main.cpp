#include <iostream>

using namespace std;
long long int fib[200],i,n,T;
long long int binsrch(long long int x)
{
    long long int low=0;
    long long int high=50,mid=(low+high)/2;
    while(low<mid)
    {
        if(fib[mid]==x)
        break;
        else if(fib[mid]>x)
        high=mid;
        else
        low=mid;
        mid=(low+high)/2;
    }
    if(fib[mid]==x)
    return 1;
    else
    return 0;
}
int main()
{
    fib[0]=0;fib[1]=1;
    for(i=2;i<50;i++)
    fib[i]=fib[i-1]+fib[i-2];
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(binsrch(n))
        cout<<"IsFibo";
        else
        cout<<"IsNotFibo";
        cout<<endl;
    }
    return 0;
}

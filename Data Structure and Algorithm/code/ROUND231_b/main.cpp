#include <iostream>
#include<cmath>
using namespace std;
int n,k,i;
int main()
{
    cin>>n>>k;
    for(i=int(pow(10,n-1));i<int(pow(10,n));i++)
    {
        if((k*i-i/10)==(i%10)*int(pow(10,n-1)))
        {
            cout<<i<<endl;
            break;
        }
    }
    if(i==int(pow(10,n)))
       cout<<"Impossible"<<endl;
    return 0;
}

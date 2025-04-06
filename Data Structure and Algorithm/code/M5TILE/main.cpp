#include <iostream>

using namespace std;
long long int a[40],b[40],c[40],d[40],T[40],i;
int main()
{
    a[1]=b[1]=c[1]=d[1]=T[0]=1;
    a[0]=0;
    b[0]=0;
    c[0]=0;
    T[1]=0;
    for(i=2;i<35;i++)
    {
        a[i]=T[i-1]+d[i-2]+2*a[i-2]+c[i-2]+b[i-2];
        b[i]=T[i-1]+c[i-2]+a[i-2]+b[i-2];
        c[i]=T[i-1]+3*c[i-2]+2*b[i-2]+2*a[i-2];
        d[i]=T[i-1]+a[i-2]+d[i-2];
        T[i]=2*a[i-1]+2*b[i-1]+c[i-1]+2*d[i-1]+T[i-2];
        cout<<T[i]<<" "<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<d[i]<<endl;
    }

    return 0;
}

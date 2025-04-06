#include <iostream>

using namespace std;
long long int T[305],i,j;
int main()
{
    T[0]=1;
    T[2]=1;
    for(i=4;i<=300;i+=2)
    {
           for(j=0;j<i/4;j++)
           {
               T[i]+=T[j*2]*T[i-2-2*j]*2;
           }
           if(i%4==2)
           T[i]+=T[j*2]*T[i-2-2*j];
           cout<<i<<" "<<T[i]<<endl;
    }
    return 0;
}

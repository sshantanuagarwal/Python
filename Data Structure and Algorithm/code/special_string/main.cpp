#include <iostream>

using namespace std;
int T,n,r,k,found;
char s[10000000];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        r=9%n;
        s[0]='9';
        k=1;
        found=0;
        while(found==0)
        {
            if((10*r+9)%n==0)
            {
                s[k]='9';
                k++;
                found=1;
            }
            else
            {
                s[k]='0';
                k++;
                r=(10*r)%n;
            }
        }
      cout<<s<<endl;
    }
    return 0;
}

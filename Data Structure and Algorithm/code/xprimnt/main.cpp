#include <iostream>

using namespace std;
char s[5006];
int n,i;
int main()
{
    cin>>s;
    cin>>n;
    for(i=0;i<n/2;i++)
        cout<<"person"<<endl;
    for(i=n/2;i<n;i++)
        cout<<"place"<<endl;
    return 0;
}

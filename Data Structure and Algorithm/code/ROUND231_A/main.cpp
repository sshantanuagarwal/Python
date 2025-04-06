#include <iostream>
#include<cmath>
#include<string.h>
using namespace std;
char s[200];
int i,l,k,cnt,a[3];
int main()
{
    cin>>s;
    l=strlen(s);
    cnt=0;k=0;
    for(i=0;i<l;i++)
    {
     if(s[i]=='|')
     {
         cnt++;
     }
     else
     {
         a[k]=cnt;k++;
         cnt=0;
     }
    }a[k]=cnt;
    //cout<<a[0]<<a[1]<<a[2]<<endl;
    if(fabs(a[2]-(a[1]+a[0]))==2)
    {
        if(a[2]>(a[1]+a[0]))
        {cout<<"|";
        for(i=0;i<l-1;i++)
        cout<<s[i];
        }
        else
        {
        for(i=1;i<l;i++)
        cout<<s[i];
        cout<<"|";
        }
    }
    else if(fabs(a[2]-(a[1]+a[0]))==0)
    cout<<s;
    else
    cout<<"Impossible";
    return 0;
}

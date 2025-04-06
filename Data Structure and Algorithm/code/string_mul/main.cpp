#include <iostream>
#include<cstring>
using namespace std;
char s1[100],s2[100];
int res[200],car[200],k,i,j,n,m;
int main()
{
    cin>>s1>>s2;
    n=strlen(s1);
    m=strlen(s2);
    k=0;
    for(i=n-1;i>=0;i--)
    {for(j=m-1;j>=0;j--)
    {
        res[k+n-i-1]+=((s1[i]-'0')*(s2[j]-'0')+car[k-i+n-1])/10;
        car[k-i+n]=((s1[i]-'0')*(s2[j]-'0')+car[k-i+n-1])%10;
    }
    k++;
    }
    for(i=0;i<10;i++)
    cout<<res[i];
    return 0;
}

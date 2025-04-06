#include <iostream>
#include<string.h>
#include<cmath>
using namespace std;
char s1[10004],s2[10004];
int has1[30],has2[30],i,l1,l2,ans;
int main()
{
    cin>>s1>>s2;
    l1=strlen(s1);
    l2=strlen(s2);
    for(i=0;i<l1;i++)
    has1[s1[i]-'a']++;
    for(i=0;i<l2;i++)
    has2[s2[i]-'a']++;
    ans=0;
    for(i=0;i<27;i++)
    {
        ans+=fabs(has1[i]-has2[i]);
    }
    cout<<ans<<endl;
    return 0;
}

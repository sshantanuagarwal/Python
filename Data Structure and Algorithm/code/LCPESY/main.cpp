#include <iostream>
#include<cstring>
using namespace std;
int T,i,l1,l2,a1[100],a2[100],sum;
char s1[10004],s2[10004];
int main()
{
    cin>>T;
    while(T--)
    {
        for(i=0;i<100;i++)
            a1[i]=a2[i]=0;
        cin>>s1>>s2;
        l1=strlen(s1);
        l2=strlen(s2);
        for(i=0;i<l1;i++)
        {
            a1[s1[i]-48]++;
        }
        for(i=0;i<l2;i++)
        {
            a2[s2[i]-48]++;
        }
        sum=0;
        for(i=0;i<=75;i++)
        {
           sum+=min(a1[i],a2[i]);
        }
        cout<<sum<<endl;
    }
    return 0;
}

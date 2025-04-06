#include <iostream>
#include<cstring>
using namespace std;
char s1[10000005],s2[10000005];
long long int l,l1,cnt,cnt1,found,i;
int main()
{
    cin>>s1;
    cin>>s2;
    l=strlen(s1);
    l1=strlen(s2);
    cnt=0;
    cnt1=0;
    found=0;
    for(i=0;i<l;i++)
    {
        if(s1[i]!='|'&&found==0)
            {cnt++;
            }
        else if(s1[i]!='|'&&found==1)
        {
            //cout<<s1[i]<<endl;
         cnt1++;
        }
        else
        found=1;
    }
    if((abs(cnt1-cnt)+l)%2==0)
    {
       if(l1%2==0&&abs(cnt1-cnt)<=l1)
       {
           if(cnt<cnt1)
       }
    }
    else
    {
        cout<<"Impossible"<<endl;
    }
    return 0;
}

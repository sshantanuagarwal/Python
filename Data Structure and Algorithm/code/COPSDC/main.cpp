#include <iostream>

using namespace std;
char[205];
int T,cnt1,cnt2;
int main()
{
    cin>>T;
    while(T--)
    {
        cnt1=cnt2=0;
        cin>>s;
        n=strlen(s);
        for(i=0;i<n;i++)
        {
            if(s[i]==')')
            cnt1++;
            else if(s[i]=='(')
            cnt2++;
        }
        cout<<int(fabs(cnt1-cnt2))<<endl;
    }
    return 0;
}

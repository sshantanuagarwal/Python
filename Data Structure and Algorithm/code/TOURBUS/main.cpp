#include <iostream>

using namespace std;
int cnt;
int main()
{
    cin>>n;
    cnt=0;
    for(i=0;i<n;i++)
        cin>>a>>b;
    for(i=0;i<n;i++)
        scanf("%s",s[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i<j)
               {
                edge[i][j]=1;
                cnt++;
               }
        }
    }
    cout<<cnt<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(edge[i][j]==1)
            {
                cout<<"1 "<<i<<" "<<j<<endl;

            }
        }
    }
    return 0;
}

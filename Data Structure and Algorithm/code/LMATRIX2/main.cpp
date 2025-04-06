#include <iostream>

using namespace std;
int a[100][100],n,m,i,j,cnt,p[100][100],arr[10000][5],k;
int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        cin>>p[i][j];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        cin>>a[i][j];
        cnt=0;
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    {
        if(a[i][j]!=0)
        {
            arr[cnt][0]=i+1;
            arr[cnt][1]=j+1;
            arr[cnt][2]=i+1;
            arr[cnt][3]=j+1;
            k=p[i][j]-a[i][j]%p[i][j];
            arr[cnt][4]=k;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    while(cnt--)
    {
        cout<<arr[cnt][0]<<" "<<arr[cnt][1]<<" "<<arr[cnt][2]<<" "<<arr[cnt][3]<<" "<<arr[cnt][4]<<endl;
    }
    return 0;
}

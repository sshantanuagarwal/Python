#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define gc getchar
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
inline void fastWrite(int a)
{
register char c;
char snum[20];
int i=0;
do
{
snum[i++]=a%10+48;
a=a/10;
}while(a!=0);
i=i-1;
while(i>=0)
putchar(snum[i--]);
putchar('\n');
}
int f[900],i,sum,T,n,cnt;
int digitize(int x)
{
    int a=x,ans=0,sol=0;
    while(a!=0)
    {
       ans=a%10;
       ans=ans*ans;
       sol+=ans;
       a=a/10;
    }
    return sol;
}
int main()
{
//cout<<digitize(10000);
    for(i=2;i<=811;i++)
    {
        //cout<<i<<endl;
        sum=digitize(i);
        cnt=1;
        while(sum!=1&&f[sum]==0&&sum<=810)
        {
            cnt++;
            f[sum]=-1;
            sum=digitize(sum);
        }
        if(sum==1||f[sum]>0)
        {
            if(f[sum]>0)
            f[i]=f[sum]+cnt;
            else
            f[i]=cnt;
            sum=digitize(i);
           while(f[sum]==-1&&sum<=810&&cnt>=0)
        {
            cnt--;
            f[sum]=cnt;
            sum=digitize(sum);
        }
        }
        else
        f[i]=-1;
    }
        n=read_int();
        if(n<=811)
        {
            if(f[n]>=0)
            fastWrite(f[n]);
            else
            puts("-1");
        }
        else
        {
         n=digitize(n);
         if(f[n]>=0)
         fastWrite(f[n]+1);
         else
        puts("-1");
        }
    return 0;
}

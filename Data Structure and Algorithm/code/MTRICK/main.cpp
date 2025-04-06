#include <iostream>
#include<cstdio>
using namespace std;
 long long int mulmod1(long long int a,long long int b,long long int c)
 {
if(a<=1000000000 && b<=1000000000){
long long int ret = ((a%c)*(b%c))%c;
return ret;
}
long long int x = 0,y=a%c;
while(b > 0){
if(b&1) {
x = (x+y)%c;
}
y = (y<<1)%c;
b>>=1;
}
return x%c;
}
long long int mulmod (long long int x, long long int y, long long int mod){
    if(x<=1000000000LL && y<=1000000000LL){
        long long int ret = ((x%mod)*(y%mod))%mod;
        return ret;
    }
	long long int ret = 0LL;

    x %= mod;
	y %= mod;
	while (y) {
		if (y & 1LL) {
			ret += x;
			ret %= mod;
		}
		y >>= 1;
		x <<= 1;
		x %= mod;
	}
	return ret%mod;
}
long long int mod_exp1(long long int a,long long int b,long long int c)
{
    if(a==0)
    return 0;
    else if(b==0)
    return 1;
    else if(b==1)
    return a%c;
    else if(b%2==0)
    return mod_exp1(mulmod(a,a,c),b/2,c)%c;
    else
    return mulmod(a,mod_exp1(a,b-1,c),c)%c;
}
long long int mod_exp(long long int a,long long int p,long long int mod)
{
    long long int y=1;
    a%=mod;
    while(p>0)
    {
        if(p&1)
        {
            //y=(y*a)%mod;
            y=mulmod(y,a,mod);
        }
        //a=(a*a)%mod;
        a=mulmod(a,a,mod);
        p>>=1;
    }
    return y;
}
long long int l[1005],ans[1005],a,b,c,j,k,cnt,cntb,i,T,n,var;
char s[1005];
int main()
{
    //cout<<mod_exp(-5,5,10000);
    scanf("%lld",&T);
    while(T--)
    {
        var=1;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        scanf("%lld",&l[i]);
        scanf("%lld %lld %lld",&a,&b,&c);
        scanf("%s",s);
    j=n-1;
    k=0;
    cnt=1;
    cntb=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='R')
        {
            cnt=(cnt+1)%2;
          if(cnt==0)
          {
              if(i>0)
              ans[i]=(ans[i-1]+c+mulmod(l[j]-l[k-1],var,c))%c;
              else
              ans[i]=l[j]%c;
              j--;
          }
          else
          {
              //ans[i]=l[k];
              if(i>0)
              ans[i]=(ans[i-1]+c+mulmod(l[k]-l[j+1],var,c))%c;
              else
              ans[i]=l[k]%c;
              k++;
          }
        }
        else if(s[i]=='A')
        {
            if(cnt==0)
            {
              if(i>0)
              ans[i]=(ans[i-1]+c+mulmod(l[j]-l[j+1],var,c))%c;
              else
              ans[i]=l[j]%c;
              ans[i]=(ans[i]+a)%c;
              j--;
            }
            else
            {
                if(i>0)
                ans[i]=(ans[i-1]+c+mulmod(l[k]-l[k-1],var,c))%c;
                else
                ans[i]=l[k]%c;
                ans[i]=(ans[i]+a)%c;
                k++;
            }
        }
        else
        {
           if(cnt==0)
            {
                if(i>0)
              ans[i]=(ans[i-1]+c+mulmod(l[j]-l[j+1],var,c)%c)%c;
              else
                ans[i]=l[j]%c;
              ans[i]=mulmod(ans[i],b,c);
              j--;
            }
            else
            {
                if(i>0)
                ans[i]=(ans[i-1]+c+mulmod(l[k]-l[k-1],var,c))%c;
                else
                ans[i]=l[k]%c;
                ans[i]=mulmod(ans[i],b,c);
                k++;
            }
            var=mulmod(b,var,c);
            cntb++;
        }
      printf("%lld ",ans[i]);
    }
    printf("\n");
    }
    return 0;
}

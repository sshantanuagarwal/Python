#include <iostream>
#include<cstdio>
using namespace std;
int a[40],b[100005],c[40],n,T,i,l,maxi,k,maxi1,min1;
int binsrch(int x)
{
 int low=0,high=30,mid=(low+high)/2;
 while(low<mid)
 {
     if(a[mid]==x)
     return mid;
     else if(a[mid]>x)
     high=mid;
     else
     low=mid;
     mid=(low+high)/2;
 }
 if(a[mid]==x)
 return mid;
 else return -1;
}
int main()
{
    a[0]=1;
    for(i=1;i<=30;i++)
    {a[i]=a[i-1]*2;}
    scanf("%d",&T);
    while(T--)
    {k=0;maxi=maxi1=-1;min1=1000000009;
        scanf("%d",&n);
        for(i=0;i<=32;i++)
        c[i]=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            l=binsrch(b[i]);
            if(l!=-1)
            {
                c[l]=1;
             maxi1=max(maxi1,b[i]);
            }
            maxi=max(b[i],maxi);
            min1=min(b[i],min1);
        }
        if(min1==maxi)
        printf("YES");
        else if(2*maxi1>maxi)
        {l=binsrch(maxi1);
        for(i=0;i<=l;i++)
            if(c[i]==0)
            break;
        if(i<=l||l==-1)
        printf("NO");
        else
        printf("YES");
        }
        else
        printf("NO");;
        cout<<endl;
    }
    return 0;
}

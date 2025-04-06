#include <iostream>
#include<cstring>
#include<cstdio>
#include<math.h>
using namespace std;
struct z
{
    int p;
    int rnk;
}a[30];
void link(int x,int y)
{
    if(a[x].rnk>a[y].rnk)
        a[y].p=x;
    else
        a[x].p=y;
    if(a[x].rnk==a[y].rnk)
        a[y].rnk++;
}
int find_set(int x)
{
    if(x!=a[x].p)
    {

        find_set(a[x].p);
    }
    return a[x].p;
}
int T,i,l,n,var,indeg[30],outdeg[30],st,en,coun;
char s[1010];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        for(i=0;i<27;i++)
        {
            a[i].p=-1;a[i].rnk=1;
            indeg[i]=outdeg[i]=0;
        }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        l=strlen(s);
        if(a[s[0]-'a'].p==-1)
        a[s[0]-'a'].p=s[0]-'a';
        if(a[s[l-1]-'a'].p==-1)
        a[s[l-1]-'a'].p=s[l-1]-'a';
        outdeg[s[0]-'a']++;
        indeg[s[l-1]-'a']++;
        if(find_set(s[0]-'a')!=find_set(s[l-1]-'a'))
        link(find_set(s[0]-'a'),find_set(s[l-1]-'a'));
    }
    st=0;en=0;
    for(i=0;i<27;i++)
    {
        if(fabs(indeg[i]-outdeg[i])==1)
        {
            if(indeg[i]>outdeg[i]&&st==0)
            st=1;
            else if(indeg[i]<outdeg[i]&&en==0)
            en=1;
            else
            break;
        }
        else if(indeg[i]==outdeg[i]);
        else
        break;
    }

    if(i==27)
    {coun=0;
        for(i=0;i<27;i++)
        {
            if(a[i].p==i)
            {
                coun++;
                break;
            }
        }
        if(coun==1)
        printf("Ordering is possible.");
        else
        printf("The door cannot be opened.");
    }
    else
    printf("The door cannot be opened.");
    printf("\n");
    }
    return 0;
}

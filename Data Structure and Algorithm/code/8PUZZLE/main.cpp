//adi_prakash
//27-1-2014
//crypt arithmatic
// artificial intelligence lab
#include <iostream>
#include<deque>
#include<cstdio>
using namespace std;
struct v
{
    int a[9];
    int par ;
    int idx;
}t,f[100007],ans,adi[100007];
deque<struct v> d;
bool check(struct v n)
{
    if(n.a[0]==1&&n.a[1]==2&&n.a[2]==3&&n.a[5]==4&&n.a[8]==5&&n.a[7]==6&&n.a[6]==7&&n.a[3]==8)
    return true;
    else
    return false;
}
bool check1(struct v n)
{int i;
    for(i=0;i<9;i++)
    if(t.a[i]!=n.a[i])
    break;
    if(i>=9)
    return false;
    else return true;
}
int found=0,k=0,cnt1=0,co;
int bfs(struct v q)
{cnt1++;
   int i,id,j;
   for(i=0;i<9;i++)
    if(q.a[i]==0)
    break;
   id=i;
   f[k]=q;
   q.idx=k;
   k++;
   if(check(q))
   {
   found=1;
   ans=q;
   co=q.idx;
   return 0;
   }
   if((check1(q)||q.par==-1)&&found==0)
   {struct v p;
   if(id%3!=0)
   {p=q;
       swap(p.a[id-1],p.a[id]);
       p.par=q.idx;
       d.push_back(p);
   }
   if(id%3!=2)
   {p=q;
      swap(p.a[id+1],p.a[id]);
      p.par=q.idx;
       d.push_back(p);
   }
   if(id/3!=0)
   {p=q;
      swap(p.a[id-3],p.a[id]);
      p.par=q.idx;
       d.push_back(p);
   }
   if(id/3!=2)
   {p=q;
      swap(p.a[id+3],p.a[id]);
      p.par=q.idx;
       d.push_back(p);
   }
   }
    while(!d.empty())
    {
        struct v x;
        x=d.front();
        d.pop_front();
        bfs(x);
    }
}
int main()
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,c,n;
    struct v m;
    found=0;
    k=0;
    for(i=0;i<9;i++)
        cin>>t.a[i];
    /*
    t.a[0]=2;
    t.a[1]=0;
    t.a[2]=3;
    t.a[3]=1;
    t.a[4]=8;
    t.a[5]=4;
    t.a[6]=7;
    t.a[7]=6;
    t.a[8]=5;
    */
    t.par=-1;
    t.idx=0;
    m=t;
    bfs(m);
    k=0;
    while(co!=-1)
    {adi[k]=f[co];
    k++;
        co=f[co].par;
    }
    cout<<"the total number of steps taken were "<<k-1<<endl;
    cout<<endl;
    for(n=k-1;n>=0;n--)
    {
        for(i=0;i<3;i++)
        {for(j=0;j<3;j++)
        cout<<adi[n].a[i*3+j]<<" ";
        cout<<endl;
        }
        cout<<endl;
        if(n==k-1)
        cout<<"INITIAL STATE"<<endl;
        else
        cout<<"STEP NUMBER "<<k-1-n<<endl;
        cout<<"-------------------------"<<endl;
    }
    return 0;
}

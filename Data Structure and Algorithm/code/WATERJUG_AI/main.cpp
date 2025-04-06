/*
adi_prakash
21-1-2014
@adisticated
IT GIVES YOU THE LEAST NUMBER OF WAYS TO GET A PERTICULAR
QTY. OF WATER IN TWO GIVEN CAPACITY VESSELS
CHECK WHERE YOUR CODEBLOCKS PROGRAMS ARE SAVED...SEARCH WATER_JUG FILE...
YOU WILL FIND INSIDE IT "outt.txt"
OPEN IT!!!
*/
#include <iostream>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{int r;
while(b!=0)
    {r=a%b;
    a=b;
    b=r;
    }
    return a;
}
int a,b,c,prev_x,prev_y,cnt,x,y,t,ans,found,s;
int main()
{
    freopen("outt.txt","w",stdout);
    a=4;b=3;c=2;
     found=0;
    if(c<=max(a,b))
    {
        if(c%gcd(a,b)==0)
        {
            found=1;
        }
    }
    if(found==1)
    {x=0;y=0;
    cnt=0;
    while(x!=c&&y!=c)
    {
        if(x==0)
        {cnt++;
        x=a;
        }
      if(x==c||y==c)
        break;
        cnt++;
        prev_x=x;
        prev_y=y;
        if(y+x>b)
        {y=b;x=prev_y+x-b;}
        else
        {y+=x;x=0;}
          if(x==c||y==c)
        break;
        if(y==b)
        {
            cnt++;
            y=0;
        }
        if(x==c||y==c)
        break;
    }
    ans=cnt;
        x=0;y=0;
    cnt=0;
    while(x!=c&&y!=c)
    {
        if(y==0)
        {cnt++;
        y=b;
        }
      if(x==c||y==c)
        break;
        cnt++;
        prev_x=x;
        prev_y=y;
        if(y+x>a)
        {x=a;y=prev_x+y-a;}
        else
        {x+=y;y=0;}
          if(x==c||y==c)
        break;
        if(x==a)
        {
            cnt++;
            x=0;
        }
        if(x==c||y==c)
        break;
    }
    if(ans<=cnt)
    s=1;
    }
    //cin>>a>>b>>c;
    if(found==1)
    {
    if(s)
    {x=0;y=0;
    cnt=0;
    cout<<"STEPS\t|   PROCESS"<<"\t\t\t|"<<"  A"<<"\t|"<<"  B  |"<<endl;
    cout<<" \t|              \t\t\t|    \t|     |"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<" \t|              \t\t\t|    \t|     |"<<endl;
    cout<<"0\t|  INTIALISING \t\t\t|  0 \t|  0  |"<<endl;
    while(x!=c&&y!=c)
    {
        if(x==0)
        {cnt++;
        //load(x);
        cout<<cnt<<"\t|  FILLING A FULLY"<<"\t\t";
        x=a;
        cout<<"|  "<<x<<"\t|  "<<y<<"  |"<<endl;
        }
      if(x==c||y==c)
        break;
        cnt++;
        prev_x=x;
        prev_y=y;
        if(y+x>b)
        {y=b;x=prev_y+x-b;}
        else
        {y+=x;x=0;}
        //unload(x,y,prev_x,prev_y);
        cout<<cnt<<"\t|  POURING A TO B "<<"\t\t";
        cout<<"|  "<<x<<"\t|  "<<y<<"  |"<<endl;
          if(x==c||y==c)
        break;
        if(y==b)
        {
            cnt++;
            //emp(y);
            cout<<cnt<<"\t|  EMPTYING B "<<"\t\t\t";
            y=0;
            cout<<"|  "<<x<<"\t|  "<<y<<"  |"<<endl;
        }
        if(x==c||y==c)
        break;
    }
    cout<<endl<<endl<<endl;
    cout<<"ACCOMPLISHED!!!\n";
    cout<<endl<<endl<<endl;
    cout<<"Number Of Steps Involved = ";
    cout<<cnt<<endl;
    }
    else
    {
    x=0;y=0;
    cnt=0;
    cout<<"STEPS\t|   PROCESS"<<"\t\t\t|"<<"  A"<<"\t|"<<"  B  |"<<endl;
    cout<<" \t|              \t\t\t|    \t|     |"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<" \t|              \t\t\t|    \t|     |"<<endl;
    cout<<"0\t|  INTIALISING \t\t\t|  0 \t|  0  |"<<endl;
    while(x!=c&&y!=c)
    {
        if(y==0)
        {cnt++;
        //load(x);
        cout<<cnt<<"\t|  FILLING B FULLY"<<"\t\t";
        y=b;
        cout<<"|  "<<x<<"\t|  "<<y<<"  |"<<endl;
        }
      if(x==c||y==c)
        break;
        cnt++;
        prev_x=x;
        prev_y=y;
        if(y+x>a)
        {x=a;y=prev_x+y-a;}
        else
        {x+=y;y=0;}
        //unload(x,y,prev_x,prev_y);
        cout<<cnt<<"\t|  POURING B TO A "<<"\t\t";
        cout<<"|  "<<x<<"\t|  "<<y<<"  |"<<endl;
          if(x==c||y==c)
        break;
        if(x==a)
        {
            cnt++;
            //emp(y);
            cout<<cnt<<"\t|  EMPTYING A "<<"\t\t\t";
            x=0;
            cout<<"|  "<<x<<"\t|  "<<y<<"  |"<<endl;
        }
        if(x==c||y==c)
        break;
    }
    cout<<endl<<endl<<endl;
    cout<<"ACCOMPLISHED!!!\n";
    cout<<endl<<endl<<endl;
    cout<<"Number Of Steps Involved = ";
    cout<<cnt<<endl;
    }
    }
    else
    cout<<"not possible"<<endl;
    return 0;
}

#include <iostream>
#include<cstdio>
using namespace std;
int a,b,c,prev_x,prev_y,cnt,x,y,t;
int main()
{freopen("out.txt","w",stdout);
    a=39989;b=2999;c=5000;
    //cin>>a>>b>>c;
    if(a>b)
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
    return 0;
}

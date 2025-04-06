#include <iostream>
#include<deque>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
deque<double> b;
long long int T,n,res,found,z;
long long int bfs(long long int &a,long long int ans)
 {long long int x,y;
    // cout<<ans<<endl;
    if(ans%n==0&&ans!=0)
     {
         if(res>ans)
        {res=ans;
        found=a;
        }
     }
     if(found>a)
     {b.push_back(double(ans));
     b.push_back(double(a+1));
     }
     if(found>a)
     {b.push_back(double(double(ans)+pow(10,a)*9));
     b.push_back(double(a+1));
     }
     while(!b.empty())
    {
          x=b.front();
          b.pop_front();
          y=b.front();
          b.pop_front();
          bfs(y,x);
    }
 }
int main()
{
    cin>>T;
    while(T--)
    {
        z=0;
        res=pow(10,18);
        //cout<<res;
        found=18;
        cin>>n;
        bfs(z,0);
        cout<<res<<endl;;
    }
    return 0;
}

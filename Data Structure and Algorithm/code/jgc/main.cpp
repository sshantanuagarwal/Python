#include <iostream>
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;
int inf=1000,pr[100005];
struct Vertex{
        int v;
        int key;
        int par;
};
struct Comp{
bool operator()(Vertex &t1, Vertex &t2)
    {
        return t1.key<t2.key;
    }
};
Vertex edge[100005];
int main()
{
    std::priority_queue<Vertex, std::vector<Vertex>, Comp> pq;
   for(int i=0;i<10;i++)
   {
       if(i==5)
        edge[5].key=-1;
       else
       edge[i].key=i;
       edge[i].v=i;
       pq.push(edge[i]);
   }
   while(!pq.empty())
   {
       cout<<pq.top().v<<" ";
       pq.pop();
   }
}
/*
9 14
1 2 4
2 3 8
3 4 7
4 5 9
5 6 10
6 7 2
7 8 1
8 1 8
2 8 11
8 9 7
7 9 6
3 6 4
4 6 14
3 9 2
*/

#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 1010
int d[maxn][maxn], c[maxn][maxn], up[maxn][maxn], v[maxn][maxn];
int n, m, k, st0;
int st[maxn], p[maxn];
int main()
{
 //  freopen("standard.in", "r", stdin);
//  freopen("standard.out", "w", stdout);
scanf("%d%d", &n, &m);
for(int i=1; i<=n; ++i)
{
for(int j=1; j<=m; ++j)
{
scanf("%d", &v[i][j]);
if(v[i][j]==1)
up[i][j]=0;
else
up[i][j]=up[i-1][j]+1;
}
}
for(int i=1; i<=n; ++i)
{
st0=1;
st[1]=0;
p[1]=0;
for(int j=1; j<=m+1; ++j)
{
while(st[st0]>=up[i][j] && st0>0)
{
d[i][i-st[st0]+1]=max(d[i][i-st[st0]+1], j-1-p[st0-1]);
//     printf("%d %d\n", st[st0], j-1-p[st0-1]);
--st0;
}
//     printf("***\n");
st[++st0]=up[i][j];
p[st0]=j;
}
//  printf("\n");
}
for(int i=1; i<=n; ++i)
{
for(int j=1; j<=i; ++j)
{
d[i][j]=max(d[i][j], d[i][j-1]);
//    printf("%d ", d[i][j]);
}
      //  printf("\n");
}
for(int i=1; i<=n; ++i)
for(int j=1; i+j-1<=n; ++j)
c[i+j-1][j]=max(d[i+j-1][j]*i, max(c[i+j-2][j], c[i+j-1][j+1]));
int a, b;
scanf("%d", &k);
while(k--)
{
scanf("%d%d", &a, &b);
printf("%d\n", c[b][a]);
}
return 0;
}



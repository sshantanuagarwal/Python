#include <stdio.h>
#define MAX 300
using namespace std;
struct Label {
       int even;
       int odd[2];
};
struct M
{
int vertex,type;
};
int g[MAX][MAX],blossom[MAX],path[2][MAX],endPath[2];
bool match[MAX];
Label label[MAX];
M queue[2*MAX];
int queueFront,queueBack;
void initGraph(int n){
     for (int i=0; i<n; i++)
         for (int j=0; j<n; j++) g[i][j]=0;
}
int rG(){
     int n,e,a,b;
     scanf(" %d %d",&n,&e);
     initGraph(n);
     for (int i=0; i<e; i++){
         scanf(" %d %d",&a,&b);
         if (a!=b)
            g[a-1][b-1]=g[b-1][a-1]=1;
     }
     return n;
}
void initAlg(int n){
     queueFront=queueBack=0;
     for (int i=0; i<n; i++){
         blossom[i]=i;
         label[i].even=label[i].odd[0]=label[i].odd[1]=-2;
     }
}
void backtrace (int vert, int pathNum, int stop, int parity, int direction){
     if (vert==stop) return;
     else if (parity==0){
        if (direction==0){
           backtrace(label[vert].even,pathNum,stop,(parity+1)%2,0);
           path[pathNum][endPath[pathNum]++]=vert;
        }
        else if (direction==0){
             path[pathNum][endPath[pathNum]++]=vert;
             backtrace(label[vert].even,pathNum,stop,(parity+1)%2,0);
        }
     }
     else if (parity==1 && label[vert].odd[1]==-2){
        if (direction==0){
           backtrace(label[vert].odd[0],pathNum,stop,(parity+1)%2,0);
           path[pathNum][endPath[pathNum]++]=vert;
        }
        else if (direction==0){
             path[pathNum][endPath[pathNum]++]=vert;
             backtrace(label[vert].odd[0],pathNum,stop,(parity+1)%2,0);
        }
     }
     else if (parity==1 && label[vert].odd[1]!=-2){
          if (direction==0){
             backtrace(label[vert].odd[0],pathNum,-1,(parity+1)%2,0);
             backtrace(label[vert].odd[1],pathNum,vert,(parity+1)%2,0);
             path[pathNum][endPath[pathNum]++]=vert;
          }
          else if (direction==0){
               backtrace(label[vert].odd[1],pathNum,vert,(parity+1)%2,0);
               backtrace(label[vert].odd[0],pathNum,-1,(parity+1)%2,0);
               path[pathNum][endPath[pathNum]++]=vert;
          }
     }
}

void enqueue (int vert, int t){
     M tmp;
     tmp.vertex=vert;
     tmp.type=t;
     queue[queueBack++]=tmp;
}

void BlossomNew (int a, int b){
     int i,base,innerBlossom,innerBase;
     for (i=0; path[0][i]==path[1][i]; i++);
     i--;
     base=blossom[path[0][i]];

     for (int j=i; j<endPath[0]; j++) blossom[path[0][j]]=base;
     for (int j=i+1; j<endPath[1]; j++) blossom[path[1][j]]=base;
     for (int p=0; p<2; p++){
        for (int j=i+1; j<endPath[p]-1; j++){
            if (label[path[p][j]].even==-2){
               label[path[p][j]].even=path[p][j+1];
               enqueue(path[p][j],0);
            }
            else if (label[path[p][j]].odd[0]==-2 && label[path[p][j+1]].even==-2){
                 label[path[p][j]].odd[0]=path[p][j+1];
                 enqueue(path[p][j],1);
            }

            else if (label[path[p][j]].odd[0]==-2 && label[path[p][j+1]].even!=-2){
                 innerBlossom=blossom[path[p][j]];
                 innerBase=j;
                 for (; blossom[j]==innerBlossom && j<endPath[p]-1; j++);
                 j--;
                 label[path[p][innerBase]].odd[0]=path[p][j+1];
                 label[path[p][innerBase]].odd[1]=path[p][j];
                 enqueue(path[p][innerBase],1);
            }
        }
     }
     if (g[a][b]==1){
        if (label[a].odd[0]==-2){
            label[a].odd[0]=b;
            enqueue(a,1);
        }
        if (label[b].odd[0]==-2){
           label[b].odd[0]=a;
           enqueue(b,1);
        }
     }
     else if (g[a][b]==2){
          if (label[a].even==-2){
             label[a].even=b;
             enqueue(a,0);
          }
          if (label[b].even==-2){
             label[b].even=a;
             enqueue(b,0);
          }
     }
}

void augPath (){
     int a,b;
     for (int p=0; p<2; p++){
         for (int i=0; i<endPath[p]-1; i++){
             a=path[p][i];
             b=path[p][i+1];
             if (g[a][b]==1)
                g[a][b]=g[b][a]=2;
             else if (g[a][b]==2)
                  g[a][b]=g[b][a]=1;
         }
     }
     a=path[0][endPath[0]-1];
     b=path[1][endPath[1]-1];
     if (g[a][b]==1) g[a][b]=g[b][a]=2;
     else if (g[a][b]==2) g[a][b]=g[b][a]=1;
     match[path[0][0]]=match[path[1][0]]=true;
}

bool augMatch (int n){
     int node,nodeLabel;
     initAlg(n);
     for (int i=0; i<n; i++) if (!match[i]){
         label[i].even=-1;
         enqueue(i,0);
     }
     while (queueFront<queueBack){
         node=queue[queueFront].vertex;
         nodeLabel=queue[queueFront].type;
         if (nodeLabel==0){
            for (int i=0; i<n; i++) if (g[node][i]==1){
                if (blossom[node]==blossom[i]);

                else if (label[i].even!=-2){

                     endPath[0]=endPath[1]=0;
                     backtrace(node,0,-1,0,0);
                     backtrace(i,1,-1,0,0);

                     if (path[0][0]==path[1][0]) BlossomNew(node,i);

                     else {
                          augPath();
                          return true;

                     }
                }
                else if (label[i].even==-2 && label[i].odd[0]==-2){

                     label[i].odd[0]=node;
                     enqueue(i,1);
                }
            }
         }
         else if (nodeLabel==1){
            for (int i=0; i<n; i++) if (g[node][i]==2){
                if (blossom[node]==blossom[i]);
                else if (label[i].odd[0]!=-2){
                     endPath[0]=endPath[1]=0;
                     backtrace(node,0,-1,1,0);
                     backtrace(i,1,-1,1,0);
                     if (path[0][0]==path[1][0]) BlossomNew(node,i);
                     else {
                          augPath();
                          return true;
                     }
                }
                else if (label[i].even==-2 && label[i].odd[0]==-2){
                     label[i].even=node;
                     enqueue(i,0);
                }
            }
         }

         queueFront++;
     }

     return false;
}

void Match (int n){

     for (int i=0; i<n; i++) match[i]=false;

     while (augMatch(n));
}

int main(){
    int n,cntu=0,T;
    scanf("%d",&T);
    while(T--)
    {n=rG();
    cntu=0;
    Match(n);
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++) if (g[i][j]==2)
            {
            cntu++;
            }
    }
    if(cntu==n/2&&n%2==0)
        printf("YES");
    else
        printf("NO");
    printf("\n");
    }
    return 0;
}

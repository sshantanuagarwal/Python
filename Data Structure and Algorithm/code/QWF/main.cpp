//#include"/home/pratu/coding/header.h"
#include <iostream>
#include<cstdio>
using namespace std;
#define sz 1002
typedef long long int LL;
bool dir, found;
int rev, fw, n;
LL A,B,C;
LL X,Y;
char str[sz];
struct oper{
    LL V;
    bool T;  // T = 1 means add and T = 0 means multiply
    oper(LL V_, bool T_){ V=V_; T = T_; }
    oper(){}
};

oper opdq[sz];
int opdq_sz;
LL num[sz];

void init(){
    opdq_sz = -1;
    fw=0; rev=n-1;
    dir = 1;
    X=-1LL; Y=-1LL;
    found =0;
}
/*
LL mulmod(LL a,LL b,LL c){
    if(a<=1000000000LL && b<=1000000000LL){
        LL ret = ((a%c)*(b%c))%c;
        return ret;
    }
    LL x = 0LL,y=a%c;
    while(b > 0LL){
        if(b&1LL) {
            x = (x+y)%c;
        }
        y = (y<<1LL)%c;
        b>>=1LL;
    }
    return x%c;
}
*/

LL mulmod (LL x, LL y, LL mod){
    if(x<=1000000000LL && y<=1000000000LL){
        LL ret = ((x%mod)*(y%mod))%mod;
        return ret;
    }
	LL ret = 0LL;

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


LL getres(LL ele){
    LL ans = ele%C;
    if(X!=-1LL) ans = mulmod(ans, X,C);
    if(Y!=-1LL) ans = ((ans%C) + (Y%C))%C;
    return ans;
}

void move(){
    LL ele;
    if(dir) { // dir = 1 means forward
        ele = num[fw];
//        show1("fow");
//        show2("ele",ele);
        LL get = getres(ele);
//        show2("get",ele);
//        show1("-----------------------------------------------");
        printf("%lld ",get%C);
//        cout<<(get%C)<<" ";
        fw++;
    }
    else {
        ele = num[rev];
//        show1("rev");
//        show2("ele",ele);
        LL get = getres(ele);
//        show2("get",ele);
//        show1("-----------------------------------------------");
        printf("%lld ",get%C);
//        cout<<(get%C)<<" ";
        rev--;
    }
}

void addop(bool type){
    if(type==0){  // multiply
        if(!found){
            if(X==-1LL) X=1LL;
            X = mulmod(X,B,C);
        }
        else{
            if(X==-1LL) X = 1LL;
            if(Y==-1LL) Y = 1LL;
            X = mulmod(X,B,C);
            Y = mulmod(Y,B,C);
        }
    }
    else{   // add
        if(!found) found = 1;
        if(X == -1LL) X = 1LL;
        if(Y == -1LL) Y = 0LL;
        Y = ((Y%C) + (A%C))%C;
    }
}



void takeInput(){
    //si1(n);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&num[i]);
    scanf("%lld%lld%lld",&A,&B,&C);

//    FOR(i,0,n) cin>>num[i];
//    cin>>A>>B>>C;
    scanf("%s",str);
    init();
}

int main(){
//    READ("input.txt");
    int test;
    scanf("%d",&test);
    //si1(test);
    while(test--){
        takeInput();
        for(int i=0;i<n;i++){
            if(str[i] == 'R'){
                dir=!dir;
                move();
            }
            else if(str[i] == 'A'){
                addop(1);
                move();
            }
            else {
                addop(0);
                move();
            }
        }
        printf("\n");
    }
    return 0;
}
/*
Input
7
3
1 2 3
2 3 5
RRR
7
1 4 5 6 2 8 6
2 5 13
AMRARMR
7
1 4 5 6 2 8 6
2 5 13
AMAMAMA
4
1 2 3 4
1 2 3
RAMA
1
6
2 4 97
R
1
6
2 4 97
A
1
6
2 4 97
M

Output:
3 1 2
3 4 1 0 11 2 6
3 4 11 2 8 10 9
1 1 0 2
6
8
24

*/

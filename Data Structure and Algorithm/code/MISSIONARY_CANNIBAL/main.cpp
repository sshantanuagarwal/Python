#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("inpp.txt","r",stdin);
    freopen("outp.txt","w",stdout);
int cnumright=0, cnumleft = 3, mnumright=0, mnumleft=3;
static char boatposition = 'l';
char entity1, entity2;

cout<<"Initial positions of the Missionaries and Cannibals\n";
for(int i = 0; i<cnumleft; i++)
{cout<<"c"<<" ";}
for(int i2 = 0; i2<mnumleft; i2++)
{cout<<"m"<<" ";}
if(boatposition == 'r'){cout<<".....................<boat> ";}
else if(boatposition == 'l'){cout<<" <boat>.....................";}
for(int j = 0; j<cnumright; j++)
{cout<<"c"<<" ";}
for(int j2 = 0; j2<mnumright; j2++)
{cout<<"m"<<" ";}
cout<<"\n";
cout<<"*************************************************\n\n";

/*for(int i = 0; i<(cnumleft+mnumleft); i++)
{cout<<left[i]<<" ";}
if(boatposition == 'l'){cout<<".....................<boat>";}
else if(boatposition == 'r'){cout<<"<boat>.....................";}
for(int j = 0; j<(cnumright+mnumright); j++)*/
int gameover = 0;

while(gameover==0)
{       int num = 1;
cout<<"How many people are going to travel in the boat(1/2):";
cin>>num;
cout<<num<<endl<<endl;
if(num==1)
{
cout<<"The Enitity travelling is a missionary or cannibal(m/c):";
cin>>entity1;
cout<<entity1<<endl<<endl;
if(boatposition=='l'){if(entity1=='c'){cnumright++; cnumleft--; boatposition='r';}
else if(entity1=='m'){mnumright++; mnumleft--; boatposition='r';}}
if(boatposition=='r'){if(entity1=='c'){cnumright--; cnumleft++; boatposition='l';}
else if(entity1=='m'){mnumright--; mnumleft++; boatposition='l';}}
}

else if(num==2)
{
cout<<"The First Enitity travelling is a missionary or cannibal(m/c):";
cin>>entity1;
cout<<entity1<<endl<<endl;
cout<<"The Second Enitity travelling is a missionary or cannibal(m/c):";
cin>>entity2;
cout<<entity2<<endl<<endl;
if(boatposition=='l')
{
if(entity1=='c' && entity2=='c'){cnumright=cnumright+2; cnumleft=cnumleft-2;}
else if(entity1=='m' && entity2=='m'){mnumright=mnumright+2; mnumleft=mnumleft-2;}
else if(entity1=='c' && entity2=='m'){cnumright++; cnumleft--; mnumright++; mnumleft--;}
else if(entity1=='m' && entity2=='c'){cnumright++; cnumleft--; mnumright++; mnumleft--;}
boatposition='r';
}

else if(boatposition=='r')
{
if(entity1=='c' && entity2=='c'){cnumright=cnumright-2; cnumleft=cnumleft+2;}
else if(entity1=='m' && entity2=='m'){mnumright=mnumright-2; mnumleft=mnumleft+2;}
else if(entity1=='c' && entity2=='m'){cnumright--; cnumleft++; mnumright--; mnumleft++;}
else if(entity1=='m' && entity2=='c'){cnumright--; cnumleft++; mnumright--; mnumleft++;}
boatposition='l';
}

}

cout<<"Positions of the Missionaries and Cannibals\n";
for(int i = 0; i<cnumleft; i++)
{cout<<"c"<<" ";}
for(int i2 = 0; i2<mnumleft; i2++)
{cout<<"m"<<" ";}
if(boatposition == 'r'){cout<<".....................<boat> ";}
else if(boatposition == 'l'){cout<<" <boat>.....................";}
for(int j = 0; j<cnumright; j++)
{cout<<"c"<<" ";}
for(int j2 = 0; j2<mnumright; j2++)
{cout<<"m"<<" ";}
cout<<"\n";
cout<<"*************************************************\n\n";
if(cnumright>mnumright){if(mnumright!=0){gameover=1; cout<<"GAMEOVER!!!";}}
else if(cnumleft>mnumleft){if(mnumleft!=0){gameover=1; cout<<"GAMEOVER!!!";}}
if(cnumright==3&&mnumright==3){return 0;}
}
//getch();
return 0;
}
/*output:

Initial positions of the Missionaries and Cannibals
c c c m m m  <boat>.....................
*************************************************

How many people are going to travel in the boat(1/2):2
The First Enitity travelling is a missionary or cannibal(m/c):c
The Second Enitity travelling is a missionary or cannibal(m/c):c
Positions of the Missionaries and Cannibals
c m m m .....................<boat> c c
*************************************************

How many people are going to travel in the boat(1/2):1
The Enitity travelling is a missionary or cannibal(m/c):c
Positions of the Missionaries and Cannibals
c c m m m  <boat>.....................c
*************************************************

How many people are going to travel in the boat(1/2):2
The First Enitity travelling is a missionary or cannibal(m/c):c
The Second Enitity travelling is a missionary or cannibal(m/c):c
Positions of the Missionaries and Cannibals
m m m .....................<boat> c c c
*************************************************

How many people are going to travel in the boat(1/2):1
The Enitity travelling is a missionary or cannibal(m/c):c
Positions of the Missionaries and Cannibals
c m m m  <boat>.....................c c
*************************************************

How many people are going to travel in the boat(1/2):2
The First Enitity travelling is a missionary or cannibal(m/c):m
The Second Enitity travelling is a missionary or cannibal(m/c):m
Positions of the Missionaries and Cannibals
c m .....................<boat> c c m m
*************************************************

How many people are going to travel in the boat(1/2):2
The First Enitity travelling is a missionary or cannibal(m/c):c
The Second Enitity travelling is a missionary or cannibal(m/c):m
Positions of the Missionaries and Cannibals
c c m m  <boat>.....................c m
*************************************************

How many people are going to travel in the boat(1/2):2
The First Enitity travelling is a missionary or cannibal(m/c):m
The Second Enitity travelling is a missionary or cannibal(m/c):m
Positions of the Missionaries and Cannibals
c c .....................<boat> c m m m
*************************************************

How many people are going to travel in the boat(1/2):1
The Enitity travelling is a missionary or cannibal(m/c):c
Positions of the Missionaries and Cannibals
c c c  <boat>.....................m m m
*************************************************

How many people are going to travel in the boat(1/2):2
The First Enitity travelling is a missionary or cannibal(m/c):c
The Second Enitity travelling is a missionary or cannibal(m/c):c
Positions of the Missionaries and Cannibals
c .....................<boat> c c m m m
*************************************************

How many people are going to travel in the boat(1/2):1
The Enitity travelling is a missionary or cannibal(m/c):c
Positions of the Missionaries and Cannibals
c c  <boat>.....................c m m m
*************************************************

How many people are going to travel in the boat(1/2):2
The First Enitity travelling is a missionary or cannibal(m/c):c
The Second Enitity travelling is a missionary or cannibal(m/c):c
Positions of the Missionaries and Cannibals
.....................<boat> c c c m m m
*/

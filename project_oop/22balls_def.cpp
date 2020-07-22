#include<bits/stdc++.h>
#include<windows.h>
#include"22balls.hpp"

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

Balls :: Balls()
{
    tickets=0;
    r=22;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
}

int Balls :: playthegame()
{
    SetConsoleTextAttribute(console,11);
    cout<<"\n                         WELCOME TO THE 22 BALLS GAME\n";
    SetConsoleTextAttribute(console,6);
    cout<<"\nHow to play?";
    SetConsoleTextAttribute(console,15);
    cout<<"\n There are 22 balls on  a table,you can take either a ";
    cout<<"\n maximum of 4 balls or a minimum of 1 at a time.If you take";
    cout<<"\n the last ball from the table you will WIN other wise Computer will win\n";
    SetConsoleTextAttribute(console,6);
    lb:
    cout<<"\n Either You or Computer can Take First ,Enter your choice"<<"\nI(you)/C(computer)   ";
    SetConsoleTextAttribute(console,15);
    cin>>ch;
    if(ch=='i'||ch=='I')
    {
        cout<<"\nYou:";
        cin>>a;
        while(a>4||a<1)
        {
            SetConsoleTextAttribute(console,12);
            cout<<"\nWRONG INPUT";
            SetConsoleTextAttribute(console,15);
            cout<<"\nEnter again:    ";
            cin>>a;
        }
        r=r-a;
    }
    else if(ch!='c' && ch!='C')
        goto lb;
    while(r>0)
    {
        c=r%5;
        if(c==0)
        {
            srand(time(NULL));
            c=rand();
            c=c%4;
            c=arr[c];
        }
        cout<<"\nComputer:"<<c;
        r=r-c;
        if(r==0)
        {
            SetConsoleTextAttribute(console,12);
            cout<<"\nYou lose!";
            tickets=0;
            return tickets;
            //break;
        }
        cout<<"\nRemaining:"<<r;
        cout<<"\nYou:";
        cin>>a;
        while(a>4||a<1)
        {
            SetConsoleTextAttribute(console,12);
            cout<<"\nWRONG INPUT";
            SetConsoleTextAttribute(console,15);
            cout<<"\nEnter again:    ";
            cin>>a;
        }
        r=r-a;
        if(r==0)
        {
            SetConsoleTextAttribute(console,10);
            cout<<"\nYou Win!";
            tickets=30;
            SetConsoleTextAttribute(console,15);
            cout<<"\nTICKETS WON:"<<tickets;
            return tickets;
            //break;
        }
    }
    return 0;
}

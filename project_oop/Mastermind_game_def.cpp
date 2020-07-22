#include<bits/stdc++.h>
#include<windows.h>
#include<fstream>
#include<ctime>
#include"Mastermind_game.hpp"


using namespace std;

HANDLE consolez = GetStdHandle(STD_OUTPUT_HANDLE);


Mastermind :: Mastermind()
{
    x=0;
    y=0;
    flag=0;
}

void Mastermind :: randomize(int arr[], int n)
{
    srand( time(NULL) );
    for (int i = n-1; i > 0; i--)
    { int j = rand() % (i+1);
        swap(arr[i], arr[j]);
    }
}

int Mastermind :: playthegame()
{
    SetConsoleTextAttribute(consolez,11);
    cout<<"\t\t\t\t\tWELCOME TO MASTERMIND\n";
    j:
    SetConsoleTextAttribute(consolez,14);
    cout<<"\n1.New Game\n2.Instructions    ";
    cin>>ch1;
    if(ch1==1)
    {   SetConsoleTextAttribute(consolez,14);
        cout<<"\nCHOOSE DIFFICULTY LEVEL:";
        SetConsoleTextAttribute(consolez,15);
        cout<<"\n1.Rookie  [3 digits]\n2.Amateur [4 digits]\n3.Pro [5 digits] ";
        cin>>ch2;
        l=ch2+2;
        int g[l];
        int arr[6]={1,2,3,4,5,6};
        randomize (arr, 6);
        SetConsoleTextAttribute(consolez,14);
        cout<<"\t\t\t\tENTER 10 GUESSES\n";
        for(i=0;i<10;++i)
        {   x=0;
            y=0;
            SetConsoleTextAttribute(consolez,14);
            cout<<"\n-----------------------------------------------------------------------------\n";
            SetConsoleTextAttribute(consolez,11);
            cout<<"("<<i+1<<")";
            SetConsoleTextAttribute(consolez,15);
            for(j=0;j<l;++j)
                cin>>g[j];
            for(j=0;j<l;++j)
            {  for(k=0;k<l;++k)
                {   if(g[j]==arr[k])
                    {   if(j==k)
                            x++;
                        else
                            y++;
                        break;
                    }
                }
            }
            SetConsoleTextAttribute(consolez,11);
            for(j=0;j<x;++j)
                cout<<"#";
            for(j=0;j<y;++j)
                cout<<"$";
            if(x==l)
            {   SetConsoleTextAttribute(consolez,10);
                cout<<"\n\nCONGRATULATIONS!    YOU WON!!! \n\n";
                tickets=50-5*i;
                cout<<"\nTickets won = "<<tickets;
                SetConsoleTextAttribute(consolez,15);
                flag=1;
                return tickets;
                //break;
            }
        }
        if(flag==0)
        {   SetConsoleTextAttribute(consolez,12);
            cout<<"\n\nSORRY YOU LOST.BETTER LUCK NEXT TIME.\nCORRECT CODE WAS:\n";
            for(i=0;i<l;++i)
                cout<<arr[i]<<" ";
            SetConsoleTextAttribute(consolez,15);
            tickets=0;
            cout<<"\nTickets won = 0";
            SetConsoleTextAttribute(consolez,15);
            return tickets;

        }
    }
    else
    {   fstream ob;
        ob.open("Instructions.txt",ios::in);
        char ch;
        SetConsoleTextAttribute(consolez,12);
        cout<<"\nINSTRUCTIONS:\n";
        SetConsoleTextAttribute(consolez,15);
        while(!ob.eof())
        {   ob.get(ch);
            cout<<ch;
        }
        ob.close();
        SetConsoleTextAttribute(consolez,12);
        cout<<"\t\t\t^_^   BEST OF LUCK!    ^_^";
        goto j;
    }
    SetConsoleTextAttribute(consolez,10);
    return tickets;
}

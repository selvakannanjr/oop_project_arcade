#include<bits/stdc++.h>
#include<windows.h>
//#include<fstream>
#include<ctime>
#include"Customer.hpp"

using namespace std;

HANDLE consolecu = GetStdHandle(STD_OUTPUT_HANDLE);

Customer :: Customer()
{
    points=0;
    a=0;
    cardd=0;
    rc=0;
}
void Customer :: view()				// Displays the details of customer
{
    SetConsoleTextAttribute(consolecu,15);
    cout<<" Name :  ";
    puts(name);
    cout<<"   Age :   "<<age;
    cout<<"\n   Phone :   "<<phone;
    cout<<"\n   Card selected:   ";
    if(cardd==1)
        cout<<"platinum card(1000)";
    if(cardd==2)
        cout<< "gold card(800)";
    if(cardd==3)
        cout<<"silver card(400)";
    cout<<"\n   Money paid for recharge: "<<rc;
}

void Customer ::  start()					//Welcomes the user
{
    cout<<"\n enter your name    ";
    SetConsoleTextAttribute(consolecu,14);
    cin>>name;
    SetConsoleTextAttribute(consolecu,15);
    cout<<"\n enter your age    ";
    SetConsoleTextAttribute(consolecu,14);
    cin>>age;
    SetConsoleTextAttribute(consolecu,15);
    cout<<"\n enter your phone no    ";
    SetConsoleTextAttribute(consolecu,14);
    cin>>phone;
    SetConsoleTextAttribute(consolecu,15);
    card();
}
void Customer :: card()
{
    cout<<"\n The type of tickets available are";
    SetConsoleTextAttribute(consolecu,15);
    cout<<"\n\n\n\t\t\t 1.PLATINUM     [1000] ";
    SetConsoleTextAttribute(consolecu,14);
    cout<<"\n\n\n\t\t\t 2.GOLD          [800] ";
    SetConsoleTextAttribute(consolecu,7);
    cout<<"\n\n\n\t\t\t 3.SILVER        [400] ";
    cout<<"\nEnter your choice     ";
    int choice;
    cin>>choice;
    cardd=choice;
    SetConsoleTextAttribute(consolecu,15);

    if(choice==1)
    {
        cout<<"\nYou have to pay rupees 1000 for 1000 virtual money (platinum card)";
        points=1000;

    }
    if(choice==2)
    {
        cout<<"\nYou have to pay rupees 800 for 800 virtual money (gold card)";
        points=800;
    }
    if(choice==3)
    {
        cout<<"\nYou have to pay rupees 400 for 400 virtual money (silver card)";
        points=400;
    }
    SetConsoleTextAttribute(consolecu,15);
    option();
}

void Customer :: check()
{
    SetConsoleTextAttribute(consolecu,11);
    cout<<"\n CHECK REPORT ";
    SetConsoleTextAttribute(consolecu,15);
    cout<<"\nPoints left in card are:  "<<points;
    cout<<"\nTickets:  "<<a;
}

void Customer :: recharge()					//For recharging the card
{
    char cho;
    int code;
    SetConsoleTextAttribute(consolecu,12);
    cout<<"\n    WELCOME TO RECHARGE ZONE";
    cout<<"\n";
    SetConsoleTextAttribute(consolecu,5);
    fstream ob;
    ob.open("RechargeMenu.txt",ios::in);
    char ch;
    SetConsoleTextAttribute(consolecu,15);
    while(!ob.eof())
    {
        ob.get(ch);
        cout<<ch;
    }
    ob.close();
    cout<<"\n Do you want to recharge [R] or mortage tickets[M]  ";
    cin>>cho;
    if(cho=='R')
    {
        cout<<"\n Enter the package code   ";
        cin>>code;
        if(code==1)
        {
            points+=50;
            rc+=80;
            cout<<"\n amount to be paid is  "<<80;
            cout<<"\n recharged balance is  "<<50;
        }
        if(code==2)
        {
            points+=150;
            rc+=180;
            cout<<"\n amount to be paid is  "<<180;
            cout<<"\n recharged balance is  "<<150;
        }
        if(code==3)
        {
            points+=250;
            rc+=280;
            cout<<"\n amount to be paid is  "<<280;
            cout<<"\n recharged balance is  "<<250;
        }

    }
    if(cho=='M')
    {
        int tick;
        cout<<"\n current no of tickets are  ";
        cout<<a;
        if(a==0)
        {
            SetConsoleTextAttribute(consolecu,12);
            cout<<"\n No tickets are present to be mortaged";
        }
        else
        {
            SetConsoleTextAttribute(consolecu,15);
            cout<<"\n enter the no of tickets you want to mortage ";
            cin>>tick;
            points+=tick*5;
            a-=tick;
            SetConsoleTextAttribute(consolecu,12);
            cout<<"\n balance is  "<<points;
            cout<<"\n tickets left   "<<a;
        }
    }
}

void Customer :: option()					//Displays the choices to do
{
    int op;
    SetConsoleTextAttribute(consolecu,15);
    cout<<endl;
    cout<<"---------------------------";
    cout<<"\n";
    SetConsoleTextAttribute(consolecu,11);
    cout<<"\n\n\tTHINGS TO DO:";
    cout<<"\n\t\t 1.Mastermind   (price-40 points)";
    cout<<"\n\t\t 2.22 balls     (price-30 points)";
    cout<<"\n\t\t 3.Ultimate Tic Tac Toe [2-player]    (price-50 points)";
    cout<<"\n\t\t 4.Food court";
    cout<<"\n\t\t 5.Gift shop";
    cout<<"\n\t\t 6.Check balance";
    cout<<"\n\t\t 7.Recharge your card";
    cout<<"\n\t\t 8.Exit";
    SetConsoleTextAttribute(consolecu,15);
    cout<<"\nEnter your option   ";
    cin>>op;
    system("cls");
    if(op==1)
    {
        Mastermind ob;
        int r;

        r=ob.playthegame();
        points-=40;
        a+=r;
        option();

    }
    if(op==2)
    {
        Balls ob2;
        int r;
        r=ob2.playthegame();
        points-=30;
        a+=r;
        option();
    }

    if(op==3)
    {
        Ultimate ob3;
        ob3.control();
        points-=50;
        option();
    }

    if(op==4)
    {
        int x;
        x=foodcourt();
        points=points-x;
        option();
    }
    if(op==5)
    {
        int x;
        x=giftshop();
        a-=x;
        option();
    }
    if(op==6)
    {
        check();
        option();
    }
    if(op==7)
    {
        recharge();
        option();
    }
    if(op==8)
    {
        SetConsoleTextAttribute(consolecu,14);
        cout<<"\n THANKS FOR VISITING,HAVE A NICE DAY,COME AGAIN!!!! ";
    }
}

int Customer :: giftshop()						// giftshop
{
    SetConsoleTextAttribute(consolecu,11);
    cout<<"\n\tWELCOME TO THE GIFT SHOP!\n\n";
    SetConsoleTextAttribute(consolecu,12);
    cout<<"CODE\t\tNAME\t\t   PRICE\n";
    SetConsoleTextAttribute(consolecu,15);
    fstream ob;
    ob.open("Giftlist.txt",ios::in);
    char ch;
    while(!ob.eof())
    {
        ob.get(ch);
        cout<<ch;
    }
    ob.close();
    int n=0;
    SetConsoleTextAttribute(consolecu,12);
    cout<<"\nEnter the Number of items you want to buy   ";
    SetConsoleTextAttribute(consolecu,15);
    cin>>n;
    int a[n];
    SetConsoleTextAttribute(consolecu,12);
    label:
    cout<<"\nEnter the code of items you want to buy   ";
    SetConsoleTextAttribute(consolecu,15);
    for(int i=0; i<n; ++i)
    {
        cout<<"\nItem "<<i+1<<" ";
        cin>>a[i];
    }
    int b=0;
    for(int i=0; i<n; ++i)
    {
        if(a[i]==1)
            b+=150;
        if(a[i]==2)
            b+=80;
        if(a[i]==3)
            b+=20;
        if(a[i]==4)
            b+=170;
        if(a[i]==5)
            b+=30;
        if(a[i]==6)
            b+=300;
        if(a[i]==7)
            b+=250;
        if(a[i]==8)
            b+=50;
        if(a[i]==9)
            b+=40;
        if(a[i]==10)
            b+=80;
    }
    if(b>points)
    {
        cout<<"Amount exceeding balance";
        goto label;
    }
    SetConsoleTextAttribute(consolecu,11);
    cout<<"\nYou have bought:\n";
    SetConsoleTextAttribute(consolecu,10);
    for(int i=0; i<n; ++i)
    {
        if(a[i]==1)
            cout<<"\n\tGeometry Box";
        if(a[i]==2)
            cout<<"\n\tPuzzle";
        if(a[i]==3)
            cout<<"\n\tTeddy Bear";
        if(a[i]==4)
            cout<<"\n\tMickey Mouse Pillow";
        if(a[i]==5)
            cout<<"\n\tAvengers Stickers";
        if(a[i]==6)
            cout<<"\n\tMaster Chief's Helmet";
        if(a[i]==7)
            cout<<"\n\tT-Shirt";
        if(a[i]==8)
            cout<<"\n\tBuzz Lightyear Pencil";
        if(a[i]==9)
            cout<<"\n\tLittle Mermaid Locket";
        if(a[i]==10)
            cout<<"\n\tBen10 Watch";
    }
    SetConsoleTextAttribute(consolecu,11);
    cout<<"\n\nTotal Tickets:"<<b;
    SetConsoleTextAttribute(consolecu,15);
    return b;
}

int Customer :: foodcourt()						//Foodcourt
{

    SetConsoleTextAttribute(consolecu,12);
    system("cls");
    cout<<"\n\t\t\t\t    WELCOME TO THE FOODCOURT   ";
    SetConsoleTextAttribute(consolecu,15);
    fstream ob;
    ob.open("Foodcourt.txt",ios::in);
    char ch;
    SetConsoleTextAttribute(consolecu,12);
    cout<<"\n KHANA KHAZANA:\n";
    SetConsoleTextAttribute(consolecu,15);
    while(!ob.eof())
    {
        ob.get(ch);
        cout<<ch;
    }
    ob.close();
    int f,n,total,c=0,d=0;
    err:
    cout<<"\nENTER THE NUMBER OF FOOD ITEMS   ";
    cin>>n;
    int item[n];
    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter your choice  "<< i+1<<":";
        cin>>f;
        if(f==1||f==5||f==6||f==7||f==9||f==12)
        {
            c+=80;
            item[i]=f;
        }
        if(f==2||f==3||f==4||f==8||f==10||f==11||f==13||f==14)
        {
            d+=60;
            item[i]=f;
        }
    }
    if((c+d)>points)
    {
        cout<<"Amount exceeding the balance";
        goto err;
    }
    SetConsoleTextAttribute(consolecu,12);
    cout<<"\n\nBILL ORDER  ";
    SetConsoleTextAttribute(consolecu,10);
    cout<<"\n The items bought are ";
    for(int k=0; k<n; k++)
    {
        if(item[k]==1)
            cout<<"\n\n RAJMA CHAWAL";
        if(item[k]==2)
            cout<<"\n\n CHOLE KULCHE	";
        if(item[k]==3)
            cout<<"\n\n HARA BHARA KEBAB";
        if(item[k]==4)
            cout<<"\n\n HONEY CHILLY POTATO";
        if(item[k]==5)
            cout<<"\n\n FRIED RICE MANCHURIAN";
        if(item[k]==6)
            cout<<"\n\n CHILLY CHICKEN";
        if(item[k]==7)
            cout<<"\n\n BUTTER CHICKEN";
        if(item[k]==8)
            cout<<"\n\n SEEKH KEBAB";
        if(item[k]==9)
            cout<<"\n\n HANDI CHICKEN";
        if(item[k]==10)
            cout<<"\n\n CHICKEN WINGS";
        if(item[k]==11)
            cout<<"\n\n WAFFLES";
        if(item[k]==12)
            cout<<"\n\n PANCAKES";
        if(item[k]==13)
            cout<<"\n\n JALEBI";
        if(item[k]==14)
            cout<<"\n\n BASUNDI";
    }
    total=c+d;
    SetConsoleTextAttribute(consolecu,12);
    cout<<"\n TOTAL BILL "<<total;
    return total;
}

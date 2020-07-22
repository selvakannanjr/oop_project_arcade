#include<bits/stdc++.h>
#include<fstream>
#include<windows.h>
#include"Admin.hpp"
#include"Customer.hpp"

using namespace std;

HANDLE consolemain = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    char ch;
    SetConsoleTextAttribute(consolemain,11);
    cout<<"\n\t\t\t  WELCOME TO ARCADE   ";
    SetConsoleTextAttribute(consolemain,15);
    cout<<"\n\n\n\nARE YOU ADMIN [A] OR CUSTOMER [C]  ";
    cin>>ch;
    if(ch=='a' || ch=='A')
    {
        Admin ad;
        ad.Admin_menu();
        exit(0);
    }
    if(ch=='c' || ch=='C')
    {
        Customer c;
        c.start();
        fstream ob;
        ob.open("CustomerRecord.dat",ios::app|ios::out|ios::binary);
        ob.write((char*)&c,sizeof(c));
        ob.close();
    }
    return 0;
}

#include"Admin.hpp"
#include<fstream>
#include<windows.h>
#include<iostream>

using namespace std;

HANDLE consoleadmin = GetStdHandle(STD_OUTPUT_HANDLE);

Admin::Admin()
{
    countt=0;
}

void Admin::Admin_menu()
{
    cout<<"\n        Enter password    ";
        cin>>pass;
        if(strcmp(pass,"ENTER")==0)
        {
            SetConsoleTextAttribute(consoleadmin,10);
            cout<<"\n ACCESS GRANTED ";
            SetConsoleTextAttribute(consoleadmin,15);
            cout<<"\n 1.DO YOU WANT TO SEE CUSTOMER DETAILS? (y/n)  ";
            cin>>cho;
            if(cho=='y')
            {
                int ctr=0;
                Customer h;
                cout<<"\n THE RECORDS ARE \n";
                fstream ob;
                ob.open("CustomerRecord.dat",ios::in);
                while(ob.read((char*)&h,sizeof(h)))
                {
                    SetConsoleTextAttribute(consoleadmin,10);
                    cout<<"-----------------------------------------------\n";
                    cout<<ctr+1<<".";
                    h.view();
                    cout<<endl;
                    ctr++;
                }
                SetConsoleTextAttribute(consoleadmin,10);
                cout<<"-----------------------------------------------";
                SetConsoleTextAttribute(consoleadmin,9);
                cout<<"\nTotal number of records are:"<<ctr;
                ob.close();
            }
        }
        else
        {
            while(countt<3)
            {
                cout<<"\nTry again   ";
                cout<<"\n Enter password    ";
                cin>>pass;
                if(strcmp(pass,"ENTER")==0)
                {
                    SetConsoleTextAttribute(consoleadmin,10);
                    cout<<"\nACCESS GRANTED";
                    SetConsoleTextAttribute(consoleadmin,15);
                    cout<<"\n 1.DO YOU WANT TO SEE CUSTOMER DETAILS? (y/n)  ";
                    cin>>cho;
                    if(cho=='y')
                    {
                        int ctr=0;
                        Customer h;
                        cout<<"\n THE RECORDS ARE: \n";
                        fstream ob;
                        ob.open("CustomerRecord.dat",ios::in);
                        while(ob.read((char*)&h,sizeof(h)))
                        {
                            SetConsoleTextAttribute(consoleadmin,10);
                            cout<<"-----------------------------------------------\n";
                            cout<<ctr+1<<".";
                            h.view();
                            cout<<endl;
                            ctr++;
                        }
                        SetConsoleTextAttribute(consoleadmin,10);
                        cout<<"-----------------------------------------------";
                        SetConsoleTextAttribute(consoleadmin,9);
                        cout<<"\nTotal number of records are:"<<ctr;
                        ob.close();
                    }
                    break;
                }
                countt++;
            }
            if(countt>2)
            {
                SetConsoleTextAttribute(consoleadmin,12);
                cout<<"\nACCESS DENIED,CONTACT SERVER";
                SetConsoleTextAttribute(consoleadmin,15);
            }
        }
}

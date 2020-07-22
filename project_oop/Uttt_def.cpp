#ifndef UTTT_DEF
#define UTTT_DEF
#include"Uttt.hpp"
#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
using namespace std;

int Ultimate :: win;
int Ultimate :: master[]={0};

Ultimate :: Ultimate()
{
   // master[9] = {0};
    big_pos=0;
    draw=1;
    p_number=0;

}

void Ultimate :: put_struc_in_file()
{
    struct game ob;
    ob.p_number=p_number;
    ob.draw_g=draw;
    ob.shell=big_pos;
    for (int i=0;i<9;i++)
        ob.master_rec[i]=master[i];
    int n,i,j;
    for(n=0; n<9; n++)
    {
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                ob.b[i][j][n]=a[i][j][n];
            }
        }
    }

    ofstream p;
    p.open("Ultimate.dat",ios::binary); //do i have to add multiple saves?

    //if(p==NULL)
     //   cout<<"\nNot created";
    //else
    {
        p.write((char *)&ob,sizeof(ob));
        cout<<"\n**************GAME SUCCESSFULLY SAVED*******\n";
    }
    p.close();
}

void Ultimate :: get_struc_from_file()
{
    struct game ob1;

    ifstream p;

    p.open("Ultimate.dat",ios::binary);
    //if(p==NULL)
       // cout<<"FILE Not created ";
    //else
    {
        p.read((char *)&ob1,sizeof(ob1));
        p_number=ob1.p_number;
        draw=ob1.draw_g;
        big_pos=ob1.shell;
        int n,i,j;
        for(n=0; n<9; n++)
        {
            for(i=0; i<3; i++)
            {
                for(j=0; j<3; j++)
                {
                    a[i][j][n]=ob1.b[i][j][n];
                }
            }
        }
        for(i=0;i<9;i++)
            cout<<" "<<ob1.master_rec[i];
        for(i=0;i<9;i++)
            master[i]=ob1.master_rec[i];
        cout<<"\n******GAME  SUCCESSFULLY LOADED**********\n";
        getch();
    }
    p.close();
}

int Ultimate :: winner()
{
    if(master[0]!=0&&master[0]!=3&&master[0]==master[1]&&master[1]==master[2])
    {
        if (master[0]==1)
            cout<<"\nPlayer 1 wins !";
        else
            cout<<"Player 2 wins !";
        return 1;
    }
    else

        if(master[0]!=0&&master[0]!=3&&master[0]==master[3]&&master[3]==master[6])
        {
            if (master[0]==1)
                cout<<"\nPlayer 1 wins !";
            else
                cout<<"Player 2 wins !";
            return 1;
        }

        else

            if(master[0]!=0&&master[0]!=3&&master[0]==master[4]&&master[4]==master[8])
            {
                if (master[0]==1)
                    cout<<"\nPlayer 1 wins !";
                else
                    cout<<"Player 2 wins !";
                return 1;
            }

            else

                if(master[8]!=0&&master[8]==master[7]&&master[7]==master[6])
                {
                    if (master[8]==1)
                        cout<<"\nPlayer 1 wins !";
                    else
                        cout<<"Player 2 wins !";
                    return 1;
                }

                else

                    if(master[8]!=0&&master[8]==master[5]&&master[5]==master[2])
                    {
                        if (master[8]==1)
                            cout<<"\nPlayer 1 wins !";
                        else
                            cout<<"Player 2 wins !";
                        return 1;
                    }

                    else

                        if(master[3]!=0&&master[3]==master[4]&&master[4]==master[5])
                        {
                            if (master[3]==1)
                                cout<<"\nPlayer 1 wins !";
                            else
                                cout<<"Player 2 wins !";
                            return 1;
                        }

                        else

                            if(master[1]!=0&&master[1]==master[4]&&master[4]==master[7])
                            {
                                if (master[1]==1)
                                    cout<<"\nPlayer 1 wins !";
                                else
                                    cout<<"Player 2 wins !";
                                return 1;
                            }
                            else
                                return 0;

}

void Ultimate :: checkforwin(int x)
{
    if(a[0][0][x]==a[0][1][x]&&a[0][1][x]==a[0][2][x])
    {
        if (a[0][0][x]=='X')
            master[x]=1;
        else
            master[x]=2;
    }
    else if(a[0][0][x]==a[1][0][x]&&a[1][0][x]==a[2][0][x])
    {
        if (a[0][0][x]=='X')
            master[x]=1;
        else
            master[x]=2;
    }
    else if(a[0][0][x]==a[1][1][x]&&a[1][1][x]==a[2][2][x])
    {
        if (a[0][0][x]=='X')
            master[x]=1;
        else
            master[x]=2;
    }
    else if(a[2][2][x]==a[2][1][x]&&a[2][1][x]==a[2][0][x])
    {
        if (a[2][2][x]=='X')
            master[x]=1;
        else
            master[x]=2;
    }
    else if(a[2][2][x]==a[1][2][x]&&a[1][2][x]==a[0][2][x])
    {
        if (a[2][2][x]=='X')
            master[x]=1;
        else
            master[x]=2;
    }
    else if(a[2][0][x]==a[1][1][x]&&a[1][1][x]==a[0][2][x])
    {
        if (a[2][0][x]=='X')
            master[x]=1;
        else
            master[x]=2;
    }
    else if(a[1][0][x]==a[1][1][x]&&a[1][1][x]==a[1][2][x])
    {
        if (a[1][0][x]=='X')
            master[x]=1;
        else
            master[x]=2;
    }
    else if(a[0][1][x]==a[1][1][x]&&a[1][1][x]==a[2][1][x])
    {
        if (a[0][1][x]=='X')
            master[x]=1;
        else
            master[x]=2;
    }
}

void Ultimate :: display()
{

    int i,j,k,n,t=-2,t1=-1,t2=0;
    system("cls");
    cout<<"PLAYER 1 = 'X' \nPLAYER 2 = 'Y'";
    for(n=0; n<9; n+=3)
    {
        t+=3;
        t1+=3;
        t2+=3;
        cout<<"\n\t  "<<t<<"\t  "<<t1<<"\t  "<<t2<<"\n";
        for(i=0; i<3; i++)
        {
            cout<<"\t";
            for(k=n; k<n+3; k++)
            {

                for(j=0; j<3; j++)
                {
                    if(isdigit(a[i][j][k]))
                        cout<<"* ";
                    else cout<<a[i][j][k]<<" ";
                }
                cout<<"\t";
            }
            cout<<"\n";
        }
    }
}

void Ultimate :: put()
{
    char c;
    int n,i,j;
    for(n=0; n<9; n++)
    {
        c='1';
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                a[i][j][n]=c;
                c++;
            }
        }
    }
}

void Ultimate :: check_for_draw(int box_no)
{
    int i,t=0,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(isdigit(a[i][j][box_no]))
            {
                t++;
                break;
            }
        }
    }
    if(t==0)
    {
        master[box_no]=3;
    }
}

int Ultimate :: game_input(int box_number)
{
    int i,j,smallbox_input;         //temp;

    cout<<"\nPLAYER "<<p_number<<" : ";

    // box_number--;

    if(master[box_number]==0)
    {
        int temp = box_number;
m:
        cout<<"\n(PRESS 0 TO SAVE THE GAME)";
        cout<<"\n(Enter 123 to save and exit the game)";
        cout<<"\n(game inn)Enter small box number from : \n";
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                if(isdigit(a[i][j][temp]))
                    cout<<a[i][j][temp];
                cout<<" ";
            }
            cout<<"\n";
        }
        fflush(stdin);
        cin>>smallbox_input;
        if(smallbox_input==0)
        {
            put_struc_in_file();
            goto m;
        }
        if(smallbox_input==123)
        {
            put_struc_in_file();
            return 666;
        }
        if(isdigit(a[(smallbox_input-1)/3][(smallbox_input-1)%3][temp]))
        {
            int s_in = smallbox_input-1;

            if(p_number==1)
            {

                a[(smallbox_input-1)/3][(smallbox_input-1)%3][temp]='X';
                p_number=2;
            }
            else if(p_number==2)
            {
                a[(smallbox_input-1)/3][(smallbox_input-1)%3][temp]='O';
                p_number=1;
            }
            display();
            checkforwin(temp);
            //checkforwin(smallbox_input);
            check_for_draw(temp);
            return s_in;
        }
        else
        {
            cout<<"\nInvalid Input!";
            goto m;
        }
    }
    return big_box_input(p_number);
}

int Ultimate :: big_box_input(int player_number)
{
    cout<<"\n PLAYER - "<<player_number;
    int input_big_box,smallbox_input,i,j;
in:
    cout<<"\n(PRESS 0 TO SAVE THE GAME)";
    cout<<"\nEnter 123 to save and quit game";
    cout<<"\nEnter big box number from : ";
    for(i=0; i<9; i++)
    {
        if(master[i]==0)
            cout<<" "<<i+1<<" ,";
    }
    scanf("%d",&input_big_box);
    if(input_big_box==0)
    {
        put_struc_in_file();
        goto in;
    }

    if(input_big_box==123)
        {
            put_struc_in_file();
            return 666;
        }
    if(input_big_box>0&&input_big_box<10&&master[input_big_box-1]==0)
    {
        int temp = input_big_box-1;
m:
        cout<<"\n(PRESS 0 TO SAVE THE GAME)";
        cout<<"\nEnter 123 to save and quit game";
        cout<<"\n(big inn)Enter small box number from : \n";
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                if(isdigit(a[i][j][temp]))
                    cout<<" "<<a[i][j][temp]<<" ";
            }
            cout<<"\n";
        }
        fflush(stdin);
        cin>>smallbox_input;
        if(smallbox_input==0)
        {
            put_struc_in_file();
            goto m;
        }
        if(smallbox_input==123)
        {
            put_struc_in_file();
            return 666;
        }
        cout<<"\n "<<a[(smallbox_input-1)/3][(smallbox_input-1)%3][temp]<<" \n";
        if(isdigit(a[(smallbox_input-1)/3][(smallbox_input-1)%3][temp]))
        {
            int sb = smallbox_input-1;
            if(player_number==1)
            {

                a[(smallbox_input-1)/3][(smallbox_input-1)%3][temp]='X';
                p_number=2;
            }
            else if(player_number==2)
            {
                a[(smallbox_input-1)/3][(smallbox_input-1)%3][temp]='O';
                p_number=1;
            }
            display();
           // cout<<"\nRETURN sb = %d"<<sb;
            checkforwin(temp);
            check_for_draw(temp);
            return sb;
        }
        else
        {
            cout<<"\nInvalid Input!";
            goto m;
        }

    }
    else
    {
        cout<<"\n Invalid input!";
        goto in;
    }

}

int Ultimate :: menu()
{
    cout<<"\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t $      $       $$$$$$$$$$       $$$$$$$$$       $$$$$$$$$            \n";
    cout<<"\t\t\t\t  $    $        $        $                $      $       $      \n";
    cout<<"\t\t\t\t   $  $         $        $                $      $       $     \n";
    cout<<"\t\t\t\t     $          $        $         $$$$$$$$      $       $      \n";
    cout<<"\t\t\t\t    $  $        $        $         $             $       $     \n";
    cout<<"\t\t\t\t  $     $       $        $         $             $       $     \n";
    cout<<"\t\t\t\t$         $     $$$$$$$$$$  ##     $$$$$$$$$$ ## $$$$$$$$$               \n";
    cout<<"\n\n\n\npress any key to continue:";
    //scanf("%c",&a);
    getch();
    system("cls");
lb2:
    cout<<"\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t1. START GAME\n\n";
    cout<<"\t\t\t\t\t2. RULEZZZZ\n\n";
    cout<<"\t\t\t\t\t3. LOAD GAME\n\n";
    cout<<"\t\t\t\t\t4. EXIT GAME\n\n\n";
    int o;
lb:
    //scanf("%d%*c",&o);
    cin>>o;
    if(o==1)
        return 1;
    else if(o==2)
    {
        cout<<"1. These rules assume you know how to play regular tic tac toe.\n\n";

        cout<<"2. An ultimate tic tac toe board is made up of 9 regular sized tic tac toe boards,\n as shown below. Each regular sized tic tac toe board has 9 cells. I will refer to the location of these boards and cells using compass directions.\n\n";

        cout<<"3. The player who goes first gets to move anywhere on the board.\n\n";

        cout<<"4. In this case, X chose to move in the northwestern corner of one of the smaller boards. \nThis means on the next turn, O is forced to move in the northwestern board.\n\n";
        cout<<"WINNING\n";
        cout<<"\tThe game is won once one of the players gets three in a row.";
        cout<<"\n\n\npress any key to continue...";
        getch();
        system("cls");
        goto lb2;

    }
    else if(o==3)
    {
        get_struc_from_file();
    }
    else if(o==4)
    {
        return 0;
    }
    else
    {
        cout<<"Enter either 1 or 2:";
        goto lb;
    }
    return 0;
}

void Ultimate :: control()
{
    put();

    p_number=1;

    menu();

    display();

    int pos;

    if(big_pos==0)
    big_pos=big_box_input(p_number);        //first seed to initiate game

    do
    {

        cout<<"\nbig box Position = "<<big_pos+1<<"\n";

        pos = game_input(big_pos);
        if (pos==666)
            return;

        win = winner();

        big_pos = pos;

        draw++;
    }
    while(win==0&&draw<81);

    if(draw==81)
        cout<<"\n DRAW !";
    return;
}
#endif // UTTT_DEF

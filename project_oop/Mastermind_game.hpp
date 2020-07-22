#ifndef MASTERMIND_GAME_HPP_INCLUDED
#define MASTERMIND_GAME_HPP_INCLUDED

class Mastermind
{
    int ch1,ch2,l,i,j,k,x,y,flag,tickets;
public:
    Mastermind();
    int playthegame();
    void randomize ( int arr[], int n );
};

#endif // MASTERMIND_GAME_HPP_INCLUDED

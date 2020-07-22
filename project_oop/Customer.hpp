#ifndef CUSTOMER_HPP_INCLUDED
#define CUSTOMER_HPP_INCLUDED
#include"Mastermind_game.hpp"
#include"22balls.hpp"
#include"Uttt.hpp"

class Customer
{

    char name[80];
    int age;
    double phone;
    int a;
    long points;
    int cardd;
    int rc;

public:

    Customer();

    void view();		// Displays the details of customer

    void start();					//Welcomes the user

    void card();

    void check();

    void recharge();     //For recharging the card

    int giftshop();

    int foodcourt();

    void option();					//Displays the choices to do


};

#endif // CUSTOMER_HPP_INCLUDED

/************************************
* CS50 cash.c build                 *
* Purpose: Find how many coins will *
* be needed to give the fewest      *
* amount of coins as possible.      *
* Student: Rick Schroeder           *
*************************************/

//Included libraries
#include <cs50.h>
#include <stdio.h>

//Section for main code
int main(void)
{

    //Declared variables
    int tcoins = 0; //Total number of coins
    int nquarters = 0; //Total number of quarters
    int ndimes = 0; //Total number of dimes
    int nnickels = 0; //Total number of nickels
    int npennies = 0; //Total number of pennies
    float change = get_float("How much Change is owed?\n"); //User input for how much change is owed
    float mquarters = 0; //Total quaters' value
    float mdimes = 0; //Total dimes' value
    float mnickels = 0; //Total nickels' value

    //Start subtracting change
    //Math to calculate the number of quarters
    nquarters = (change / .25);
    mquarters = (nquarters * .25);
    change = (change - mquarters);

    //Math to calculate dimes
    ndimes = (change / .1);
    mdimes = (ndimes * .1);
    change = (change - mdimes);

    //Math to calculate nickels
    nnickels = (change / .05);
    mnickels = (nnickels * .05);
    change = (change - mnickels);

    //Math to calculate pennies
    if (change > 0)
    {
        while (change > 0)
        {
            change = change - .01;
            npennies++;
        }
    }

    //total the number of coins
    tcoins = (nquarters + ndimes + nnickels + npennies);

    //Print Totals
    printf("You will need %i of quarters\n", nquarters);
    printf("You will need %i of dimes\n", ndimes);
    printf("You will need %i of nickels\n", nnickels);
    printf("You will need %i of pennies\n", npennies);
    printf("For a total of %i coins\n", tcoins);

}

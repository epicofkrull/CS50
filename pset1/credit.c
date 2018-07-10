/************************************
* CS50 credit.c build               *
* Purpose: verify if a CC is valid  *
* and what company the card was     *
* issued from.                      *
* Student: Rick Schroeder           *
*************************************/

//included libraries, I added math.h which makes counting the digits
//in the cc number easier
#include <stdio.h>
#include <cs50.h>
#include <math.h>

//Section is for declared variables and functions
long long cc;
int count = 0;
void cc_company(long long ccn);
bool checksum(long long ccn, int len);
int length(long long n);
bool lengthchecksum(int len);
void check_card(long long ccn);



//Section for the main code
int main(void)
{
    do
    {
        //get the credit card number making sure its not negative
        cc = get_long_long("Please enter your Credit Card Number: ");
    }
    while (cc < 0); //Verify the number is not negative

    //Pass the CC number to the check card function
    check_card(cc);
}

//Check_card function to verify the math for the checksum works out
//and the lenght of the card numbers is a valid card number length
//if the card appears valid it will find the card manufacturer
void check_card(long long ccn)
{
    int len = length(ccn);
    if (!(lengthchecksum(len)) || checksum(ccn, len))
    {
        printf("INVALID\n");
        return;
    }
    //If the card is valid it will pass the number to find out the manufacturer
    cc_company(ccn);

}

//The hard way to find the length of the number without the math.h library
int length(long long n)
{
    while(n != 0)
    {
        n /= 10;
        ++count;
    }
    return count;
}

//True or False checksum to see if the length of the card matches one of the manufacturer's
bool lengthchecksum(int len)
{
    if (len == 13 || len == 15 || len == 16)
        return true;
    return false;
}

//True or False checksum to see the Luhn's algorithm works out

//// THIS MATH IS WRONG FIGURE IT OUT
bool checksum(long long ccn, int len)
{
    int total = 0;
    int a, b;

    for (int i = 0; i < (len+1); i++)
    {
        //evens
        if (i % 2 == 0)
        {
            a = (ccn % 10);
            ccn /=10;
            total += a;
        }
        //odds
        else
        {
            b = (ccn %10);
            ccn /= 10;
            b = b * 2;
            total += ((b / 10)+(b % 10));
        }

    }

    //check if the end digit is 0
    if (total % 10 == 0)
        return false;
    return true;
}

//Function to find out what manufacturer made the card, this uses the
// math.h library for pow and log10 to seperate the first character and
//the first two characters plus the length of the cc number
void cc_company(long long ccn)
{
    int firstdigit, secdigit, len;

    len = log10(ccn);

    firstdigit = ccn / pow(10, len);
    secdigit = ccn / pow(10, (len - 1));


    //If card starts with 4 and is 13 or 16 digits = Visa
    if ((len == 12 || len == 15) && (firstdigit == 4))
    {
        printf("VISA\n");
    }
    //If card starts with 51,52,53,54,55 and 16 digits = Mastercard
    else if (len == 15 && secdigit >= 51 && secdigit <= 55)
    {
        printf("MASTERCARD\n");
    }
    //If card starts with 34 or 37 and 15 digits = American Express
    else if ((secdigit == 34 || secdigit == 37) && len == 14)
    {
        printf("AMEX\n");
    }
    else
        printf("INVALID\n");
}

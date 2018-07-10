/**************************************
* CS50 mario.c less comfortable build *
* Purpose: To build a mario pyrimad   *
* as tall as the user's input         *
* between a height of 1 and 23        *
* Student: Rick Schroeder             *
***************************************/

//included libraries
#include <cs50.h>
#include <stdio.h>

//Section for the main code
int main(void)
{
    int h;

    //Ask user how tall they want the pyrimad must answer between 1-23
    do
    {
        printf("How many blocks tall do yo want your pyramid?\n");
        h = get_int("(Choose a number between 1 and 23)\n");
    }
    while (h < 1 || h > 23);

    //Declare the needed variables
    int s = (h - 1), p = 2;
    char space = ' ', hashtag = '#', newline = '\n';

    //Looping the spaces and # sign
    for (int i = 0; i < h; i++)
    {
        for (int a = s; a > 0; a--)
        {
            putchar(space);
        }
        for (int b = p; b > 0; b--)
        {
            putchar(hashtag);
        }
        putchar(newline);
        s--;
        p++;
    }
}

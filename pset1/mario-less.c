#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a,j;
    do
    {
        a=get_int("Number: ");
    }while(a>8 || a<=0); //input a valid number
    for(int i=1; i<=a; i++)
    {
        for(j=0; j<a-i; j++) //add the number of spaces necessary
        printf(" ");
        for(j=0; j<i; j++) //add hashes to give the required mario effect
        printf("#");
        printf("\n"); //add a new line to build the different layers of the pyramid
    }
}
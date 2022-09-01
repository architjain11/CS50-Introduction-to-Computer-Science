#include<cs50.h>
#include<stdio.h>
#include<math.h>

int main(void)
{
    float change;
    do
    {
        change=100*get_float("Change owed: ");  
    }while(change<0);
    change=round(change); //get the round off value of change owed
    int coins=0;
    while(change>=25) //get number of quarters coins needed
    {
        change-=25;
        coins++;
    }
    while(change>=10) //get number of dimes coins needed
    {
        change-=10;
        coins++;
    }
    while(change>=5) //get number of nickels coins needed
    {
        change-=5;
        coins++;
    }
    while(change>=1) //get number of pennis coins needed
    {
        change-=1;
        coins++;
    }  
    printf("%i\n", coins); //output the number of coins needed ATQ
}
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a, j;
    do
    {
        a=get_int("Height: ");
    } while(a<=0 || a>8); //input height between required numbers
    for(int i=1; i<=a; i++)
    {
        for(j=0; j<a-i; j++) 
            printf(" ");//print spaces before the hashes
        int flag=0;
        while(flag<2)
        {
            for(j=0; j<i; j++)
                printf("#"); //print the hashes as required
            if(flag==0)
                printf("  "); //add the gap between the two pyramids
            flag++;
        }
        printf("\n");
    }
}
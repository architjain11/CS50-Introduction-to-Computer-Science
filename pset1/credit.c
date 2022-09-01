#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int flag=1,nod=1; //nod stands for number of digits
    long int num=get_long("Number: "); //input credit card number
    long int a=num;
    while(flag) //find the number of digits in the number
    {
        if(a/10!=0)
        {
            nod++;
            a/=10;
        }
        else
            flag=0;
    }
    a=num;
    int sum=0,x; 
    for(int i=nod; i>0; i--) //checksum is being applied
    {
        if(flag==0)
        {
            sum+=a%10;
            a/=10;
            flag=1;
        }
        else
        {
            x=2*(a%10);
            if(x/10==0)
                sum+=x;
            else
            {
                sum+=(x%10);
                x/=10;
                sum+=x;
            }
            a/=10;
            flag=0;
        }
    }
    a=num;
    if(sum%10==0)
    {
        for(int i=nod; i>2; i--) //the variable a stores the first two digits of the number
            a/=10;
        if(nod==15 && (a==34 || a==37)) //determines the type of credit card
            printf("AMEX\n");
        else if(nod==16 && (a>=51 && a<=55))
            printf("MASTERCARD\n");
        else if((nod==16 || nod==13) && a/10==4)
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");
}
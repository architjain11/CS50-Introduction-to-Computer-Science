#include <cs50.h>
#include <stdio.h>
#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./Caesar key\n");
        return 1;
    }
    for(int i=0; argv[1][i]!='\0'; i++)
    {
        if(!isdigit(argv[1][i]))
        {
            printf("Usage: ./Caesar key\n");
            return 1;
        }
    }

    int key=atoi(argv[1]);
    string plain=get_string("plaintext: ");
    for(int i=0; plain[i]!='\0'; i++)
    {
        if(isalpha(plain[i]))
        {
            if(isupper(plain[i]))
            {
                plain[i]=65+(plain[i]+key-65)%26;
            }
            else
            {
                plain[i]=97+(plain[i]+key-97)%26;
            }
        }
    }
    printf("ciphertext: %s\n",plain);
}
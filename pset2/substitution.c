#include<cs50.h>
#include<stdio.h>
#include<ctype.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./Substitution key\n");
        return 1;
    }
    if(argv[1][26]!='\0')
    {
        printf("26 Characters must be there\n");
        return 1;
    }
    for(int i=0; i<26; i++)
    {
        if(isalpha(argv[1][i]))
        {
            if(islower(argv[1][i]))
                argv[1][i]=toupper(argv[1][i]);
        }
        else
        {
             printf("Only alphabets can be entered\n");
             return 1;
        }
    }
    for(int i=0; i<25; i++)
        for(int j=i+1; j<26; j++)
            if(argv[1][i]==argv[1][j])
            {
                 printf("Each alphabet should appear only once\n");
                 return 1;
            }
    string plain=get_string("plaintext: ");
    for(int i=0; plain[i]!='\0'; i++)
    {
        if(isalpha(plain[i]))
        {
            int j;
            if(islower(plain[i]))
                j=plain[i]%97;
            else
                j=plain[i]%65;
            char k=argv[1][j];
            if(islower(plain[i]))
                k+=32;
            plain[i]=k;
        }
    }
    printf("ciphertext: %s\n", plain);
}
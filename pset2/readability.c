#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

int main(void)
{
    string a=get_string("Text: ");
    float l=0, s=0, w=0, flag=0;
    for(int i=0; a[i]!='\0'; i++)
    {
        if(a[i]==' ')
            flag=0;
        if(isalpha(a[i]))
        {
            if(flag==0)
            {
                w++;
                flag=1;
            }
            l++;
        }
        if(a[i]=='.' || a[i]=='!' || a[i]=='?')
            s++;
    }
    l=(l/w)*100;
    s=(s/w)*100;
    float index=0.0588*l-0.296*s-15.8;
    index=round(index);
    if(index>16)
        printf("Grade 16+\n");
    else if(index<1)
        printf("Before Grade 1\n");
    else
        printf("Grade %i\n", (int)index);
}




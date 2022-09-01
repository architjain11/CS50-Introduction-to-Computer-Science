#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *f=fopen("card.raw","r");
    if(f==NULL)
        return 1;
    BYTE *buffer=malloc(512);
    int a=fread(buffer, 1, 512, f);
    int i=0;
    int flag=0;
    while(a>=512)
    {
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0)==0xe0)
        {
            i++;
            char *newfile=malloc(10);
            sprintf(newfile, "%03i.jpg", i-1);
            FILE *img=fopen(newfile, "a");
            fwrite(buffer, 1, 512, img);
            fclose(img);
            free(newfile);
        }
        else if(i>0)
        {
            char *newfile=malloc(10);
            sprintf(newfile, "%03i.jpg", i-1);
            FILE *img=fopen(newfile, "a");
            fwrite(buffer, 1, 512, img);
            fclose(img);
            free(newfile);
        }

        a=fread(buffer, 1, 512, f);
    }
    fclose(f);
    free(buffer);
    return 0;
}

#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            float avg=((float)image[i][j].rgbtRed+image[i][j].rgbtBlue+image[i][j].rgbtGreen)/3;
            int new=round(avg);
            image[i][j].rgbtRed=new;
            image[i][j].rgbtGreen=new;
            image[i][j].rgbtBlue=new;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            float r=image[i][j].rgbtRed;
            float g=image[i][j].rgbtGreen;
            float b=image[i][j].rgbtBlue;

            int x=round((0.393*r)+(0.769*g)+(0.189*b));
            if(x>255)
                x=255;
            image[i][j].rgbtRed=x;

            int y=round((0.349*r)+(0.686*g)+(0.168*b));
            if(y>255)
                y=255;
            image[i][j].rgbtGreen=y;

            int z=round((0.272*r)+(0.534*g)+(0.131*b));
            if(z>255)
                z=255;
            image[i][j].rgbtBlue=z;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tmp;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width/2; j++)
        {
            tmp=image[i][j].rgbtRed;
            image[i][j].rgbtRed=image[i][width-1-j].rgbtRed;
            image[i][width-1-j].rgbtRed=tmp;

            tmp=image[i][j].rgbtGreen;
            image[i][j].rgbtGreen=image[i][width-1-j].rgbtGreen;
            image[i][width-1-j].rgbtGreen=tmp;

            tmp=image[i][j].rgbtBlue;
            image[i][j].rgbtBlue=image[i][width-1-j].rgbtBlue;
            image[i][width-1-j].rgbtBlue=tmp;
        }
    }
    return;
}
/*
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new[height][width];
    for(int i=1; i<height-1; i++)
    {
        for(int j=1; j<width-1; j++)
        {
            new[i][j].rgbtRed=round((float)(image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i+1][j].rgbtRed+image[i][j-1].rgbtRed+image[i][j+1].rgbtRed+image[i-1][j+1].rgbtRed+image[i+1][j-1].rgbtRed+image[i+1][j+1].rgbtRed+image[i-1][j-1].rgbtRed)/9);
            new[i][j].rgbtGreen=round((float)(image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i+1][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i][j+1].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i+1][j+1].rgbtGreen+image[i-1][j-1].rgbtGreen)/9);
            new[i][j].rgbtBlue=round((float)(image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i+1][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i][j+1].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i+1][j+1].rgbtBlue+image[i-1][j-1].rgbtBlue)/9);
        }

        int j=0;
        new[i][j].rgbtRed=round((float)(image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i+1][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j+1].rgbtRed+image[i-1][j+1].rgbtRed)/6);
        new[i][j].rgbtGreen=round((float)(image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i+1][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j+1].rgbtGreen+image[i-1][j+1].rgbtGreen)/6);
        new[i][j].rgbtBlue=round((float)(image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i+1][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j+1].rgbtBlue+image[i-1][j+1].rgbtBlue)/6);

        j=width-1;
        new[i][j].rgbtRed=round((float)(image[i][j].rgbtRed+image[i-1][j].rgbtRed+image[i+1][j].rgbtRed+image[i-1][j-1].rgbtRed+image[i+1][j-1].rgbtRed+image[i][j-1].rgbtRed)/6);
        new[i][j].rgbtGreen=round((float)(image[i][j].rgbtGreen+image[i-1][j].rgbtGreen+image[i+1][j].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i+1][j-1].rgbtGreen+image[i][j-1].rgbtGreen)/6);
        new[i][j].rgbtBlue=round((float)(image[i][j].rgbtBlue+image[i-1][j].rgbtBlue+image[i+1][j].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i+1][j-1].rgbtBlue+image[i][j-1].rgbtBlue)/6);

    }
    for(int j=1; j<width-1; j++)
    {
        int i=0;
        new[i][j].rgbtRed=round((float)(image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j+1].rgbtRed+image[i+1][j-1].rgbtRed)/6);
        new[i][j].rgbtGreen=round((float)(image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j+1].rgbtGreen+image[i+1][j-1].rgbtGreen)/6);
        new[i][j].rgbtBlue=round((float)(image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j+1].rgbtBlue+image[i+1][j-1].rgbtBlue)/6);

        i=height-1;
        new[i][j].rgbtRed=round((float)(image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j-1].rgbtRed+image[i-1][j+1].rgbtRed+image[i][j+1].rgbtRed)/6);
        new[i][j].rgbtGreen=round((float)(image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j-1].rgbtGreen+image[i-1][j+1].rgbtGreen+image[i][j+1].rgbtGreen)/6);
        new[i][j].rgbtBlue=round((float)(image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j-1].rgbtBlue+image[i-1][j+1].rgbtBlue+image[i][j+1].rgbtBlue)/6);
     }

    int i=0;
    int j=0;
    new[0][0].rgbtRed=round((float)(image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j+1].rgbtRed)/4);
    new[0][0].rgbtBlue=round((float)(image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j+1].rgbtBlue)/4);
    new[0][0].rgbtGreen=round((float)(image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j+1].rgbtGreen)/4);

    i=height-1;
    j=width-1;
    new[i][j].rgbtRed=round((float)(image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j-1].rgbtRed)/4);
    new[i][j].rgbtBlue=round((float)(image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j-1].rgbtBlue)/4);
    new[i][j].rgbtGreen=round((float)(image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j-1].rgbtGreen)/4);

    i=0;
    j=width-1;
    new[0][j].rgbtRed=round((float)(image[i][j].rgbtRed+image[i][j-1].rgbtRed+image[i+1][j].rgbtRed+image[i+1][j-1].rgbtRed)/4);
    new[0][j].rgbtBlue=round((float)(image[i][j].rgbtBlue+image[i][j-1].rgbtBlue+image[i+1][j].rgbtBlue+image[i+1][j-1].rgbtBlue)/4);
    new[0][j].rgbtGreen=round((float)(image[i][j].rgbtGreen+image[i][j-1].rgbtGreen+image[i+1][j].rgbtGreen+image[i+1][j-1].rgbtGreen)/4);

    i=height-1;
    j=0;
    new[i][0].rgbtRed=round((float)(image[i][j].rgbtRed+image[i][j+1].rgbtRed+image[i-1][j].rgbtRed+image[i-1][j+1].rgbtRed)/4);
    new[i][0].rgbtBlue=round((float)(image[i][j].rgbtBlue+image[i][j+1].rgbtBlue+image[i-1][j].rgbtBlue+image[i-1][j+1].rgbtBlue)/4);
    new[i][0].rgbtGreen=round((float)(image[i][j].rgbtGreen+image[i][j+1].rgbtGreen+image[i-1][j].rgbtGreen+image[i-1][j+1].rgbtGreen)/4);

    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
            image[i][j]=new[i][j];
    }
    return;
} 
*/

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{   RGBTRIPLE cpy[height][width];

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            cpy[i][j].rgbtRed=image[i][j].rgbtRed;
            cpy[i][j].rgbtBlue=image[i][j].rgbtBlue;
            cpy[i][j].rgbtGreen=image[i][j].rgbtGreen;
        }
    }
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
           if(i==0&&j==0)
           {
               image[i][j].rgbtRed=round((float)(cpy[i][j].rgbtRed+cpy[i][j+1].rgbtRed+cpy[i+1][j].rgbtRed+cpy[i+1][j+1].rgbtRed)/4.0);
               image[i][j].rgbtBlue=round((float)(cpy[i][j].rgbtBlue+cpy[i][j+1].rgbtBlue+cpy[i+1][j].rgbtBlue+cpy[i+1][j+1].rgbtBlue)/4.0);
               image[i][j].rgbtGreen=round((float)(cpy[i][j].rgbtGreen+cpy[i][j+1].rgbtGreen+cpy[i+1][j].rgbtGreen+cpy[i+1][j+1].rgbtGreen)/4.0);
           }
          else if(i==0&&j==width-1)
          {
               image[i][j].rgbtRed=round((float)(cpy[i][j].rgbtRed+cpy[i][j-1].rgbtRed+cpy[i+1][j].rgbtRed+cpy[i+1][j-1].rgbtRed)/4.0);
               image[i][j].rgbtBlue=round((float)(cpy[i][j].rgbtBlue+cpy[i][j-1].rgbtBlue+cpy[i+1][j].rgbtBlue+cpy[i+1][j-1].rgbtBlue)/4.0);
               image[i][j].rgbtGreen=round((float)(cpy[i][j].rgbtGreen+cpy[i][j-1].rgbtGreen+cpy[i+1][j].rgbtGreen+cpy[i+1][j-1].rgbtGreen)/4.0);

          }
          else if(i==height-1&&j==0)
           {
               image[i][j].rgbtRed=round((float)(cpy[i][j].rgbtRed+cpy[i][j+1].rgbtRed+cpy[i-1][j].rgbtRed+cpy[i-1][j+1].rgbtRed)/4.0);
               image[i][j].rgbtBlue=round((float)(cpy[i][j].rgbtBlue+cpy[i][j+1].rgbtBlue+cpy[i-1][j].rgbtBlue+cpy[i-1][j+1].rgbtBlue)/4.0);
               image[i][j].rgbtGreen=round((float)(cpy[i][j].rgbtGreen+cpy[i][j+1].rgbtGreen+cpy[i-1][j].rgbtGreen+cpy[i-1][j+1].rgbtGreen)/4.0);
           }
          else if(i==height-1&&j==width-1)
           {
               image[i][j].rgbtRed=round((float)(cpy[i][j].rgbtRed+cpy[i][j-1].rgbtRed+cpy[i-1][j].rgbtRed+cpy[i-1][j-1].rgbtRed)/4.0);
               image[i][j].rgbtBlue=round((float)(cpy[i][j].rgbtBlue+cpy[i][j-1].rgbtBlue+cpy[i-1][j].rgbtBlue+cpy[i-1][j-1].rgbtBlue)/4.0);
               image[i][j].rgbtGreen=round((float)(cpy[i][j].rgbtGreen+cpy[i][j-1].rgbtGreen+cpy[i-1][j].rgbtGreen+cpy[i-1][j-1].rgbtGreen)/4.0);
           }
          else if(i==0&&(j>0&&j<width-1))
           {
               image[i][j].rgbtRed=round((float)(cpy[i][j].rgbtRed+cpy[i][j+1].rgbtRed+cpy[i][j-1].rgbtRed+cpy[i+1][j].rgbtRed+cpy[i+1][j+1].rgbtRed+cpy[i+1][j-1].rgbtRed)/6.0);
               image[i][j].rgbtBlue=round((float)(cpy[i][j].rgbtBlue+cpy[i][j+1].rgbtBlue+cpy[i][j-1].rgbtBlue+cpy[i+1][j].rgbtBlue+cpy[i+1][j+1].rgbtBlue+cpy[i+1][j-1].rgbtBlue)/6.0);
               image[i][j].rgbtGreen=round((float)(cpy[i][j].rgbtGreen+cpy[i][j+1].rgbtGreen+cpy[i][j-1].rgbtGreen+cpy[i+1][j].rgbtGreen+cpy[i+1][j+1].rgbtGreen+cpy[i+1][j-1].rgbtGreen)/6.0);
           }
          else if(i==height-1&&(j>0&&j<width-1))
           {
               image[i][j].rgbtRed=round((float)(cpy[i][j].rgbtRed+cpy[i][j+1].rgbtRed+cpy[i][j-1].rgbtRed+cpy[i-1][j].rgbtRed+cpy[i-1][j+1].rgbtRed+cpy[i-1][j-1].rgbtRed)/6.0);
               image[i][j].rgbtBlue=round((float)(cpy[i][j].rgbtBlue+cpy[i][j+1].rgbtBlue+cpy[i][j-1].rgbtBlue+cpy[i-1][j].rgbtBlue+cpy[i-1][j+1].rgbtBlue+cpy[i-1][j-1].rgbtBlue)/6.0);
               image[i][j].rgbtGreen=round((float)(cpy[i][j].rgbtGreen+cpy[i][j+1].rgbtGreen+cpy[i][j-1].rgbtGreen+cpy[i-1][j].rgbtGreen+cpy[i-1][j+1].rgbtGreen+cpy[i-1][j-1].rgbtGreen)/6.0);
           }
          else if(j==0&&(i>0&&i<height-1))
           {
               image[i][j].rgbtRed=round((float)(cpy[i][j].rgbtRed+cpy[i][j+1].rgbtRed+cpy[i+1][j].rgbtRed+cpy[i+1][j+1].rgbtRed+cpy[i-1][j].rgbtRed+cpy[i-1][j+1].rgbtRed)/6.0);
               image[i][j].rgbtBlue=round((float)(cpy[i][j].rgbtBlue+cpy[i][j+1].rgbtBlue+cpy[i+1][j].rgbtBlue+cpy[i+1][j+1].rgbtBlue+cpy[i-1][j].rgbtBlue+cpy[i-1][j+1].rgbtBlue)/6.0);
               image[i][j].rgbtGreen=round((float)(cpy[i][j].rgbtGreen+cpy[i][j+1].rgbtGreen+cpy[i+1][j].rgbtGreen+cpy[i+1][j+1].rgbtGreen+cpy[i-1][j].rgbtGreen+cpy[i-1][j+1].rgbtGreen)/6.0);
           }
          else if(j==width-1&&(i>0&&i<height-1))
           {
               image[i][j].rgbtRed=round((float)(cpy[i][j].rgbtRed+cpy[i][j-1].rgbtRed+cpy[i+1][j].rgbtRed+cpy[i+1][j-1].rgbtRed+cpy[i-1][j].rgbtRed+cpy[i-1][j-1].rgbtRed)/6.0);
               image[i][j].rgbtBlue=round((float)(cpy[i][j].rgbtBlue+cpy[i][j-1].rgbtBlue+cpy[i+1][j].rgbtBlue+cpy[i+1][j-1].rgbtBlue+cpy[i-1][j].rgbtBlue+cpy[i-1][j-1].rgbtBlue)/6.0);
               image[i][j].rgbtGreen=round((float)(cpy[i][j].rgbtGreen+cpy[i][j-1].rgbtGreen+cpy[i+1][j].rgbtGreen+cpy[i+1][j-1].rgbtGreen+cpy[i-1][j].rgbtGreen+cpy[i-1][j-1].rgbtGreen)/6.0);
           }
          else
           {
               image[i][j].rgbtRed=round((float)(cpy[i][j].rgbtRed+cpy[i][j-1].rgbtRed+cpy[i][j+1].rgbtRed+cpy[i+1][j].rgbtRed+cpy[i+1][j-1].rgbtRed+cpy[i+1][j+1].rgbtRed+cpy[i-1][j].rgbtRed+cpy[i-1][j-1].rgbtRed+cpy[i-1][j+1].rgbtRed)/9.0);
               image[i][j].rgbtBlue=round((float)(cpy[i][j].rgbtBlue+cpy[i][j-1].rgbtBlue+cpy[i][j+1].rgbtBlue+cpy[i+1][j].rgbtBlue+cpy[i+1][j+1].rgbtBlue+cpy[i+1][j-1].rgbtBlue+cpy[i-1][j].rgbtBlue+cpy[i-1][j+1].rgbtBlue+cpy[i-1][j-1].rgbtBlue)/9.0);
               image[i][j].rgbtGreen=round((float)(cpy[i][j].rgbtGreen+cpy[i][j-1].rgbtGreen+cpy[i][j+1].rgbtGreen+cpy[i+1][j].rgbtGreen+cpy[i+1][j+1].rgbtGreen+cpy[i+1][j-1].rgbtGreen+cpy[i-1][j].rgbtGreen+cpy[i-1][j+1].rgbtGreen+cpy[i-1][j-1].rgbtGreen)/9.0);
           }

        }

    }

    return;
}
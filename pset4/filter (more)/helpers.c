#include "helpers.h"
#include <math.h>

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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new[height][width];

    for(int i=1; i<height-1; i++)
    {
        for(int j=1; j<width-1; j++)
        {
            float gx = ((-2)*image[i][j-1].rgbtRed) + (2*image[i][j+1].rgbtRed) + image[i-1][j+1].rgbtRed - image[i+1][j-1].rgbtRed + image[i+1][j+1].rgbtRed - image[i-1][j-1].rgbtRed;
            float gy = (2*image[i+1][j].rgbtRed) - image[i-1][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j+1].rgbtRed - image[i-1][j-1].rgbtRed - (2*image[i-1][j].rgbtRed);
            int n=round(sqrtf(powf(gx,2)+powf(gy,2)));
            new[i][j].rgbtRed = n<255 ? n : 255;

            gx = ((-2)*image[i][j-1].rgbtGreen) + (2*image[i][j+1].rgbtGreen) + image[i-1][j+1].rgbtGreen - image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen - image[i-1][j-1].rgbtGreen;
            gy = (2*image[i+1][j].rgbtGreen) - image[i-1][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen - image[i-1][j-1].rgbtGreen - (2*image[i-1][j].rgbtGreen);
            n=round(sqrtf(powf(gx,2)+powf(gy,2)));
            new[i][j].rgbtGreen = n<255 ? n : 255;

            gx = ((-2)*image[i][j-1].rgbtBlue) + (2*image[i][j+1].rgbtBlue) + image[i-1][j+1].rgbtBlue - image[i+1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue - image[i-1][j-1].rgbtBlue;
            gy = (2*image[i+1][j].rgbtBlue) - image[i-1][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue - image[i-1][j-1].rgbtBlue - (2*image[i-1][j].rgbtBlue);
            n=round(sqrtf(powf(gx,2)+powf(gy,2)));
            new[i][j].rgbtBlue = n<255 ? n : 255;
        }

        int j=0;
        float gx = (2*image[i][j+1].rgbtRed) + image[i+1][j+1].rgbtRed + image[i-1][j+1].rgbtRed;
        float gy = ((-2)*image[i-1][j].rgbtRed) + (2*image[i+1][j].rgbtRed) + image[i+1][j+1].rgbtRed - image[i-1][j+1].rgbtRed;
        int n=round(sqrtf(powf(gx,2)+powf(gy,2)));
        new[i][j].rgbtRed = n<255 ? n : 255;

        gx = (2*image[i][j+1].rgbtGreen) + image[i+1][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen;
        gy = ((-2)*image[i-1][j].rgbtGreen) + (2*image[i+1][j].rgbtGreen) + image[i+1][j+1].rgbtGreen - image[i-1][j+1].rgbtGreen;
        n=round(sqrtf(powf(gx,2)+powf(gy,2)));
        new[i][j].rgbtGreen = n<255 ? n : 255;

        gx = (2*image[i][j+1].rgbtBlue) + image[i+1][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue;
        gy = ((-2)*image[i-1][j].rgbtBlue) + (2*image[i+1][j].rgbtBlue) + image[i+1][j+1].rgbtBlue - image[i-1][j+1].rgbtBlue;
        n=round(sqrtf(powf(gx,2)+powf(gy,2)));
        new[i][j].rgbtBlue = n<255 ? n : 255;

        j=width-1;
        gx = -image[i-1][j-1].rgbtRed - image[i+1][j-1].rgbtRed + ((-2)*image[i][j-1].rgbtRed);
        gy = ((-2)*image[i-1][j].rgbtRed) + (2*image[i+1][j].rgbtRed) - image[i-1][j-1].rgbtRed + image[i+1][j-1].rgbtRed;
        n=round(sqrtf(powf(gx,2)+powf(gy,2)));
        new[i][j].rgbtRed = n<255 ? n : 255;

        gx = -image[i-1][j-1].rgbtGreen - image[i+1][j-1].rgbtGreen + ((-2)*image[i][j-1].rgbtGreen);
        gy = ((-2)*image[i-1][j].rgbtGreen) + (2*image[i+1][j].rgbtGreen) - image[i-1][j-1].rgbtGreen + image[i+1][j-1].rgbtGreen;
        n=round(sqrtf(powf(gx,2)+powf(gy,2)));
        new[i][j].rgbtGreen = n<255 ? n : 255;

        gx = -image[i-1][j-1].rgbtBlue - image[i+1][j-1].rgbtBlue + ((-2)*image[i][j-1].rgbtBlue);
        gy = ((-2)*image[i-1][j].rgbtBlue) + (2*image[i+1][j].rgbtBlue) - image[i-1][j-1].rgbtBlue + image[i+1][j-1].rgbtBlue;
        n=round(sqrtf(powf(gx,2)+powf(gy,2)));
        new[i][j].rgbtBlue = n<255 ? n : 255;
    }

    for(int j=1; j<width-1; j++)
    {
        int i=0;
        float gx = ((-2)*image[i][j-1].rgbtRed) + (2*image[i][j+1].rgbtRed) + image[i+1][j+1].rgbtRed - image[i+1][j-1].rgbtRed;
        float gy = (2*image[i+1][j].rgbtRed) + image[i+1][j+1].rgbtRed + image[i+1][j-1].rgbtRed;
        int n = round(sqrtf(powf(gx,2)+powf(gy,2)));
        new[i][j].rgbtRed = n<255 ? n : 255;

        gx = ((-2)*image[i][j-1].rgbtGreen) + (2*image[i][j+1].rgbtGreen) + image[i+1][j+1].rgbtGreen - image[i+1][j-1].rgbtGreen;
        gy = (2*image[i+1][j].rgbtGreen) + image[i+1][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen;
        n = round(sqrtf(powf(gx,2)+powf(gy,2)));
        new[i][j].rgbtGreen = n<255 ? n : 255;

        gx = ((-2)*image[i][j-1].rgbtBlue) + (2*image[i][j+1].rgbtBlue) + image[i+1][j+1].rgbtBlue - image[i+1][j-1].rgbtBlue;
        gy = (2*image[i+1][j].rgbtBlue) + image[i+1][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue;
        n = round(sqrtf(powf(gx,2)+powf(gy,2)));
        new[i][j].rgbtBlue = n<255 ? n : 255;

        i=height-1;
        gx = ((-2)*image[i][j-1].rgbtRed) - image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed + (2*image[i][j+1].rgbtRed);
        gy = ((-2)*image[i-1][j].rgbtRed) - image[i-1][j-1].rgbtRed - image[i-1][j+1].rgbtRed;
        n = round(sqrtf(powf(gx,2)+powf(gy,2)));
        new[i][j].rgbtRed = n<255 ? n : 255;

        gx = ((-2)*image[i][j-1].rgbtGreen) - image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen + (2*image[i][j+1].rgbtGreen);
        gy = ((-2)*image[i-1][j].rgbtGreen) - image[i-1][j-1].rgbtGreen - image[i-1][j+1].rgbtGreen;
        n = round(sqrtf(powf(gx,2)+powf(gy,2)));
        new[i][j].rgbtGreen = n<255 ? n : 255;

        gx = ((-2)*image[i][j-1].rgbtBlue) - image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue + (2*image[i][j+1].rgbtBlue);
        gy = ((-2)*image[i-1][j].rgbtBlue) - image[i-1][j-1].rgbtBlue - image[i-1][j+1].rgbtBlue;
        n = round(sqrtf(powf(gx,2)+powf(gy,2)));
        new[i][j].rgbtBlue = n<255 ? n : 255;
    }

    int i=0;
    int j=0;
    float gx = (2*image[i][j+1].rgbtRed) + image[i+1][j+1].rgbtRed;
    float gy = (2*image[i+1][j].rgbtRed) + image[i+1][j+1].rgbtRed;
    int n = round(sqrtf(powf(gx,2)+powf(gy,2)));
    new[0][0].rgbtRed = n<255 ? n : 255;

    gx = (2*image[i][j+1].rgbtGreen) + image[i+1][j+1].rgbtGreen;
    gy = (2*image[i+1][j].rgbtGreen) + image[i+1][j+1].rgbtGreen;
    n = round(sqrtf(powf(gx,2)+powf(gy,2)));
    new[0][0].rgbtGreen = n<255 ? n : 255;

    gx = (2*image[i][j+1].rgbtBlue) + image[i+1][j+1].rgbtBlue;
    gy = (2*image[i+1][j].rgbtBlue) + image[i+1][j+1].rgbtBlue;
    n = round(sqrtf(powf(gx,2)+powf(gy,2)));
    new[0][0].rgbtBlue = n<255 ? n : 255;


    i=height-1;
    j=width-1;
    gx = ((-2)*image[i][j-1].rgbtRed) - image[i-1][j-1].rgbtRed;
    gy = ((-2)*image[i-1][j].rgbtRed) - image[i-1][j-1].rgbtRed;
    n = round(sqrtf(powf(gx,2)+powf(gy,2)));
    new[i][j].rgbtRed = n<255 ? n : 255;

    gx = ((-2)*image[i][j-1].rgbtGreen) - image[i-1][j-1].rgbtGreen;
    gy = ((-2)*image[i-1][j].rgbtGreen) - image[i-1][j-1].rgbtGreen;
    n = round(sqrtf(powf(gx,2)+powf(gy,2)));
    new[i][j].rgbtGreen = n<255 ? n : 255;


    gx = ((-2)*image[i][j-1].rgbtBlue) - image[i-1][j-1].rgbtBlue;
    gy = ((-2)*image[i-1][j].rgbtBlue) - image[i-1][j-1].rgbtBlue;
    n = round(sqrtf(powf(gx,2)+powf(gy,2)));
    new[i][j].rgbtBlue = n<255 ? n : 255;



    i=0;
    j=width-1;
    gx = ((-2)*image[i][j-1].rgbtRed) - image[i+1][j-1].rgbtRed;
    gy = (2*image[i+1][j].rgbtRed) + image[i+1][j-1].rgbtRed;
    n = round(sqrtf(powf(gx,2)+powf(gy,2)));
    new[0][j].rgbtRed = n<255 ? n : 255;

    gx = ((-2)*image[i][j-1].rgbtGreen) - image[i+1][j-1].rgbtGreen;
    gy = (2*image[i+1][j].rgbtGreen) + image[i+1][j-1].rgbtGreen;
    n = round(sqrtf(powf(gx,2)+powf(gy,2)));
    new[0][j].rgbtGreen = n<255 ? n : 255;

    gx = ((-2)*image[i][j-1].rgbtBlue) - image[i+1][j-1].rgbtBlue;
    gy = (2*image[i+1][j].rgbtBlue) + image[i+1][j-1].rgbtBlue;
    n = round(sqrtf(powf(gx,2)+powf(gy,2)));
    new[0][j].rgbtBlue = n<255 ? n : 255;


    i=height-1;
    j=0;
    gx = (2*image[i][j+1].rgbtRed) + image[i-1][j+1].rgbtRed;
    gy = ((-2)*image[i-1][j].rgbtRed) - image[i-1][j+1].rgbtRed;
    n = round(sqrtf(powf(gx,2)+powf(gy,2)));
    new[i][0].rgbtRed = n<255 ? n : 255;

    gx = (2*image[i][j+1].rgbtGreen) + image[i-1][j+1].rgbtGreen;
    gy = ((-2)*image[i-1][j].rgbtGreen) - image[i-1][j+1].rgbtGreen;
    n = round(sqrtf(powf(gx,2)+powf(gy,2)));
    new[i][0].rgbtGreen = n<255 ? n : 255;

    gx = (2*image[i][j+1].rgbtBlue) + image[i-1][j+1].rgbtBlue;
    gy = ((-2)*image[i-1][j].rgbtBlue) - image[i-1][j+1].rgbtBlue;
    n = round(sqrtf(powf(gx,2)+powf(gy,2)));
    new[i][0].rgbtBlue = n<255 ? n : 255;

    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
            image[i][j]=new[i][j];
    }
    return;
}

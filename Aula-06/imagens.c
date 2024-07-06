#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uchar;

typedef struct{
    uchar r;
    uchar g;
    uchar b;
} Pixel;

typedef struct{
    int width;
    int height;
    Pixel *pixels;
    //Pixel **mpixels;
} Image;


Image alocImage(int width, int height)
{
    Image img;
    img.width = width;
    img.height = height;
    img.pixels = (Pixel *)malloc(width * height * sizeof(Pixel));
    return img;
}

Image geraImagem(int width, int height)
{
    Image img = alocImage(width, height);
    int faixa = width / 3;
    
    for (int i = 0; i < height; i++)
    {
        int iL = i * width;
        for(int j = 0; j < faixa; j++)
        {
            int cor = (int) (256 * ((float)j / faixa));
            img.pixels[iL + j].r = cor;
            img.pixels[iL + j].g = 0;
            img.pixels[iL + j].b = 0;

            img.pixels[iL + j + faixa].r = 0;
            img.pixels[iL + j + faixa].g = cor;
            img.pixels[iL + j + faixa].b = 0;

            img.pixels[iL + j + 2*faixa].r = 0;
            img.pixels[iL + j + 2*faixa].g = 0;
            img.pixels[iL + j + 2*faixa].b = cor;
        }
        
    }
    return img;
}

void printPixel(Pixel p)
{
    printf("(%d, %d, %d)\n", p.r, p.g, p.b);
}   

int main(void)
{
    Image img = geraImagem(600, 400);
    for (int j = 0; j < img.width; j++)
    {
        printPixel(img.pixels[200*img.width + j]);
    }
    return 0;
}
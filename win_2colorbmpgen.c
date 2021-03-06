#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SKY_START 0
#define LAND_START 32512

typedef unsigned char byte;

int i;
byte sky_colors = 3;
byte land_colors = 3;

/*Used to generate images*/
byte file_ch_write;
byte color_typed[2];
byte sky_col[1] =
{
    0x43,0x22
};
byte land_col[1] =
{
    0x65,0x42
};
/*1077 Bytes header*/
byte bmp_header[1077] =
{
    0x42,0x4D,0x36,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x36,0x04,0x00,0x00,0x28,0x00,0x00,0x00,
    0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x01,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x80,0x00,0x80,0x00,
    0x00,0x00,0x80,0x00,0x80,0x00,0x80,0x80,0x00,0x00,0xC0,0xC0,0xC0,0x00,0xC0,0xDC,0xC0,0x00,
    0xF0,0xCA,0xA6,0x00,0x00,0x20,0x40,0x00,0x00,0x20,0x60,0x00,0x00,0x20,0x80,0x00,0x00,0x20,
    0xA0,0x00,0x00,0x20,0xC0,0x00,0x00,0x20,0xE0,0x00,0x00,0x40,0x00,0x00,0x00,0x40,0x20,0x00,
    0x00,0x40,0x40,0x00,0x00,0x40,0x60,0x00,0x00,0x40,0x80,0x00,0x00,0x40,0xA0,0x00,0x00,0x40,
    0xC0,0x00,0x00,0x40,0xE0,0x00,0x00,0x60,0x00,0x00,0x00,0x60,0x20,0x00,0x00,0x60,0x40,0x00,
    0x00,0x60,0x60,0x00,0x00,0x60,0x80,0x00,0x00,0x60,0xA0,0x00,0x00,0x60,0xC0,0x00,0x00,0x60,
    0xE0,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x20,0x00,0x00,0x80,0x40,0x00,0x00,0x80,0x60,0x00,
    0x00,0x80,0x80,0x00,0x00,0x80,0xA0,0x00,0x00,0x80,0xC0,0x00,0x00,0x80,0xE0,0x00,0x00,0xA0,
    0x00,0x00,0x00,0xA0,0x20,0x00,0x00,0xA0,0x40,0x00,0x00,0xA0,0x60,0x00,0x00,0xA0,0x80,0x00,
    0x00,0xA0,0xA0,0x00,0x00,0xA0,0xC0,0x00,0x00,0xA0,0xE0,0x00,0x00,0xC0,0x00,0x00,0x00,0xC0,
    0x20,0x00,0x00,0xC0,0x40,0x00,0x00,0xC0,0x60,0x00,0x00,0xC0,0x80,0x00,0x00,0xC0,0xA0,0x00,
    0x00,0xC0,0xC0,0x00,0x00,0xC0,0xE0,0x00,0x00,0xE0,0x00,0x00,0x00,0xE0,0x20,0x00,0x00,0xE0,
    0x40,0x00,0x00,0xE0,0x60,0x00,0x00,0xE0,0x80,0x00,0x00,0xE0,0xA0,0x00,0x00,0xE0,0xC0,0x00,
    0x00,0xE0,0xE0,0x00,0x40,0x00,0x00,0x00,0x40,0x00,0x20,0x00,0x40,0x00,0x40,0x00,0x40,0x00,
    0x60,0x00,0x40,0x00,0x80,0x00,0x40,0x00,0xA0,0x00,0x40,0x00,0xC0,0x00,0x40,0x00,0xE0,0x00,
    0x40,0x20,0x00,0x00,0x40,0x20,0x20,0x00,0x40,0x20,0x40,0x00,0x40,0x20,0x60,0x00,0x40,0x20,
    0x80,0x00,0x40,0x20,0xA0,0x00,0x40,0x20,0xC0,0x00,0x40,0x20,0xE0,0x00,0x40,0x40,0x00,0x00,
    0x40,0x40,0x20,0x00,0x40,0x40,0x40,0x00,0x40,0x40,0x60,0x00,0x40,0x40,0x80,0x00,0x40,0x40,
    0xA0,0x00,0x40,0x40,0xC0,0x00,0x40,0x40,0xE0,0x00,0x40,0x60,0x00,0x00,0x40,0x60,0x20,0x00,
    0x40,0x60,0x40,0x00,0x40,0x60,0x60,0x00,0x40,0x60,0x80,0x00,0x40,0x60,0xA0,0x00,0x40,0x60,
    0xC0,0x00,0x40,0x60,0xE0,0x00,0x40,0x80,0x00,0x00,0x40,0x80,0x20,0x00,0x40,0x80,0x40,0x00,
    0x40,0x80,0x60,0x00,0x40,0x80,0x80,0x00,0x40,0x80,0xA0,0x00,0x40,0x80,0xC0,0x00,0x40,0x80,
    0xE0,0x00,0x40,0xA0,0x00,0x00,0x40,0xA0,0x20,0x00,0x40,0xA0,0x40,0x00,0x40,0xA0,0x60,0x00,
    0x40,0xA0,0x80,0x00,0x40,0xA0,0xA0,0x00,0x40,0xA0,0xC0,0x00,0x40,0xA0,0xE0,0x00,0x40,0xC0,
    0x00,0x00,0x40,0xC0,0x20,0x00,0x40,0xC0,0x40,0x00,0x40,0xC0,0x60,0x00,0x40,0xC0,0x80,0x00,
    0x40,0xC0,0xA0,0x00,0x40,0xC0,0xC0,0x00,0x40,0xC0,0xE0,0x00,0x40,0xE0,0x00,0x00,0x40,0xE0,
    0x20,0x00,0x40,0xE0,0x40,0x00,0x40,0xE0,0x60,0x00,0x40,0xE0,0x80,0x00,0x40,0xE0,0xA0,0x00,
    0x40,0xE0,0xC0,0x00,0x40,0xE0,0xE0,0x00,0x80,0x00,0x00,0x00,0x80,0x00,0x20,0x00,0x80,0x00,
    0x40,0x00,0x80,0x00,0x60,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0xA0,0x00,0x80,0x00,0xC0,0x00,
    0x80,0x00,0xE0,0x00,0x80,0x20,0x00,0x00,0x80,0x20,0x20,0x00,0x80,0x20,0x40,0x00,0x80,0x20,
    0x60,0x00,0x80,0x20,0x80,0x00,0x80,0x20,0xA0,0x00,0x80,0x20,0xC0,0x00,0x80,0x20,0xE0,0x00,
    0x80,0x40,0x00,0x00,0x80,0x40,0x20,0x00,0x80,0x40,0x40,0x00,0x80,0x40,0x60,0x00,0x80,0x40,
    0x80,0x00,0x80,0x40,0xA0,0x00,0x80,0x40,0xC0,0x00,0x80,0x40,0xE0,0x00,0x80,0x60,0x00,0x00,
    0x80,0x60,0x20,0x00,0x80,0x60,0x40,0x00,0x80,0x60,0x60,0x00,0x80,0x60,0x80,0x00,0x80,0x60,
    0xA0,0x00,0x80,0x60,0xC0,0x00,0x80,0x60,0xE0,0x00,0x80,0x80,0x00,0x00,0x80,0x80,0x20,0x00,
    0x80,0x80,0x40,0x00,0x80,0x80,0x60,0x00,0x80,0x80,0x80,0x00,0x80,0x80,0xA0,0x00,0x80,0x80,
    0xC0,0x00,0x80,0x80,0xE0,0x00,0x80,0xA0,0x00,0x00,0x80,0xA0,0x20,0x00,0x80,0xA0,0x40,0x00,
    0x80,0xA0,0x60,0x00,0x80,0xA0,0x80,0x00,0x80,0xA0,0xA0,0x00,0x80,0xA0,0xC0,0x00,0x80,0xA0,
    0xE0,0x00,0x80,0xC0,0x00,0x00,0x80,0xC0,0x20,0x00,0x80,0xC0,0x40,0x00,0x80,0xC0,0x60,0x00,
    0x80,0xC0,0x80,0x00,0x80,0xC0,0xA0,0x00,0x80,0xC0,0xC0,0x00,0x80,0xC0,0xE0,0x00,0x80,0xE0,
    0x00,0x00,0x80,0xE0,0x20,0x00,0x80,0xE0,0x40,0x00,0x80,0xE0,0x60,0x00,0x80,0xE0,0x80,0x00,
    0x80,0xE0,0xA0,0x00,0x80,0xE0,0xC0,0x00,0x80,0xE0,0xE0,0x00,0xC0,0x00,0x00,0x00,0xC0,0x00,
    0x20,0x00,0xC0,0x00,0x40,0x00,0xC0,0x00,0x60,0x00,0xC0,0x00,0x80,0x00,0xC0,0x00,0xA0,0x00,
    0xC0,0x00,0xC0,0x00,0xC0,0x00,0xE0,0x00,0xC0,0x20,0x00,0x00,0xC0,0x20,0x20,0x00,0xC0,0x20,
    0x40,0x00,0xC0,0x20,0x60,0x00,0xC0,0x20,0x80,0x00,0xC0,0x20,0xA0,0x00,0xC0,0x20,0xC0,0x00,
    0xC0,0x20,0xE0,0x00,0xC0,0x40,0x00,0x00,0xC0,0x40,0x20,0x00,0xC0,0x40,0x40,0x00,0xC0,0x40,
    0x60,0x00,0xC0,0x40,0x80,0x00,0xC0,0x40,0xA0,0x00,0xC0,0x40,0xC0,0x00,0xC0,0x40,0xE0,0x00,
    0xC0,0x60,0x00,0x00,0xC0,0x60,0x20,0x00,0xC0,0x60,0x40,0x00,0xC0,0x60,0x60,0x00,0xC0,0x60,
    0x80,0x00,0xC0,0x60,0xA0,0x00,0xC0,0x60,0xC0,0x00,0xC0,0x60,0xE0,0x00,0xC0,0x80,0x00,0x00,
    0xC0,0x80,0x20,0x00,0xC0,0x80,0x40,0x00,0xC0,0x80,0x60,0x00,0xC0,0x80,0x80,0x00,0xC0,0x80,
    0xA0,0x00,0xC0,0x80,0xC0,0x00,0xC0,0x80,0xE0,0x00,0xC0,0xA0,0x00,0x00,0xC0,0xA0,0x20,0x00,
    0xC0,0xA0,0x40,0x00,0xC0,0xA0,0x60,0x00,0xC0,0xA0,0x80,0x00,0xC0,0xA0,0xA0,0x00,0xC0,0xA0,
    0xC0,0x00,0xC0,0xA0,0xE0,0x00,0xC0,0xC0,0x00,0x00,0xC0,0xC0,0x20,0x00,0xC0,0xC0,0x40,0x00,
    0xC0,0xC0,0x60,0x00,0xC0,0xC0,0x80,0x00,0xC0,0xC0,0xA0,0x00,0xF0,0xFB,0xFF,0x00,0xA4,0xA0,
    0xA0,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0xFF,0x00,
    0xFF,0x00,0x00,0x00,0xFF,0x00,0xFF,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xFF
};

void write_bmp_header(FILE *stream,const char* filename)
{
    stream = fopen(filename,"w+b");
    for(i = 0; i < 1077; i++)
    {
        fwrite(&bmp_header[i],1,1,stream);
    }
    fclose(stream);
    return;
}

void write_bmp(FILE *stream,const char* filename)
{
    write_bmp_header(stream,filename);
    stream = fopen(filename,"ab");
    for(i = 0; i < 65025; i++)
    {
        /*Lets decide*/
        if(i < LAND_START)
        {
            fwrite(&color_typed[0],1,1,stream);
        }
        if(i > LAND_START)
        {
            fwrite(&color_typed[1],1,1,stream);
        }
    }
    fclose(stream);
    return;
}

FILE *fp;

int main()
{
    printf("Hello, type in a color (in ASCII) and i will make a 2 colored bitmap for you!\n");
    scanf("%c%*c",&color_typed[0]);
    printf("type the second color\n");
    scanf("%c%*c",&color_typed[1]);
    write_bmp(fp,"test.bmp");
    return 0;
}

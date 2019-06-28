#include <stdio.h>
#include <conio.h>
#include <dos.h>

typedef unsigned char byte;

char *buffer;
signed int carTrack;
byte yTrack;
byte xTrack;
signed int t;
signed int a;
signed int c;
signed int d;

signed int cl;

signed char * token;
signed char delim = ' ';

FILE *fp;

void setcol(byte c1, byte c2)
{
	textcolor(c1);
	textbackground(c2);
}

int main(void)
{
	fp = fopen("UNAMED.C","w");
	clrscr();
	buffer = (char *)malloc(80*25);
	if(buffer == NULL)
	{
		return 0;
	}
	for(t = 0; t < 80*25; t++)
	{
		buffer[t] = 0;
	}
	carTrack = 0;
	yTrack = 1;
	for(;;)
	{
		cl = 0;
		setcol(0xF,0x0);
		t = 0; c = 0;
		for(a = 0; a < carTrack; a++)
		{
			gotoxy(c+4,t+1);
			if(buffer[a] == 13 || c > 80-4)
			{
				t++;
				c = 0;
				gotoxy(c+4,t+1);
			}
			if(buffer[a] == 8)
			{
				buffer[a] = 0;
				buffer[a-1] = 0;
				c -= 2;
				carTrack -= 2;
				cprintf("  ");
				gotoxy(c+3,t+1);
			}
			/*Cprintf is reported to not support newlines*/
			else
			{
				cprintf("%c",buffer[a]);
				c++;
			}
		}
		for(a = 1; a < 25; a++)
		{
			if(a != t+1)
			{
				setcol(0x0,0xB);
			}
			else
			{
				setcol(0x0,0xF);
			}
			gotoxy(1,a);
			cprintf("%d:",a);
			if(a < 10)
			{
				cprintf(" ");
			}
			else
			{
				/*Do nothing*/
			}
		}
		buffer[carTrack] = getch();
		if(buffer[carTrack] == 0x1B)
		{
			for(t = 0; t < carTrack; t++)
			{
				if(buffer[t] == '\n'||buffer[t] < 32)
				{
					fprintf(fp,"\n");
				}
				else
				{
					fprintf(fp,"%c",buffer[t]);
				}
			}
			fclose(fp);
			return 0;
		}
		if(carTrack < 0)
		{
			carTrack = 0;
		}
		if(xTrack > 80-3)
		{
			yTrack++;
			xTrack = 0;
		}
		xTrack++;
		carTrack++;
	}
}


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

unsigned char *ptr = (unsigned char*)0x0C030;
unsigned int i,u;

void play_sound(unsigned char tone)
{
  for(i = 0; i < tone; i++)
  {
    /*Assign tone to the ptr, so the speaker "receives it"*/
    *ptr = i;
  }
}

int main (void)
{
  printf("Test Fu");
  for(;;)
  {
  	for(u = 0; u < 128; u++)
  	{
  	  play_sound(u);
  	}
   	 for(u = 128; u > 0; u--)
  	{
  	  play_sound(u);
  	}
    for(u = 128; u > 0; u--)
  	{
  	  play_sound(u);
  	}
    for(u = 128; u > 0; u--)
  	{
  	  play_sound(u);
  	}
  }
  return EXIT_SUCCESS;
}


#include <stdlib.h>
#include <stdio.h>
//#include <ctype.h>
#include <conio.h>
#include <apple2.h>

#define true 1
#define false 0

#define uint8 char

// Graphics
#define BackbufferSetPage1 0xc054
#define BackbufferSetPage2 0xc055
#define BackbufferHiRes 0xc057
#define UseGraphicsMode 0xC050
#define UseTextMode 0xc051

#define Poke(addr) __asm__("sta %w", addr)





#include "HelloWorld.h"
#include "ScreenClear.h"



int main (void)
{
  
  HelloWorld();
  //ScreenClear();
  
  cgetc();
  
  return EXIT_SUCCESS;
}

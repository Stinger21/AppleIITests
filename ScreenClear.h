



void ScreenClear(void)
{
  
  
  uint8 line;
  uint8 x;
  uint8* block;
  uint8 eighthLineCounter;
  
  uint8 AA;
  uint8 BBB;
  uint8 CC;
  uint8 AA_mask;
  uint8 BBB_mask;
  uint8 CC_mask;
  
  Poke(BackbufferSetPage1);
  Poke(BackbufferHiRes);
  Poke(UseGraphicsMode);
  //Poke(UseTextMode);
  
  // Clear
  block = (uint8*)0x2000;
  while(block != (uint8*)0x4000)
  {
    *block = 0;
    block++;
  }
  
  
  
  line = 0;
  while(line <= 191)
  {
    line++;
    
    AA_mask = 0xC0;  // 11000000
    BBB_mask = 0x38; // 00111000
    CC_mask = 0x7;   // 00000111

    AA  = (line & AA_mask) >> 6;
    BBB = (line & BBB_mask) >> 3;
    CC  = (line & CC_mask) >> 0;
    block = (uint8*)(0x2000 + (AA * 0x0028) + (BBB * 0x0080) + (CC * 0x0400) + x);
    
    while(x < 0x28)
    {
      *block = 255;
      x++;
      block++;
    }
    block -= 0x28;
    x = 0;
  }
  
  x = 0;
  eighthLineCounter = 0;
  
  //// Coerce wozniaks fucking cancer computer to draw a raster pattern.
  //line = 0;
  //x = 0;
  //block = (uint8*)0x2000;
  //eighthLineCounter = 0;
  //
  //while(line <= 191)
  //{
  //   while(x < 0x28)
  //   {
  //     *block = 255;
  //     // set byte color (7 pixels)
  //     x++;
  //     block++; // This brings us to 0x27
  //   }
  //   block -= 0x28;
  //  
  //  eighthLineCounter++;
  //  if(eighthLineCounter == 8)
  //  {
  //    block -= 0x1B80;
  //    block -= 0x400;
  //    eighthLineCounter = 0;
  //  }
  //  
  //  if(line == 63)
  //  {
  //    block = (uint8*)0x2028;
  //  }
  //    
  //  if(line == 127)
  //  {
  //    block = (uint8*)0x2050;
  //  }
  //  
  //  if(line == 63 || line == 127) // Magic bullshit lines where we 
  //  {
  //    //block -= 0x1FA7;
  //    //block += 0x28;
  //  }
  //  else
  //  {
  //    block += 0x400; // This gets us to the next line
  //  }
  //  
  //  x = 0;
  //  line++;
  //  
  //}
  
  
}
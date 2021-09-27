


void HelloWorld(void)
{
    printf("\n Hello world!");
  
  while(true)
  {
    uint8 c = cgetc();
    printf(&c);
  }
}
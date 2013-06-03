#include <stdlib.h>
#include <stdio.h>

#include "buffer.h"

/* Genny's main method. Fills a buffer with odd numbers, starting with 5, 
 * continuing alternatingly with +2 and +4; e.g. 5, 7, 11, 13, 17, 19, 23, 25.*/
void* generate(void* arg)
{
  buffer* B = (buffer*) arg;
  unsigned long x = 5;
  char coin = 0;
  
  while (IsRunning)
  {
    x += 2 + 2 * coin;
    while (IsRunning && !add(B, x))
    {
      yield();
    }
    //printf("\tGenny: \t%lu\n", x);
    coin = !coin;
  }
  
  return NULL;
}

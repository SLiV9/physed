#include <stdlib.h>
#include <stdio.h>

#include "buffer.h"

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

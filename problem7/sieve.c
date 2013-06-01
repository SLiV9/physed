#include <stdlib.h>
#include <stdio.h>

#include "buffer.h"
#include "sieve.h"

char sieveit(buffer* B)
{
  unsigned long x;
  char dirty = 0;
  
  if ((x = B->next->extra))
  {
    if (add(B->next, x))
    {
      B->next->extra = 0;
      dirty = 1;
    }
  }
  
  if ((B->next->extra == 0) && (x = get(B)))
  {
    dirty = 1;
    if (1 || x % B->prime != 0)
    {
      B->next->extra = x;
    }
  }
  
  return dirty;
}

void* sieve(void* arg)
{
  buffer* B = (buffer*) arg;
  buffer* b;
  char dirty;
  
  printf("\t[%lu] \tHello!\n", B->prime);
  
  while (IsRunning)
  {
    b = B;
    dirty = 0;
    
    while (b && b->prime)
    {
      printf("\t[%lu] \t#%lu.\n", B->prime, b->prime);
      dirty = (sieveit(b) || dirty);
      for (int i = 0; i < NTHREADS; i++)
      {
        b = b->next;
        if (!(b && b->prime))
          break;
      }
    }
    
    if (!dirty)
    {
      printf("\t[%lu] \t...\n", B->prime);
      yield();
    }
  }
  
  return NULL;
}

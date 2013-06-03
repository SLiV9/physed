#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "buffer.h"
#include "sieve.h"

/* Tries to add one number from the extra slot to the next buffer.
 * Tries to take one number from the buffer; if it is not divisible by the 
 * prime, puts it in the extra slot. */
void sieveit(buffer* B)
{
  unsigned long x;
  
  if ((x = B->extra))
  {
    if (add(B->next, x))
    {
      B->extra = 0;
    }
  }
  
  if ((B->extra == 0) && (x = get(B)))
  {
    if (x % B->prime != 0)
    {
      B->extra = x;
    }
  }
}

/* The sieve's main method. Keeps sieving numbers from its buffers to their 
 * next buffers. */
void* sieve(void* arg)
{
  buffer* B = (buffer*) arg;
  buffer* b;
  
  printf("\t[%lu] \tHello!\n", B->prime);
  
  while (IsRunning)
  {
    b = B;
    
    while (b && b->prime)
    {
      //printf("\t[%lu] \t#%lu#\n", B->prime, b->prime);
      sieveit(b);
      
      for (int i = 0; i < NTHREADS; i++)
      {
        b = b->next;
        if (!(b && b->prime))
          break;
      }
    }
    
    yield();
  }
  
  return NULL;
}

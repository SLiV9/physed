#include <stdlib.h>
#include <stdio.h>

#include "buffer.h"

/* The main thread method. */
int main(int argc, char** argv)
{
  printf("[ Eratosthenes Sieve ]\n\n\n");
  
  buffer* b = init_buffer();
  
  add(b, 2);
  add(b, 5);
  printf("%lu\n", get(b));
  printf("%lu\n", get(b));
  printf("%lu\n", get(b));
  
  free_buffer(b);
  
  printf("\n\n[ done ]\n");
}

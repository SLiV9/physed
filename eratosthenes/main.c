#include <stdlib.h>
#include <stdio.h>

#include "sieve.h"

/* The main thread method. */
int main(int argc, char** argv)
{
  printf("[ Eratosthenes Sieve ]\n\n\n");
  
  init_sieve();
  start();
  end();
  free_sieve();
  
  printf("\n\n[ done ]\n");
}

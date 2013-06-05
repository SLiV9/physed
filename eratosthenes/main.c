#include <stdlib.h>
#include <stdio.h>

#include "sieve.h"

#define PRIME_INDEX 10

/* The main thread method. */
int main(int argc, char** argv)
{
  printf("[ Eratosthenes Sieve ]\n\n\n");
  
  unsigned long last_prime;
  
  init_sieve();
  start();
  
  for (int i = 1; i < PRIME_INDEX; i++)
  {
    while ((last_prime = get_prime()) == BUSY);
    advance(last_prime);
  }
  
  end();
  free_sieve();
  
  printf("The 10th prime is %lu.\n", last_prime);
  
  printf("\nPrimes:\n");
  for (int i = 0; i < PRIME_INDEX; i++)
  {
    printf("\t%lu", prime[i]);
  }
  
  printf("\n\n[ done ]\n");
}

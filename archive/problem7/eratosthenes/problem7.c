#include <stdlib.h>
#include <stdio.h>

#include "sieve.h"

#define PRIME_INDEX 10001

/* The main thread method. */
int main(int argc, char** argv)
{
  printf("[ Eratosthenes Sieve ]\n\n\n");
  
  unsigned long last_prime;
  
  init_sieve();
  
  printf("Primes:\n");
  start();
  for (int i = 1; i < PRIME_INDEX; i++)
  {
    while ((last_prime = get_prime()) == BUSY);
    printf(" %lu \t", last_prime);
    advance();
  }
  end();
  printf("\n");
  
  free_sieve();
  
  printf("The 10th prime is %lu.\n", last_prime);
  
  printf("\n\n[ done ]\n");
}

#include <stdlib.h>
#include <stdio.h>

#include "sieve.h"

#define PRIME_INDEX 1000000

/* The main thread method. */
int main(int argc, char** argv)
{
  printf("[ Eratosthenes Sieve ]\n\n\n");
  
  unsigned long last_prime;
  unsigned long long total = 2;
  
  init_sieve();
  
  printf("Primes: \t2\n");
  start();
  for (int i = 1; i < PRIME_INDEX; i++)
  {
    while ((last_prime = get_prime()) == BUSY);
    if (last_prime >= 2000000)
    {
      break;
    }
    
    printf(" %lu \t", last_prime);
    total += last_prime;
    advance();
  }
  end();
  printf("\n");
  
  free_sieve();
  
  printf("The sum of primes below 2000000 is %llu.\n", total);
  
  printf("\n\n[ done ]\n");
}

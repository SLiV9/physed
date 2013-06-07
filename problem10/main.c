#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bitmap.h"

#define VAL(D) (2*D + 3)
#define ID(V) ((V-3) / 2)

typedef unsigned long natural;

natural get_next_prime(unsigned int d)
{
  for (unsigned int u = d; u < ID(1999999); u++)
  {
    if (!getbit(u))
    {
      return VAL(u);
    }
  }
  
  return 0;
}

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem 10 ]\n\n\n");
    
    natural total = 2;
    printf("Primes:\t2\n");
    
    natural next_prime;
    natural prime_index = 0;
    while ((next_prime = get_next_prime(prime_index)))
    {
      total += next_prime;
      printf("%lu \t", next_prime);
      prime_index = ID(next_prime) + 1;
    }
    printf("end.\n\n");
    
    printf("Total: %lu.\n", total);

    printf("\n\n[ done ]\n");

    return 0;
}

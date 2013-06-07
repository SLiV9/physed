#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bitmap.h"

#define CLEAN 0
#define NOTPRIME 1

#define VAL(D) (2*D + 3)
#define ID(V) ((V-3) / 2)

typedef unsigned long natural;

/* Find the next prime number by finding the next non-dirty bit. */
natural get_next_prime(unsigned int d)
{
  for (unsigned int u = d; u <= ID(1999999); u++)
  {
    if (getbit(u) != NOTPRIME)
    {
      return VAL(u);
    }
  }
  
  return 0;
}

/* We want to mark multiples of p as dirty: i.e. setbit(2p), setbit(3p), ...
 * However, 2p % 2 == 0, so we only need 3p, 5p, 7p, 9p, ...
 * ID((2k+1)p) = ((2kp+p-3)/2) = kp + ((p-3)/2) = kp + ID(p), for k = 1, 2, ...
 * This is how we find the following for-loop. */
void filter(natural p)
{
  for (unsigned int u = ID(p) + p; u <= ID(1999999); u += p)
  {
    setbit(u, NOTPRIME);
  }
}

/* Our main method. */
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
      filter(next_prime);
      prime_index = ID(next_prime) + 1;
    }
    printf("end.\n\n");
    
    printf("Total: %lu.\n", total);

    printf("\n\n[ done ]\n");

    return 0;
}

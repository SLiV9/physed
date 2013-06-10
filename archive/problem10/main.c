#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bitmap.h"

#define CLEAN 0
#define NOTPRIME 1

#define VAL(D) (2*D + 3)
#define ID(V) ((V-3) / 2)

#define MAXID ID(1999999)

typedef unsigned long natural;

/* We want to mark multiples of p as dirty: i.e. setbit(2p), setbit(3p), ...
 * However, 2p % 2 == 0, so we only need 3p, 5p, 7p, 9p, ...
 * ID((2k+1)p) = ((2kp+p-3)/2) = kp + ((p-3)/2) = kp + ID(p), for k = 1, 2, ...
 * This is how we find the following for-loop. */
void filter(natural p)
{
  for (unsigned int u = ID(p) + p; u <= MAXID; u += p)
  {
    setbit(u, NOTPRIME);
  }
}

/* Our main method. */
int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem 10 ]\n\n\n");
    
    natural total = 2;
    //printf("Primes:\t2\n");
    clear_bitmap();
    
    natural next_prime;
    natural prime_index = 0;
    while ((prime_index = find(prime_index, CLEAN)) <= MAXID)
    {
      next_prime = VAL(prime_index);
      
      total += next_prime;
      //printf("%lu \t", next_prime);
      filter(next_prime);
      
      prime_index++;
    }
    //printf("end.\n\n");
    
    //print_bitmap();
    
    printf("Total: %lu.\n", total);

    printf("\n\n[ done ]\n");

    return 0;
}

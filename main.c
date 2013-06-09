#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem 14 ]\n\n\n");
    
    unsigned int collatz[1000000];
    collatz[0] = 0;
    collatz[1] = 1;
    for (unsigned int n = 2; n < 1000000; n++)
    {
      collatz[n] = 0;
    }
    
    unsigned int nsteps;
    unsigned int k;
    for (unsigned int n = 2; n < 1000000; n++)
    {
      //printf("[ %d ", n);
      nsteps = 0;
      k = n;
      
      while (k > 1)
      {
        nsteps += 1;
        if (k % 2 == 0)
        {
          k = k / 2;
        }
        else
        {
          k = 3 * k + 1;
        }
        //printf("> %d ", k);
        
        if (k < 1000000)
        {
        if (collatz[k] != 0)
        {
          nsteps += collatz[k];
          break;
        }
        }
      }
      
      collatz[n] = nsteps;
      //printf("] (%u)\n", nsteps);
    }
    
    unsigned int highest_collatz = 0;
    unsigned int which_number = 0;
    for (unsigned int n = 1; n < 1000000; n++)
    {
      if (collatz[n] > highest_collatz)
      {
        highest_collatz = collatz[n];
        which_number = n;
      }
    }
    
    printf("The longest chain starts at %d and has length %u.\n", which_number, 
        highest_collatz);
    
    printf("\n\n[ done ]\n");

    return 0;
}

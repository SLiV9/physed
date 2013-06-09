#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    printf("[ Project Euler: Problem 12 ]\n\n\n");
    
    unsigned long w = 0;
    unsigned int divs = 0;
    
    for (unsigned long x = 1; x < 999999; x++)
    {
      w += x;
      
      unsigned long n;
      
      /* Now to calculate the number of divisors. 
       * If n | w == 0, then w = n * k for some k in Z. However, note that 
       * w = k * n and therefore k | w, so each divisor has a counterpart;
       * apart from sqrt(w). Also, not that if n < sqrt(w), then k > sqrt(w).
       * We only need to test the numbers that are smaller than sqrt(w), which, 
       * for w >= 1000000 is less than 0.1% of the numbers below w. */
      divs = 0;
      for (n = 1; n * n < w; n++)
      {
        if (w % n == 0)
        {
          divs += 2;
        }
      }
      if (n * n == w)
      {
        divs += 1;
      }
      
      printf("%lu: %u\n", w, divs);
      
      if (divs >= 500)
      {
        break;
      }
    }
    
    printf("Answer: w = %lu.\n", w);
    
    printf("\n\n[ done ]\n");

    return 0;
}
